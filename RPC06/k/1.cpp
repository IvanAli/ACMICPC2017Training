#include <bits/stdc++.h>
using namespace std;

const int N = 3456;

int T;
int n;
char type[N];
int len[N];


int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      char tt[2]; int ll; scanf("%s %d", tt, &ll);
      type[i] = tt[0];
      len[i] = ll;
    } 
    int side1 = -1, side2 = -1;
    int sum = 0;
    double houses = 0;
    for (int i = 0; i < n; i++) {
      sum += len[i];
      if (type[i] == 'C') {
        if (side1 == -1 && i > 0) side1 = sum;
        else if (side2 == -1 && side1 > -1) side2 = sum;
        sum = len[i];
      }
      if (type[i] == 'C' || type[i] == 'S') {
        houses += (double) len[i] * len[i];
      } else if (type[i] == 'T') {
        houses += (sqrt((double) len[i] * len[i] - (double) (len[i] / 2.) * (len[i] / 2.)) * len[i]) / 2.;
      }
    }
    double ans = (double) side1 * side2;
    ans -= houses;
    printf("%.4lf\n", ans);
  }
  return 0;
}