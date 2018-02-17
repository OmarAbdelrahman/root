#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max() / 2;

struct edge {
    int f, t;
    long long c;
    int id;
    
    edge(int _f, int _t, long long _c, int _id):
        f(_f), t(_t), c(_c), id(_id) { }
    
    bool operator < (const edge& e) const {
        return c < e.c;
    }
};

struct disjoint_set {
    disjoint_set(int n): p(n), r(n), sets_count(n) {
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
        sets_count -= 1;
        return true;
    }
    
    vector<int> p, r;
    int sets_count;
};

vector<edge> mst(int n, vector<edge>& es) {
    disjoint_set s(n);
    sort(begin(es), end(es));
    vector<edge> r;
    for (const auto& e : es) {
        if (s.merge(e.f, e.t)) {
            r.push_back(e);
        }
    }
    return r;
}

vector<edge> mst_again(int n, int id, vector<edge>& es) {
    disjoint_set s(n);
    vector<edge> r;
    for (const auto& e : es) {
        if (e.id == id) continue;
        if (s.merge(e.f, e.t)) {
            r.push_back(e);
        }
    }
    if (s.sets_count != 1) return {};
    return r;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<edge> edges;
    int id = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        scanf("%d%d%lld", &a, &b, &c);
        if (a == b) continue;
        a -= 1;
        b -= 1;
        edges.push_back(edge(a, b, c, id++));
    }
    
    vector<edge> es = mst(n, edges);
    long long mn = INF;
    vector<edge> r;
    
    for (const auto& e : es) {
        vector<edge> second_mst = mst_again(n, e.id, edges);
        if (second_mst.empty()) continue;
        long long s = 0;
        for (const auto& ce : second_mst) s += ce.c;
        if (s < mn) {
            mn = s;
            r = second_mst;
        }
    }
    
    if (mn == INF) {
        puts("-1");
    } else {
        printf("%lld\n", mn);
        sort(begin(r), end(r), [](const edge& e1, const edge& e2) { return e1.id < e2.id; });
        for (const auto& e : r) {
            printf("%d %d %lld\n", e.f + 1, e.t + 1, e.c);
        }
    }
}
