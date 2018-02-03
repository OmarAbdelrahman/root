#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

template<typename T>
struct fenwick_tree
{
    fenwick_tree(int n): f(n, 0)
    {
    }

    fenwick_tree(const vector<int>& a)
    {
        f = vector<T>(a.size());
        int n = SIZE(f);
        for (int i = 0; i < n; i++) {
            f[i] += a[i];
            int ni = i | (i + 1);
            if (ni < n) {
                f[ni] += f[i];
            }
        }
    }

    void update(int at, T by)
    {
        while (at < SIZE(f)) {
            f[at] += by;
            at |= (at + 1);
        }
    }

    T query(int at)
    {
        T result = T();
        while (at >= 0) {
            result += f[at];
            at = (at & (at + 1)) - 1;
        }
        return result;
    }

    T query(int b, int e)
    {
        return query(e) - query(b - 1);
    }

    friend ostream& operator << (ostream& ostr, const fenwick_tree<T>& mf)
    {
        for (int i = 0; i < SIZE(mf.f); i++) {
            if (i > 0) ostr << ' ';
            ostr << mf.f[i];
        }
        return ostr;
    }

private:
    vector<T> f;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n), b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            b.push_back(a[i]);
        } else {
            b.push_back(a[i] - a[i - 1]);
        }
    }

    fenwick_tree<long long> tree(b);
    while (q-- > 0) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, y, z;
            cin >> x >> y >> z;
            tree.update(x - 1, z);
            tree.update(y, -z);
        } else {
            int x;
            cin >> x;
            x -= 1;
            cout << tree.query(x) << '\n';
        }
    }
}
