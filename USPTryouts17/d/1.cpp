#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;
const long double eps = 1e-9;

int n;
long double m[N], b[N];

long double f(int i, long double x) {
  return m[i] * x - b[i];
}

long double g(int i, long double y) {
  return (y + b[i]) / m[i];
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
//     scanf("%lf %lf", m + i, b + i);
    cin >> m[i] >> b[i];
  }
  long double xa = -(1e19 + 1e18);
  long double xb = 1e19 + 1e18;
  long double ya = -(1e19 + 1e18);
  long double yb = 1e19 + 1e18;
  vector<pair<long double, int> > vya, vyb, vxa, vxb;
  for (int i = 0; i < n; i++) {
    long double y = f(i, xa);
    vya.push_back(make_pair(y, i));
  }
  for (int i = 0; i < n; i++) {
    long double y = f(i, xb);
    vyb.push_back(make_pair(y, i));
  }
  for (int i = 0; i < n; i++) {
    long double y = g(i, ya);
    vxa.push_back(make_pair(y, i));
  }              
  for (int i = 0; i < n; i++) {
    long double y = g(i, yb);
    vxb.push_back(make_pair(y, i));
  }
  sort(vya.begin(), vya.end());
  sort(vyb.begin(), vyb.end());
  sort(vxa.begin(), vxa.end());
  sort(vxb.begin(), vxb.end());
  long double ivya = 1e19 + 1e18;
  long double ivyb = -(1e19 + 1e18);
  long double ivxa = 1e19 + 1e18;
  long double ivxb = -(1e19 + 1e18);
  for (int i = 0; i < (int) vya.size() - 1; i++) {
    int p1 = vya[i].second, p2 = vya[i + 1].second;
    if (fabs(m[p1] - m[p2]) < eps) continue;
    long double x = (b[p1] - b[p2]) / (m[p1] - m[p2]);
    ivya = min(ivya, x);
  }
  for (int i = 0; i < (int) vyb.size() - 1; i++) {
    int p1 = vyb[i].second, p2 = vyb[i + 1].second;
    if (fabs(m[p1] - m[p2]) < eps) continue;
    long double x = (b[p1] - b[p2]) / (m[p1] - m[p2]);
    ivyb = max(ivyb, x);
  }
  for (int i = 0; i < (int) vxa.size() - 1; i++) {
    int p1 = vxa[i].second, p2 = vxa[i + 1].second;
    if (fabs(m[p1] - m[p2]) < eps) continue;
    long double x = (b[p2] * m[p1] - b[p1] * m[p2]) / (m[p2] - m[p1]);
    ivxa = min(ivxa, x);
  }
  for (int i = 0; i < (int) vxb.size() - 1; i++) {
    int p1 = vxb[i].second, p2 = vxb[i + 1].second;
    if (fabs(m[p1] - m[p2]) < eps) continue;
    long double x = (b[p2] * m[p1] - b[p1] * m[p2]) / (m[p2] - m[p1]);
//    long double x = (b[p1] - b[p2]) / (m[p1] - m[p2]);
    ivxb = max(ivxb, x);
  }
//  printf("%.6lf %.6lf %.6lf %.6lf\n", ivya, ivxa, ivyb, ivxb);
  setprecision(12);
  cout << fixed << ivya << ' ' << ivxa << ' ' << ivyb << ' ' << ivxb << endl;
  return 0;
}