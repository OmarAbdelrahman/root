#include <bits/stdc++.h>
using namespace std;

const int N = 100;

void do_sort(vector<int>& a, vector<int>& p) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int e = a[i];
        int j = i;
        while (j > 0 && e < a[j - 1]) {
            a[j] = a[j - 1];
            p[a[j]] = j;
            j -= 1;
        }
        a[j] = e;
        p[a[j]] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), p(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> c = a;
    do_sort(a, p);
    for (int i = 0; i < n; i++) {
        cout << p[c[i]] + 1 << " \n"[i == n - 1];
    }
}
