#include <bits/stdc++.h>
using namespace std;

struct edge {
    int f, t, c, id;
    
    edge(int _f, int _t, int _c, int _id): f(_f), t(_t), c(_c), id(_id) { }
    
    bool operator < (const edge& e) const {
        return c < e.c;
    }
};

struct disjoin_set {
    disjoin_set(int n): parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int a) {
        return parent[a] == a ? a : (parent[a] = find(parent[a]));
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rank[a] > rank[b])
            swap(a, b);
        parent[a] = b;
        rank[b] += int(rank[a] == rank[b]);
        return true;
    }
    
    vector<int> parent;
    vector<int> rank;
};

vector<edge> solve(int n, vector<int>& cnt, vector<edge>& es) {
    disjoin_set s(n);
    sort(begin(es), end(es));
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<edge> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back(edge(a - 1, b - 1, c, i));
    }
    
    vector<int> cnt(m, 0);
    vector<edge> e1 = solve(n, cnt, edges);
    for (const auto& e : e1) {
        solve_again(n, e.id, cnt, edges);
    }
    
    for (int i = 0; i < m; i++) {
        int c = cnt[i];
        if (c == 0) puts("none");
        else if (c == 1) puts("at least one");
        else puts("any");
    }
}
