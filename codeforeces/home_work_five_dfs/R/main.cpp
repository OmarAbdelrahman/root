#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

struct edge {
    int f, t;
};

int n, m;
array<bool, N> visited;
array<vector<int>, N> g;
array<int, N> fup, depth;
array<int, N> parent;
vector<vector<edge>> edges;
map<pair<int, int>, bool> colored;
vector<bool> internal_visited;

void same_color_dfs(int u, int v, int c) {
    colored[{v, u}] = true;
    colored[{u, v}] = true;
    internal_visited[u] = true;
    edges[c].push_back({v, u});
    for (const int i : g[u]) {
        if (!internal_visited[i] && !colored[{u, i}]) {
            same_color_dfs(i, u, c);
        }
    }
}

void dfs(int u, int d, int c) {
    visited[u] = true;
    fup[u] = depth[u] = d;
    int children = 0;
    for (const int v : g[u]) {
        if (!visited[v]) {
            children++;
            dfs(v, d + 1, c);
            // articulation vertex 'u';
            if (d > 0 && depth[u] <= fup[v]) {
                internal_visited[u] = true;
                same_color_dfs(v, u, c++);
                internal_visited[u] = false;
            }
            fup[u] = min(fup[u], fup[v]);
        } else {
            fup[u] = min(fup[u], depth[v]);
        }
    }
    if (d == 0 && children >= 2) {
        internal_visited[u] = true;
        same_color_dfs(u, u, c++);
        internal_visited[u] = false;
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        g[i].clear();
        fup[i] = depth[i] = 0;
        parent[i] = -1;
        internal_visited[i] = false;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
        colored[{a, b}] = false;
        colored[{b, a}] = false;
    }

    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, 0, cc++);
        }
    }

    printf("%d\n", cc);
    for (const auto& edge_list : edges) {
        printf("%d\n", int(edge_list.size()));
        for (const auto& edge : edge_list) {
            printf("%d %d\n", edge.f + 1, edge.t + 1);
        }
    }
}
