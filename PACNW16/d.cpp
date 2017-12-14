#include <bits/stdc++.h>
using namespace std;


const int maxn = 100005;

int n, k, r;
int fen[maxn];

void add(int i) {
	while (i <= n) {
		fen[i] += 1;
		i += i & -i;
	}
}

int get(int i) {
	int ret = 0;
	while (i > 0) {
		ret += fen[i];
		i -= i & -i;
	}
	return ret;
}

int main() {
	cin >> n >> k >> r;
	for (int i = 0; i < k; i++) {
		int foo;
		cin >> foo;
		add(foo);
	}
	int ans = 0;
	for (int i = 1; i + r - 1 <= n; i++) {
		int high = get(i + r - 1);
		int low = i > 1 ? get(i - 1) : 0;
		int cnt = high - low;
		int j = i + r - 1;
		while (cnt < 2) {
			ans++;
			while (j > i && get(j) - (j > 1 ? get(j - 1) : 0) > 0) j--;
			add(j);
			cnt++;
		}
	}
	cout << ans << endl;
	return 0;
}