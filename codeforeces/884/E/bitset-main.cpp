#include <bits/stdc++.h>
using namespace std;

const int M = (1 << 14) + 1;

struct disjoint_set {
  int* parent;

  disjoint_set() { }

  disjoint_set(int n) {
    initialize(n);
  }

  void initialize(int n) {
    parent = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int operator [](int x) {
    if (parent[x] == x) return x;
    return (parent[x] = operator[](parent[x]));
  }

  void merge(int a, int b) {
    a = (*this)[a];
    b = (*this)[b];
    if (a == b) {
      return;
    }
    if (a < b) {
      parent[a] = b;
    } else {
      parent[b] = a;
    }
  }

  ~disjoint_set() {
    delete[] parent;
  }
};

inline int from_hex(char c) {
  if (isdigit(c)) return c - '0';
  return c - 'A' + 10;
}

char column[M];
bitset<M> row;
bitset<M> top;

int main() {
  int n, m;
  cin >> n >> m;
  const int ms = m / 4;
  disjoint_set ds(m * 2);
  int result = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", column);
    for (int j = 0; j < ms; j++) {
      int value = from_hex(column[j]);
      for (int k = 0; k < 4; k++) {
        row[j * 4 + k] = (value >> (3 - k)) & 1;
      }
    }
    for (int j = 0; j < m; j++) {
      ds.parent[j + m] = j + m;
    }
    for (int j = 0; j < m; j++) {
      if (j > 0 && row[j - 1] && row[j]) {
        ds.merge(j + m - 1, j + m);
      }
      if (row[j] && top[j]) {
        ds.merge(j, j + m);
      }
    }
    for (int j = 0; j < m; j++) {
      if (top[j] && ds[j] == j) {
        ++result;
      }
      int row_parent = ds[j + m];
      ds.parent[j] = row_parent != j + m ? row_parent - m : j;
    }
    top = row;
  }
  for (int j = 0; j < m; j++) {
    if (top[j] && ds[j] == j) {
      ++result;
    }
  }
  cout << result << endl;
  return 0;
}
