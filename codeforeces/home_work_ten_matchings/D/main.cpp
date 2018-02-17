#include <bits/stdc++.h>
using namespace std;

const int N = 255;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

bool visited[N];
vector<vector<int>> g;
int R[N];

bool enlarge(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int v : g[u]) {
        if (R[v] == -1) {
            R[v] = u;
            return true;
        }
    }
    for (int v : g[u]) {
        if (enlarge(R[v])) {
            R[v] = u;
            return true;
        }
    }
    return false;
}

int main() {
    int n = nxt();
    int m = nxt();
    
    g = vector<vector<int>>(n);
    for (int i = 0; i < n; i++) {
        for (int j = nxt(); j != 0; j = nxt()) {
            g[i].push_back(j - 1);
        }
    }
    
    memset(R, -1, sizeof(R));
    for (int i = 0; i < n; i++) {
        memset(visited, false, sizeof(visited));
        enlarge(i);
    }
    
    vector<pair<int, int>> r;
    for (int i = 0; i < m; i++)
        if (R[i] != -1)
            r.push_back({R[i] + 1, i + 1});
    
    printf("%d\n", int(r.size()));
    for (const auto& p : r)
        printf("%d %d\n", p.first, p.second);
}
