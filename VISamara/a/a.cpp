#include <bits/stdc++.h>
using namespace std;

const int maxn = 2005;

int n, k;

int main() {
//	this problem made no sense to me
	scanf("%d%d", &n, &k);
	if (n == 1) printf("0\n");
	else if (n == k) printf("-1\n");
	else if (k == 1) printf("%d\n", n - 1);
	else if (n % k == 0 || n % k == 1) printf("%d\n", n / k);
	else printf("%d\n", n / k + 1);
	return 0;
}