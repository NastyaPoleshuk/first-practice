#include <iostream>
#include <vector>

class Graph {
 private:
  std::vector<std::vector<int>> graph;
  int size;

 public:
  void AddEdge(int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  explicit Graph(int n): size(n), graph(n) {
  }
  void DFS(int from, std::vector<bool>& visited) {
    visited[from] = true;
    for(int child : graph[from]) {
      if (!visited[child]) {
        DFS(child, visited);
      }
    }
  }
};

int main() {
  int size = 0;
  int edges = 0;
  std::cin >> size >> edges;
  Graph graph(size);
  std::vector<bool> visited(size, false);
  int from = 0;
  int to = 0;
  int count = -1;
  for (int i = 0; i < edges; ++i) {
    std::cin >> from >> to;
    --from;
    --to;
    graph.AddEdge(from, to);
  }
  for (int i = 0; i < size; ++i) {
    if (!visited[i]) {
      graph.DFS(i, visited);
      count += 1;
    }
  }
  std::cout << count <<"\n";
  return 0;
}