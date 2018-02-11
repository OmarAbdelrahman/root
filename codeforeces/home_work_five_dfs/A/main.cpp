#include <bits/stdc++.h>
using namespace std;

const int N = 505;

const int W = 0;
const int G = 1;
const int B = 2;

int graph[N][N];
int color[N], p[N];

void dfs(int u, int v, int n) {
    p[u] = v;
    color[u] = G;
    for (int i = 0; i < n; i++) {
        if (graph[u][i] && color[i] == W) {
            dfs(i, u, n);
        }
    }
    color[u] = B;
}

vector<int> get_path(int u, int v) {
    if (color[v] == W) return {};
    vector<int> result;
    while (v != u) {
        result.push_back(v);
        v = p[v];
    }
    result.push_back(u);
    reverse(begin(result), end(result));
    return result;
}

int main() {
    int n, u, v;
    scanf("%d%d%d", &n, &u, &v);

    u -= 1;
    v -= 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }

    for (int i = 0; i < n; i++) {
        color[i] = W;
        p[i] = -1;
    }

    dfs(u, u, n);
    vector<int> path = get_path(u, v);

    if (path.empty()) {
        puts("-1");
    } else {
        printf("%d\n", (int) path.size() - 1);
        for (size_t i = 0; i < path.size(); i++) {
            if (i > 0) printf(" ");
            printf("%d", path[i] + 1);
        }
    }
}