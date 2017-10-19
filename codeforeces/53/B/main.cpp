#include <bits/stdc++.h>
using namespace std;

int area;

ostream& operator << (ostream& ostr, const pair<long long, long long>& p) {
  ostr << p.first << " " << p.second;
  return ostr;
}

vector<int> power_of_twos(int limit) {
  vector<int> result(1, 1);
  while (result.back() * 2 < limit) {
    result.push_back(result.back() * 2);
  }
  return result;
}

inline bool okay_ratio(long long a, long long b) {
  return 4 * b <= a * 5 && a * 4 <= 5 * b;
}

long long solve_width(long long e, long long h) {
  long long s = 1;
  long long result = -1;
  while (s <= e) {
    long long width = (s + e) / 2;
    if (okay_ratio(h, width)) {
      s = width + 1;
      if (h * width > area) {
        area = h * width;
        result = width;
      }
    } else if (h * 4 > 5 * width) {
      s = width + 1;
    } else if (h * 5 < 4 * width) {
      e = width - 1;
    }
  }
  return result;
}

long long solve_height(long long e, long long w, long long cur_h) {
  long long s = 1;
  long long result = -1;
  while (s <= e) {
    long long height = (s + e) / 2;
    if (okay_ratio(height, w)) {
      s = height + 1;
      if (height * w > area || (height * w == area && height > cur_h)) {
        area = height * w;
        result = height;
      }
    } else if (height * 4 > 5 * w) {
      e = height - 1;
    } else if (height * 5 < 4 * w) {
      s = height + 1;
    }
  }
  return result;
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
  area = -1;
  pair<long long, long long> result1 = { twos[hi], solve_width(w, twos[hi]) };
  pair<long long, long long> result2 = { solve_height(h, twos[wi], result1.first), twos[wi] };
  long long a1 = result1.first * result1.second;
  long long a2 = result2.first * result2.second;
  if (a1 > a2 || (a1 == a2 && result1.first > result2.first)) {
    cout << result1 << endl;
  } else {
    cout << result2 << endl;
  }
  return 0;
}
