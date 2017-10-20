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
  long long h, w;
  cin >> h >> w;
  for (long long ch = 1; ch <= h; ch *= 2) {
    check(ch, min(w, ch * 5 / 4));
  }
  for (long long cw = 1; cw <= w; cw *= 2) {
    check(min(h, cw * 5 / 4), cw);
  }
  cout << rh << " " << rw << endl;
  return 0;
}
