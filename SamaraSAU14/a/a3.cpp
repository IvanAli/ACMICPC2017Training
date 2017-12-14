#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 200005;

int n;
int a[maxn][3];
vector<int> va, vb;
int ans[maxn];
int sz;
 
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
		sort(a[i], a[i] + 3);
		va.pb(a[i][0]);
		vb.pb(a[i][1]);
	}
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());
	for (int i = 0; i < n; i++) {
		auto ita = lower_bound(va.begin(), va.end(), a[i][1]);
		auto itb = lower_bound(vb.begin(), vb.end(), a[i][2]);
		if (ita == va.end() && itb == vb.end()) {
			ans[sz++] = i;
		}
	}
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++) {
		if (i > 0) putchar(' ');
		printf("%d", ans[i] + 1);
	}
	putchar('\n');
	return 0;
}