#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n;
int a[N];

int main() {
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++) {
		printf("Case %d: ", tc + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		int ans = 0;
		for (int i = 30; i >= 0; i--) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (a[j] & (1 << i)) cnt++;
			}
			if (cnt & 1) {
				ans = cnt;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}