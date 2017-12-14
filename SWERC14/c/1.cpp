#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0);
const int N = 200005;

int n, m;
int a[N], b[N];
int possible[N << 2];
vector<complex<double>> c;

int rev(int n, int log) {
  int ret = 0;
  for (int i = 0; i < log; i++) {
    if (n & (1 << i)) ret |= 1 << (log - i - 1);
  }
  return ret;
}      

void fft(vector<complex<double>> &a, bool invert) {
  int n = (int) a.size();
  int log = 0;
  while (1 << log < n) log++;
  for (int i = 0; i < n; i++) if (i < rev(i, log)) swap(a[i], a[rev(i, log)]);
  for (int len = 2; len <= n; len += len) {
    double ang = 2 * pi / len * (invert ? -1 : 1);
    for (int i = 0; i < n; i += len) {
      complex<double> w(1), wn(cos(ang), sin(ang));
      for (int j = 0; j < len / 2; j++) {
        complex<double> u = a[i + j];
        complex<double> v = a[i + j + len / 2] * w;
        a[i + j] = u + v;
        a[i + j + len / 2] = u - v;
        w *= wn;
      }
    }
  }
  if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}

void multiply() {
  c = vector<complex<double>>(a, a + N);
  int n = 1;
  while (n < (int) c.size()) n += n;
  n += n;
  c.resize(n);
  fft(c, false);
  for (int i = 0; i < n; i++) c[i] *= c[i];
  fft(c, true);
  for (int i = 0; i < n; i++) {
    possible[i] = (int) (c[i].real() + 0.5);
    possible[i] = min(possible[i], 1);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int foo; scanf("%d", &foo);
    a[foo] = 1;
    possible[foo] = 1;
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int foo; scanf("%d", &foo);
    b[foo] = 1;
  }
  multiply();
  int ans = 0;
  for (int i = 0; i < (int) c.size(); i++) {
    if (possible[i] > 0 && b[i] > 0) ans++;
  }
  printf("%d\n", ans);
  return 0;
}