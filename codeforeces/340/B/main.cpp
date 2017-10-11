#include <bits/stdc++.h>
using namespace std;

const double EPSILON = 1e-9;

struct point {
  int x;
  int y;

  friend ostream& operator << (ostream& ostr, const point& p) {
    ostr << "(" << p.x << ", " << p.y << ")";
    return ostr;
  }
};

struct vector_t {
  point a;
  point b;

  int x_length() const {
    return b.x - a.x;
  }

  int y_length() const {
    return b.y - a.y;
  }

  double length() const {
    return hypot(a.x - b.x, a.y - b.y);
  }
};

inline double cp(const vector_t& a, const vector_t& b) {
  const int x1 = a.x_length();
  const int y1 = a.y_length();
  const int x2 = b.x_length();
  const int y2 = b.y_length();
  return x1 * y2 - x2 * y1;
}

inline void get_max(double& a, double b) {
  if (b - a > EPSILON) {
    a = b;
  }
}

int main() {
  int n;
  cin >> n;
  vector<point> ps(n);
  for (int i = 0; i < n; i++) {
    cin >> ps[i].x >> ps[i].y;
  }
  double result = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      const vector_t AB = { ps[i], ps[j] };
      double mx_pos = -1;
      double mx_neg = -1;
      for (int k = 0; k < n; k++) {
        if (k == i || k == j) {
          continue;
        }
        const vector_t BC = { ps[j], ps[k] };
        const double area = cp(AB, BC) / 2.0;
        if (area < 0) {
          get_max(mx_neg, -area);
        } else {
          get_max(mx_pos, area);
        }
      }
      if (mx_pos >= 0 && mx_neg >= 0) {
        get_max(result, mx_pos + mx_neg);
      }
    }
  }
  cout << fixed << result << endl;
  return 0;
}
