#include <bits/stdc++.h>

using namespace std;

const int N = 123456;
const double pi = acos(-1.0);
const double g = 9.81;

double x[N];
char ss[N][20];

double to_rad(int ang) {
  return ang * pi / 180.;
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%lf %s", x + i, ss[i]);
    }
    int pts = -1e9;
    int ang_ans = 0;
    for (int ang = -90; ang <= 90; ang++) {
      double a = to_rad(ang);
      double xfall;
      if (ang >= 0) {
        double tup = 25.0 * sin(a) / g;
        double h = 25 * sin(a) * tup - g * tup * tup / 2. + 1;
        double tdown = sqrt(2 * h / g);
        xfall = (tup + tdown) * 25 * cos(a);
      } else {
//        double tdown = sqrt((2. + 50 * sin(a)) / g);
        double tdown = -25 * sin(a) + sqrt(25 * 25 + 2 * a) / (2 * a);
        if (tdown < 0) -25 * sin(a) - sqrt(25 * 25 + 2 * a) / (2 * a);
        xfall = tdown * 25 * cos(a);
      }
      double vi = 25 * cos(a);
      int ptr = 0;
      while (true) {
        while (ptr < n && x[ptr] < xfall) ptr++;
        if (ptr == n) {
          xfall += vi * (vi / 5.) - 0.2 * vi * vi / 2.;
          break;
        }

        double thit = -vi + sqrt(vi * vi - 10 * (x[ptr] - xfall)) / -5.;
        if (thit < 0) thit = -vi - sqrt(vi * vi - 10 * (x[ptr] - xfall)) / -5.;
        double tstop = vi / 5.;
        if (thit < tstop) {
          if (strcmp(ss[ptr], "spike") == 0) {
            if (-100 > pts) {
              pts = -100;
              ang_ans = ang;
            }
            break;
          } else if (strcmp(ss[ptr], "mine") == 0) {
            xfall += 2;
            vi += 4;
            vi -= 5. * thit;
          }
        } else {
          xfall += vi * (vi / 5.) - 0.2 * vi * vi / 2.;
          break;
        }
      }
      if ((int) xfall * 100 > pts) {
        pts = (int) xfall * 100;
        ang_ans = ang;
      }
    }
    printf("%d %d\n", pts, ang_ans);
  }

  return 0;
}