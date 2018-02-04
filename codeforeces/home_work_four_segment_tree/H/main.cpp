#include <bits/stdc++.h>
using namespace std;

const long long INF = numeric_limits<long long>::max();

struct node {
    long long sum = 0;
    long long wsum = 0;
    long long delayed = 0;
    long long size = 0;

    void update(int d) {
        delayed += d;
        sum += d * size;
        wsum += size * (size + 1) / 2 * d;
    }

    static node* combine(node* a, node* b) {
        if (a == nullptr) return b;
        if (b == nullptr) return a;
        node* n = new node();
        n->sum = a->sum + b->sum;
        n->size = a->size + b->size;
        n->wsum = a->wsum + b->wsum + a->size * b->sum;
        return n;
    }
};

struct segment_tree {
    segment_tree(const vector<int>& _a): a(_a), tree(4 * a.size()) {
        build(0, 0, a.size() - 1);
    }

    void inc(int l, int r, int by) {
        inc(0, 0, a.size() - 1, l, r, by);
    }

    node* query(int l, int r) {
        return query(0, 0, a.size() - 1, l, r);
    }

private:
    void collect(int i) {
        tree[i].sum = tree[2 * i + 1].sum + tree[2 * i + 2].sum;
        tree[i].wsum = tree[2 * i + 1].wsum + tree[2 * i + 2].wsum + tree[2 * i + 1].size * tree[2 * i + 2].sum;
    }

    void push_down(int i) {
        if (tree[i].delayed != 0) {
            tree[2 * i + 1].update(tree[i].delayed);
            tree[2 * i + 2].update(tree[i].delayed);
            tree[i].delayed = 0;
        }
    }

    void build(int i, int l, int r) {
        tree[i].size = r - l + 1;
        if (l == r) {
            tree[i].sum = tree[i].wsum = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * i + 1, l, m);
            build(2 * i + 2, m + 1, r);
            collect(i);
        }
    }

    void inc(int i, int L, int R, int l, int r, int by) {
        if (L == l && R == r) {
            tree[i].update(by);
        } else {
            push_down(i);
            int m = (L + R) / 2;
            if (l <= m)
                inc(2 * i + 1, L, m, l, min(m, r), by);
            if (r > m)
                inc(2 * i + 2, m + 1, R, max(l, m + 1), r, by);
            collect(i);
        }
    }

    node* query(int i, int L, int R, int l, int r) {
        if (L == l && R == r) {
            return &tree[i];
        } else {
            push_down(i);
            node* n1 = nullptr;
            node* n2 = nullptr;
            int m = (L + R) / 2;
            if (l <= m)
                n1 = query(2 * i + 1, L, m, l, min(m, r));
            if (r > m)
                n2 = query(2 * i + 2, m + 1, R, max(l, m + 1), r);
            return node::combine(n1, n2);
        }
    }

    vector<int> a;
    vector<node> tree;
};

int main() {
    int n, q;
    scanf("%d%d", &n, &q);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    segment_tree tree(a);
    while (q-- > 0) {
        int t, b, e;
        scanf("%d%d%d", &t, &b, &e);
        if (t == 1) {
            int x;
            scanf("%d", &x);
            tree.inc(b - 1, e - 1, x);
        } else {
            printf("%lld\n", tree.query(b - 1, e - 1)->wsum);
        }
    }
}
