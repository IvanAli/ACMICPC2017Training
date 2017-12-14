#include <bits/stdc++.h>
using namespace std;

int c, n;
int leave[105], enter[105], wait[105];

bool ok() {
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 && enter[i] + wait[i] > 0) return false;
		if (leave[i] > cur) return false;
		cur -= leave[i];
		cur += enter[i];
		if (cur > c) return false;
		if (cur < c && wait[i]) return false;
	}
	if (cur == 0) return true;
	return false;
}

int main() {
	scanf("%d%d", &c, &n);
	for (int i = 0; i < n; i++) scanf("%d%d%d", &leave[i], &enter[i], &wait[i]);
	if (ok()) printf("possible\n");
	else printf("impossible\n");
	return 0;
}
