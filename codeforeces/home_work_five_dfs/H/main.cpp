#include <bits/stdc++.h>
using namespace std;

const int COLORED = 1;

vector<bool> visited;
vector<vector<int>> g;
vector<int> color;

bool dfs(int u, int node_color) {
    visited[u] = true;
    color[u] = node_color;
    bool ok = true;
    for (int i : g[u]) {
        if (!visited[i]) {
            ok &= dfs(i, 1 - node_color);
        } else if (color[u] == color[i] && u != i) {
            return false;
        }
    }
    return ok;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g.resize(n);
    visited.resize(n);
    color.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ok &= dfs(i, COLORED);
        }
    }

    if (ok) puts("YES"); else puts("NO");
}
