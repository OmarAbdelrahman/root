#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, c;

    bool operator < (const state& s) const {
        return c > s.c;
    }
};

int solve(int s, int t, const vector<int>& w, const vector<vector<state>>& g) {
    int n = w.size();

    vector<int> dist(n, numeric_limits<int>::max() / 3);
    vector<bool> visisted(n, false);
    priority_queue<state> q;

    dist[s] = w[s];
    for (q.push({s, w[s]}); !q.empty(); ) {
        state cur = q.top();
        int index = cur.x;
        int cost = cur.c;
        q.pop();

        if (index == t) {
            return cost;
        }
        if (visisted[index]) continue;
        visisted[index] = true;

        for (const auto& next : g[index]) {
            int nc = dist[index] + w[next.x];
            if (dist[next.x] > nc) {
                dist[next.x] = nc;
                q.push({next.x, nc});
            }
        }
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);

        vector<int> w(n);
        for (int& i : w) scanf("%d", &i);

        vector<vector<state>> g(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            a -= 1;
            b -= 1;
            g[a].push_back({b, w[b]});
            g[b].push_back({a, w[a]});
        }

        printf("%d\n", solve(s - 1, t - 1, w, g));
    }
}
