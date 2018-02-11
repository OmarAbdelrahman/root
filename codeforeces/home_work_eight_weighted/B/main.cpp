#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 3;

struct state {
    int x, c;

    bool operator < (const state& s) const {
        return c > s.c;
    }
};

int solve(int s, int t, const vector<vector<state>>& g) {
    const int n = g.size();

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<state> q;


    dist[s] = 0;
    for (q.push({s, 0}); !q.empty(); ) {
        int index = q.top().x;
        int cost = q.top().c;
        q.pop();

        if (index == t) return cost;

        if (visited[index]) continue;
        visited[index] = true;

        for (const auto& cs : g[index]) {
            int nc = dist[index] + cs.c;
            if (nc < dist[cs.x]) {
                dist[cs.x] = nc;
                q.push({cs.x, nc});
            }
        }
    }

    return -1;
}

int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);

    s -= 1;
    t -= 1;

    vector<vector<state>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a -= 1;
        b -= 1;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    printf("%d\n", solve(s, t, g));
}
