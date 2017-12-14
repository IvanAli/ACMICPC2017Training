#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 200005;

int n;
int a[N];
map<long long, int> pre;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	long long cur = 0;
	int ans = 1 << 30;
	int start = -1;
	for (int i = 0; i <= n; i++) {
		cur += a[i];
		if (pre.count(cur)) {
			if (i - pre[cur] < ans) {
				start = pre[cur];
				ans = i - pre[cur];
			}
		}
		pre[cur] = i;
	}
	if (ans == 1 << 30) printf("-1\n");
	else printf("%d %d\n", start + 1, ans);
	return 0;
}