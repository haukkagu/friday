#pragma once

#include <string>
#include <vector>

class ICommand {
private:
  std::string id;
public:
  ICommand(std::string id);
  virtual ~ICommand() = default;

  inline std::string getId() { return id; }

  virtual void execute(std::vector<std::string> arguments) = 0;
};
