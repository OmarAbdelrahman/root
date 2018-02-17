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
vector<vector<edge>> edges;
map<pair<int, int>, bool> colored;
array<bool, N> internal_visited;
array<int, N> parent;

void mark(int u, int v, int c) {
    colored[{u, v}] = true;
    colored[{v, u}] = true;
    edges[c].push_back({u, v});
}

void internal_dfs(int u, int v, int c) {
    if (u != v) mark(v, u, c);
    internal_visited[u] = true;
    for (const int i : g[u]) if (i != v) {
        if (!internal_visited[i] && !colored[{u, i}]) {
            internal_dfs(i, u, c);
        } else if (!colored[{u, i}]) {
            mark(u, i, c);
        }
    }
}

void dfs(int u, int w, int d) {
    visited[u] = true;
    fup[u] = depth[u] = d;
    int children = 0;
    for (const int v : g[u]) if (v != w) {
        if (!visited[v]) {
            dfs(v, u, d + 1);
            if (d > 0 && depth[u] <= fup[v]) {
                internal_visited[u] = true;
                edges.push_back(vector<edge>());
                internal_dfs(v, u, edges.size() - 1);
                internal_visited[u] = false;
            }
            children++;
            fup[u] = min(fup[u], fup[v]);
        } else {
            fup[u] = min(fup[u], depth[v]);
        }
    }
    if (d == 0) {
        cerr << "I'm Groot! " << u + 1 << endl;
        for (const int v : g[u]) {
            if (!internal_visited[v]) {
                edges.push_back(vector<edge>());
                internal_dfs(u, u, edges.size() - 1);
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        g[i].clear();
        fup[i] = depth[i] = 0;
        internal_visited[i] = false;
    }

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
    
    printf("%d\n", int(edges.size()));
    for (const auto& edge_list : edges) {
        printf("%d\n", int(edge_list.size()));
        for (const auto& edge : edge_list) {
            printf("%d %d\n", edge.f + 1, edge.t + 1);
        }
    }
}
