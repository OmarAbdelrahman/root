#include <bits/stdc++.h>
using namespace std;

int count_bits(int n) {
    return n == 0 ? 0 : 1 + count_bits(n & (n - 1));
}

void print(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); i++) {
        cout << a[i] << " \n"[i == a.size() - 1];
    }
}

void count_sort(vector<int>& a, int pos) {
    vector<int> f(10, 0);
    for (int x : a) {
        int d = (x / pos) % 10;
        f[d] += 1;
    }
    for (int i = 1; i < 10; i++) {
        f[i] += f[i - 1];
    }
    vector<int> t(a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        int d = (a[i] / pos) % 10;
        int p = f[d] - 1;
        t[p] = a[i];
        f[d] -= 1;
    }
    a.swap(t);
}

void radix_sort(vector<int>& a) {
    int k = *max_element(begin(a), end(a));
    int pos = 1;
    while (k > 0) {
        count_sort(a, pos);
        k /= 10;
        pos *= 10;
    }
}

void bucket_sort(const vector<int>& a) {
    int bits = 0;
    for (int x : a) {
        bits = max(bits, count_bits(x));
    }
    map<int, vector<int>> buckets;
    for (int x : a) {
        buckets[count_bits(x)].push_back(x);
    }
    for (auto& p : buckets) {
        radix_sort(p.second);
        print(p.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
    }
    bucket_sort(a);
}
