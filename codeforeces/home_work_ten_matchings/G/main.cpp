#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 200;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int R[N], L[N];
vector<int> g[N];
bool v[N];

bool enlarge(int u) {
    if (v[u]) return false;
    v[u] = true;
    for (int nv : g[u]) {
        if (R[nv] == -1 || enlarge(R[nv])) {
            R[nv] = u;
            L[u] = nv;
            return true;
        }
    }
    return false;
}

int main() {
    int n = nxt(), m = nxt();
    for (int i = 0; i < n + n; i++) {
        g[i].clear();
        R[i] = -1;
        L[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int a = nxt() - 1, b = nxt() - 1;
        g[a].push_back(b + n);
    }
    int matching = 0;
    for (int i = 0; i < n; i++) {
        memset(v, false, sizeof(v));
        matching += enlarge(i);
    }
    memset(v, false, sizeof(v));
    for (int i = 0; i < n; i++) {
        if (L[i] != -1) {
            L[i] -= n;
            v[L[i]] = true;
        }
    }
    printf("%d\n", n - matching);
    for (int i = 0; i < n; i++) {
        if (v[i]) continue;
        int u = i;
        while (u != -1) {
            printf("%d ", u + 1);
            u = L[u];
        }
        puts("");
    }
}
