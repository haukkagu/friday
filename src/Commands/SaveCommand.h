#pragma once
#include "ICommand.h"

class SaveCommand : public ICommand {
public:
  SaveCommand();

  void execute(const std::vector<std::string>& arguments, TerminalContext& context) override;
};
