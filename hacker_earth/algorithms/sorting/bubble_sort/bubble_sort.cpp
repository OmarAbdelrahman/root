#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int a[N];

int sort(int n) {
    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                res += 1;
            }
        }
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
    int swaps = sort(n);
    cout << swaps << '\n';
}
