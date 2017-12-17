#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
    T x;
    cin >> x;
    return x;
}

int f(int elem, const vector<int>& a) {
    int s = 0;
    int e = a.size();
    while (s < e) {
        int m = (s / 2) + (e / 2);
        if (a[m] <= elem) {
            s = m + 1;
        } else {
            e = m;
        }
    }
    return s;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& it : a) cin >> it;
    for (int& it : b) cin >> it;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        if (i > 0) cout << " ";
        cout << f(b[i], a);
    }
    cout << endl;
  return 0;
}
