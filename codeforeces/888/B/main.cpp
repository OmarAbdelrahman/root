#include <bits/stdc++.h>
using namespace std;

const int N = 111;
const int OFFSET = 100;

template<class T>
inline T next() {
  T x;
  cin >> x;
  return x;
}

int dp[N][N][N];

int main() {
  int n = next<int>();
  string cmds = next<string>();
  for (int i = 1; i <= n; i++) {
    for (int x = 1; x <= 100; x++) {
      for (int y = 1; y <= 100; y++) {
        char command = cmds[i - 1];
        dp[i][x][y] = dp[i - 1][x][y];
        if (command == 'U') {
          dp[i][x][y] = max(dp[i][x][y], (int) (y == 1) + dp[i - 1][x][y + 1]);
        } else if (command == 'D') {
          dp[i][x][y] = max(dp[i][x][y], (int) (y == 1) + dp[i - 1][x][y - 1]);
        } else if (command == 'L') {
          dp[i][x][y] = max(dp[i][x][y], (int) (x == 1) + dp[i - 1][x - 1][y]);
        } else {
          dp[i][x][y] = max(dp[i][x][y], (int) (x == 1) + dp[i - 1][x + 1][y]);
        }
      }
    }
  }
  cout << dp[n][100][100] << endl;
  return 0;
}
