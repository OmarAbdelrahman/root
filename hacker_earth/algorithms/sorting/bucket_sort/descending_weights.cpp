#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

template<typename T>
inline void print(const vector<T>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }
}

int a[N];
map<int, vector<int>, greater<int>> buckets;

void count_sort(vector<int>& ar, int pos) {
    vector<int> f(10, 0);
    for (int x : ar) {
        int d = (x / pos) % 10;
        f[d] += 1;
    }
    for (int i = 1; i < 10; i++) {
        f[i] += f[i - 1];
    }
    vector<int> t(ar.size());
    for (int i = ar.size() - 1; i >= 0; i--) {
        int d = (ar[i] / pos) % 10;
        t[f[d] - 1] = ar[i];
        f[d] -= 1;
    }
    ar.swap(t);
}

void radix_sort(vector<int>& ar) {
    int k = *max_element(begin(ar), end(ar));
    int pos = 1;
    while (k > 0) {
        count_sort(ar, pos);
        pos *= 10;
        k /= 10;
    }
}

void bucket_sort(int n, int k) {
    buckets.clear();
    for (int i = 0; i < n; i++) {
        buckets[a[i] % k].push_back(a[i]);
    }
    int ai = 0;
    for (auto& p : buckets) {
        radix_sort(p.second);
        for (int e : p.second) {
            a[ai++] = e;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bucket_sort(n, k);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}
