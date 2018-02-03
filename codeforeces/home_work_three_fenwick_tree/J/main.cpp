#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> v;

struct fenwick_tree
{
    fenwick_tree(int _n): f(_n), n(_n)
    {        
    }

    fenwick_tree(const vector<int>& a): n(a.size())
    {
        f = vector<multiset<int>>(n);
        for (int i = 0; i < n; i++) {
            f[i].insert(a[i]);
            int ni = i | (i + 1);
            if (ni < n) {
                f[ni].insert(begin(f[i]), end(f[i]));
            }
        }
    }

    void update(int at, int val)
    {
        while (at < n) {
            f[at].insert(val);
            at |= (at + 1);
        }
    }

    void remove(int at, int val)
    {
        while (at < n) {
            remove_element(at, val);
            at |= (at + 1);
        }
    }

    int query(int b, int e, int x)
    {
        int r = INF;
        while (b <= e) {
            int nb = e & (e + 1);
            if (nb >= b) {
                r = min(r, get_val(e, x));
                e = nb - 1;
            } else {
                if (v[e] >= x) r = min(r, v[e]);
                e -= 1;
            }
        }
        return r;
    }

private:
    vector<multiset<int>> f;
    int n;

    int get_val(int at, int x)
    {
        auto pos = f[at].lower_bound(x);
        if (pos != end(f[at])) return *pos;
        return INF;
    }

    void remove_element(int at, int elem)
    {
        auto pos = f[at].find(elem);
        if (pos != end(f[at])) f[at].erase(pos);
    }
};

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    v = vector<int>(n);
    for (int& it : v) scanf("%d", &it);

    fenwick_tree tree(v);
    while (k-- > 0) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int p, x;
            scanf("%d%d", &p, &x);
            p -= 1;
            tree.remove(p, v[p]);
            tree.update(p, x);
            v[p] = x;
        } else {
            int b, e, x;
            scanf("%d%d%d", &b, &e, &x);
            int r = tree.query(b - 1, e - 1, x);
            if (r == INF) {
                puts("?");
            } else {
                printf("%d\n", r);
            }
        }
    }
}
