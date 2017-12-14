#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int n;
int ans[maxn];

int main() {
	scanf("%d", &n);
	memset(ans, -1, sizeof ans);
	for (long long i = 0; i < n; i++) {
		int res = (i * i) % n;
		ans[res] = i;
	}
	for (int i = 0; i < n; i++) {
		if (i > 0) printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}