#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

vector<bool> visited;
vector<int> lca_values;
vector<vector<pair<int, int>>> g;
vector<vector<pair<int, int>>> qs;

struct disjoint_set {
    disjoint_set(int n): p(n), g(n) {
        for (int i = 0; i < n; i++) {
            p[i] = {i, INF};
            g[i] = i;
        }
    }
    
    pair<int, int> find(int x) {
        if (p[x] == x) return p[x];
        else {
            auto pp = find(p[x].first);
            p[x].first = pp.first;
            p[x].second = min(p[x].second, pp.second);
            return p[x];
        }
    }
    
    bool merge(int a, int b) {
        if (a == b) return false;
        p[a].first = b;
        p[a].second = g[b][a].second;
        return true;
    }
    
    int get_min(int u) {
        return p[u].second;
    }

    int operator [](int u) {
        return p[u].first;
    }
  
private:
    vector<pair<int, int>> p;
    vector<int> g;
};

disjoint_set s;

void dfs(int u, int p) {
    visited[u] = true;
    for (auto n : g[u]) {
        int v, w;
        tie(v, w) = n;
        if (v != p && !visited[v]) {
            dfs(v, u);
            s.merge(v, u);
        }
    }
    for (auto n : qs[u]) {
        int v, i;
        tie(v, i) = n;
        if (visited[v] && lca_values[i] == -1)
            lca_values[i] = s[v];
    }
}

int main() {
    int n = nxt();
    
    g = vector<vector<pair<int, int>>>(n);
    qs = vector<vector<pair<int, int>>(n);
    visited = vector<bool>(n, false);
    s = disjoint_set(n);
    lca_values = vector<int>(n, -1);
    
    for (int i = 0; i < n - 1; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        int w = nxt();
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }
    
    T = 0;
    dfs(0, 0);
    
    int q = nxt();
    for (int i = 0; i < q; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        qs[a].push_back({b, i});
        qs[b].push_back({a, i});
        queries.push_back({a, b});
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        tie(a, b) = queries[i];
        int v = lca_values[i];
        int m1 = s.get_min(v);
    }
}
