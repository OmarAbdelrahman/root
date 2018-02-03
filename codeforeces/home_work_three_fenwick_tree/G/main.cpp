#include <bits/stdc++.h>
using namespace std;

template<typename U, typename V>
struct fenwick_tree
{
    fenwick_tree(int _n, int _m): n(_n), m(_m)
    {
    }

    void update(U x, U y, U by)
    {
        for (; x < n; x |= (x + 1)) {
            for (U j = y; j < m; j |= (j + 1)) {
                f[x][j] += by;
            }
        }
    }

    V query(U x, U y)
    {
        V result = V();
        for (; x >= 0; x = (x & (x + 1)) - 1) {
            for (U j = y; j >= 0; j = (j & (j + 1)) - 1) {
                result += f[x][j];
            }
        }
        return result;
    }

    V query(U x1, U y1, U x2, U y2)
    {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }

private:
    map<U, map<U, V>> f;
    int n, m;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    fenwick_tree<int, long long> tree(n, n);
    while (q-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, d;
            cin >> x >> y >> d;
            tree.update(x - 1, y - 1, d);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.query(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
        }
    }
}
