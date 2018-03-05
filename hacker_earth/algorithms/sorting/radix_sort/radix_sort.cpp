#include <bits/stdc++.h>

using std::vector;

void print(const vector<int>& v) {
    using std::cout;
    for (size_t i = 0; i < v.size(); i++) {
	cout << v[i] << " \n"[i == v.size() - 1];
    }
}

void count_sort(vector<int>& a, int pos) {
    vector<int> f(10, 0);
    for (int n : a) {
	int d = (n / pos) % 10;
	f[d] += 1;
    }
    for (int i = 1; i < 10; i++) {
	f[i] += f[i - 1];
    }
    vector<int> t(a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
	int d = (a[i] / pos) % 10;
	int p = f[d] - 1;
	f[d] -= 1;
	t[p] = a[i];
    }
    a.swap(t);
}

void radix_sort(vector<int>& a) {
    int k = *max_element(begin(a), end(a));
    int pos = 1;
    for (; k > 0; k /= 10, pos *= 10) {
	count_sort(a, pos);
	print(a);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    
    using std::cin;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
	cin >> a[i];
    }
    radix_sort(a);
}

