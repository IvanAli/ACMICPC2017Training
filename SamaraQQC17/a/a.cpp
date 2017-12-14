#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int foo; scanf("%d", &foo);
		ans = max(ans, foo);
	}
	printf("%d\n", ans);
	return 0;
}