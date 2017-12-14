#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 100005;

int n, b;
int tot;

int main() {
	while (scanf("%d%d", &n, &b) && n + b > 0) {
		tot = 0;
		for (int i = 0; i < n; i++) {
			int foo; scanf("%d", &foo);
			tot += foo;
		}
		int ans = b / tot;
		printf("%d\n", ans);
	}
	return 0;
}
