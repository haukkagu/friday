#include "Utils.h"

bool parseToInt(std::string str, int& out) {
  out = 0;

  for (int i = 0; i < str.size(); i++) {
    int digit = str[i] - '0'; // Parse char to int. Chars that are not digits will be either negative or more than 9.
    if (digit >= 0 && digit <= 9) {
      int place_value = str.size() - i - 1;

      int expanded_digit = digit;
      for (int i = 0; i < place_value; i++) {
        expanded_digit *= 10;
      }

      out += expanded_digit;
    }else {
      out = 0;
      return false;
    }
  }

  return true;
}
