#include <bits/stdc++.h>
using namespace std;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

struct disjoint_set {
    disjoint_set() { }
    
    disjoint_set(int n): p(n), grey(n), rnd(n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
            grey[i] = i;
        }
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnd() % 2)
            p[a] = b;
        else
            p[b] = a;
        return true;
    }
    
    void set_grey(int u) {
        grey[find(u)] = u;
    }
    
    int get_grey(int u) {
        return grey[find(u)];
    }
    
private:
    vector<int> p;
    vector<int> grey;
    mt19937 rnd;
};

disjoint_set s;
vector<bool> visited;
vector<vector<pair<int, int>>> qs;
vector<vector<int>> g;
vector<int> grey;
vector<int> res;

void dfs(int u, int w) {
    visited[u] = true;
    for (int v : g[u])
        if (v != w && !visited[v]) {
            dfs(v, u);
            s.merge(u, v);
            s.set_grey(u);
        }
    
    for (auto p : qs[u]) {
        int v, i;
        tie(v, i) = p;
        if (visited[v] && res[i] == -1)
            res[i] = s.get_grey(v);
    }
}

int main() {
    int n = nxt();
    
    grey = vector<int>(n);
    visited = vector<bool>(n, false);
    g = vector<vector<int>>(n);
    qs = vector<vector<pair<int, int>>>(n);
    s = disjoint_set(n);
    
    for (int i = 0; i < n - 1; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int nqs = 0;
    for (int a, b; scanf("%d%d", &a, &b) != EOF; nqs++) {
        a -= 1;
        b -= 1;
        qs[a].push_back({b, nqs});
        qs[b].push_back({a, nqs});
    }
    
    res = vector<int>(nqs, -1);
    dfs(0, 0);
    
    for (int i : res) printf("%d ", i + 1);
}
