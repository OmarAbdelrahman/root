#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
    T x;
    cin >> x;
    return x;
}

int main() {
    int n = next<int>();
    vector<int> a(n), b(n);
    for (int& it : a) cin >> it;
    for (int& it : b) cin >> it;
    sort(b.rbegin(), b.rend());
    if (accumulate(a.begin(), a.end(), 0ll) <= (long long) b[0] + b[1]) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}
