#include <bits/stdc++.h>
using namespace std;

const int N = 1000001;

template<typename T>
struct fenwick_tree
{
    fenwick_tree(int _n): f(_n, T()), n(_n)
    {        
    }

    void update(int at, T by)
    {
        while (at < n) {
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

private:
    vector<T> f;
    int n;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long result = 0;
    fenwick_tree<long long> tree(N);

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        result += tree.query(v + 1, N - 1);
        tree.update(v, 1);
    }
    cout << result << '\n';
}
