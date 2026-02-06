// The grasshopper jumps from cell 1 to cell n
// jumping 1 or 2 cells forward each time.
// Each cell has a cost.
// --------------------------------------------------
// Find the number of different paths of minimum cost. Time O(n).

#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> costs(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> costs[i];
  }

  std::vector<int> steps(n + 1);
  steps[1] = 0;
  steps[2] = costs[2] + 1;
  for (int i = 3; i <= n; ++i) {
    if (steps[i - 2] < steps[i - 1])
      steps[i] = steps[i - 2] + costs[i];
    else
      steps[i] = steps[i - 1] + costs[i];
  }
  std::cout << steps[n] << '\n';
  return 0;
}