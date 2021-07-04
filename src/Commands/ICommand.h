#pragma once
#include "TerminalContext.h"

#include <string>
#include <vector>

class ICommand {
private:
  std::string m_id;
public:
  ICommand(std::string id);
  virtual ~ICommand() = default;

  inline std::string getId() { return m_id; }

  virtual void execute(const std::vector<std::string>& arguments, TerminalContext& context) = 0;
protected:
  std::string getNextArgument(std::vector<std::string>::const_iterator& it, std::vector<std::string>::const_iterator end);
  std::vector<std::string> getRemainingArguments(std::vector<std::string>::const_iterator& it, std::vector<std::string>::const_iterator end);
  void printInvalidArgument(std::string argument);
};
