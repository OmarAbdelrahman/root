#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> fup, depth;
vector<bool> cut_vertex;

void dfs(int u, int v, int d) {
    visited[u] = true;
    fup[u] = depth[u] = d;
    int children = 0;
    for (const int i : g[u]) {
        if (!visited[i]) {
            dfs(i, u, d + 1);
            if (d > 0 && fup[i] >= depth[u]) {
                cut_vertex[u] = true;
            }
            fup[u] = min(fup[u], fup[i]);
            children++;
        } else {
            fup[u] = min(fup[u], depth[i]);
        }
    }
    if (d == 0 && children >= 2) {
        cut_vertex[u] = true;
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g = vector<vector<int>>(n);
    visited = vector<bool>(n, false);
    fup = vector<int>(n);
    depth = vector<int>(n);
    cut_vertex = vector<bool>(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, i, 0);
        }
    }

    printf("%d\n", (int) count(begin(cut_vertex), end(cut_vertex), true));
    for (int i = 0; i < n; i++) {
        if (cut_vertex[i]) {
            printf("%d ", i + 1);
        }
    }
    puts("");
}
