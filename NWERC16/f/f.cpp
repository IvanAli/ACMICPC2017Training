#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000005;

int n;
int a[maxn], b[maxn];

bool ok(int x) {
	int las;
	las = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= x) continue;
		if (las == -1) las = a[i];
		else {
			if (a[i] != las) return false;
			las = -1;
		}
	}
	if (las != -1) return false;
	las = -1;
	for (int i = 0; i < n; i++) {
		if (b[i] <= x) continue;
		if (las == -1) las = b[i];
		else {
			if (b[i] != las) return false; 
			las = -1;
		}
	}
	return las == -1;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	int low = 0, high = 1000000000, mid;
	while (low < high) {
		mid = low + high >> 1;
		if (ok(mid)) high = mid;
		else low = mid + 1;
	}
	printf("%d\n", low);
	return 0;
}