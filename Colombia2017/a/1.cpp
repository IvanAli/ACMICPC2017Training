#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MAX = 19;

int n;
int tree[N << 4][10];
int sz;
int cnt[N << 4];
char ss[N][25];
int len[N];

void insert(int w) {
  int id = 1;
  for (int i = 0; i < len[w]; i++) {
    int d = ss[w][i] - '0';
    if (tree[id][d] == 0) tree[id][d] = sz++;
    id = tree[id][d];
    cnt[id]++;
  }
}

void erase(int w) {
  int id = 1;
  for (int i = 0; i < len[w]; i++) {
    int d = ss[w][i] - '0';
    assert(tree[id][d] > 0);
    id = tree[id][d];
    cnt[id]--;
  }
}

long long go_max(int w) {
  long long ret = 0;
  int id = 1;
  for (int i = 0; i < len[w]; i++) {
    int d = ss[w][i] - '0';
    int mx = -1;
    for (int j = 0; j < 10; j++) {
      int nd = d + j;
      if (nd >= 10) nd -= 10;
      if (tree[id][j] > 0 && cnt[tree[id][j]] > 0) {
        if (mx == -1) {
          mx = j;
        } else if (nd > (d + mx) % 10) {
          mx = j;
        }
      }
    }
    int nd = d + mx;
    if (nd >= 10) nd -= 10;
    ret = ret * 10 + nd;
    assert(mx > -1);
    id = tree[id][mx];
  }
  return ret;
}

long long go_min(int w) {
  long long ret = 0;
  int id = 1;
  for (int i = 0; i < len[w]; i++) {
    int d = ss[w][i] - '0';
    int mn = -1;
    for (int j = 0; j < 10; j++) {
      int nd = d + j;
      if (nd >= 10) nd -= 10;
      if (tree[id][j] > 0 && cnt[tree[id][j]] > 0) {
        if (mn == -1) {
          mn = j;
        } else if (nd < (d + mn) % 10) {
          mn = j;
        }
      }
    }
    int nd = d + mn;
    if (nd >= 10) nd -= 10;
    ret = ret * 10 + nd;
    assert(mn > -1);
    id = tree[id][mn];
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  sz = 2;
  for (int i = 0; i < n; i++) {
    scanf("%s", ss[i]);
    len[i] = strlen(ss[i]);
    int k = MAX - len[i];
    for (int j = len[i] - 1; j >= 0; j--) {
      ss[i][j + k] = ss[i][j];
    }
    for (int j = 0; j < k; j++) ss[i][j] = '0';
    len[i] = strlen(ss[i]);
    assert(len[i] == MAX);
    insert(i);
  }
  long long mx = 0;
  long long mn = (long long) 2e18;
  for (int i = 0; i < n; i++) {
    erase(i);
    mx = max(mx, go_max(i));
    mn = min(mn, go_min(i));
    insert(i);
  }
  printf("%lld %lld\n", mn, mx);
  return 0;
}