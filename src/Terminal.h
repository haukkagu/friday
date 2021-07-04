#pragma once
#include "TerminalContext.h"
#include "Commands/ICommand.h"

#include <string>
#include <memory>
#include <vector>
#include <map>

using CmdPtr = std::shared_ptr<ICommand>;

class Terminal {
private:
  TerminalContext m_context;
  std::map<std::string, CmdPtr> m_commands;

public:
  Terminal(const std::vector<CmdPtr>& commands);

  void run();
private:
  void executeCommand(std::string id, std::vector<std::string> arguments);
};
