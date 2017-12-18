#include <bits/stdc++.h>
using namespace std;

const int N = 1234567;

template<class T>
inline T next() {
    T x;
    cin >> x;
    return x;
}

int L[N];

int main() {
    int n = next<int>();
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    int size = n--;
    while (n >= 0 && L[n] == 0) {
        n--;
    }
    int killed = 0;
    int index = n;
    for (int i = n - 1; i >= 0; i--) {
        if (i + L[index] >= index) {
            killed++;
        }
        if (L[i] != 0) {
            index = i;
        }
    }
    cout << size - killed << endl;
    return 0;
}
