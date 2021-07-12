#include "SaveCommand.h"
#include "Utils.h"

SaveCommand::SaveCommand() : ICommand("save") { }

void SaveCommand::execute(const std::vector<std::string>& arguments, TerminalContext& context) {
  saveContext(context);
}
