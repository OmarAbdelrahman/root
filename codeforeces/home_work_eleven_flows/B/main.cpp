#include <bits/stdc++.h>
using namespace std;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    for (int T = nxt(); T-- > 0; ) {
        int n, m, s, t;
        scanf("%d%d%d%d", &n, &m, &s, &t);

        vector<vector<int>> f(n, vector<int>(n, 0));
        vector<vector<int>> c(n, vector<int>(n, 0));

        bool ok = true;
        for (int i = 0; i < m; i++) {
            int a, b, cap, flow;
            scanf("%d%d%d%d", &a, &b, &cap, &flow);
            ok &= flow <= cap;
            c[a][b] += cap;
            f[a][b] += flow;
            f[b][a] -= flow;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ok &= f[i][j] <= c[i][j];
            }
            int sum = accumulate(begin(f[i]), end(f[i]), 0);
            if (i == s) ok &= sum >= 0;
            else if (i == t) ok &= sum <= 0;
            else ok &= sum == 0;
        }

        if (ok) {
            puts("YES");
            int fs = 0;
            for (int i = 0; i < n; i++) fs += f[s][i];
            printf("%d\n", fs);
        } else {
            puts("NO");
        }
        puts("");
    }
}
