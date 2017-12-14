#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int s, b;
int lef[maxn], rig[maxn];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (scanf("%d%d", &s, &b) && s + b > 0) {
		for (int i = 1; i <= s; i++) lef[i] = i - 1, rig[i] = i + 1;
		for (int i = 0; i < b; i++) {
			lef[1] = -1, rig[s] = -1;
			int x, y; scanf("%d%d", &x, &y);
			int lans = lef[x], rans = rig[y];
			if (lef[x] > -1) rig[lef[x]] = rig[y];
			if (rig[y] > -1) lef[rig[y]] = lef[x];
			if (lans > -1) printf("%d ", lans);
			else printf("* ");
			if (rans > -1) printf("%d\n", rans);
			else printf("*\n");
		}
		printf("-\n");
	}
	return 0;
}