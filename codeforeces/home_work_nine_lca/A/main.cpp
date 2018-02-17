#include <bits/stdc++.h>
using namespace std;

int T;
vector<vector<int>> g;
vector<int> tin, tout;
vector<int> depth;
vector<bool> visited;

void dfs(int u, int w, int d) {
    visited[u] = true;
    tin[u] = T++;
    depth[u] = d;
    for (int v : g[u])
        if (v != w)
            if (!visited[v])
                dfs(v, u, d + 1);
    tout[u] = T++;
}

int main() {
    int n;
    scanf("%d", &n);
    
    g = vector<set<int>>(n);
    tin = vector<int>(n);
    tout = vector<int>(n);
    depth = vector<int>(n);
    visited = vector<bool>(n, false);
    
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    T = 0;
    dfs(0, 0, 0);
    
    for (int i = 0; i < n; i++)
        printf("%d %d %d\n", depth[i], tin[i], tout[i]);
}
