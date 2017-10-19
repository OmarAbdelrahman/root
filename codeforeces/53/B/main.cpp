#include <bits/stdc++.h>
using namespace std;

long long rh, rw;

void check(long long h, long long w) {
  if (4 * w > 5 * h || 4 * h > w * 5) {
    return;
  }
  if (h * w > rh * rw || (h * w == rh * rw && h > rh)) {
    rh = h;
    rw = w;
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  rh = -1, rw = 1;
  for (int i = 1; i <= h; i *= 2) {
    check(i, w);
  }
  for (int i = 1; i <= w; i *= 2) {
    check(h, i);
  }
  cout << rh << " " << rw << endl;
  return 0;
}
