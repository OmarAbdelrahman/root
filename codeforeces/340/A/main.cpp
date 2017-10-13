#include <bits/stdc++.h>
using namespace std;

inline long long gcd(const long long a, const long long b) {
  return __gcd(a, b);
}

inline long long lcm(const long long a, const long long b) {
  return (a / gcd(a, b)) * b;
}

int count_xy_divisables(const long long x, const long long y, const long long limit) {
  return limit / lcm(x, y);
}

int main() {
  long long x, y, a, b;
  cin >> x >> y >> a >> b;
  cout << count_xy_divisables(x, y, b) - count_xy_divisables(x, y, a - 1) << endl;
  return 0;
}
