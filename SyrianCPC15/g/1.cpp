#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 305;

int T;
int n;
char grid[3][N];
int cnt[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof cnt);
		scanf("%d", &n);
		for (int i = 0; i < 3; i++) scanf("%s", grid[i]);
		for (int i = 0; i < 3; i++) for (int j = 0; j < n * 3; j++) {
			if (grid[i][j] == '*') cnt[j / 3]++;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) ans = max(ans, cnt[i]);
		printf("%d\n", ans * 4);
	}
	return 0;
}