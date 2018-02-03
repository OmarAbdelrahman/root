#include <bits/stdc++.h>
using namespace std;

const long long N = 1000000000000000001;

template<typename T>
struct fenwick_tree
{
    void update(T at, T by)
    {
        while (at < N) {
            f[at] += by;
            at |= (at + 1);
        }
    }

    T query(T at)
    {
        T result = T();
        while (at >= 0) {
            result += f[at];
            at = (at & (at + 1)) - 1;
        }
        return result;
    }

    T query(T b, T e)
    {
        return query(e) - query(b - 1);
    }

private:
    map<T, T> f;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    fenwick_tree<long long> tree;
    while (q-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            long long p, x;
            cin >> p >> x;
            tree.update(p - 1, x);
        } else {
            long long x, y;
            cin >> x >> y;
            cout << tree.query(x - 1, y - 1) << '\n';
        }
    }
}
