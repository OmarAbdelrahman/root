#include <bits/stdc++.h>
using namespace std;

const double EPSILON = 1e-9;

vector<int> power_of_twos(int limit) {
  vector<int> result(1, 1);
  while (result.back() * 2 < limit) {
    result.push_back(result.back() * 2);
  }
  return result;
}

inline bool okay_ratio(int a, int b) {
  return 0.8 * b <= a * 1.0 && a * 1.0 <= 1.25;
}

int solve_width(int e, int h, int w_len) {
  int s = 1;
  int result = 1;
  while (s < e) {
    int width = (s + e) / 2;
    if (okay_ratio(h, w_len - width)) {
      e = width - 1;
      result = e;
    } else if (h > 1.25 * width) {
      s = width + 1;
    } else if (h < 0.8 * width) {
      e = width - 1;
    }
  }
  return result;
}

int solve_height(int e, int w, int h_len) {
  int s = 1;
  int result = 1;
  while (s < e) {
    int height = (s + e) / 2;
    if (okay_ratio(h_len - height, w)) {
      s = height + 1;
      result = s;
    } else if (height > 1.25 * w) {
      e = height - 1;
    } else if (height < 0.8 * w)
  }
  return e;
}

int main() {
  vector<int> twos = power_of_twos(1e9);
  int h, w;
  cin >> h >> w;
  int wi = -1;
  int hi = -1;
  for (int i = 0; i < (int) twos.size(); i++) {
    if (w <= twos[i]) {
      wi = i;
    }
    if (h <= twos[i]) {
      hi = i;
    }
  }
  pair<int, int> resutl1 = { twos[hi], solve_width(w, twos[hi], w) };
  pair<int, int> resutl2 = { solve_height(h, twos[wi], h), twos[wi] };
  return 0;
}
