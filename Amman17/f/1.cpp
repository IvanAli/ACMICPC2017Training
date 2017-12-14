#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int T;
int n, k;
int a[N];
map<int, int> last;
int nxt[N];
set<int> st;

int main() {
  scanf("%d", &T);
  while (T--) {
    st.clear();
    last.clear();
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) last[a[i]] = n;
    for (int i = n - 1; i >= 0; i--) {
      nxt[i] = last[a[i]];
      last[a[i]] = i;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (st.count(i)) {
        st.erase(i);
        st.insert(nxt[i]);
      } else {
        ans++;
        if ((int) st.size() < k) {
          st.insert(nxt[i]);
        } else {
          st.erase(--st.end());
          st.insert(nxt[i]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}