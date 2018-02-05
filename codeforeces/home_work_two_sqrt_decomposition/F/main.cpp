#include <bits/stdc++.h>
using namespace std;

struct query {
    int l, r, k, i;

    query() { }

    query(int _l, int _r, int _k, int _i): l(_l), r(_r), k(_k), i(_i) { }

    bool operator < (const query& q) const {
        if (l / k == q.l / k) return r < q.r;
        return l / k < q.l / k;
    }
};

unordered_map<int, int> freq;
set<pair<int, int>> s;

void add(int x) {
    auto pos = s.find({-freq[x], x});
    if (pos != end(s)) s.erase(pos);
    freq[x] += 1;
    s.insert({-freq[x], x});
}

void remove(int x) {
    auto pos = s.find({-freq[x], x});
    if (pos != end(s)) s.erase(pos);
    freq[x] -= 1;
    s.insert({-freq[x], x});
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    int k = (int) sqrt(n * 1.0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<query> qs(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        qs[i] = query(l, r, k, i);
    }
    sort(begin(qs), end(qs));

    int r = -1;
    int l = 0;

    vector<int> result(q);
    for (const auto& qr : qs) {
        int L = qr.l;
        int R = qr.r;
        while (r < R) add(a[++r]);
        while (r > R) remove(a[r--]);
        while (l > L) add(a[--l]);
        while (l < L) remove(a[l++]);
        result[qr.i] = s.begin()->second;
    }

    for (int i : result) printf("%d\n", i);
}
