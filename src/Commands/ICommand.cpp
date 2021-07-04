#include "ICommand.h"

#include <iostream>

ICommand::ICommand(std::string id) : id(id) { }

std::string ICommand::getNextArgument(std::vector<std::string>::const_iterator& it, std::vector<std::string>::const_iterator end) {
  if (it == end) return "";

  return *(it++);
}

std::vector<std::string> ICommand::getRemainingArguments(std::vector<std::string>::const_iterator& it, std::vector<std::string>::const_iterator end) {
  std::vector<std::string> remaining_arguments;
  while (it != end) {
    remaining_arguments.push_back(getNextArgument(it, end));
  }

  return remaining_arguments;
}

void ICommand::printInvalidArgument(std::string argument) {
  std::cout << "'" << argument << "' is not a valid argument\n";
}
