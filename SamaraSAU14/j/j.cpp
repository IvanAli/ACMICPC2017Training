#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n;
int a[maxn], b[maxn];

int main() {
	scanf("%d", &n);
	int prv = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		if (a[i] > prv) ans = max(ans, b[i]), prv = a[i];
	}
	printf("%d\n", ans);
	return 0;
}