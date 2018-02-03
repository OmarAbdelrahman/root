#include <bits/stdc++.h>
using namespace std;

const int N = 200002;

int a[N], c[N];

void update(int pos, int val, int chunk_size, int n)
{
    a[pos] = val;
    int j = pos / chunk_size;
    c[j] = numeric_limits<int>::max();
    for (int i = j * chunk_size; i < min(n, (j + 1) * chunk_size); i++) {
        c[j] = min(c[j], a[i]);
    }
}

int rmq(int b, int e, int chunk_size)
{
    int result = numeric_limits<int>::max();
    for (int i = b; i <= e; ) {
        if (i % chunk_size == 0 && i + chunk_size - 1 <= e) {
            result = min(result, c[i / chunk_size]);
            i += chunk_size;
        } else {
            result = min(result, a[i++]);
        }
    }
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int k = (int) sqrt(n * 1.0);
    int m = (n + k - 1) / k;
    for (int i = 0; i < m; i++) {
        c[i] = numeric_limits<int>::max();
    }
    for (int i = 0; i < n; i++) {
        c[i / k] = min(c[i / k], a[i]);
    }
    int q;
    scanf("%d", &q);
    while (q-- > 0) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1) {
            update(y - 1, z, k, n);
        } else {
            printf("%d\n", rmq(y - 1, z - 1, k));
        }
    }
}
