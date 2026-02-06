#include <iostream>
#include <vector>

bool IsPossible(int from, int to, const int length) {
  const int mask = 3;
  for (int i = 1; i < length; ++i) {
    if ((from & mask) == 3 && (to & mask) == 3) return false;
    if ((from & mask) == 0 && (to & mask) == 0) return false;
    from >>= 1;
    to >>= 1;
  }
  return true;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  const int bound = 1 << n;
  std::vector<std::vector<char>> connections(bound, std::vector<char>(bound, 0));

  for (int i = 0; i < bound; ++i) {
    for (int j = 0; j < bound; ++j) {
      connections[i][j] = (IsPossible(i, j, n)) ? 1 : 0;
    }
  }
  std::vector<std::vector<uint32_t>> steps(m, std::vector<uint32_t>(bound, 0));
  for (int i = 0; i < bound; ++i) {
    steps[0][i] = 1;
  }
  for (int k = 1; k < m; ++k) {
    for (int i = 0; i < bound; ++i) {
      for (int j = 0; j < bound; ++j) {
        steps[k][i] += steps[k - 1][j] * connections[j][i];
      }
    }
  }

  uint32_t result = 0;
  for (int i = 0; i < bound; ++i) {
    result += steps[m - 1][i];
  }
  std::cout << result << '\n';
  return 0;

}