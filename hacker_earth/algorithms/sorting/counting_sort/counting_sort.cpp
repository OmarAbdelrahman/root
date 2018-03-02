#include <bits/stdc++.h>
using namespace std;

constexpr int M = 100000;
constexpr int N = 100;

int f[M];
int a[N];
int s[N];

void sort(int n) {
    int mx = *max_element(a, a + n);
    for (int i = 0, si = 0; i <= mx; i++) {
        int cf = f[i];
        while (cf-- > 0) {
            s[si++] = i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        f[a[i]]++;
    }
    sort(n);
    for (int i = 0; i < n; i++) {
        if (f[s[i]] != -1) {
            cout << s[i] << ' ' << f[s[i]] << '\n';
            f[s[i]] = -1;
        }
    }
}
