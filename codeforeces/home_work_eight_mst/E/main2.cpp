#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;

struct disjoint_set {
    disjoint_set(int n): p(n), r(n), c(n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
            r[i] = 0;
        }
    }
    
    int find(int x) {
        return p[x] == x ? x : (p[x] = find(p[x]));
    }
    
    bool merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] > r[b])
            swap(a, b);
        p[a] = b;
        r[b] += int(r[a] == r[b]);
        c -= 1;
        return true;
    }
    
    vector<int> p, r;
    int c;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<pair<int, int>> es;
    vector<vector<int>> g(n);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        es.push_back({a, b});
    }
    
    disjoint_set s(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        tie(a, b) = es[i];
        if (s.merge(a, b)) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    
    vector<int> dist(n, INF);
    queue<int> q;
    
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            dist[i] = 0;
            for (q.push(i); !q.empty(); q.pop()) {
                int u = q.front();
                for (const int v : g[u]) {
                    if (dist[v] > dist[u] + 1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    
    bool found = false;
    for (int i = 0; i < m && !found; i++) {
        int a, b;
        tie(a, b) = es[i];
        if (!s.merge(a, b) && (dist[a] + dist[b] + 1) % 2 != 0) {
            printf("%d\n", i + 1);
            found = true;
        }
    }
    
    if (!found) puts("-1");
}
