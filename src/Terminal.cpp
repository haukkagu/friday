#include "Terminal.h"

#include <iostream>

Terminal::Terminal(const std::vector<CmdPtr>& commands) {
  for (int i = 0; i < commands.size(); i++) {
    this->commands.insert({(*commands[i].get()).getId(), commands[i]});
  }
}

void parse(std::string cmd, std::string& id, std::vector<std::string>& arguments);
void Terminal::run() {
  std::string cmd;
  while (this->context.running) {
    std::cout << "> ";
    std::getline(std::cin, cmd);

    std::string id;
    std::vector<std::string> arguments;
    parse(cmd, id, arguments);

    executeCommand(id, arguments);
  }
}

void Terminal::executeCommand(std::string id, std::vector<std::string> arguments) {
  auto it = commands.find(id);
  if (it == commands.end()){
    std::cout << "The command '" << id << "' does not exist.\n";
  }else {
    (*it).second.get()->execute(arguments, this->context);
  }
}

void eatWhitespace(std::string::iterator& it, std::string::iterator end) {
  while (*it == ' ' && it != end) {
    it++;
  }
}

std::string getToken(std::string::iterator& it, std::string::iterator end) {
  eatWhitespace(it, end);

  char seperate_char = ' ';
  if (*it == '"') {
    seperate_char = *it;
    it++;
  }

  auto start = it;
  while (*it != seperate_char && it != end) {
    it++;
  }

  return std::string(start, it);
}

void parse(std::string cmd, std::string& id, std::vector<std::string>& arguments) {
  auto it = cmd.begin();

  id = getToken(it, cmd.end());

  while (it != cmd.end()) {
    it++; // Skip over the seperate char from the previous token

    std::string argument = getToken(it, cmd.end());
    if (argument != "") arguments.push_back(argument);
  }
}
