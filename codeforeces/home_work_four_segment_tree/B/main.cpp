#include <bits/stdc++.h>
using namespace std;

struct node
{
    int b, e, m;
    long long v;
};

struct segment_tree
{
    segment_tree(const vector<int>& _a): a(_a)
    {
        t = vector<node>(4 * a.size());
        build();
    }

    void build()
    {
        build(0, 0, a.size() - 1);
    }

    void update(int pos, int x)
    {
        update(0, pos, x);
    }

    long long query(int b, int e)
    {
        return query(0, b, e);
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
        t[i].v = t[L(i)].v + t[R(i)].v;
    }

    void build(int i, int b, int e)
    {
        node& n = t[i];
        n.b = b;
        n.e = e;
        n.m = (b + e) / 2;
        if (n.b == n.e) {
            n.v = a[n.b];
        } else {
            build(L(i), n.b, n.m);
            build(R(i), n.m + 1, n.e);
            collect(i);
        }
    }

    void update(int i, int pos, int x)
    {
        node& n = t[i];
        if (n.b == n.e) {
            n.v = a[n.b] = x;
        } else {
            if (pos <= n.m)
                update(L(i), pos, x);
            else
                update(R(i), pos, x);
            collect(i);
        }
    }

    long long query(int i, int b, int e)
    {
        node& n = t[i];
        if (n.b == b && n.e == e) {
            return n.v;
        } else {
            int result = 0;
            if (b <= n.m)
                result += query(L(i), b, min(n.m, e));
            if (e > n.m)
                result += query(R(i), max(b, n.m + 1), e);
            return result;
        }
    }

    vector<node> t;
    vector<int> a;
};

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);

    vector<int> a(n);
    for (int& it : a) scanf("%d", &it);

    segment_tree tree(a);
    while (q-- > 0) {
        int t;
        scanf("%d", &t);
        if (t == 0) {
            int b, e;
            scanf("%d%d", &b, &e);
            printf("%lld\n", tree.query(b - 1, e - 1));
        } else {
            int id, val;
            scanf("%d%d", &id, &val);
            tree.update(id - 1, val);
        }
    }
}
