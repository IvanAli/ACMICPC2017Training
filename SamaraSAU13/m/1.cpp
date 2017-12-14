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
map<int, int> ma;
int close[N];
int dp[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	memset(close, -1, sizeof close);
	for (int i = 0; i < n; i++) {
		if (ma.count(a[i])) close[i] = ma[a[i]];
		ma[a[i]] = i;
	}
	for (int i = 0; i < n; i++) dp[i + 1] = 1 << 30;
	for (int i = 0; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (close[i] > -1) dp[i + 1] = min(dp[i + 1], dp[close[i] + 1] + 1);
	}
	printf("%d\n", dp[n] - 1);
	return 0;
}