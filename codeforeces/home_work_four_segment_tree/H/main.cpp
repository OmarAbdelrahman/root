#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

struct node {
    int b, e;
    long long sum = 0;
    long long weighted_sum = 0;
    long long delayed = INF;
    long long size;

    void update(int d) {
        delayed = delayed == INF ? d : delayed + d;
        sum += 1LL * size * d;
        weighted_sum += (size * (size + 1) / 2) * d;
    }

    friend ostream& operator << (ostream& ostr, const node& mn) {
        ostr << "[" << mn.b << ", " << mn.e << "] = "
             << "(sum=" << mn.sum
             << ", weighted_sum=" << mn.weighted_sum
             << ", delayed=" << mn.delayed
             << ", size=" << mn.size << ")";
        return ostr;
    }
};

struct segment_tree {
    segment_tree(const vector<int>& _a): a(_a), t(4 * a.size()) {
        build(0, 0, a.size() - 1);
    }

    void inc(int b, int e, int d) {
        inc(0, 0, a.size() - 1, b, e, d);
    }

    long long query(int b, int e) {
        return query(0, 0, a.size() - 1, b, e);
    }

    friend ostream& operator << (ostream& ostr, const segment_tree& tree) {
        for (const auto& mn : tree.t) ostr << mn << endl;
        return ostr;
    }

private:
    void collect(int i) {
        t[i].sum = t[2 * i + 1].sum + t[2 * i + 2].sum;
        t[i].weighted_sum = t[2 * i + 1].weighted_sum + t[2 * i + 2].weighted_sum + t[2 * i + 1].size * t[2 * i + 2].sum;
    }

    void push_down(int i) {
        if (t[i].delayed != INF) {
            t[2 * i + 1].update(t[i].delayed);
            t[2 * i + 2].update(t[i].delayed);
            t[i].delayed = INF;
        }
    }

    void build(int i, int L, int R) {
        t[i].b = L;
        t[i].e = R;
        t[i].size = R - L + 1;
        if (L == R) {
            t[i].sum = t[i].weighted_sum = a[L];
        } else {
            int M = (L + R) / 2;
            build(2 * i + 1, L, M);
            build(2 * i + 2, M + 1, R);
            collect(i);
        }
    }

    void inc(int i, int L, int R, int l, int r, int d) {
        if (L == l && R == r) {
            t[i].update(d);
        } else {
            push_down(i);
            int M = (L + R) / 2;
            if (l <= M)
                inc(2 * i + 1, L, M, l, min(M, r), d);
            if (r > M)
                inc(2 * i + 2, M + 1, R, max(l, M + 1), r, d);
            collect(i);
        }
    }

    long long query(int i, int L, int R, int l, int r) {
        if (L == l && R == r) {
            return t[i].weighted_sum;
        } else {
            push_down(i);
            long long result = 0;
            int M = (L + R) / 2;
            if (l <= M)
                result += query(2 * i + 1, L, M, l, min(M, r));
            if (r > M)
                result += query(2 * i + 2, M + 1, R, max(l, M + 1), r);
            return result;
        }
    }

    vector<int> a;
    vector<node> t;
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    segment_tree tree(a);
    cerr << tree << endl;
    cerr << "=============" << endl;
    while (q-- > 0) {
        int t, b, e;
        scanf("%d%d%d", &t, &b, &e);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            tree.inc(b - 1, e - 1, x);
            cerr << tree << endl;
            cerr << "=============" << endl;
        } else {
            printf("%lld\n", tree.query(b - 1, e - 1));
        }
    }
}
