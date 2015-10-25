#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

string s;

bool input() {
  return cin >> s;
}

int cnt[256];

bool check() {
  string t = "LTIM";
  for (auto c : t) {
    if (cnt[c] < 2) return false;
  }
  if (s.size() <= 9) {
    if (cnt['E'] < 1) return false;
  } else {
    if (cnt['E'] < 2) return false;
  }
  return true;
}

bool solve() {
  fill(cnt, cnt+256, 0);
  for (auto c : s) {
    ++cnt[c];
  }
  return check();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  rep (i, t) {
    if (input()) cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}
