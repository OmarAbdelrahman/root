#include <bits/stdc++.h>
using namespace std;

int MOD;
vector<long long> a;

struct fenwick_tree
{
    fenwick_tree(int _n): f(_n, 1L), n(_n)
    {        
    }

    void update(int at, long long by)
    {
        while (at < n) {
            (f[at] *= by) %= MOD;
            at |= (at + 1);
        }
    }

    long long query(int at)
    {
        long long result = 1;
        while (at >= 0) {
            (result *= f[at]) %= MOD;
            at = (at & (at + 1)) - 1;
        }
        return result;
    }

    long long query(int b, int e)
    {
        long long result = 1;
        while (b <= e) {
            int nb = e & (e + 1);
            if (nb >= b) {
                (result *= f[e]) %= MOD;
                e = nb - 1;
            } else {
                (result *= a[e]) %= MOD;
                e -= 1;
            }
        }
        return result;
    }

private:
    vector<long long> f;
    int n;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m >> MOD;
    a = vector<long long>(n, 1);

    fenwick_tree tree(n);
    while (m-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, d;
            cin >> i >> d;
            i -= 1;
            (a[i] *= d) %= MOD;
            tree.update(i, d);
        } else {
            int x, y;
            cin >> x >> y;
            cout << tree.query(x - 1, y - 1) << endl;
        }
    }
}
