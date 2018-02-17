#include <bits/stdc++.h>
using namespace std;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

vector<vector<int>> g;
vector<bool> visited;
vector<vector<int>> up;

void dfs(int u, int w) {
    visited[u] = true;
    up[u][0] = w;
    for (int k = 1; k < int(up[k].size()); k++)
        up[u][k] = up[up[u][k - 1]][k - 1];
    for (int v : g[u])
        if (v != w && !visited[v])
            dfs(v, u);
}

int main() {
    int n = nxt();
    int mk = 0;
    
    while ((1 << mk) < n) mk += 1;
    
    g = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    up = vector<vector<int>>(n, vector<int>(mk));
    
    for (int i = 0; i < n - 1; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        printf("%d", up[i][0] + 1);
        for (int k = 1; k < mk; k++)
            printf(" %d", up[i][k] + 1);
        puts("");
    }
}
