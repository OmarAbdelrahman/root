#include <bits/stdc++.h>
using namespace std;

int k;

struct query {
    int l, r, i;

    query(int _l, int _r, int _i): l(_l), r(_r), i(_i) { }

    bool operator < (const query& q) const {
        if (l / k == q.l / k) return r < q.r;
        return l / k < q.l / k;
    }
};

unordered_map<int, int> freq;

void add(int x, int& cnt) {
    freq[x] += 1;
    cnt += (int) (freq[x] == 1);
}

void remove(int x, int& cnt) {
    freq[x] -= 1;
    cnt -= (int) (freq[x] == 0);
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    k = (int) sqrt(n * 1.0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    vector<query> qs;
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        qs.push_back(query(l, r, i));
    }
    sort(begin(qs), end(qs));

    int r = -1;
    int l = 0;
    int cnt = 0;

    vector<int> result(q);
    for (const auto& qr : qs) {
        int L = qr.l;
        int R = qr.r;
        while (r < R) add(a[++r], cnt);
        while (r > R) remove(a[r--], cnt);
        while (l > L) add(a[--l], cnt);
        while (l < L) remove(a[l++], cnt);
        result[qr.i] = cnt;
    }

    for (int i : result) printf("%d\n", i);
}
