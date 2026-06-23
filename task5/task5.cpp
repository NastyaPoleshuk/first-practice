#include <iostream>

int main() {
  int h = 0;
  int w = 0;
  std::cin >> h >> w;
  int left_x = w;
  int left_y = h;
  int right_x = -1;
  int right_y = -1;
  int current = 0;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      std::cin >> current;
      if (current == 1) {
        if (i < left_y) {
          left_y = i;
        }
        if (j < left_x) {
          left_x = j;
        }
        if (i > right_y) {
          right_y = i;
        }
        if (j > right_x) {
          right_x = j;
        }
      }
    }
  }
  std::cout << left_y - 1 << " " << left_x - 1 << " " << right_y + 1 << " " << right_x + 1 << "\n";
  return 0;
}