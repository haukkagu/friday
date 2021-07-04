#include "QuitCommand.h"

QuitCommand::QuitCommand() : ICommand("quit") { }

void QuitCommand::execute(const std::vector<std::string>& arguments, TerminalContext& context) {
  context.running = false;
}
