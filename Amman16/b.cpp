#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int n;
int T;
char s[maxn];
int ma[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[3] = {9, 7, 1};
int cnt[10];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s);
		for (int i = 0; i < 10; i++) cnt[i] = 0;
		int k = 0;
		int tot = 0;
		for (int i = 0; i < n; i++) tot += ma[s[i] - '0'];
		int cur = 0;
		for (int i = 0; i < n; i++) {
			int rem = n - i - 1;
			while (k < 3 && tot - cur - ma[a[k]] < rem * 2) k++;
			assert(k < 3);
			cur += ma[a[k]];
			cnt[a[k]]++;
		}
		if (a[k] == 9) {
			while (cur < tot) cnt[9]--, cnt[8]++, cur++;
			assert(cur == tot);
		} else if (a[k] == 7) {
			while (cur < tot) cnt[7]--, cnt[5]++, cur += 2;
			if (cur > tot) cnt[5]--, cnt[4]++, cur--;
			assert(cur == tot);
		}
		for (int i = 9; i >= 0; i--) for (int j = 0; j < cnt[i]; j++) printf("%d", i);
		printf("\n");
	}
	return 0;
}
