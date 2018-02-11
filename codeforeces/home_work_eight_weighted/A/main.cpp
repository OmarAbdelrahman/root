#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 3;

struct edge {
    int t, c;
};

vector<int> bellman_ford(int src, const vector<vector<edge>>& g) {
    const int n = g.size();
    vector<int> dist(n, INF);
    dist[src] = 0;

    for (int i = 0; i < n; i++) {
        bool updated = false;
        for (int j = 0; j < n; j++) {
            for (const auto& e : g[j]) {
                if (dist[j] < INF && dist[e.t] > dist[j] + e.c) {
                    dist[e.t] = dist[j] + e.c;
                    updated = true;
                }
            }
        }
        if (!updated) break;
    }
    return dist;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<edge>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a - 1].push_back({b - 1, c});
    }

    vector<int> dist = bellman_ford(0, g);
    for (int i = 1; i < n; i++) {
        if (dist[i] >= INF) puts("NO"); else printf("%d\n", dist[i]);
    }
}
