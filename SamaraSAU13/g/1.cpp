#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 200005;

int n;
char s[N];
int cnt[26];

int main() {
	scanf("%s", s);
	n = strlen(s);
	if (n > 26) return printf("IMPOSSIBLE\n"), 0;
	memset(cnt, -1, sizeof cnt);
	for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
	for (int i = 0, j = 0; i < n; i++) if (cnt[s[i] - 'a'] > 0) {
		while (j < 26 && cnt[j] > -1) j++;
		if (j == 26) return printf("IMPOSSIBLE\n"), 0;
		cnt[j]++;
		cnt[s[i] - 'a']--;
		s[i] = j + 'a';
	}
	printf("%s\n", s);
	return 0;
}