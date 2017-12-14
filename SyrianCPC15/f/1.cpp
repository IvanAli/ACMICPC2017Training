#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 15;

int T;
int cnt[N];
char s[N];
int p[N];

bool valid() {
	for (int i = 1; i <= 7; i++) if (p[p[i]] != i) return false;
	return true;
}

bool solve() {
	for (int i = 1; i < N; i++) cnt[i] = 0;
	for (int i = 1; i <= 7; i++) {
		if (p[i] == i) cnt[s[i - 1] - 'A' + 1]++;
		else if (i < p[i]) cnt[s[p[i] - 1] - 'A' + 1 + s[i - 1] - 'A' + 1]++;
	}
	for (int i = 1; i <= 5; i++) if (cnt[i] == 0) return false;
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		for (int i = 1; i <= 7; i++) p[i] = i;
		bool ok = false;
		do {
			if (!valid()) continue;
			if (solve()) {
				ok = true;
				break;
			}
		} while (next_permutation(p + 1, p + 7 + 1));
		if (ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}