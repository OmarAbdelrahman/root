#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max() / 2;

struct edge {
    int f, t;
    long long c;
    
    bool operator < (const edge& e) const {
        if (c == e.c) {
            if (f == e.f) return t < e.t;
            return f < e.f;
        }
        return c < e.c;
    }
};

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

pair<vector<edge>, long long> mst(int n, vector<edge>& es) {
    disjoint_set s(n);
    sort(begin(es), end(es));
    
    vector<edge> r;
    long long c = 0;
    
    for (const auto& e : es) {
        if (s.merge(e.f, e.t)) {
            r.push_back(e);
            c += e.c;
        }
    }
    if (s.c != 1) return {{}, INF};
    
    return {r, c};
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<edge> es;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        es.push_back({a - 1, b - 1, c});
    }
    
    auto r = mst(n, es);
    printf("%lld\n", r.second);
    for (const auto& e : r.first) {
        printf("%d %d\n", e.f + 1, e.t + 1);
    }
}
