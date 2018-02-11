#include <bits/stdc++.h>
using namespace std;

struct state {
    int h, m;
    int cost;
};

bool visited[61][61];

void push(int a, int b, const state& s, queue<state>& q) {
    int h = s.h;
    int m = s.m;
    h += a;
    if (h >= 24) h -= 24;
    m += b;
    if (m >= 60) m -= 60;
    if (!visited[h][m]) {
        visited[h][m] = true;
        q.push({h, m, s.cost + 1});
    }
}

int main() {
    int a1, b1, a2, b2;
    scanf("%d%d%d%d", &a1, &b1, &a2, &b2);

    int sh, sm;
    scanf("%d%d", &sh, &sm);

    int th, tm;
    scanf("%d%d", &th, &tm);

    visited[sh][sm] = true;

    queue<state> q;
    for (q.push({sh, sm, 0}); !q.empty(); q.pop()) {
        state cur = q.front();
        if (cur.h == th && cur.m == tm) {
            printf("%d\n", cur.cost);
            return 0;
        }
        push(a1, b1, cur, q);
        push(a2, b2, cur, q);
    }
    puts("-1");
}
