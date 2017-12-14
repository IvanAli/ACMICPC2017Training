#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int a, b;
vector<int> ans;

int g(int n) {
	return (n * n + n) / 2;
}

void go(int x, int y, int a, int b, bool turn) {
	if (!turn && a == 0) return;
	if (turn && b == 0) return;
	if (!turn) for (int i = 0; i < a; i++) ans.pb(y - a + i + 1);
	else for (int i = 0; i < b; i++) ans.pb(x + b - i - 1);
	if (!turn) go(x, y - a, a - 1, b, !turn);
	else go(x + b, y, a, b - 1, !turn);
}

int main() {
	scanf("%d%d", &a, &b);
	bool rev = false;
	if (a < b) rev = true, swap(a, b);
	go(0, g(a) + g(b - 1) - g(a - b) - 1, a, b - 1, 0);
	int n = ans.size();
	printf("%d\n", n);
	for (int i = 0; i < n; i++) {
		if (i > 0) putchar(' ');
		if (rev) printf("%d", ans[n - i - 1] + 1);
		else printf("%d", ans[i] + 1);
	}
	putchar('\n');
	return 0;
}