#include <bits/stdc++.h>
using namespace std;

const int W = 0;
const int G = 1;
const int B = 2;

vector<int> id;
vector<vector<int>> g;
vector<int> color;
vector<int> components;

int dfs(int u, int component_id) {
    color[u] = G;
    int result = 1;
    for (int i : g[u]) if (color[i] == W) {
        result += dfs(i, component_id);
    }
    color[u] = B;
    id[u] = component_id;
    return result;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g.resize(n);
    color.resize(n);
    id.resize(n);
    components.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int ncomponents = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == W) {
            components[ncomponents] = dfs(i, ncomponents);
            ncomponents += 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", components[id[i]]);
    }
    puts("");
}
