#include "EchoCommand.h"

#include <iostream>

EchoCommand::EchoCommand() : ICommand("echo") { }

void EchoCommand::execute (std::vector<std::string> arguments) {
  for (int i = 0; i < arguments.size(); i++) {
    std::cout << arguments[i] << "\n";
  }
}
