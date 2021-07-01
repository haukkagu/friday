#include "Terminal.h"
#include "Commands/EchoCommand.h"

int main() {
  std::vector<CmdPtr> commands = { CmdPtr(new EchoCommand()) };

  Terminal terminal(commands);
  terminal.run();

  return 0;
}
