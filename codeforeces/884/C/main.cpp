#include <bits/stdc++.h>
using namespace std;

const int N = 111111;

struct disjoint_set {
  int* parent;
  int* rank;
  int* set_size;
  int sets_count;

  disjoint_set(int n) {
    initialize(n);
  }

  void initialize(int n) {
    parent = new int[n];
    rank = new int[n];
    set_size = new int[n];
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
      set_size[i] = 1;
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
    if (rank[a] == rank[b]) {
      rank[a]++;
    }
    if (rank[a] < rank[b]) {
      swap(a, b);
    }
    parent[b] = a;
    set_size[a] += set_size[b];
    sets_count--;
  }

  ~disjoint_set() {
    delete[] parent;
    delete[] rank;
    delete[] set_size;
  }
};

template<class T>
inline T next() {
  T x;
  cin >> x;
  return x;
}

int main() {
  int n = next<int>();
  vector<int> p(n);
  for (int& i : p) {
    cin >> i;
  }
  return 0;
}
