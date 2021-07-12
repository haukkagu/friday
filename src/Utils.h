#pragma once
#include "TerminalContext.h"

#include <string>

bool parseToInt(std::string str, int& out);

bool fileExists(std::string file_path);

const std::string& getDatabasePath();

TerminalContext setupContext();
void saveContext(TerminalContext context);
TerminalContext loadContext();
