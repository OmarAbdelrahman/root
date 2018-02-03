#include <bits/stdc++.h>
using namespace std;

const int N = 100001;

long long a[N], c[N];

void update(int pos, int val, int chunk_size)
{
    c[pos / chunk_size] -= a[pos];
    a[pos] = val;
    c[pos / chunk_size] += a[pos];
}

long long rsq(int b, int e, int chunk_size)
{
    long long result = 0;
    for (int i = b; i <= e; ) {
        if (i % chunk_size == 0 && i + chunk_size - 1 <= e) {
            result += c[i / chunk_size];
            i += chunk_size;
        } else {
            result += a[i++];
        }
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = (int) sqrt(n * 1.0);
    for (int i = 0; i < n; i++) {
        c[i / k] += a[i];
    }
    while (q-- > 0) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            cout << rsq(x - 1, y - 1, k) << '\n';
        } else {
            update(x - 1, y, k);
        }
    }
}