#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> g;

template<typename T, typename F>
void dprint(const vector<T>& v, F f) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) cerr << ' ';
        cerr << f(v[i]);
    }
    cerr << endl;
}

void process(const vector<int>& bfs_pos, const vector<int>& bfs, const vector<int>& dfs) {
    if (bfs.size() <= 2) {
        for (size_t i = 1; i < bfs.size(); i++)
            g.push_back({bfs.front(), bfs[i]});
        return;
    }
    
    vector<int> dfs_pos(n);
    for (size_t i = 0; i < dfs.size(); i++) {
        dfs_pos[dfs[i]] = i;
    }
    
    int root = bfs.front();
    vector<int> root_children;
    
    for (size_t i = 1; i < bfs.size(); i++) {
        int prev_child = bfs[i - 1];
        int child = bfs[i];
        if (i > 1 && bfs_pos[child] - 1 != bfs_pos[prev_child])
            break;
        if (i > 1 && child < prev_child)
            break;
        if (dfs_pos[child] <= dfs_pos[prev_child])
            break;
        root_children.push_back(child);
        g.push_back({root, child});
    }
    
    int sz = root_children.size();
    for (int i = 0; i < sz; i++) {
        vector<int> b, d;
        int child_i = dfs_pos[root_children[i]];
        int child_j = i + 1 < sz ? dfs_pos[root_children[i + 1]] : int(dfs.size());
        for (int j = child_i; j < child_j; j++) {
            d.push_back(dfs[j]);
        }
        for (auto node : bfs) {
            if (find(begin(d), end(d), node) != end(d)) {
                b.push_back(node);
            }
        }
        process(bfs_pos, b, d);
    }
}

vector<int> read() {
    vector<int> v(n);
    for (int& i : v) {
        scanf("%d", &i);
        i -= 1;
    }
    return v;
}

int main() {
    scanf("%d", &n);

    vector<int> bfs = read();
    vector<int> dfs = read();
    
    if (n == 1) return 0;
    
    vector<int> bfs_pos(n);
    for (int i = 0; i < n; i++) {
        bfs_pos[bfs[i]] = i;
    }
    
    g.clear();
    process(bfs_pos, bfs, dfs);

    for (const auto& p : g) {
        printf("%d %d\n", p.first + 1, p.second + 1);
    }
}
