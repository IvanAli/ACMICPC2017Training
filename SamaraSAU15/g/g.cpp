#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n, s;
int a[maxn];

int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += s % a[i];
		s /= a[i];
	}
	ans += s;
	printf("%d\n", ans);
	return 0;
}