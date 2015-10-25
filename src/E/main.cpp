#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

const int H_MAX = 1000;
int h, w;
string t[H_MAX];

bool input() {
  if (cin >> h >> w) {
    rep (i, h) cin >> t[i];
    return true;
  }
  return false;
}

typedef tuple<int, int, int, int> node_t;
typedef priority_queue<node_t, vector<node_t>, greater<node_t>> queue_t;

inline int steps(const node_t& x) { return get<0>(x); }
inline int row(const node_t& x) { return get<1>(x); }
inline int col(const node_t& x) { return get<2>(x); }
inline int num(const node_t& x) { return get<3>(x); }

queue_t q;
int mc[H_MAX][H_MAX];

int solve() {
  const int inf = 1e9;
  rep (i, H_MAX) fill(mc[i], mc[i]+H_MAX, inf);
  q = queue_t();
  const int dr[4] = {0, 0, 1, -1};
  const int dc[4] = {1, -1, 0, 0};
  int gn = 0;
  rep (i, h) rep (j, w) if (isdigit(t[i][j])) ++gn;
  while (!q.empty()) {
    auto node = q.top(); q.pop();
    auto s = steps(node);
    auto r = row(node);
    auto c = col(node);
    auto n = num(node);
    if (n == gn) return s;
    for (int k = 0; k < 4; ++k) {
      auto ns = s;
      auto nr = r + dr[k];
      auto nc = c + dc[k];
      auto nn = n;
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
