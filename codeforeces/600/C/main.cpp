#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  unordered_map<char, int> f;
  for (char ch : s) {
    f[ch]++;
  }
  const int size = s.length();
  for (char ch1 = 'a'; ch1 <= 'z'; ch1++) {
    if (f[ch1] % 2 == 0) continue;
    for (char ch2 = 'z'; ch2 >= 'a'; ch2--) {
      if (f[ch2] % 2 == 0 || ch1 == ch2) continue;
      if (ch1 < ch2) {
        f[ch1]++;
        f[ch2]--;
      } else {
        f[ch1]--;
        f[ch2]++;
      }
      break;
    }
  }
  int index = 0;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    while (f[ch] >= 2) {
      if (index < size / 2) {
        s[index] = s[size - index - 1] = ch;
        index++;
        f[ch] -= 2;
      }
    }
  }
  for (char ch = 'a'; ch <= 'z'; ch++) {
    if (f[ch] % 2 != 0) {
      s[size / 2] = ch;
    }
  }
  cout << s << endl;
  return 0;
}
