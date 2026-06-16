#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, std::vector<int>> ShortestWay(std::vector<int> triangle, int size) {
  //для каждой высоты считать начало строки
  std::vector<int> row_start(size + 1, 0);
  for (int i = 0; i < size; ++i) {
    row_start[i + 1] = row_start[i] + (i + 1);
  }
  //идём дп снизу вверх - считаем выгодных детей
  for (int i = size - 2; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      int current_idx = row_start[i] + j;
      int left_child = row_start[i + 1] + j;
      int right_child = row_start[i + 1] + j + 1;
      triangle[current_idx] += std::min(triangle[left_child], triangle[right_child]);
    }
  }
  int min_sum = triangle[0]; //нашли минимальный путь
  //восстанавливаем путь
  std::vector<int> path;
  int current_j = 0;
  for (int i = 0; i < size; ++i) {
    int current_idx = row_start[i] + current_j;
    if (i == size - 1) {
      path.push_back(triangle[current_idx]);
      break;
    }
    int left_child  = row_start[i + 1] + current_j;
    int right_child = row_start[i + 1] + current_j + 1;
    int next_j = current_j;
    int next_idx = left_child;
    if (triangle[left_child] > triangle[right_child]) {
      next_j = current_j + 1;
      next_idx = right_child;
    }
    int original_val = triangle[current_idx] - triangle[next_idx];
    path.push_back(original_val);
    current_j = next_j;
  }
  return {min_sum, path};
}
int main() {
  int height = 0;
  std::cin >> height;
  int num_elements = height * (height + 1) / 2;
  std::vector<int> triangle(num_elements);
  for (int i = 0; i < num_elements; ++i) {
    std::cin >> triangle[i];
  }
  std::pair<int, std::vector<int>> result = ShortestWay(triangle, height);
  int min_sum = result.first;
  std::vector<int> path = result.second;
  std::cout << min_sum << "\n";
  for (int i = 0; i < height; ++i) {
    std::cout << path[i] << (i == height - 1 ? "" : " ");
  }
  std::cout << "\n";
  return 0;
}