#pragma once
#include "ICommand.h"

class TodoCommand : public ICommand {
public:
  TodoCommand();

  void execute(const std::vector<std::string>& arguments, TerminalContext& data) override;
};
