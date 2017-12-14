#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;


int main() {
	scanf("%d", &T);
	while (T--) {
		int x, y; scanf("%d%d", &x, &y);
		int ans = max(x, y) * max(x, y);
		printf("%d\n", ans);
	}
	return 0;
}