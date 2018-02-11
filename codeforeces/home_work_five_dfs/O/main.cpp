#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<bool> visited;
vector<vector<int>> g;

void dfs(int u, int d, vector<int>& dist) {
    visited[u] = true;
    dist[u] = d;
    for (const int v : g[u]) {
        if (!visited[v]) {
            dfs(v, d + 1, dist);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    visited = vector<bool>(n, false);
    g = vector<vector<int>>(n);

    for (int i = 0; i + 1 < n; i++) {
        int pi;
        scanf("%d", &pi);
        g[i + 1].push_back(pi - 1);
        g[pi - 1].push_back(i + 1);
    }

    vector<int> dist(n);
    dfs(0, 0, dist);

    int farthest_node = 0;
    for (int i = 1; i < n; i++) {
        if (dist[i] > dist[farthest_node]) {
            farthest_node = i;
        }
    }

    visited = vector<bool>(n, false);
    dist = vector<int>(n);
    dfs(farthest_node, 0, dist);

    printf("%d\n", *max_element(begin(dist), end(dist)));
}
