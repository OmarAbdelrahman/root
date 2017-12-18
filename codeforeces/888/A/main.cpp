#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& it : a) cin >> it;
  int count = 0;
  for (int i = 1; i + 1 < n; i++) {
    count += (int) (a[i] < a[i - 1] && a[i] < a[i + 1]) || (a[i] > a[i - 1] && a[i] > a[i + 1]);
  }
  cout << count << endl;
  return 0;
}
