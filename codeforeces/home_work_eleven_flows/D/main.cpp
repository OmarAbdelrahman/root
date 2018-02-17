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

int n;
int cap[N][N];
int flow[N][N];
int dist[N], p[N];
bool visited[N];

int path() {
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        p[i] = -1;
    }

    queue<int> q;
    dist[0] = 0;
    visited[0] = true;
    p[0] = 0;

    for (q.push(0); !q.empty(); q.pop()) {
        int u = q.front();
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] > dist[u] + 1 && cap[u][v] - flow[u][v] > 0) {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
                p[v] = u;
            }
        }
    }

    vector<int> path;
    if (dist[n - 1] != INF) {
        int node = n - 1;
        while (node != 0) {
            path.push_back(node);
            node = p[node];
        }
        path.push_back(0);
        reverse(begin(path), end(path));

        int res_cap = INF;
        for (int i = 0; i + 1 < SIZE(path); i++) {
            int f = path[i];
            int t = path[i + 1];
            res_cap = min(res_cap, cap[f][t] - flow[f][t]);
        }

        for (int i = 0; i + 1 < SIZE(path); i++) {
            int f = path[i];
            int t = path[i + 1];
            flow[f][t] += res_cap;
            flow[t][f] -= res_cap;
        }
        return res_cap;
    }

    return -1;
}

int main() {
    n = nxt();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cap[i][j] = nxt();

    int res = 0, f;
    while ((f = path()) != -1) res += f;

    printf("%d\n", res);
}
