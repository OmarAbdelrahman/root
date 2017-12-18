#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() { 
  T x;
  cin >> x;
  return x;
}

int main() {
  int n, m;
  cin >> n >> m;
  string s = " " + next<string>();
  for (int i = 0; i < m; i++) {
    int l, r;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    for (int j = l; j <= r; j++) {
      if (s[j] == c1) {
        s[j] = c2;
      }
    }
  }
  s.erase(s.begin());
  cout << s << endl;
  return 0;
}
