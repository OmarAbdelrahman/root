#include <bits/stdc++.h>
using namespace std;

const int M = (1 << 14) + 1;

inline int from_hex(char c) {
  if (isdigit(c)) return c - '0';
  return c - 'A' + 10;
}

char column[M];
int parent[M * 2];

inline int fs(int x) {
  if (parent[x] == x) return x;
  return (parent[x] = fs(parent[x]));
}

void merge(int a, int b) {
  a = fs(a);
  b = fs(b);
  if (a == b) {
    return;
  }
  if (a < b) {
    parent[b] = a;
  } else {
    parent[a] = b;
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 2 * m; i++) {
    parent[i] = -1;
  }
  int result = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", column);
    for (int j = 0; j < m; j++) {
      if (parent[j] != -1) {
        parent[j + m] = parent[j] + m;
      } else {
        parent[j + m] = -1;
      }
      parent[j] = -1;
    }
    bool left = false;
    for (int j = 0; j < m; j++) {
      const int index = j / 4;
      bool cur_bit = (from_hex(column[index]) >> ((j & 3) ^ 3)) & 1;
      if (cur_bit) {
        parent[j] = j;
        if (left) {
          merge(j, j - 1);
        }
        if (parent[j + m] != -1) {
          merge(j, j + m);
        }
      } else {
        parent[j] = -1;
      }
      left = cur_bit;
    }
    for (int j = m; j < 2 * m; j++) {
      if (parent[j] == j) {
        result++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (parent[i] == i) {
      result++;
    }
  }
  cout << result << endl;
  return 0;
}
