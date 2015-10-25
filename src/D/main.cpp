#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

namespace {
  double x1, y1, x2, y2;
  double v_max;
  int t;
  double vx, vy;
  double wx, wy;

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

  vector_t norm(const vector_t& v) {
    return vector_t(x(v) / size(v), y(v) / size(v));
  }

  void print(const vector_t& v) {
    cout << "(" << x(v) << ", " << y(v) << ")" << endl;
  }

  vector_t mul(const vector_t& v, double k) {
    return vector_t(x(v) * k, y(v) * k);
  }

  vector_t diff(const vector_t& a, const vector_t& b) {
    return vector_t(x(a) - x(b), y(a) - y(b));
  }

  vector_t add(const vector_t& a, const vector_t& b) {
    return vector_t(x(a) + x(b), y(a) + y(b));
  }

  double solve() {
    vector_t v = diff(x1, y1, x2, y2);
    double need = size(v);
    v = mul(norm(v), v_max);
    vector_t v1 = add(v, vector_t(vx, vy));
    double len = size(v1) * t;
    if (len >= need) {
      return need / size(v1);
    } else {
      vector_t v2 = add(v, vector_t(wx, wy));
      return t + (need - len) / size(v2);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
