#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N];

void sort(int n, int s) {
    for (int i = 0; i < s; i++) {
        auto p = min_element(a + i, a + n);
        swap(a[i], a[p - a]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(n, s);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
