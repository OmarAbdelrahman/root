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
  cerr << "W FUN =================== " << endl;
  int s = 1;
  while (s < e) {
    int width = (s + e) / 2;
    if (okay_ratio(h, width)) {
      cerr << "(h, w) = " << h << " " << width << endl;
      return width;
    } else if (h > 1.25 * width) {
      s = width + 1;
    } else if (h < 0.8 * width) {
      e = width - 1;
    }
  }
  return -1;
}

int solve_height(int e, int w, int h_len) {
  cerr << "H FUN ====================== " << endl;
  int s = 1;
  while (s < e) {
    int height = (s + e) / 2;
    if (okay_ratio(height, w)) {
      cerr << "(h, w) = " << height << " " << w << endl;
      return height;
    } else if (height > 1.25 * w) {
      e = height - 1;
    } else if (height < 0.8 * w) {
      s = height + 1;
    }
  }
  return -1;
}

int main() {
  vector<int> twos = power_of_twos(1e9);
  int h, w;
  cin >> h >> w;
  int wi = -1;
  int hi = -1;
  for (int i = 0; i < (int) twos.size(); i++) {
    if (twos[i] <= w) {
      wi = i;
    }
    if (twos[i] <= h) {
      hi = i;
    }
  }
  pair<int, int> result1 = { twos[hi], solve_width(w, twos[hi], w) };
  cerr << result1.first << " " << result1.second << endl;
  pair<int, int> result2 = { solve_height(h, twos[wi], h), twos[wi] };
  cerr << result2.first << " " << result2.second << endl;
  return 0;
}
