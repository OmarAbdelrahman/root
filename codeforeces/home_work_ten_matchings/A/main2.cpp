#include <bits/stdc++.h>
using namespace std;

const int N = 4001 * 2;

inline int nxt() {
    int n;
    scanf("%d", &n);
    return n;
}

vector<int> mm;
vector<vector<int>> g;
bool visited[N];

void dfs(int u) {
    visited[u] = true;
    for (int v : g[u])
        if (!visited[v])
            dfs(v);
}

int main() {
    int m = nxt();
    int n = nxt();
    
    g = vector<vector<int>>(n + m);
    
    for (int i = 0; i < m; i++) {
        int e = nxt();
        int f = i;
        for (int j = 0; j < e; j++) {
            int t = m + nxt() - 1;
            g[f].push_back(t);
        }
    }
    
    mm = vector<int>(m, -1);
    for (int i = 0; i < m; i++) {
        int f = nxt() - 1;
        if (f == -1) continue;
        mm[i] = m + f;
        g[m + f].push_back(i);
    }
    
    for (int i = 0; i < m; i++)
        if (mm[i] == -1)
            dfs(i);
    
    vector<int> l;
    for (int i = 0; i < m; i++)
        if (!visited[i])
            l.push_back(i);
    
    vector<int> r;
    for (int i = m; i < m + n; i++)
        if (visited[i])
            r.push_back(i);
    
    printf("%d\n", int(l.size() + r.size()));
    printf("%d", int(l.size()));
    for (int i : l) printf(" %d", i + 1);
    printf("\n%d", int(r.size()));
    for (int i : r) printf(" %d", i - m + 1);
    puts("");
}
