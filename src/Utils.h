#pragma once
#include "TerminalContext.h"

#include <string>
#ifdef FRIDAY_LINUX
  #define FRIDAY_PLATFORM_PATHSTR std::string
  #define FRIDAY_PLATFORM_CCHARPTR(x) x
#elif FRIDAY_WINDOWS
  #define FRIDAY_PLATFORM_PATHSTR std::wstring
  #define FRIDAY_PLATFORM_CCHARPTR(x) L##x
#endif

bool parseToInt(std::string str, int& out);

bool fileExists(FRIDAY_PLATFORM_PATHSTR file_path);

const FRIDAY_PLATFORM_PATHSTR& getDatabasePath();

TerminalContext setupContext();
void saveContext(TerminalContext context);
TerminalContext loadContext();
