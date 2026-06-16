#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, std::vector<int>> ShortestWay(std::vector<int> triangle, int num) {

}
int main() {
  int size = 0;
  std::cin >> size;
  int num_elements = size * (size + 1) / 2;
  std::vector<int> triangle(num_elements);
  for (int i = 0; i < num_elements; ++i) {
    std::cin >> triangle[i];
  }
  std::pair<int, std::vector<int>> result = ShortestWay(triangle, size);
  int min_sum = result.first;
  std::vector<int> path = result.second;
  std::cout << min_sum << "\n";
  for (int i = 0; i < size; ++i) {
    std::cout << path[i] << (i == size - 1 ? "" : " ");
  }
  std::cout << "\n";
  return 0;
}