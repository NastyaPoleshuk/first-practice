#include <iostream>
#include<vector>

void Snow(std::vector<int>& streets, int i, int x) {
  streets[i - 1] += x;
}
int IsSnow(std::vector<int>& streets, int u, int r) {
  int count = 0;
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
  std::vector<int> streets(n, 0);
  int num = 0;
  int i = 0;
  int x = 0;
  for (int q = 0; q < k; ++q) {
    std::cin >> num;
    if (num == 1) {
      std::cin >> i >> x;
      Snow(streets, i, x);
    } else if (num == 2) {
      std::cin >> i >> x;
      std::cout << IsSnow(streets, i, x) << "\n";
    }
  }
  return 0;
}