#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

vector<vector<int>> g;

int bfs(int src, int n) {
    queue<int> q;
    vector<int> dist(n, INF);
    vector<int> parent(n, -1);

    dist[src] = 0;
    parent[src] = src;

    int result = INF;
    for (q.push(src); !q.empty(); q.pop()) {
        int u = q.front();
        for (const int v : g[u]) {
            if (dist[v] == INF) {
                dist[v] = 1 + dist[u];
                parent[v] = u;
                q.push(v);
            } else if (v != parent[u]) {
                result = min(result, dist[u] + dist[v] + 1);
            }
        }
    }
    return result;
}

int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        g = vector<vector<int>>(n);

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a -= 1;
            b -= 1;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        int result = INF;
        for (int i = 0; i < n; i++)
            result = min(result, bfs(i, n));
        
        printf("%d\n", result == INF ? -1 : result);
    }
}
