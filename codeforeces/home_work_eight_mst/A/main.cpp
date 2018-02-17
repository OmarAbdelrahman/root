#include <bits/stdc++.h>
using namespace std;

struct disjoint_set {
    disjoint_set(int n): parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = {i, 0};
        }
    }
    
    pair<int, int> find(int x) {
        if (parent[x].first == x) return parent[x];
        else {
            auto p = find(parent[x].first);
            parent[x].first = p.first;
            parent[x].second += p.second;
            return parent[x];
        }
    }
    
    bool same(int a, int b) {
        return find(a).first == find(b).first;
    }
    
    bool join(int a, int b) {
        a = find(a).first;
        b = find(b).first;
        if (a == b) return false;
        parent[a].first = b;
        parent[a].second += 1;
        return true;
    }
    
    vector<pair<int, int>> parent;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    disjoint_set s(n);
    for (int i = 0; i < m; i++) {
        int cm;
        scanf("%d", &cm);
        if (cm == 1) {
            int a, b;
            scanf("%d%d", &a, &b);
            s.join(a - 1, b - 1);
        } else {
            int a;
            scanf("%d", &a);
            a -= 1;
            auto p = s.find(a);
            if (p.first == a)
                puts("0");
            else
                printf("%d\n", p.second);
        }
    }
}
