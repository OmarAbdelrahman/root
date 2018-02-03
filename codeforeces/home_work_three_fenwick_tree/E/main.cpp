#include <bits/stdc++.h>
using namespace std;

struct fenwick_tree
{
    fenwick_tree(int _n): f(_n), n(_n)
    {
    }

    fenwick_tree(const vector<int>& a): n(a.size())
    {
        f = vector<map<int, int>>(n);
        for (int i = 0; i < n; i++) {
            f[i][a[i]]++;
            int ni = i | (i + 1);
            if (ni < n) {
                for (auto p : f[i]) {
                    f[ni][p.first] += p.second;
                }
            }
        }
    }

    void update(int at, int elem, int by)
    {
        while (at < n) {
            f[at][elem] += by;
            at |= (at + 1);
        }
    }

    int query(int at, int val)
    {
        int result = 0;
        while (at >= 0) {
            result += f[at][val];
            at = (at & (at + 1)) - 1;
        }
        return result;
    }

    int query(int b, int e, int val)
    {
        return query(e, val) - query(b - 1, val);
    }

private:
    vector<map<int, int>> f;
    int n;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    fenwick_tree tree(a);
    while (q-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int p, x;
            cin >> p >> x;
            p -= 1;
            tree.update(p, a[p], -1);
            tree.update(p, x, +1);
            a[p] = x;
        } else {
            int b, e, x;
            cin >> b >> e >> x;
            cout << tree.query(b - 1, e - 1, x) << '\n';
        }
    }
}
