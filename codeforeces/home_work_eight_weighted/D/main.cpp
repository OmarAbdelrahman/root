#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 3;

struct state {
    int x, c;

    bool operator < (const state& s) const {
        return c > s.c;
    }
};

int solve(int s, int t, int A, int B, const vector<int>& h) {
    const int n = h.size();

    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    priority_queue<state> q;

    dist[s] = 0;
    for (q.push({s, 0}); !q.empty();) {
        state cur = q.top();
        int index = cur.x;
        int cost = cur.c;
        q.pop();

        if (index == t) {
            return cost;
        }

        if (visited[index]) continue;
        visited[index] = true;

        for (int i = 0; i < n; i++) {
            if (i == index) continue;

            int vdiff = abs(h[i] - h[index]);
            int hdiff = abs(i - index);

            if (vdiff <= A && hdiff <= B) {
                int jump_cost = vdiff + hdiff;
                if (dist[i] > dist[index] + jump_cost) {
                    dist[i] = dist[index] + jump_cost;
                    q.push({i, dist[i]});
                }
            }

            int move_cost = h[index] + hdiff + h[i];
            if (dist[i] > dist[index] + move_cost) {
                dist[i] = dist[index] + move_cost;
                q.push({i, dist[i]});
            }
        }
    }

    return -1;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int n, A, B, s, t;
        scanf("%d%d%d%d%d", &n, &A, &B, &s, &t);

        vector<int> h(n);
        for (int& i : h) scanf("%d", &i);

        printf("%d\n", solve(s - 1, t - 1, A, B, h));
    }
}
