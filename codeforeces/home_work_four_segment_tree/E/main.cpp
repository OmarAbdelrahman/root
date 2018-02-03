#include <bits/stdc++.h>
using namespace std;

struct node
{
    int b, e, m;
    int v = numeric_limits<int>::max();
    int x = -1;

    node(): v(numeric_limits<int>::max()), x(-1) { }

    void update(int nx)
    {
        v = nx;
        x = nx;
    }

    void combine(const node& other)
    {
        v = min(v, other.v);
    }
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

    void update(int b, int e, int x)
    {
        update(0, b, e, x);
    }

    node query(int b, int e)
    {
        return query(0, b, e);
    }

private:
    int left(int i) const
    {
        return 2 * i + 1;
    }

    int right(int i) const
    {
        return 2 * i + 2;
    }

    void collect(int i)
    {
        t[i].v = min(t[left(i)].v, t[right(i)].v);
    }

    void push(int i)
    {
        if (t[i].x != -1) {
            t[left(i)].update(t[i].x);
            t[right(i)].update(t[i].x);
            t[i].x = -1;
        }
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
            build(left(i), n.b, n.m);
            build(right(i), n.m + 1, n.e);
            collect(i);
        }
    }

    void update(int i, int b, int e, int x)
    {
        node& n = t[i];
        if (b == n.b && e == n.e) {
            n.update(x);
        } else {
            push(i);
            if (b <= n.m)
                update(left(i), b, min(n.m, e), x);
            if (e > n.m)
                update(right(i), max(b, n.m + 1), e, x);
            collect(i);
        }
    }

    node query(int i, int b, int e)
    {
        node& n = t[i];
        if (b == n.b && e == n.e) {
            return n;
        } else {
            push(i);
            node result;
            if (b <= n.m)
                result.combine(query(left(i), b, min(n.m, e)));
            if (e > n.m)
                result.combine(query(right(i), max(b, n.m + 1), e));
            return result;
        }
    }

    vector<node> t;
    vector<int> a;
};

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for (int& it : a) scanf("%d", &it);

    int q;
    scanf("%d", &q);

    segment_tree tree(a);
    while (q-- > 0) {
        int t, b, e;
        scanf("%d%d%d", &t, &b, &e);
        if (t == 1) {
            printf("%d\n", tree.query(b - 1, e - 1).v);
        } else {
            int x;
            scanf("%d", &x);
            tree.update(b - 1, e - 1, x);
        }
    }
}
