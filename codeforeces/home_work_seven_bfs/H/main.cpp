#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 4;

vector<int> bfs(int s, const vector<vector<int>>& g) {
    vector<int> dist(g.size(), INF);
    dist[s] = 0;

    queue<int> q;
    for (q.push(s); !q.empty(); q.pop()) {
        int u = q.front();
        for (const int v : g[u]) {
            if (dist[v] == INF) {
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int n, m, a, b, s;
        scanf("%d%d%d%d%d", &n, &m, &a, &b, &s);

        a -= 1;
        b -= 1;
        s -= 1;

        vector<vector<int>> g(n);
        vector<vector<int>> r(n);

        for (int i = 0; i < m; i++) {
            int f, t;
            scanf("%d%d", &f, &t);
            g[f - 1].push_back(t - 1);
            r[t - 1].push_back(f - 1);
        }

        vector<int> ds = bfs(s, r);
        vector<int> da = bfs(a, g);
        vector<int> db = bfs(b, g);

        int result = INF;
        for (int i = 0; i < n; i++)
            result = min(result, da[i] + db[i] + ds[i]);

        if (result >= INF)
            puts("-1");
        else
            printf("%d\n", result);
    }
}
