#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define replr(i, l, r) for (int i = l; i < r; ++i)
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

struct fenwick_t {
  int n;
  vector<int_t> v;
  void build(int n) {
    ++n;
    this->n = n;
    v.assign(n, 0);
  }
  void add(int k, int_t x) {
    ++k;
    while (k < n) {
      v[k] += x;
      k += k & (-k);
    }
  }
  int_t get(int x) {
    ++x;
    int_t res = 0;
    while (x > 0) {
      res += v[x];
      x -= x & (-x);
    }
    return res;
  }
};

typedef set<int_t> set_t;

int_t solve() {
  int_t res = 0;
  int_t s1[N_MAX][N_MAX];
  int_t s2[N_MAX][N_MAX];
  rep (r0, h) {
    fill(s1[r0], s1[r0]+w, 0);
    fill(s2[r0], s2[r0]+w, 0);
    set_t v;
    fenwick_t tree;
    replr (r, r0, h) {
      rep (i, w) s1[r0][i] += a[r][i];
      rep (i, w) s2[r0][i] = s1[r0][i];
      rep (i, w) if (i - 1 > 0) s2[r0][i] += s2[r0][i-1];
      rep (i, w) v.insert(s2[r0][i]);
      tree.build(v.size());
      rep (i, w) {
        tree.add(distance(v.begin(), v.lower_bound(s2[r0][i])), 1);
        res += i + 1 - tree.get(distance(v.begin(), v.lower_bound(s2[r0][i] - s)));
      }
    }
  }
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
