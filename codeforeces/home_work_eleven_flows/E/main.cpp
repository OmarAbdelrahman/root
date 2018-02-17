#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 100;
const int INF = numeric_limits<int>::max() / 2;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int n, m;
int d[N], p[N], v[N];
int c[N][N];
int f[N][N];
pair<int, int> es[400];

int path() {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        p[i] = -1;
        v[i] = false;
    }

    d[0] = 0;
    p[0] = 0;
    v[0] = true;

    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
        int u = q.front();
        for (int nv = 0; nv < n; nv++) {
            if (!v[nv] && d[nv] > d[u] + 1 && c[u][nv] - f[u][nv] > 0) {
                d[nv] = d[u] + 1;
                v[nv] = true;
                p[nv] = u;
                q.push(nv);
            }
        }
    }

    if (d[n - 1] != INF) {
        int node = n - 1;
        vector<int> path;
        while (node != 0) {
            path.push_back(node);
            node = p[node];
        }
        path.push_back(0);
        reverse(begin(path), end(path));

        int res_min = INF;
        for (int i = 0; i + 1 < SIZE(path); i++) {
            int a = path[i];
            int b = path[i + 1];
            res_min = min(res_min, c[a][b] - f[a][b]);
        }

        for (int i = 0; i + 1 < SIZE(path); i++) {
            int a = path[i];
            int b = path[i + 1];
            f[a][b] += res_min;
            f[b][a] -= res_min;
        }

        return res_min;
    }

    return -1;
}

int main() {
    n = nxt(), m = nxt();
    for (int i = 0; i < m; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        int cap = nxt();
        c[a][b] = cap;
        c[b][a] = cap;
        es[i] = {a, b};
    }

    int mnc = 0;
    for (int cf = path(); cf != -1; cf = path())
        mnc += cf;

    vector<int> ei;
    for (int i = 0; i < m; i++) {
        int a, b;
        tie(a, b) = es[i];
        if ((v[a] && !v[b]) || (!v[a] && v[b]))
            ei.push_back(i + 1);
    }

    printf("%d %d\n", SIZE(ei), mnc);
    for (int i = 0; i < SIZE(ei); i++) {
        if (i > 0) printf(" ");
        printf("%d", ei[i]);
    }
    puts("");
}
