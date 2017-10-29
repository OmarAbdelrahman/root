#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, x;
  cin >> n >> x;
  vector<long long> a(n);
  for (long long& v : a) {
    cin >> v;
  }
  long long total = accumulate(a.begin(), a.end(), 0);
  if (total + n - 1 == x) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
