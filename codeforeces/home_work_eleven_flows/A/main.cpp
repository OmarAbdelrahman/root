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

        vector<vector<int>> c(n, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int a, b, cap;
            scanf("%d%d%d", &a, &b, &cap);
            c[a][b] += cap;
        }

        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                f[i][j] = nxt();

        bool ok = true;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ok &= f[i][j] <= c[i][j];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ok &= f[i][j] == -f[j][i];

        for (int i = 0; i < n; i++) {
            if (i == s || i == t) continue;
            ok &= accumulate(begin(f[i]), end(f[i]), 0) == 0;
        }

        if (ok) puts("YES"); else puts("NO");
    }
}
