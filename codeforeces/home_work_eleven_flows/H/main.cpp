#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 100;
const int M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int c[M][M];
int f[M][M];
int d[M], rd[M];
int v[M], p[M];

int path(int src, int sink, int n) {
    for (int i = 0; i < n; i++) {
        d[i] = INF;
        rd[i] = 0;
        v[i] = false;
        p[i] = -1;
    }
    d[src] = 0;
    rd[src] = INF;
    v[src] = true;
    p[src] = src;
    queue<int> q;
    for (q.push(src); !q.empty(); q.pop()) {
        int u = q.front();
        for (int nv = 0; nv < n; nv++) {
            if (!v[nv] && d[nv] > d[u] + 1 && c[u][nv] - f[u][nv] > 0) {
                v[nv] = true;
                d[nv] = d[u] + 1;
                rd[nv] = min(rd[u], c[u][nv] - f[u][nv]);
                p[nv] = u;
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

bool print_path(int src, int sink, int n) {
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    visited[src] = true;
    parent[src] = src;
    queue<int> q;
    for (q.push(src); !q.empty(); q.pop()) {
        int u = q.front();
        for (int nv = 0; nv < n; nv++) {
            if (!visited[nv] && f[u][nv] > 0) {
                visited[nv] = true;
                parent[nv] = u;
                q.push(nv);
            }
        }
    }
    if (visited[sink]) {
        vector<int> path;
        for (int node = sink; node != src; node = parent[node]) {
            if (node < n / 2) path.push_back(node);
        }
        path.push_back(src);
        reverse(begin(path), end(path));
        for (int i = 0; i + 1 < SIZE(path); i++) {
            int a = path[i];
            int b = path[i + 1];
            f[a][b] -= 1;
            f[b][a] += 1;
        }
        for (int i : path) if (i >= n / 2) printf("%d ", i - (n / 2) + 1); else printf("%d ", i + 1);
        puts("");
    }
    return visited[sink];
}

int main() {
    int n = nxt(), m = nxt();
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j < 2 * n; j++) {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        c[i][i + n] = 1;
    }
    for (int i = 0; i < m; i++) {
        int a = nxt() - 1, b = nxt() - 1;
        c[a + n][b] = 1;
        c[b + n][a] = 1;
    }
    int src = 0 + n;
    int sink = n - 1;
    int res = 0;
    for (int cf = path(src, sink, 2 * n); cf > 0; cf = path(src, sink, 2 * n)) {
        res += cf;
    }
    printf("%d\n", res);
    while (print_path(src, sink, 2 * n));
}
