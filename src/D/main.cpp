#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

namespace {
  int x1, y1, x2, y2;
  int v_max, t;
  int vx, vy;
  int wx, wy;

  bool input() {
    if (cin >> x1 >> y1 >> x2 >> y2) {
      cin >> v_max >> t;
      cin >> vx >> vy >> wx >> wy;
      return true;
    }
    return false;
  }

  typedef tuple<double, double> vector_t;

  inline double x(const vector_t& v) { return get<0>(v); }
  inline double y(const vector_t& v) { return get<1>(v); }

  vector_t diff(double x1, double y1, double x2, double y2) {
    return vector_t(x2 - x1, y2 - y1);
  }

  double size(const vector_t& v) {
    return sqrt(x(v) * x(v) + y(v) * y(v));
  }

  void print(const vector_t& v) {
    cout << "(" << x(v) << ", " << y(v) << ")" << endl;
  }

  vector_t mul(const vector_t& v, double k) {
    return vector_t(x(v) * k, y(v) * k);
  }

  vector_t sub(const vector_t& a, const vector_t& b) {
    return vector_t(x(a) - x(b), y(a) - y(b));
  }

  double solve() {
    double l = 0.0;
    double r = 1e12;
    rep (k, 1e6) {
      double mid = (l + r) / 2.0;
      vector_t d = diff(x1, y1, x2, y2);
      if (mid > t) {
        d = sub(d, mul(vector_t(vx, vy), t));
        d = sub(d, mul(vector_t(wx, wy), mid - t));
      } else {
        d = sub(d, mul(vector_t(vx, vy), mid));
      }
      if (size(d) > v_max * mid) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return (l + r) / 2.0;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    printf("%.12f\n", solve());
  }
  return 0;
}
