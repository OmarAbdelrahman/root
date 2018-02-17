#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

const int N = 10001;
const int INF = numeric_limits<int>::max() / 2;

inline int nxt() {
    int x;
    scanf("%d", &x);
    return x;
}

struct edge {
    int from, to, cap, flow;
    edge* backward;

    edge() { }

    edge(int f, int t, int c, int fl)
        : from(f), to(t), cap(c), flow(fl), backward(nullptr) { }
};

int rd[N], d[N];
int v[N], p[N];
edge* pe[N];
vector<vector<edge*>> g;

void add_edge(int from, int to, int cap, int flow = 0) {
    edge* e1 = new edge(from, to, cap, flow);
    edge* e2 = new edge(to, from, 0, flow);
    e1->backward = e2;
    e2->backward = e1;
    g[from].push_back(e1);
    g[to].push_back(e2);
}

int path() {
    int n = g.size();
    for (int i = 0; i < n; i++) {
        rd[i] = INF;
        d[i] = INF;
        v[i] = false;
        p[i] = -1;
    }
    d[0] = 0;
    v[0] = true;
    p[0] = 0;
    queue<int> q;
    for (q.push(0); !q.empty(); q.pop()) {
        int u = q.front();
        for (const auto e : g[u]) {
            int nv = e->to;
            if (!v[nv] && d[nv] > d[u] + 1 && e->cap - e->flow > 0) {
                v[nv] = true;
                d[nv] = d[u] + 1;
                p[nv] = u;
                pe[nv] = e;
                rd[nv] = min(rd[u], e->cap - e->flow);
                q.push(nv);
            }
        }
    }
    if (d[n - 1] != INF) {
        for (int node = n - 1; node != 0; node = p[node]) {
            pe[node]->flow += rd[n - 1];
            pe[node]->backward->flow -= rd[n - 1];
        }
        return rd[n - 1];
    }
    return -1;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    g = vector<vector<edge*>>(n);
    for (int i = 0; i < m; i++) {
        int f = nxt() - 1;
        int t = nxt() - 1;
        int cap = nxt();
        add_edge(f, t, cap);
    }

    int res = 0;
    for (int cf = path(); cf != -1; cf = path())
        res += cf;

    printf("%d\n", res);
}
