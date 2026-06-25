#include <iostream>
#include <string>

bool isUpperLatin(char c) {
  return (c >= 'A' && c <= 'Z');
}
bool isDigit(char c) {
  return (c >= '0' && c <= '9');
}

int main() {
  std::string s;
  std::cin >> s;
  if (s.length() == 6 && isUpperLatin(s[0]) && isDigit(s[1]) && isDigit(s[2]) && isDigit(s[3]) && isUpperLatin(s[4]) && isUpperLatin(s[5])) {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
  return 0;
}