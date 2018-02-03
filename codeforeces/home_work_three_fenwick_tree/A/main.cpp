#include <bits/stdc++.h>
using namespace std;

#define SIZE(a) (int) (a).size()

template<typename T>
struct fenwick_tree
{
    fenwick_tree() { }

    fenwick_tree(int n): f(n, 0)
    {
    }

    fenwick_tree(const vector<int>& a)
    {
        f = vector<T>(SIZE(a));
        for (int i = 0; i < SIZE(f); i++) {
            f[i] += a[i];
            int ni = i | (i + 1);
            if (ni < SIZE(f)) {
                f[ni] += f[i];
            }
        }
    }

    void update(int pos, T val)
    {
        while (pos < SIZE(f)) {
            f[pos] += val;
            pos |= (pos + 1);
        }
    }

    T rsq(int pos)
    {
        T result = T();
        while (pos >= 0) {
            result += f[pos];
            pos = (pos & (pos + 1)) - 1;
        }
        return result;
    }

    T rsq(int b, int e)
    {
        return rsq(e) - rsq(b - 1);
    }

private:
    vector<T> f;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int& it : a) cin >> it;

    fenwick_tree<long long> tree(a);
    while (m-- > 0) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            cout << tree.rsq(x - 1, y - 1) << '\n';
        } else {
            x -= 1;
            tree.update(x, -tree.rsq(x, x));
            tree.update(x, y);
        }
    }
}
