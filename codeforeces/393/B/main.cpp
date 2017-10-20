#include <bits/stdc++.h>
using namespace std;

const int N = 177;
const double EPSILON = 1e-4;

double w[N][N];
double a[N][N];
double b[N][N];

inline bool equal(double x, double y) {
  return fabs(x - y) < EPSILON;
}

void print(double m[N][N], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j != 0) cout << " ";
      cout << fixed << m[i][j];
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> w[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        a[i][j] = w[i][j];
      }
      if (!equal(a[i][j] + b[i][j], w[i][j])) {
        a[i][j] = (w[i][j] + w[j][i]) / 2;
        a[j][i] = a[i][j];
        b[i][j] = w[i][j] - a[i][j];
        b[j][i] = -b[i][j];
      }
    }
  }
  print(a, n);
  print(b, n);
  return 0;
}
