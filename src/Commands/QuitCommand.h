#pragma once
#include "ICommand.h"

class QuitCommand : public ICommand {
public:
  QuitCommand();

  void execute(const std::vector<std::string>& arguments, TerminalContext& data) override;
};
