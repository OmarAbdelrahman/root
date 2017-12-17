#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()

template<class T>
inline T next() {
    T x;
    cin >> x;
    return x;
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, vector<int>> ct;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ct[a[i]].push_back(i);
    }
    while (q-- > 0) {
        int f, type;
        cin >> f >> type;
        auto d = next<char>();
        if (ct[type].empty()) {
            cout << -1 << endl;
            continue;
        }
        if (a[f] == type) {
            cout << 0 << endl;
            continue;
        }
        vector<int> next = ct[type];
        int result = numeric_limits<int>::max();
        if (d == 'R') {
            for (const int& t : next) {
                result = min(result, (f <= t ? t - f : n - f + t));
            }
        } else {
            for (const int& t : next) {
                result = min(result, (f >= t ? f - t : f + n - t));
            }
        }
        cout << result << endl;
    }
    return 0;
}