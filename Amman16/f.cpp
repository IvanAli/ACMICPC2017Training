#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int T;
char s[maxn];
int cnt[maxn][26];
int n;

void go() {
	for (int i = 0; i < n; i++) {
		int cur = s[i] - 'a';
		for (int j = 0; j < cur; j++) if (cnt[i][j] == 0 && cnt[n - 1][j] > 0) {
			for (int it = 0; it < n; it++) {
				if (s[it] - 'a' == j) putchar(cur + 'a');
				else if (s[it] - 'a' == cur) putchar(j + 'a');
				else putchar(s[it]);
			}
			putchar('\n');
			return;
		}
	}
	printf("%s\n", s);
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 26; j++) cnt[i][j] = 0;
			cnt[i][s[i] - 'a']++;
			if (i > 0) for (int j = 0; j < 26; j++) cnt[i][j] += cnt[i - 1][j];
		}
		go();
	}
	return 0;
}
