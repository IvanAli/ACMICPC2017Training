#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T, n;
int h[N];

int main() {
  h[1] = 1;
  h[2] = 2;
  h[3] = 4;
  for (int i = 4; i < N; i++) h[i] = h[i - 1] + 3;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", h[n]);
  }
  return 0;
}