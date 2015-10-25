#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

const int N_MAX = 150 + 1;
int_t h, w, s;
int_t a[N_MAX][N_MAX];

bool input() {
  if (cin >> h >> w >> s) {
    rep (i, h) rep (j, w) cin >> a[i][j];
    return true;
  }
  return false;
}

bool check(int a, int b, int c, int d) {
  return a + b + c + d;
}

typedef set<int_t> set_t;
int_t s1[N_MAX][N_MAX]; // line
int_t s2[N_MAX][N_MAX]; // block

inline int_t sum(int r1, int c1, int r2, int c2) {
  return s2[r2][c2] - s2[r1-1][c2] - s2[r2][c1-1] + s2[r1-1][c1-1];
}

int_t solve() {
  rep (i, h) fill(s1[i], s1[i]+N_MAX, 0);
  rep (i, h) fill(s2[i], s2[i]+N_MAX, 0);
  rep (i, h) rep (j, w) {
    s1[i+1][j+1] = s1[i+1][j] + a[i][j];
  }
  rep (i, h+1) rep (j, w+1) {
    s2[i][j] += s1[i][j];
    rep (k, i) {
      s2[i][j] += s1[k][j];
    }
  }
  int res = 0;
  for (int r1 = 1; r1 <= h; ++r1) for (int r2 = r1; r2 <= h; ++r2) {
    int_t t = 0;
    set_t v;
    for (int c = 1; c <= w; ++c) {
      t += s2[r2][c] - s2[r1-1][c];
      v.insert(t);
    }
    res += 1 + distance(v.begin(), v.lower_bound(s));
    // for (int c1 = 1; c1 <= w; ++c1) for (int c2 = c1; c2 <= w; ++c2) {
    //   if (sum(r1, c1, r2, c2) <= s) ++res;
    // }
  }
  // printf("sum(%d, %d, %d, %d) = %d, res = %d\n", r1, c1, r2, c2, sum(r1, c1, r2, c2-1), res);
  // printf("\n");
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  rep (i, t) {
    if (input()) cout << solve() << endl;
  }
  return 0;
}
