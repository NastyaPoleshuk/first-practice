#include <iostream>
#include <algorithm>

int main() {
  int n = 0;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    int b = 0;
    int x = 0;
    int y = 0;
    std::cin >> a >> b >> x >> y;
    int min_b = std::min(b, x);
    x -= min_b;
    int for_a = x + y;
    int result = std::min(a, for_a) + min_b;
    std::cout << result;
    if (i < n - 1) {
      std::cout << " ";
    } else {
      std::cout << "\n";
    }
  }
  return 0;
}