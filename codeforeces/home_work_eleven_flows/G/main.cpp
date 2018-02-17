#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 50;
const int M = N * 2 + 2;
const int INF = numeric_limits<int>::max() / 2;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int c[M][M];
int f[M][M];
int v[M], p[M];
int rd[M], d[M];
int in[N], out[N];

void add_edge(int from, int to, int cap) {
    c[from][to] = cap;
}

void inc_cap(int from, int to, int by) {
    c[from][to] += by;
}

int path(int src, int sink, int n) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        rd[i] = 0;
        p[i] = -1;
        v[i] = false;
    }
    d[src] = 0;
    v[src] = true;
    p[src] = src;
    rd[src] = INF;
    queue<int> q;
    for (q.push(src); !q.empty(); q.pop()) {
        int u = q.front();
        for (int nv = 0; nv < n; nv++) {
            if (!v[nv] && d[nv] > d[u] + 1 && c[u][nv] - f[u][nv] > 0) {
                d[nv] = d[u] + 1;
                v[nv] = true;
                p[nv] = u;
                rd[nv] = min(rd[u], c[u][nv] - f[u][nv]);
                q.push(nv);
            }
        }
    }
    if (d[sink] != INF) {
        vector<int> path;
        for (int node = sink; node != src; node = p[node]) {
            path.push_back(node);
        }
        path.push_back(src);
        reverse(begin(path), end(path));
        for (int i = 0; i + 1 < SIZE(path); i++) {
            int a = path[i];
            int b = path[i + 1];
            f[a][b] += rd[sink];
            f[b][a] -= rd[sink];
        }
    }
    return rd[sink];
}

int main() {
    int n = nxt();
    for (int i = 0; i < n; i++) {
        out[i] = nxt();
        in[i] = nxt();
    }
    for (int i = 0; i < n; i++) {
        add_edge(0, i + 1, out[i]);
        add_edge(i + 1 + n, n + 1 + n, in[i]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            add_edge(i + 1, j + 1 + n, 1);
        }
    }
    int m = nxt();
    vector<pair<int, int>> r;
    for (int i = 0; i < m; i++) {
        int a = nxt() - 1;
        int b = nxt() - 1;
        inc_cap(0, a + 1, -1);
        inc_cap(b + 1 + n, n + n + 1, -1);
        inc_cap(a + 1, b + 1 + n, -1);
        r.push_back({a, b});
    }
    while (path(0, n + n + 1, n + n + 2) > 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (f[i + 1][j + 1 + n] > 0)
                r.push_back({i, j});
        }
    }
    printf("%d\n", SIZE(r));
    for (auto e : r)
        printf("%d %d\n", e.first + 1, e.second + 1);
}
