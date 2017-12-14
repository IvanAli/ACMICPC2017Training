#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  vector<char> ans;
  while (n > 1) {
    if (n % 2) {
      ans.push_back('A');
      n /= 2;
    } else {
      ans.push_back('B');      
      n = n / 2 - 1;
    }
  }
  if (n == 1) ans.push_back('A');
  reverse(ans.begin(), ans.end());
  for (auto it : ans) putchar(it);
  puts("");
  return 0;
}