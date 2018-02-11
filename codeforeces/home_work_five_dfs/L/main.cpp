#include <bits/stdc++.h>
using namespace std;

const int W = 0;
const int G = 1;
const int B = 2;

vector<int> parent;
vector<vector<int>> g;
vector<int> color;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g = vector<vector<int>>(n);
    color = vector<int>(n, W);
    parent = vector<int>(n, -1);
    rg = vector<vector<int>>(n);

    for (int i = 0; i < n - 1; i++) {
        int pi;
        scanf("%d", &pi);
        g[pi - 1].push_back(i + 1);
    }

    for (int i = 0; i < n; i++) {
        if (color[i] == W) {
            dfs(i);
        }
    }
}
