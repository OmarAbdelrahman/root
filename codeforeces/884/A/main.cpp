#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
    x = 86400 - x;
  }
  int result = 0;
  for (int rem : a) {
    t -= rem;
    result++;
    if (t <= 0) {
      break;
    }
  }
  cout << result << endl;
  return 0;
}
