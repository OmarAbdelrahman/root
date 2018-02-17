#include <bits/stdc++.h>
using namespace std;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

int T;
vector<vector<int>> g;
vector<int> tin, tout;
vector<vector<int>> up;
vector<bool> visited;

int mod(int x, int y) {
    if (x % y == 0) return y;
    return x % y;
}

bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    for (int i = up[u].size() - 1; i >= 0; i--)
        if (!ancestor(up[u][i], v))
            u = up[u][i];
    return up[u][0];
}

void dfs(int u, int w) {
    visited[u] = true;
    tin[u] = T++;
    up[u][0] = w;
    for (int k = 1; k < int(up[k].size()); k++)
        up[u][k] = up[up[u][k - 1]][k - 1];
    for (int v : g[u])
        if (v != w && !visited[v])
            dfs(v, u);
    tout[u] = T++;
}

int main() {
    int n = nxt();
    
    int mk = 0;
    while ((1 << mk) <= n)
        mk += 1;
    
    g = vector<vector<int>>(n + 1);
    tin = vector<int>(n + 1);
    tout = vector<int>(n + 1);
    visited = vector<bool>(n + 1, false);
    up = vector<vector<int>>(n + 1, vector<int>(mk));
    
    for (int i = 0; i < n - 1; i++) {
        int a = nxt();
        int b = nxt();
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    T = 0;
    int root = mod(8191 * n + 511, n);
    
    dfs(root, root);
    
    int ai = 1;
    int bi = n;
    int r = lca(ai, bi);
    
    printf("%d", r);
    for (int i = 2; i <= n; i++) {
        int na = mod(mod(2 * ai, n) + mod(3 * bi, n), n);
        int nb = mod(r * 1009 + 17, n);
        ai = na;
        bi = nb;
        r = lca(ai, bi);
        printf(" %d", r);
    }
    puts("");
}
