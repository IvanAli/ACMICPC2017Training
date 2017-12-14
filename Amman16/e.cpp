#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int ans = n / 5 + (n % 5 > 0);
		printf("%d\n", ans); 
	}
	return 0;
}
