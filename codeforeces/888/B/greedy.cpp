#include <bits/stdc++.h>
using namespace std;

template<class T>
inline T next() {
  T x;
  cin >> x;
  return x;
}

int main() {
  int n = next<int>();
  string cmds = next<string>();
  unordered_map<char, int> freq;
  for (char ch : cmds) {
    freq[ch]++;
  }
  int rem = abs(freq['D'] - freq['U']) + abs(freq['L'] - freq['R']);
  cout << n - rem << endl;
  return 0;
}
