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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int& it : a) cin >> it;
    for (int& it : b) cin >> it;
    int size = min(n, m);
    long result = 0;
    for (int i = 0; i < size; i++) {
        int j = i;
        while (j < size && a[j] == b[j]) {
            j++;
        }
        int ss = j - i + 1;
        if (ss < k) continue;
        result += ss;
    }
    cout << result << endl;
    return 0;
}