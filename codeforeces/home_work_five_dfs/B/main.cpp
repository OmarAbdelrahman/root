#include <bits/stdc++.h>
using namespace std;

const int W = 0;
const int G = 1;
const int B = 2;

vector<vector<int>> g;
vector<int> color;

void dfs(int u) {
    color[u] = G;
    for (int i : g[u]) if (color[i] == W) dfs(i);
    color[u] = B;
}

int main() {
    int n;
    scanf("%d", &n);

    g.resize(n);

    int m = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int v;
            scanf("%d", &v);
            if (v == 1) {
                g[i].push_back(j);
                m += 1;
            }
        }

    bool connected = true;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            color = vector<int>(n, W);
            dfs(i);
            connected &= color[j] != W;
        }

    if (connected && m / 2 == n - 1) puts("YES"); else puts("NO");
}
