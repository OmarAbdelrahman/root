#include <bits/stdc++.h>
using namespace std;

const int W = 0;
const int G = 1;
const int B = 2;

int n, m;
vector<vector<int>> g;
vector<int> parent;
vector<int> color;
vector<int> path;

int dfs(int u, int v) {
    parent[u] = v;
    color[u] = G;
    int index = -1;
    for (int i : g[u]) {
        if (color[i] == W) {
            int x = dfs(i, u);
            if (x == -1) continue;
            else if (x == -2) return x;
            else {
                path.push_back(u);
                return u == x ? -2 : x;
            }
        } else if (color[i] == G) {
            path.push_back(u);
            return i;
        }
    }
    color[u] = B;
    return index;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t-- > 0) {
        scanf("%d%d", &n, &m);

        g = vector<vector<int>>(n);
        parent = vector<int>(n, -1);
        color = vector<int>(n);

        while (m-- > 0) {
            int a, b;
            scanf("%d%d", &a, &b);
            g[a - 1].push_back(b - 1);
        }

        bool cycle = false;
        for (int i = 0; i < n; i++) {
            if (color[i] == W) {
                path.clear();
                int index = dfs(i, -1);
                cycle = index == -2;
                if (!cycle) continue;
                puts("NO");
                printf("%d\n", int(path.size()));
                reverse(begin(path), end(path));
                for (int v : path) printf("%d ", v + 1);
                printf("%d\n", path.front() + 1);
                break;
            }
        }

        if (!cycle) puts("YES");
    }
}
