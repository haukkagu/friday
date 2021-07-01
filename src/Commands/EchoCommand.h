#pragma once
#include "ICommand.h"

class EchoCommand : public ICommand {
public:
  EchoCommand();

  void execute (std::vector<std::string> arguments) override;
};
