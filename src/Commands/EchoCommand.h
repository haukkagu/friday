#pragma once
#include "ICommand.h"

class EchoCommand : public ICommand {
public:
  EchoCommand();

  void execute(const std::vector<std::string>& arguments, TerminalContext& context) override;
};
