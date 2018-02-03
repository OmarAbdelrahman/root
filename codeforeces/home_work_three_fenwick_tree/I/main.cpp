#include <bits/stdc++.h>
using namespace std;

vector<int> a;

struct fenwick_tree
{
    fenwick_tree(int _n): n(_n)
    {
    }

    fenwick_tree(const vector<int>& _a): n(_a.size())
    {
        f = vector<vector<int>>(n);
        for (int i = 0; i < n; i++) {
            f[i].push_back(_a[i]);
            int ni = i | (i + 1);
            if (ni < n) {
                f[ni].insert(end(f[ni]), begin(f[i]), end(f[i]));
            }
        }
        for (auto& v : f) sort(begin(v), end(v));
    }

    int query(int b, int e, int x)
    {
        int result = 0;
        while (b <= e) {
            int nb = e & (e + 1);
            if (nb >= b) {
                result += lower_bound(begin(f[e]), end(f[e]), x) - begin(f[e]);
                e = nb - 1;
            } else {
                if (a[e--] < x) result += 1;
            }
        }
        return result;
    }

private:
    vector<vector<int>> f;
    int n;
};

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    a = vector<int>(n);
    for (int& it : a) cin >> it;

    fenwick_tree tree(a);
    while (k-- > 0) {
        int b, e, x;
        scanf("%d%d%d", &b, &e, &x);
        printf("%d\n", tree.query(b - 1, e - 1, x));
    }
}
