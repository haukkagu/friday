#pragma once

#include <string>
#include <vector>

struct TerminalContext {
  bool running;

  std::vector<std::string> todos;

  TerminalContext();
};
