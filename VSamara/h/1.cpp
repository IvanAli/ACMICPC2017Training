#include <bits/stdc++.h>

using namespace std;

const int Z = 26;
const int N = 1234567;

char s[N];
int have[Z];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int k;
  scanf("%d", &k);
  scanf("%s", s);
  int n = strlen(s);
  int cnt = 0;
  int ans = 0;
  int l = -1, r = -1;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && cnt == k + 1) {
      have[s[j] - 'a']--;
      if (have[s[j] - 'a'] == 0) cnt--;
      j++;
    }
    have[s[i] - 'a']++;
    if (have[s[i] - 'a'] == 1) cnt++;
    if (i - j + 1 > ans && cnt <= k) {
      ans = i - j + 1;
      l = j;
      r = i;
    }
  }                           
  assert(l > -1 && r > -1);
  printf("%d %d\n", l + 1, r + 1);
  return 0;
}