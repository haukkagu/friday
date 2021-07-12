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

bool fileExists(std::string file_path) {
  std::ifstream infile(file_path);
  return infile.good();
}

#ifdef FRIDAY_LINUX
  #include <libgen.h>
  #include <unistd.h>
  #include <linux/limits.h>
#endif

const std::string& getDatabasePath() {
  static std::string file_path;
  if (file_path == "") {
    #ifdef FRIDAY_LINUX
      char result[PATH_MAX];
      ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
      const char* path;
      if (count != -1) {
          path = dirname(result);
      }
      file_path = std::string(path) + "/save.db";
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
