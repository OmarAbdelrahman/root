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
    }

    for (int i = 0; i < n; i++) d[i][i] = 0;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = max(-INF, min(d[i][j], d[i][k] + d[k][j]));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%d", d[i][j] >= INF ? 0 : d[i][j]);
        }
        puts("");
    }
}
