#include <bits/stdc++.h>
using namespace std;

template<class T> struct edge {
  int f, t; T c;
  edge() { }
  edge(int _f, int _t, T _c)
    : f(_f), t(_t), c(_c) { }
  bool operator < (const edge &e) const {
    return c < e.c;
  }
};
 
struct disjoint_set {
  int *parent;
  int *rank;
  int components;

  disjoint_set(int n) {
    parent = new int[n];
    rank = new int[n];
    components = n;
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }

  int find(int s) {
    return parent[s] == s ? (parent[s] = s) : find(parent[s]);
  }

  bool equal(int s1, int s2) {
    return find(s1) == find(s2);
  }

  void join(int s1, int s2) {
    int p1 = find(s1);
    int p2 = find(s2);
    if (p1 == p2) return;
    if (rank[p1] == rank[p2])
      ++rank[p1];
    if (rank[p1] < rank[p2])
      swap(p1, p2);
    parent[p2] = p1;
    --components;
  }
};

long long mst(int nodes, vector<edge<long long>>& edge_list) {
  disjoint_set s(nodes);
  const int edges = edge_list.size();
  sort(edge_list.begin(), edge_list.end());
  long long result = 0;
  for (int i = 0; i < edges; i++) {
    if (!s.equal(edge_list[i].f, edge_list[i].t)) {
      s.join(edge_list[i].f, edge_list[i].t);
      result += edge_list[i].c;
    }
  }
  if (s.components != 1) return -1;
  return result;
}

int main() {
  return 0;
}
