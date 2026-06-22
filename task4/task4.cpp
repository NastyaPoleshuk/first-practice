#include <iostream>
#include <cstring>
#include <vector>
#include <cstdint>

std::string GetWord(int k, std::vector<int>& permutation, std::string& word) {
  int n = static_cast<int>(permutation.size());
  for (int i = 0; i < n; ++i) {
    permutation[i]--;
  }
  std::string original(n, ' ');
  std::vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      std::vector<int> cycle;
      int curr = i;
      while (!visited[curr]) {
        visited[curr] = true;
        cycle.push_back(curr);
        curr = permutation[curr];
      }
      int len = static_cast<int>(cycle.size());
      for (int m = 0; m < len; ++m) {
        int orig_pos = cycle[(m + k) % len];
        original[orig_pos] = word[cycle[m]];
      }
    }
  }
  return original;
}
int main() {
  int n = 0;
  int64_t k = 0;
  std::cin >> n >> k;
  std::vector<int> permutation(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> permutation[i];
  }
  std::string word;
  std::cin >> word;
  std::cout << GetWord(k, permutation, word) << "\n";
  return 0;
}