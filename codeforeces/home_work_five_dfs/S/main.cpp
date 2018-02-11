#include <bits/stdc++.h>
using namespace std;

vector<int> top_sort;
vector<vector<int>> g, r;
set<pair<int, int>> edges;
vector<int> component;
vector<bool> visited;

int scc;

void do_top_sort(int u) {
    visited[u] = true;
    for (const int v : g[u]) if (!visited[v]) do_top_sort(v);
    top_sort.push_back(u);
}

void dfs(int u, int nc) {
    visited[u] = false;
    component[u] = nc;
    for (const int v : r[u]) if (visited[v]) dfs(v, nc);
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g = vector<vector<int>>(n);
    r = vector<vector<int>>(n);
    component = vector<int>(n);
    visited = vector<bool>(n, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        edges.insert({a, b});
    }

    for (const auto& e : edges) {
        g[e.first].push_back(e.second);
        r[e.second].push_back(e.first);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            do_top_sort(i);
        }
    }
    reverse(begin(top_sort), end(top_sort));

    scc = 0;
    for (int i = 0; i < n; i++) {
        if (visited[top_sort[i]]) {
            dfs(top_sort[i], scc++);
        }
    }

    printf("%d\n", scc);
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", component[i] + 1);
    }
    puts("");
}
