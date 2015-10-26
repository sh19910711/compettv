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

typedef tuple<int, int, int> node_t;
typedef set<node_t> queue_t;

int mdist[3][H_MAX][H_MAX];

void get_dist(char start) {
  int id = start - '1';
  queue_t q;
  rep (i, h) rep (j, w) {
    if (t[i][j] == start) {
      mdist[id][i][j] = 0;
      q.emplace(0, i, j);
    }
  }
  while (!q.empty()) {
    int s = get<0>(*q.begin());
    int r = get<1>(*q.begin());
    int c = get<2>(*q.begin());
    q.erase(q.begin());
    const int dr[4] = {0, 0, 1, -1};
    const int dc[4] = {1, -1, 0, 0};
    rep (k, 4) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr < 0 || nr >= h || nc < 0 || nc >= w) continue;
      if (t[nr][nc] == '#') continue;
      int ns = s + (t[nr][nc] == '.');
      if (mdist[id][nr][nc] <= ns) continue;
      mdist[id][nr][nc] = ns;
      q.emplace(ns, nr, nc);
    }
  }
}

int solve() {
  const int inf = 1e7;
  rep (i, 3) rep (j, H_MAX) fill(mdist[i][j], mdist[i][j]+H_MAX, inf);
  for (char c = '1'; c <= '3'; ++c) {
    get_dist(c);
  }
  int res = 0;
  rep (k, 3) rep (i, h) rep (j, w) if (t[i][j] == '.') {
    res += mdist[k][i][j];
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
