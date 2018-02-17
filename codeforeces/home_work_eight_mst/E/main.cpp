#include <bits/stdc++.h>
using namespace std;


// WA

struct disjoint_set {
    disjoint_set(int n): p(n), c(n) {
        for (int i = 0; i < n; i++) {
            p[i] = {i, 0};
        }
    }
    
    pair<int, int> find(int x) {
        if (p[x].first == x) return p[x];
        else {
            auto pp = find(p[x].first);
            p[x].first = pp.first;
            p[x].second += pp.second;
            return p[x];
        }
    }
    
    bool merge(int a, int b) {
        a = find(a).first;
        b = find(b).first;
        if (a == b) return false;
        p[a].first = b;
        p[a].second += 1;
        c -= 1;
        return true;
    }
    
    vector<pair<int, int>> p;
    int c;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    vector<pair<int, int>> es;
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a -= 1;
        b -= 1;
        es.push_back({a, b});
    }
    
    disjoint_set s(n);
    bool found = false;
    
    for (int i = 0; i < m && !found; i++) {
        int a, b;
        tie(a, b) = es[i];
        if (s.merge(a, b)) continue;
        auto d1 = s.find(a);
        auto d2 = s.find(b);
        if ((d1.second + d2.second + 1) % 2 != 0) {
            printf("%d\n", i + 1);
            found = true;
            break;
        }
    }
    
    if (!found) puts("-1");
}
