#include <bits/stdc++.h>
using namespace std;

const char* msg[] = {
    "none",
    "any",
    "at least one"
};

struct edge {
    int f, t, c, i, ty = -1;

    bool operator < (const edge& e) const {
        return c < e.c;
    }
};

struct disjoint_set {
    disjoint_set(int n): p(n), rnd(n) {
        for (int i = 0; i < n; i++) p[i] = i;
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
        } else {
            p[b] = a;
        }
        return true;
    }

private:
    vector<int> p;
    mt19937 rnd;
};

void process_edges(vector<edge>& es) {
    const int n = es.size();
    sort(begin(es), end(es));
    for (int i = 0; i < n; ) {

    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<edge> es(m);
    for (int i = 0; i < m; i++) {
        int f, t, c;
        scanf("%d%d%d", &f, &t, &c);
        es[i] = {f - 1, t - 1, c, i};
    }
    process_edges(es);
    sort(begin(es), end(es), [](const edge& e1, const edge& e2) {
        return e1.i < e2.i;
    });
    for (const auto& e : es) {
        puts(msg[e.i]);
    }
}
