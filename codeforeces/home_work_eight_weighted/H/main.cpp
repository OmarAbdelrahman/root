#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 3;

int main() {
    int n;
    scanf("%d", &n);

    vector<vector<int>> d(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v;
            scanf("%d", &v);
            if (v) d[i][j] = v;
        }
        d[i][i] = min(d[i][i], 0);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] < INF && d[k][j] < INF)
                    d[i][j] = max(-INF, min(d[i][j], d[i][k] + d[k][j]));
            }
        }
    }

    vector<bool> cycle(n, false);
    for (int i = 0; i < n; i++) {
        if (d[i][i] < 0) cycle[i] = true;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            int v = d[i][j];
            if (v >= INF) printf("0");
            else {
                bool c = false;
                for (int k = 0; k < n && !c; k++) if (cycle[k]) {
                    if (d[i][k] < INF && d[k][j] < INF)
                        c = true;
                }
                if (c) printf("2"); else printf("1");
            }
        }
        puts("");
    }
}
