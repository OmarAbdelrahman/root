#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max() / 4L;

struct edge {
    int t;
    long long c;
};

void dfs(int u, vector<bool>& reachable, const vector<vector<edge>>& graph) {
    reachable[u] = true;
    for (const auto& e : graph[u])
        if (!reachable[e.t])
            dfs(e.t, reachable, graph);
}

vector<long long> bellman_ford(int s, const vector<vector<edge>>& graph) {
    int n = graph.size();
    vector<long long> dist(n, INF);
    dist[s] = 0;

    vector<long long> changes(n, 0);
    vector<long long> old_dist = dist;

    for (int i = 0; i < n; i++) {
        bool updated = false;
        for (int u = 0; u < n; u++) {
            for (const auto& e : graph[u]) {
                int v = e.t;
                if (dist[u] < INF && dist[v] > dist[u] + e.c) {
                    dist[v] = dist[u] + e.c;
                    updated = true;
                }
            }
        }
        if (i > 0) {
            for (int j = 0; j < n; j++) {
                changes[j] += dist[j] - old_dist[j];
                changes[j] = max(-INF, changes[j]);
            }
        }
        old_dist = dist;
        if (!updated) {
            break;
        }
        if (i == n - 1) {
            for (int j = 0; j < n; j++) {
                if (changes[j] < 0 && dist[j] < INF) {
                    dist[j] = -INF;
                }
            }
            vector<bool> reachable(n, false);
            for (int c = 0; c < n; c++) {
                if (dist[c] <= -INF && !reachable[c]) {
                    dfs(c, reachable, graph);
                }
            }
            for (int t = 0; t < n; t++) {
                if (reachable[t]) {
                    dist[t] = -INF;
                }
            }
        }
    }

    return dist;
}

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);

    map<pair<int, int>, long long> cost;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        scanf("%d%d%lld", &a, &b, &c);
        a -= 1;
        b -= 1;
        if (cost.find(make_pair(a, b)) != end(cost)) {
            cost[{a, b}] = min(cost[{a, b}], c);
        } else {
            cost[{a, b}] = c;
        }
    }

    vector<vector<edge>> graph(n);
    for (const auto& e : cost) {
        graph[e.first.first].push_back({e.first.second, e.second});
    }

    vector<long long> dist = bellman_ford(s - 1, graph);
    for (const long long v : dist) {
        if (v >= INF) puts("*");
        else if (v <= -INF) puts("-");
        else printf("%lld\n", v);
    }
}
