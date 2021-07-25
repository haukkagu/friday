#include "Utils.h"
#include "BinarySerializer.h"

#include <fstream>

bool parseToInt(std::string str, int& out) {
  out = 0;

  for (int i = 0; i < str.size(); i++) {
    int digit = str[i] - '0'; // Parse char to int. Chars that are not digits will be either negative or more than 9.
    if (digit >= 0 && digit <= 9) {
      int place_value = str.size() - i - 1;

      int expanded_digit = digit;
      for (int i = 0; i < place_value; i++) {
        expanded_digit *= 10;
      }

      out += expanded_digit;
    }else {
      out = 0;
      return false;
    }
  }

  return true;
}

bool fileExists(FRIDAY_PLATFORM_PATHSTR file_path) {
  std::ifstream infile(file_path);
  return infile.good();
}

#ifdef FRIDAY_LINUX
  #include <libgen.h>
  #include <unistd.h>
  #include <linux/limits.h>
#endif
#ifdef FRIDAY_WINDOWS
  #include <Windows.h>
#endif

const FRIDAY_PLATFORM_PATHSTR& getDatabasePath() {
  static FRIDAY_PLATFORM_PATHSTR file_path;
  if (file_path.empty()) {
    #ifdef FRIDAY_LINUX
      char exe_path[PATH_MAX];
      ssize_t count = readlink("/proc/self/exe", exe_path, PATH_MAX);
      const char* dir_path;
      if (count != -1) {
		dir_path = dirname(exe_path);
      }

      file_path = std::string(dir_path) + "/save.db";
    #elif FRIDAY_WINDOWS
	  wchar_t raw_path[MAX_PATH];
	  GetModuleFileName(NULL, raw_path, MAX_PATH);

	  std::wstring dir_path;
	  std::wstring exe_path = std::wstring(raw_path);
	  size_t last_slash_id = exe_path.rfind('\\');
	  if (std::string::npos != last_slash_id) {
		  dir_path = exe_path.substr(0, last_slash_id);
	  }

	  file_path = dir_path + L"\\save.db";
	#endif
  }

  return file_path;
}

TerminalContext setupContext() {
  TerminalContext context;
  if (fileExists(getDatabasePath())) {
    context = loadContext();
  }else {
    saveContext(context);
  }

  return context;
}

void formatContext(BinarySerializer::Mode mode, TerminalContext& context) {
  BinarySerializer bs(getDatabasePath(), mode);
  bs.extend(context.todos);
  bs.close();
}

void saveContext(TerminalContext context) {
  formatContext(BinarySerializer::Mode::Write, context);
}

TerminalContext loadContext() {
  TerminalContext context;
  formatContext(BinarySerializer::Mode::Read, context);
  return context;
}
