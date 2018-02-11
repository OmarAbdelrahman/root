#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<bool> visited;
vector<int> depth;
vector<vector<int>> g;
vector<int> fup;
vector<int> edges;
map<pair<int, int>, int> ei;

void dfs(int u, int w, int d) {
    visited[u] = true;
    depth[u] = fup[u] = d;
    for (const int v : g[u]) if (v != w) {
        if (!visited[v]) {
            dfs(v, u, d + 1);
            if (fup[v] > depth[u]) {
                edges.push_back(ei[{u, v}]);
            }
            fup[u] = min(fup[u], fup[v]);
        } else {
            fup[u] = min(fup[u], depth[v]);
        }
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    visited = vector<bool>(n, false);
    g = vector<vector<int>>(n);
    depth = vector<int>(n);
    fup = vector<int>(n);
    edges.clear();

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
        ei[{a, b}] = i;
        ei[{b, a}] = i;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, i, 0);
        }
    }

    printf("%d\n", int(edges.size()));
    for (size_t i = 0; i < edges.size(); i++) {
        if (i > 0) printf(" ");
        printf("%d", edges[i] + 1);
    }
    puts("");
}
