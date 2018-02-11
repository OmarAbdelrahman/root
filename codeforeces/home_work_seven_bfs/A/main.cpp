#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<int>> g;
vector<int> parent, dist;

int main() {
    int n, s, t;
    scanf("%d%d%d", &n, &s, &t);

    g = vector<vector<int>>(n);
    parent = vector<int>(n, -1);
    dist = vector<int>(n, INF);

    s -= 1;
    t -= 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v;
            scanf("%d", &v);
            if (v) g[i].push_back(j);
        }
    }

    dist[s] = 0;
    parent[s] = s;
    queue<int> q;
    for (q.push(s); !q.empty(); q.pop()) {
        int u = q.front();
        for (const int v : g[u]) {
            if (parent[v] == -1) {
                dist[v] = 1 + dist[u];
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (dist[t] == INF) {
        puts("-1");
    } else {
        printf("%d\n", dist[t]);
        vector<int> result;
        while (t != s) {
            result.push_back(t);
            t = parent[t];
        }
        result.push_back(s);
        for (int i = result.size() - 1; i >= 0; i--) {
            printf("%d ", result[i] + 1);
        }
        puts("");
    }
}
