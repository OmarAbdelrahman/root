#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> f;

void put(int version, int at, int with) {
    f[at].push_back({version, with});
}

int get(int version, int at) {
    int g = upper_bound(begin(f[at]), end(f[at]), make_pair(version, INF)) - begin(f[at]);
    return g == 0 ? 0 : f[at][g - 1].second;
}

void inc(int version, int at, int by) {
    while (at < (int) f.size()) {
        int old = get(version, at);
        put(version, at, old + by);
        at |= (at + 1);
    }
}

int sum(int version, int at) {
    int result = 0;
    while (at >= 0) {
        result += get(version, at);
        at = (at & (at + 1)) - 1;
    }
    return result;
}

struct event {
    bool type;
    int y1, y2;
};

int main() {
    int n, m, a, b;
    scanf("%d%d%d%d", &n, &m, &a, &b);

    f.resize(m + 1);
    vector<vector<event>> es(n + 1);

    for (int i = 0; i < a; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        es[x1].push_back({true, y1, y2});
        es[x2 + 1].push_back({false, y1, y2});
    }

    for (int i = 0; i <= n; i++) {
        for (const event& e : es[i]) {
            inc(i, e.y1, e.type ? +1 : -1);
            inc(i, e.y2 + 1, e.type ? -1 : +1);
        }
    }

    while (b-- > 0) {
        int x, y;
        scanf("%d%d", &x, &y);
        cout << sum(x, y) << endl;
    }
}
