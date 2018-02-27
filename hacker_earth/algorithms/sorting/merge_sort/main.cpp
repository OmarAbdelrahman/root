#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

int a[N];

long long sort(int b, int e) {
    if (b >= e) return 0;

    int m = (b + e) / 2;
    long long ls = sort(b, m);
    long long rs = sort(m + 1, e);

    int* t = new int[e - b + 1];
    int jl = b;
    int jr = m + 1;
    int ti = 0;

    long long res = 0;
    for (int i = b; i <= e; i++) {
        if (jl > m) {
            t[ti++] = a[jr++];
        } else if (jr > e) {
            t[ti++] = a[jl++];
        } else if (a[jl] > a[jr]) {
            t[ti++] = a[jr++];
            res += (m -  jl + 1LL);
        } else {
            t[ti++] = a[jl++];
        }
    }
    for (int i = 0, ai = b; i < ti; i++) {
        a[ai++] = t[i];
    }
    return res + rs + ls;
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int swaps = sort(0, n - 1);
    cout << swaps << '\n';
}
