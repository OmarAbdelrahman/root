#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

template<typename F>
void dprint(const vector<int>& v, F f) {
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0) cerr << ' ';
        cerr << f(v[i]);
    }
    cerr << endl;
}

void process(vector<int> bfs, vector<int> dfs) {
    dprint(bfs, [](int i) { return i + 1; });
    dprint(dfs, [](int i) { return i + 1; });
    
    if (bfs.size() <= 3) {
        for (size_t i = 1; i < bfs.size(); i++) {
            g[bfs[0]].push_back(bfs[i]);
        }
        return;
    }

    int root = bfs.front();
    int next_level_child = dfs[2];

    int pos_in_bfs = find(begin(bfs), end(bfs), next_level_child) - begin(bfs);
    int pos_in_dfs = find(begin(dfs), end(dfs), bfs[pos_in_bfs - 1]) - begin(dfs);

    for (int i = 1; i < pos_in_bfs; i++) {
        g[root].push_back(bfs[i]);
    }

    vector<int> dfs1, bfs1;
    for (int i = 1; i < pos_in_dfs; i++) {
        dfs1.push_back(dfs[i]);
    }
    for (int i = 1; i < int(bfs.size()); i++) {
        if (find(begin(dfs1), end(dfs1), bfs[i]) != end(dfs1)) {
            bfs1.push_back(bfs[i]);
        }
    }
    process(bfs1, dfs1);

    vector<int> dfs2, bfs2;
    for (int i = pos_in_dfs; i < int(dfs.size()); i++) {
        dfs2.push_back(dfs[i]);
    }
    for (int i = 1; i < int(bfs.size()); i++) {
        if (find(begin(dfs2), end(dfs2), bfs[i]) != end(dfs2)) {
            bfs2.push_back(bfs[i]);
        }
    }
    process(bfs2, dfs2);
}

vector<int> read(int n) {
    vector<int> v(n);
    for (int& i : v) {
        scanf("%d", &i);
        i -= 1;
    }
    return v;
}

int main() {
    int n;
    scanf("%d", &n);

    vector<int> bfs = read(n);
    vector<int> dfs = read(n);

    if (n == 1) return 0;

    g = vector<vector<int>>(n);
    process(bfs, dfs);

    for (int i = 0; i < n; i++) {
        for (int v : g[i]) {
            printf("%d %d\n", i + 1, v + 1);
        }
    }
}
