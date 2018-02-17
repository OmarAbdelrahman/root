#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 251;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

int R[N], L[N];
int v[N];
vector<int> gl[N];
vector<int> gr[N];

bool enlarge(int u) {
    if (v[u]) return false;
    v[u] = true;
    for (int nv : gl[u]) {
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
    for (int i = 0; i < n; i++) {
        gl[i].clear();
        L[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        gr[i].clear();
        R[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = nxt(); j != 0; j = nxt()) {
            gl[i].push_back(j - 1);
            gr[j - 1].push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        memset(v, false, sizeof(v));
        enlarge(i);
    }
    vector<pair<int, int>> r;
    for (int i = 0; i < m; i++) {
        if (R[i] != -1) {
            r.push_back({R[i], i});
        } else if (!gr[i].empty()) {
            r.push_back({gr[i].front(), i});
        }
    }
    for (int i = 0; i < n; i++) {
        if (L[i] == -1 && !gl[i].empty()) {
            r.push_back({i, gl[i].front()});
        }
    }
    printf("%d\n", SIZE(r));
    for (auto p : r)
        printf("%d %d\n", p.first + 1, p.second + 1);
}
