#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, color;
};

struct state {
    int v;
    int cost;
    int color;
};

int bfs(int src, int trg, const vector<vector<edge>>& g) {
    vector<vector<bool>> visited(g.size(), vector<bool>(4, false));

    queue<state> q;
    for (const edge& e : g[src]) {
        q.push({e.to, 1, e.color});
        visited[e.to][e.color] = true;
    }

    while (!q.empty()) {
        state s = q.front();
        q.pop();

        if (s.v == trg) return s.cost;

        for (const edge& e : g[s.v]) {
            if (e.color != s.color && !visited[e.to][e.color]) {
                visited[e.to][e.color] = true;
                q.push({e.to, s.cost + 1, e.color});
            }
        }
    }

    return -1;
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

    printf("%d\n", bfs(0, n - 1, g));
}
