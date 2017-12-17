#include <bits/stdc++.h>
using namespace std;

long long get(long long i, int n) {
  while (n > 0) {
    i *= 10;
    i += n % 10;
    n /= 10;
  }
  return i;
}

int main() {
  int k, p;
  cin >> k >> p;
  long long result = 0;
  for (int i = 1; i <= k; i++) {
    long long v = get(i, i);
    result += v;
    result %= p;
  }
  cout << result << endl;
  return 0;
}
