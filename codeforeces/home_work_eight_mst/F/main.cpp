#include <bits/stdc++.h>
using namespace std;

struct edge {
    int t;
    long long c;
    int i;
    
    bool operator < (const edge& e) const {
        if (c == e.c) return t < e.t;
        return c < e.c;
    }
};

set<edge> s;

void f(int u, vector<bool>& visited, const vector<vector<edge>>& g) {
    visited[u] = true;
    for (const auto& e : g[u])
        if (!visited[e.t])
            s.insert(e);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<vector<edge>> g(n);
    vector<pair<int, int>> edges;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a -= 1;
        b -= 1;
        g[a].push_back({b, c, i});
        g[b].push_back({a, c, i});
        edges.push_back({a, b});
    }
    
    vector<bool> visited(n, false);
    f(0, visited, g);
    
    vector<pair<int, int>> r;
    long long cost = 0;
    
    while (!s.empty()) {
        const auto& e = begin(s);
        int u = e->t;
        long long c = e->c;
        int index = e->i;
        s.erase(begin(s));
        
        if (!visited[u]) {
            cost += c;
            r.push_back(edges[index]);
            f(u, visited, g);
        }
    }
    
    printf("%lld\n", cost);
    for (const auto& p : r) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }
}
