#include <bits/stdc++.h>
using namespace std;

const int N = 4001;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

vector<int> L, R;
vector<vector<int>> g;
bool vl[N], vr[N];

void dfs(int u) {
    if (vl[u]) return;
    vl[u] = true;
    for (int v : g[u])
        if (R[v] != -1) {
            vr[v] = true;
            dfs(R[v]);
        }
}

int main() {
    int m = nxt();
    int n = nxt();
    
    g = vector<vector<int>>(m);
    
    for (int i = 0; i < m; i++) {
        int e = nxt();
        int f = i;
        for (int j = 0; j < e; j++) {
            int t = nxt() - 1;
            g[f].push_back(t);
        }
    }
    
    L = vector<int>(m, -1);
    R = vector<int>(n, -1);
    for (int i = 0; i < m; i++) {
        int f = nxt() - 1;
        if (f == -1) continue;
        L[i] = f;
        R[f] = i;
    }
    
    for (int i = 0; i < m; i++)
        if (L[i] == -1)
            dfs(i);
    
    vector<int> l;
    for (int i = 0; i < m; i++)
        if (!vl[i])
            l.push_back(i);
    
    vector<int> r;
    for (int i = 0; i < n; i++)
        if (vr[i])
            r.push_back(i);
    
    printf("%d\n", int(l.size() + r.size()));
    printf("%d", int(l.size()));
    for (int i : l) printf(" %d", i + 1);
    printf("\n%d", int(r.size()));
    for (int i : r) printf(" %d", i + 1);
    puts("");
}
