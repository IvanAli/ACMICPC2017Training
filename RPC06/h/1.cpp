#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int T;
int n;
int a[N];

long long inv;

void merge_part(int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  vector<int> L(n1 + 2);
  vector<int> R(n2 + 2);
  for (int i = 1; i <= n1; i++) L[i] = a[p + i - 1];
  for (int i = 1; i <= n2; i++) R[i] = a[q + i];
  L[n1 + 1] = 1 << 30;
  R[n2 + 1] = 1 << 30;
  int i = 1;
  int j = 1;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = R[j];
      j++;
      inv += n1 - i + 1;
    } 
  }
}

void merge_sort(int p, int r) {
  if (p < r) {
    int q = p + r >> 1;
    merge_sort(p, q);
    merge_sort(q + 1, r);
    merge_part(p, q, r);
  }
}
  

int main() {
  while (scanf("%d", &n) && n > 0) {
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    inv = 0;
    merge_sort(1, n);
    printf("%lld\n", inv);
  }
  return 0;
}