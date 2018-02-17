#include <bits/stdc++.h>
using namespace std;

const int N = 4001;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

bool visited[N];
vector<int> L, R;
vector<vector<int>> g;

bool enlarge(int u) {
    if (visited[u]) return false;
    visited[u] = true;
    for (int v : g[u]) {
        if (L[v] == -1) {
            L[v] = u;
            R[u] = v;
            return true;
        }
    }
    for (int v : g[u]) {
        if (enlarge(L[v])) {
            L[v] = u;
            R[u] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int m = nxt();
    int n = nxt();
    
    g = vector<vector<int>>(n);
    for (int i = 0; i < m; i++) {
        int es = nxt();
        int t = i;
        for (int j = 0; j < es; j++) {
            g[nxt() - 1].push_back(t);
        }
    }
    
    L = vector<int>(m, -1);
    R = vector<int>(n, -1);
    for (int i = 0; i < m; i++) {
        int v = nxt() - 1;
        if (v == -1) continue;
        L[i] = v;
        R[v] = i;
    }
    
    bool maximized = false;
    for (int i = 0; i < n && !maximized; i++)
        if (R[i] == -1)
            maximized |= enlarge(i);
    
    if (maximized) {
        puts("NO");
        vector<pair<int, int>> r;
        for (int i = 0; i < n; i++)
            if (R[i] != -1) {
                r.push_back({R[i] + 1, i + 1});
            }
        printf("%d\n", int(r.size()));
        for (const auto& p : r) printf("%d %d\n", p.first, p.second);
    } else {
        puts("YES");
    }
}
