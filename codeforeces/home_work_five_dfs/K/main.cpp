#include <bits/stdc++.h>
using namespace std;

const int W = 0;
const int G = 1;
const int B = 2;

int T;

vector<int> parent;
vector<vector<int>> g;
vector<int> color, tin, tout;

void dfs(int u, int v) {
    parent[u] = v;
    color[u] = G;
    tin[u] = T++;
    for (int i : g[u]) if (color[i] == W) dfs(i, u);
    color[u] = B;
    tout[u] = T++;
}

int main() {
    int n;
    scanf("%d", &n);

    T = 0;
    parent.resize(n, -1);
    g.resize(n);
    color.resize(n, W);
    tin.resize(n);
    tout.resize(n);

    for (int i = 0; i < n - 1; i++) {
        int a;
        scanf("%d", &a);
        g[a - 1].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == W) {
            dfs(i, i);
        }
    }

    int m;
    scanf("%d", &m);

    while (m-- > 0) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        int l1 = tin[a];
        int r1 = tout[a];
        int l2 = tin[b];
        int r2 = tout[b];
        if (l1 <= l2 && r1 >= r2) {
            puts("1");
        } else if (l2 <= l1 && r2 >= r1) {
            puts("2");
        } else {
            puts("3");
        }
    }
}
