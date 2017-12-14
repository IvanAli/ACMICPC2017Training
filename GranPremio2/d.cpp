#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 100005;

int T;
set<int> st, ans;

bool ok(int n) {
	if (n == 2) return true;
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void gen(int cur = 0, int len = 1) {
	if (cur >= (int) 1e9) return;
	for (int d = (len == 1) ? 0 : 1; d < 10; d++) {
		if (ok(cur + d * len)) {
			st.insert(cur + d * len);
			gen(cur + d * len, len * 10);
		}
	}
}

int rev(int n) {
	int ret = 0;
	while (n) {
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main() {
	gen();
	for (auto it : st) {
		if (st.count(rev(it))) ans.insert(it);
	}
	scanf("%d", &T);
	while (T--) {
		int a, b; scanf("%d%d", &a, &b);
		int bb = distance(ans.begin(), ans.upper_bound(b));
		bb--;
		int aa = distance(ans.begin(), ans.lower_bound(a));
		aa--;
		printf("%d\n", bb - aa);
	}
	return 0;
}
