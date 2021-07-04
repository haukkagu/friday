#include "TodoCommand.h"
#include "Utils.h"

#include <iostream>
#include <algorithm>

TodoCommand::TodoCommand() : ICommand("todo") { }

void TodoCommand::execute(const std::vector<std::string>& arguments, TerminalContext& context) {
  auto it = arguments.begin();

  std::string mode = getNextArgument(it, arguments.end());

  if (mode == "list") {
    std::cout << "==TODO LIST==\n";
    for (int i = 0; i < context.todos.size(); i++) {
      std::cout << (i+1) << ") " << context.todos[i] << "\n";
    }
  }else if (mode == "add") {
    std::vector<std::string> remaining_arguments = getRemainingArguments(it, arguments.end());

    // Extend todo list by remaining_arguments
    context.todos.insert(context.todos.end(), remaining_arguments.begin(), remaining_arguments.end());
  }else if (mode == "remove") {
    std::vector<std::string> remaining_arguments = getRemainingArguments(it, arguments.end());
    std::vector<int> delete_indices;

    for (int i = 0; i < remaining_arguments.size(); i++) {
      int index_arg;

      if (parseToInt(remaining_arguments[i], index_arg)) {
        int index = index_arg - 1;
        if (index < context.todos.size()) {
          delete_indices.push_back(index);
        }else {
          std::cout << "'" << remaining_arguments[i] << "' is outside of bounds\n";
        }
      }else {
        std::cout << "'" << remaining_arguments[i] << "' is not an integer\n";
      }
    }

    std::sort(delete_indices.begin(), delete_indices.end());

    for (int i = delete_indices.size() - 1; i >= 0; i--) {
      if (i > 0 && delete_indices[i] == delete_indices[i-1]) continue; // Do not delete an element that is already deleted

      context.todos.erase(context.todos.begin()+delete_indices[i]);
    }

  }else printInvalidArgument(mode);
}
