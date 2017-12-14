#include <bits/stdc++.h>
using namespace std;

int n, p, q;
priority_queue<long long> pq;

int main() {
	scanf("%d%d%d", &n, &p, &q);
	for (int i = 0; i < n; i++) {
		int foo; scanf("%d", &foo);
		pq.push(foo);
	}
	long long ans = 0;
	long long off = 0;
	while (!pq.empty()) {
		long long top1 = pq.top(); pq.pop();
		if (p == q) {
			ans = top1 / p;
			if (top1 % p > 0) ans++;
			break;
		}
		if (pq.empty()) pq.push(0);
		long long top2 = pq.top();
		if (top1 <= off) break;
		long long t;
		if (top2 <= off) {
			t = (top1 - off) / p;
			if ((top1 - off) % p > 0) t++;
		} else {
			if (top1 == top2) t = 1;
			else {
				t = (top1 - top2) / (p - q);
				if ((top1 - top2) % (p - q) > 0) t++;
			}
		}
		ans += t;
		pq.push(top1 - t * (p - q));
		off += t * q;
	}
	printf("%lld\n", ans);
	return 0;
}