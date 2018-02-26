#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int a[N];

int sort(int b, int e) {
    if (b >= e) return 0;

    int m = (b + e) / 2;
    int ls = sort(b, m);
    int rs = sort(m + 1, e);

    int* t = new int[e - b + 1];
    int jl = m;
    int jr = m + 1;
    int ti = e - b;

    int res = ls + rs;
    for (int i = b; i <= e; i++) {
        if (jl < b) {
            t[ti--] = a[jr++];
        } else if (jr > e) {
            t[ti--] = a[jl--];
        } else if (a[jl] > a[jr]) {
            t[ti--] = a[jr++];
            res += 1;
        } else {
            t[ti--] = a[jl--];
        }
    }
    for (int i = 0, ai = b; i < e - b + 1; i++) {
        a[ai++] = t[i];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " \n"[i == n - 1];

    int swaps = sort(0, n - 1);
    cout << swaps << '\n';
}
