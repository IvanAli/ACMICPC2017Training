#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int n, m;
int test[N][66];
int len[N];
int have[66];

long long get(int mask, int w) {
  long long ret = 0;
  for (int i = 0; i < (n + w) / 2; i++) {
    if (mask & (1 << i)) {
      for (int j = 0; j < len[i + w * (n / 2)]; j++) {
        ret |= 1ll << test[i + w * (n / 2)][j];
      }
    }
  }
  return ret;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int k; scanf("%d", &k);
    len[i] = k;
    for (int j = 0; j < k; j++) {
      int x; scanf("%d", &x);
      x--;
      test[i][j] = x;
    }
  }
  int ans = (1 << N) - 1;
  vector< pair<int, long long> > va, vb;
  for (int mask = 1; mask < 1 << (n / 2); mask++) {
    va.push_back(make_pair(mask, get(mask, 0)));
  }
  for (int mask = 1; mask < 1 << ((n + 1) / 2); mask++) {
    vb.push_back(make_pair(mask, get(mask, 1)));
  }
  for (auto a : va) {
    long long c = a.second;
    if (__builtin_popcountll(c) == m) {
      if (__builtin_popcount(a.first) < __builtin_popcount(ans)) {
        ans = a.first;
      }
    }
  }
  for (auto b : vb) {
    long long c = b.second;
    if (__builtin_popcountll(c) == m) {
      if (__builtin_popcount(b.first) < __builtin_popcount(ans)) {
        ans = b.first << (n / 2);
      }
    }
  }
  for (auto a : va) {
    for (auto b : vb) {
      long long c = a.second | b.second;
      if (__builtin_popcountll(c) == m) {
        if (__builtin_popcount(a.first) + __builtin_popcount(b.first) < __builtin_popcount(ans)) {
          ans = a.first | (b.first << (n / 2));
        }
      }
    }
  }
  printf("%d\n", __builtin_popcount(ans));
  for (int i = 0; i < n; i++) {
    if (ans & (1 << i)) {
      printf("%d ", i + 1);
    }
  }
  puts("");
  return 0;
}