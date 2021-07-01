#pragma once
#include "Commands/ICommand.h"

#include <string>
#include <memory>
#include <vector>
#include <map>

using CmdPtr = std::shared_ptr<ICommand>;

class Terminal {
private:
  std::map<std::string, CmdPtr> commands;

  void executeCommand(std::string id, std::vector<std::string> arguments);
public:
  Terminal(const std::vector<CmdPtr>& commands);

  void run();
};
