#include "Terminal.h"
#include "Commands.h"

int main() {
  std::vector<CmdPtr> commands = { CmdPtr(new QuitCommand()), CmdPtr(new EchoCommand()), CmdPtr(new TodoCommand()), CmdPtr(new SaveCommand()) };

  Terminal terminal(commands);
  terminal.run();

  return 0;
}
