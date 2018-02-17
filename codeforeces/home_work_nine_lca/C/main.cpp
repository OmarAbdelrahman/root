#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

vector<vector<int>> up;
vector<vector<int>> g;
vector<bool> visited;

void dfs(int u, int w) {
    visited[u] = true;
    up[u][0] = w;
    for (int k = 1; k < int(up[k].size()); k++)
        up[u][k] = up[up[u][k - 1]][k - 1];
    for (int v : g[u]) if (v != w)
        if (!visited[v])
            dfs(v, u);
}

int main() {
    int n = nxt();
    
    int mk = 1;
    while ((1 << mk) < n) mk += 1;
    
    g = vector<vector<int>>(n);
    up = vector<vector<int>>(n, vector<int>(mk));
    visited = vector<bool>(n, false);
    
    for (int i = 0; i < n - 1; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(0, 0);
    for (int m = nxt(); m-- > 0; ) {
        int v = nxt() - 1;
        int k = nxt();
        for (int i = mk - 1; i >= 0; i--) {
            if (k >= (1 << i)) {
                v = up[v][i];
                k -= (1 << i);
            }
        }
        printf("%d\n", v + 1);
    }
}
