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
  int e = a.size() - 1;
  while (s < e) {
    int m = (s / 2) + (e / 2);
    if (a[m] <= elem) {
      s = m + 1;
    } else {
      e = m - 1;
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
  for (int i : b) {
    cout << f(i, a) << " ";
  }
  cout << endl;
  return 0;
}
