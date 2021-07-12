#include "Terminal.h"
#include "Utils.h"

#include <iostream>

Terminal::Terminal(const std::vector<CmdPtr>& commands) {
  m_context = setupContext();

  for (int i = 0; i < commands.size(); i++) {
    CmdPtr command = commands[i];
    m_commands.insert({(*command.get()).getId(), command});
  }
}

void parseToCommand(std::string cmd, std::string& id, std::vector<std::string>& arguments);
void Terminal::run() {
  std::string cmd;
  while (m_context.running) {
    std::cout << "> ";
    std::getline(std::cin, cmd);

    std::string id;
    std::vector<std::string> arguments;
    parseToCommand(cmd, id, arguments);

    executeCommand(id, arguments);
  }
}

void Terminal::executeCommand(std::string id, std::vector<std::string> arguments) {
  auto it = m_commands.find(id);
  if (it == m_commands.end()){
    std::cout << "The command '" << id << "' does not exist.\n";
  }else {
    (*it).second.get()->execute(arguments, m_context);
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

void parseToCommand(std::string cmd, std::string& id, std::vector<std::string>& arguments) {
  auto it = cmd.begin();

  id = getToken(it, cmd.end());

  while (it != cmd.end()) {
    it++; // Skip over the seperate char from the previous token

    std::string argument = getToken(it, cmd.end());
    if (argument != "") arguments.push_back(argument);
  }
}
