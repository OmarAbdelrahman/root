#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 202;
const int INF = numeric_limits<int>::max() / 2;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int n, m, k;
int c[N][N];
int f[N][N];
int p[N], d[N], v[N];

bool path() {
    int src = 0;
    int sink = n + m + 1;
    for (int i = 0; i < n + m + 2; i++) {
        d[i] = INF;
        v[i] = false;
        p[i] = -1;
    }

    d[src] = 0;
    v[src] = true;
    p[src] = src;

    queue<int> q;
    for (q.push(src); !q.empty(); q.pop()) {
        int u = q.front();
        for (int nv = 0; nv < n + m + 2; nv++) {
            if (!v[nv] && d[nv] > d[u] + 1 && c[u][nv] - f[u][nv] > 0) {
                d[nv] = d[u] + 1;
                v[nv] = true;
                p[nv] = u;
                q.push(nv);
            }
        }
    }

    if (d[sink] != INF) {
        int node = sink;
        vector<int> path;
        while (node != src) {
            path.push_back(node);
            node = p[node];
        }
        path.push_back(src);
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
        return true;
    }
    return false;
}

int main() {
    n = nxt(), m = nxt(), k = nxt();
    for (int i = 1; i <= n; i++) {
        c[0][i] = 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int t = nxt(); t-- > 0; ) {
            c[i][nxt() + 1 + n] = 1;
        }
    }
    for (int i = 1; i <= m; i++) {
        c[i + n][m + n + 1] = k;
    }

    while (path());

    bool ok = true;
    vector<vector<int>> r(n);
    for (int i = 1; i <= n && ok; i++) {
        for (int j = 1; j <= m; j++) {
            int student = i;
            int course = j + n;
            if (f[student][course] > 0)
                r[student - 1].push_back(j - 1);
        }
        ok &= r[i - 1].size() == 2;
    }

    if (ok) {
        puts("YES");
        for (auto& vec : r) {
            for (int i : vec) printf("%d ", i);
            puts("");
        }
    } else {
        puts("NO");
    }
}
