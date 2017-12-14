#include <bits/stdc++.h>
using namespace std;

unsigned long long x, y;

int main() {
	cin >> x >> y;
	unsigned long long ans = 0;
	for (int i = 1; i <= 63; i++) {
		if ((1LL << i) - 1 <= y) {
			if ((1LL << i) - 1 >= x) ans++;
		} else break;
		for (int j = 1; i + j <= 63; j++) {
			unsigned long long cur = ((1LL << i) - 1);
			int len = 0;
			while (cur <= y) {
				if (len + j > 63) break;
				len += j;
				cur <<= j;
				if (cur >= x && cur <= y) ans++;
				if (len + i > 63) break;
				len += i;
				(cur <<= i) |= ((1LL << i) - 1);
				if (cur >= x && cur <= y) ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
