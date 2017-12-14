#include <bits/stdc++.h>
using namespace std;

int n, m;
int sz[2];
int cnt[2][26];
int tree[2][123456][26];
char s[1005];

void add(int t) {
	int cur = 0;
	int len = strlen(s);
	if (t == 1) for (int i = 0; i * 2 < len; i++) swap(s[i], s[len - i - 1]);
	for (int i = 0; i < len; i++) {
		if (!tree[t][cur][s[i] - 'a']) {
			if (cur) cnt[t][s[i] - 'a']++;
			tree[t][cur][s[i] - 'a'] = sz[t]++;
		}
		cur = tree[t][cur][s[i] - 'a'];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (scanf("%d%d", &n, &m) && n + m > 0) {
		memset(tree, 0, sizeof tree);
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < 2; i++) sz[i] = 1;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			add(0);
		}
		for (int i = 0; i < m; i++) {
			scanf("%s", s);
			add(1);
		}
		long long ans = (long long)(sz[0] - 1) * (sz[1] - 1);
		for (int i = 0; i < 26; i++) ans -= (long long)cnt[0][i] * cnt[1][i];
		printf("%lld\n", ans);
	}
	return 0;
}