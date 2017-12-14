#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const double eps = 1e-8;
const double pi = acos(-1.0);

int n, m;
int x[2][N], y[2][N];

struct vec {
  int x, y;

  vec() {}

  vec(int x, int y) : x(x), y(y) {}

  vec operator + (vec other) {
    return vec(x + other.x, y + other.y);
  }

  vec operator - (vec other) {
    return vec(x - other.x, y - other.y);
  }

  double operator * (vec other) {
    return x * other.x + y * other.y;
  }

  double len() {
    return sqrt((double) x * x + y * y);
  }
};

struct point {
  double x, y;

  point() {}

  point(double x, double y) : x(x), y(y) {}

  point operator + (point other) {
    return point(x + other.x, y + other.y);
  }

  point operator - (point other) {
    return point(x - other.x, y - other.y);
  }

  double operator ^ (point other) {
    return x * other.y - y * other.x;
  }

  bool operator < (const point &other) const {
    if (x == other.x) return y < other.y;
    return x < other.x;
  }
};

bool in_pol(int xi, int yi, int w) {
  int len = (w == 0 ? n : m);
  double sum = 0;
  for (int i = 0; i < len; i++) {
    int j = i + 1;
    if (j >= len) j -= len;
    vec v1 = vec(x[w][i] - xi, y[w][i] - yi);
    vec v2 = vec(x[w][j] - xi, y[w][j] - yi);
    double ang = acos(v1 * v2 / (v1.len() * v2.len()));
    sum += ang;
  }
  return fabs(2 * pi - sum) < eps;
}

double ccw(point o, point a, point b) {
  point ao = a - o;
  point bo = b - o;
  return ao ^ bo;
}

vector<point> calc_ch(vector<point> pts) {
  vector<point> ret;
  sort(pts.begin(), pts.end());
  int k = 0;
  for (int i = 0; i < (int) pts.size(); i++, k++) {
    while (k >= 2 && ccw(ret[k - 2], ret[k - 1], pts[i]) < 0) {
      assert(!ret.empty());
      ret.pop_back();
      k--;
    }
    ret.push_back(pts[i]);
  }
  int t = k;
  for (int i = (int) pts.size() - 2; i >= 0; i--, k++) {
    while (k >= t + 1 && ccw(ret[k - 2], ret[k - 1], pts[i]) < 0) {
      assert(!ret.empty());
      ret.pop_back();
      k--;
    }
    ret.push_back(pts[i]);
  }
  if (!ret.empty()) ret.pop_back();
  return ret;
}

double calc_area(vector<point> pts) {
  double ret = 0;
  for (int i = 0; i < (int) pts.size(); i++) {
    int j = i + 1;
    if (j == (int) pts.size()) j = 0;
    ret += pts[i].x * pts[j].y - pts[i].y * pts[j].x;
  }
  return fabs(ret) / 2.;
}

pair<bool, point> intersect(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
  point x3y3 = point(x3, y3) - point(x1, y1);
  point x4y4 = point(x4, y4) - point(x1, y1);
  point x2y2 = point(x2, y2) - point(x1, y1);
  if ((x3y3 ^ x2y2) >= 0 && (x4y4 ^ x2y2) >= 0) return make_pair(false, point(0, 0));
  if ((x3y3 ^ x2y2) < 0 && (x4y4 ^ x2y2) < 0) return make_pair(false, point(0, 0));
  x2y2 = point(x2, y2) - point(x3, y3);
  point x1y1 = point(x1, y1) - point(x3, y3);
  x4y4 = point(x4, y4) - point(x3, y3);
  if ((x2y2 ^ x4y4) >= 0 && (x1y1 ^ x4y4) >= 0) return make_pair(false, point(0, 0));
  if ((x2y2 ^ x4y4) < 0 && (x1y1 ^ x4y4) < 0) return make_pair(false, point(0, 0));
  if (fabs(x2 - x1) < eps) {
    double m2 = (double) (y4 - y3) / (x4 - x3);
    double b2 = y3 - m2 * x3;
    return make_pair(true, point(x1, m2 * x1 + b2));
  }
  if (fabs(x4 - x3) < eps) {
    double m1 = (double) (y2 - y1) / (x2 - x1);
    double b1 = y1 - m1 * x1;
    return make_pair(true, point(x3, m1 * x3 + b1));
  }
  double m1 = (double) (y2 - y1) / (x2 - x1);
  double m2 = (double) (y4 - y3) / (x4 - x3);
  double b1 = y1 - m1 * x1;
  double b2 = y3 - m2 * x3;
  double xx = (b2 - b1) / (m1 - m2);
  double yy = m1 * x1 + b1;
  return make_pair(true, point(xx, yy));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
      scanf("%d %d", x[0] + i, y[0] + i);
    }
    for (int i = 0; i < m; i++) {
      scanf("%d %d", x[1] + i, y[1] + i);
    }
    vector<point> pts;
    for (int i = 0; i < n; i++) {
      if (in_pol(x[0][i], y[0][i], 1)) {
        pts.push_back(point(x[0][i], y[0][i]));
      }
    }
    for (int i = 0; i < m; i++) {
      if (in_pol(x[1][i], y[1][i], 0)) {
        pts.push_back(point(x[1][i], y[1][i]));
      } 
    }
    for (int i = 0; i < n; i++) {
      int j = i + 1;
      if (j >= n) j -= n;
      for (int k = 0; k < m; k++) {
        int l = k + 1;
        if (l >= m) l -= m;
        pair<bool, point> res = intersect(x[0][i], y[0][i], x[0][j], y[0][j], x[1][k], y[1][k], x[1][l], y[1][l]);
        if (res.first) {
          pts.push_back(res.second);
        }
      }
    }
    vector<point> ch = calc_ch(pts);
    double area = calc_area(ch);
    printf("%.4lf\n", area);
  }
  return 0;
}