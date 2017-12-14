#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int n;
int b[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		b[x]++;
	}
	for (int i = 1; i < maxn; i++) b[i] += b[i - 1];
	int ans = n;
	for (int i = 1; i < maxn; i++) {
		ans = min(ans, n - b[i] + i);
	}
	printf("%d\n", ans);
	return 0;
}
