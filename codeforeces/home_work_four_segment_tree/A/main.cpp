#include <bits/stdc++.h>
using namespace std;

struct segment_tree
{
    segment_tree(const vector<int>& _a): a(_a)
    {
        n = a.size();
        t = vector<int>(4 * n);
        build();
    }

    void build()
    {
        build(0, 0, n - 1);
    }

    void update(int pos, int x)
    {
        update(0, 0, n - 1, pos, x);
    }

    int query(int b, int e)
    {
        return query(0, 0, n - 1, b, e);
    }

private:
    int L(int i) const
    {
        return 2 * i + 1;
    }

    int R(int i) const
    {
        return 2 * i + 2;
    }

    void collect(int i)
    {
        t[i] = min(t[L(i)], t[R(i)]);
    }

    void build(int i, int b, int e)
    {
        if (b == e) {
            t[i] = a[b];
        } else {
            int m = (b + e) / 2;
            build(L(i), b, m);
            build(R(i), m + 1, e);
            collect(i);
        }
    }

    void update(int i, int b, int e, int pos, int x)
    {
        if (b == e) {
            t[i] = a[b] = x;
        } else {
            int m = (b + e) / 2;
            if (pos <= m) {
                update(L(i), b, m, pos, x);
            } else {
                update(R(i), m + 1, e, pos, x);
            }
            collect(i);
        }
    }

    int query(int i, int b, int e, int l, int r)
    {
        if (b == l && e == r) {
            return t[i];
        } else {
            int m = (b + e) / 2;
            int result = numeric_limits<int>::max();
            if (l <= m)
                result = min(result, query(L(i), b, m, l, min(m, r)));
            if (r > m)
                result = min(result, query(R(i), m + 1, e, max(m + 1, l), r));
            return result;
        }
    }

    vector<int> t;
    vector<int> a;
    int n;
};

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int& it : a) scanf("%d", &it);

    segment_tree tree(a);
    int q;
    scanf("%d", &q);
    while (q-- > 0) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int id, x;
            scanf("%d%d", &id, &x);
            tree.update(id - 1, x);
        } else {
            int b, e;
            scanf("%d%d", &b, &e);
            printf("%d\n", tree.query(b - 1, e - 1));
        }
    }
}
