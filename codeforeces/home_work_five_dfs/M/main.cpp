#include <bits/stdc++.h>
using namespace std;

const int W = 0;
const int G = 1;
const int B = 2;

vector<vector<int>> g;
vector<int> color;

bool top_sort(int u, vector<int>& ts) {
    color[u] = G;
    bool cycle = false;
    for (int i : g[u]) {
        if (color[i] == W) {
            cycle |= top_sort(i, ts);
        } else if (color[i] == G) {
            return true;
        }
    }
    color[u] = B;
    ts.push_back(u);
    return cycle;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g = vector<vector<int>>(n);
    color = vector<int>(n, W);

    set<pair<int, int>> s;
    while (m-- > 0) {
        int a, b;
        scanf("%d%d", &a, &b);
        s.insert({a, b});
    }

    for (const auto& p : s) g[p.first].push_back(p.second);

    vector<int> ts;
    bool cycle = false;

    for (int i = 0; i < n && !cycle; i++) {
        if (color[i] == W) {
            cycle |= top_sort(i, ts);
        }
    }

    if (!cycle) {
        puts("YES");
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) printf(" ");
            printf("%d", ts[i]);
        }
        puts("");
    } else {
        puts("NO");
    }
}
