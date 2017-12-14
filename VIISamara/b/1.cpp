#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N];
int b[N];
int p[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    p[i] = i;
  }
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  sort(p, p + n, [&](const int i, const int j) {
    return a[i] < a[j];
  });
  long long suma = 0, sumb = 0;
  for (int i = 0; i < n; i++) {
    sumb += b[p[i]];
    if (a[p[i]] <= sumb) {
      puts("Redemption");
      return 0;
    }
  }
  puts("Dire victory");
  
  return 0;
}