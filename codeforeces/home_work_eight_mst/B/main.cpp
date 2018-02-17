#include <bits/stdc++.h>
using namespace std;

const int L = 1;
const int R = 2;

struct disjoint_set {
    disjoint_set(int n): p(n), rnd(n), children(n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    
    bool join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (rnd() % 2 == 0) {
            p[a] = b;
            children[b].push_back(a);
        } else {
            p[b] = a;
            children[a].push_back(b);
        }
        return true;
    }
    
    set<int> components(int u) {
        set<int> visited;
        dfs(find(u), visited);
        return visited;
    }
    
private:
    void dfs(int u, set<int>& visited) {
        visited.insert(u);
        for (int v : children[u])
            if (visited.find(v) == end(visited))
                dfs(v, visited);
    }
    
    vector<int> p;
    mt19937 rnd;
    vector<vector<int>> children;
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    
    multiset<pair<int, int>> edges;
    vector<int> l(n), r(n);
    
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a != -1) {
            a -= 1;
            edges.insert({i, a});
        }
        if (b != -1) {
            b -= 1;
            edges.insert({i, b});
        }
        l[i] = a;
        r[i] = b;
    }
    
    vector<pair<int, int>> releases;
    for (int i = 0; i < m; i++) {
        int idx, h;
        scanf("%d%d", &idx, &h);
        idx -= 1;
        
        int x = idx, y = -1;
        if (h == L)
            y = l[idx];
        else
            y = r[idx];
        
        auto pos = edges.find({x, y});
        if (pos != end(edges)) edges.erase(pos);
        
        releases.push_back({x, y});
    }
    
    disjoint_set s(n);
    for (const auto& e : edges) s.join(e.first, e.second);
    
    vector<int> res(n, -1);
    for (int i = m - 1; i >= 0; --i) {
        int x, y;
        tie(x, y) = releases[i];
        x = s.find(x);
        y = s.find(y);
        if (x != y) {
            if (x == s.find(0)) {
                auto cs = s.components(y);
                for (auto u : cs) res[u] = i;
            }
            if (y == s.find(0)) {
                auto cs = s.components(x);
                for (auto u : cs) res[u] = i;
            }
            s.join(x, y);
        }
    }
    
    for (int i : res) printf("%d\n", i);
}
