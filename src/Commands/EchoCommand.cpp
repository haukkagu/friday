#include "EchoCommand.h"

#include <iostream>

EchoCommand::EchoCommand() : ICommand("echo") { }

void EchoCommand::execute(const std::vector<std::string>& arguments, TerminalContext& context) {
  for (int i = 0; i < arguments.size(); i++) {
    std::cout << arguments[i] << "\n";
  }
}
