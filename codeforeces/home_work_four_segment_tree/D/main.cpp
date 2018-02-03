#include <bits/stdc++.h>
using namespace std;

struct node
{
    int b, e, m;
    long long sum;
    long long small;
    long long x = 0;

    node(): x(0) { }

    node(long long _sum, long long _small): sum(_sum), small(_small)
    {
    }

    void combine(const node& other)
    {
        sum += other.sum;
        small = min(small, other.small);
    }

    void update(long long v)
    {
        x += v;
        small += v;
        sum += v * (e - b + 1);
    }
};

struct segment_tree
{
    segment_tree(const vector<int>& _a): a(_a)
    {
        t = vector<node>(a.size() * 4);
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
        t[i].sum = t[L(i)].sum + t[R(i)].sum;
        t[i].small = min(t[L(i)].small, t[R(i)].small);
    }

    void put_initial_value(int i, int ai)
    {
        t[i].sum = t[i].small = a[ai];
    }

    void push(int i)
    {
        t[L(i)].update(t[i].x);
        t[R(i)].update(t[i].x);
        // reset after pushing
        t[i].x = 0;
    }

    void build(int i, int b, int e)
    {
        node& n = t[i];
        n.b = b;
        n.e = e;
        n.m = (b + e) / 2;
        if (n.b == n.e) {
            put_initial_value(i, b);
        } else {
            build(L(i), n.b, n.m);
            build(R(i), n.m + 1, n.e);
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
                update(L(i), b, min(n.m, e), x);
            if (e > n.m)
                update(R(i), max(b, n.m + 1), e, x);
            collect(i);
        }
    }

    node query(int i, int b, int e)
    {
        node& n = t[i];
        if (n.b == b && n.e == e) {
            return n;
        } else {
            push(i);
            node result(0, numeric_limits<int>::max());
            if (b <= n.m)
                result.combine(query(L(i), b, min(n.m, e)));
            if (e > n.m)
                result.combine(query(R(i), max(b, n.m + 1), e));
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
        char ch[2];
        scanf("%s", ch);
        int b, e;
        scanf("%d%d", &b, &e);
        if (ch[0] == 's') {
            printf("%lld\n", tree.query(b, e).sum);
        } else if (ch[0] == 'm') {
            printf("%lld\n", tree.query(b, e).small);
        } else {
            int d;
            scanf("%d", &d);
            tree.update(b, e, d);
        }
    }
}
