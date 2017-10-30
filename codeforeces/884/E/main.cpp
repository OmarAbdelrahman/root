#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 12) + 1;
const int M = (1 << 14) + 1;

struct disjoint_set {
  vector<int> parent;

  disjoint_set() { }

  disjoint_set(int n) {
    initialize(n);
  }

  void initialize(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int operator [](int x) {
    if (parent[x] == x) return x;
    return (parent[x] = operator[](parent[x]));
  }

  void merge(int a, int b) {
    parent[(*this)[a]] = (*this)[b];
  }

  bool equal(int a, int b) {
    return (*this)[a] == (*this)[b];
  }
};

inline int from_hex(char c) {
  if (isdigit(c)) return c - '0';
  return c - 'A' + 10;
}

char column[M];
bitset<M> a;
bitset<M> b;

int main() {
  int n, m;
  cin >> n >> m;
  const int ms = m / 4;
  for (int i = 0; i < n; i++) {
    cin >> column;
    for (int j = 0; j < ms; j++) {
      int value = from_hex(column[j]);
      for (int k = 0; k < 4; k++) {
        a[j * 4 + k] = (value >> (3 - k)) & 1;
      }
    }
  }
  return 0;
}
