#include <iostream>
#include <vector>

bool GetBit(const int number, const int bit) {
  return (number & (1 << bit));
}

void Fill(std::vector<std::vector<int>> &d, int from, int to, int shift, int length) {
  if (shift == length) {
    d[from][to] = 1;
    return;
  }
  if (from & 1 << length) {
    Fill(d, from, to + 1, shift + 1, length);
  } else {
    Fill(d, from, to + (1 << shift), shift + 1, length);
    if (shift + 1 < length && !GetBit(from, shift + 1)) {
      Fill(d, from, to, shift + 2, length);
    }
  }
}

int main() {
  int n, m;
  std::cin >> n >> m;

  if (n * m % 2 != 0) {
    std::cout << 0;
    return 0;
  }

  std::vector<std::vector<int>> dp(1 << n, std::vector<int>(1 << n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < (1 << n); ++i) {
    Fill(dp, i, n, 0, 0);
  }
  std::vector<std::vector<int>> a(m, std::vector<int>(1 << n, 0));
  a[0][0] = 1;
  for (int k = 1; k < m; ++k) {
    for (int i = 0; i < 1 << n; ++i) {
      for (int j = 0; j < 1 << n; ++j) {
        a[k][i] += a[k - 1][j] * dp[j][i];
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < 1 << n; ++i) {
    ans += a[m - 1][i];
  }
  std::cout << ans << std::endl;
}