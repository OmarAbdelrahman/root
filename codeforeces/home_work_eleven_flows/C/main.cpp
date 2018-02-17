#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

struct edge {
    int f, t, c;

    bool operator < (const edge& e) const {
        if (f != e.f)
            return f < e.f;
        return t < e.t;
    }
};

int main() {
    for (int T = nxt(); T-- > 0; ) {
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);

        vector<vector<int>> flow(n, vector<int>(n));
        vector<vector<int>> cap(n, vector<int>(n));

        for (int i = 0; i < m; i++) {
            int a, b, c, f;
            scanf("%d%d%d%d", &a, &b, &c, &f);
            cap[a][b] += c;
            flow[a][b] += f;
            flow[b][a] -= f;
        }

        set<edge> r;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int rc = cap[i][j] - flow[i][j];
                if (rc > 0)
                    r.insert({i, j, rc});
            }
        }

        printf("%d\n", SIZE(r));
        for (const auto& e : r)
            printf("%d %d %d\n", e.f, e.t, e.c);
        puts("");
    }
}
