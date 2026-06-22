#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>

void Snow(std::vector<int64_t>& streets, int i, int64_t x) {
  streets[i - 1] += x;
}
int64_t IsSnow(std::vector<int64_t>& streets, int u, int r) {
  int64_t count = 0;
  if (u > r) {
    std::swap(u, r);
  }
  while (u <= r) {
    count += streets[u - 1];
    ++u;
  }
  return count;
}
int main() {
  int n = 0;
  int k = 0;
  std::cin >> n >> k;
  std::vector<int64_t> streets(n, 0);
  for (int q = 0; q < k; ++q) {
    int num = 0;
    std::cin >> num;
    if (num == 1) {
      int i = 0;
      int64_t x = 0;
      std::cin >> i >> x;
      Snow(streets, i, x);
    } else if (num == 2) {
      int i = 0;
      int u = 0;
      std::cin >> i >> u;
      std::cout << IsSnow(streets, i, u) << "\n";
    }
  }
  return 0;
}