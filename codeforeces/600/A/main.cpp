#include <bits/stdc++.h>
using namespace std;

inline bool all_numbers(const string& s) {
  if (s.empty()) {
    return false;
  }
  if (s[0] == '0') {
    return (int) s.size() == 1;
  }
  for (const char ch : s) {
    if (ch < '0' || ch > '9') {
      return false;
    }
  }
  return true;
}

void print(const vector<string>& v) {
  if (v.empty()) {
    cout << "-" << endl;
    return;
  }
  cout << "\"";
  for (int i = 0; i < (int) v.size(); i++) {
    if (i != 0) cout << ",";
    if (v[i] != "$") cout << v[i];
  }
  cout << "\"" << endl;
}

inline bool separator(const char& ch) {
  return ch == ';' || ch == ',';
}

int main() {
  string s;
  cin >> s;
  if (separator(s[0])) {
    s = "$" + s;
  }
  if (separator(s.back())) {
    s += "$";
  }
  for (int i = 0; i + 1 < (int) s.length(); i++) {
    if (separator(s[i]) && separator(s[i + 1])) {
      s.insert(s.begin() + i + 1, '$');
    }
  }
  for (char& ch : s) {
    if (separator(ch)) {
      ch = ' ';
    }
  }
  stringstream sin(s);
  vector<string> a, b;
  for (string word; sin >> word; ) {
    if (all_numbers(word)) {
      a.push_back(word);
    } else {
      b.push_back(word);
    }
  }
  print(a);
  print(b);
  return 0;
}
