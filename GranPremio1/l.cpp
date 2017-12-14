#include <bits/stdc++.h>
using namespace std;

int T;
bool have[35];
unsigned long long n;

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(have, 0, sizeof have);
		scanf("%llu", &n);
		unsigned long long tmp = n;
		n <<= 32ll;
		n |= tmp;
		long long mask = (1 << 5) - 1;
		long long smask = (1 << 5) - 1;
		for (long long i = 0; i < 32; i++) {
			unsigned long long cur = n & mask;
			cur >>= i;
			cur &= smask;
			have[cur] = 1;
			assert(cur < 32);
			mask <<= 1;
		}
		int ans = 0;
		for (int i = 0; i < 32; i++) ans += have[i];
		if (ans == 32) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
