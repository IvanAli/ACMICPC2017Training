#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int c, d;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &c, &d);
		if (c == 0 && d == 0) return printf("0\n"), 0;
		int ans = 1;
		for (int i = 0; i < c; i++) ans *= 26;
		printf("%d", ans);
		for (int i = 0; i < d; i++) printf("0");
		putchar('\n');
	}
	return 0;
}