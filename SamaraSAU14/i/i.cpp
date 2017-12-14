#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int> pq;

int main() {
	scanf("%d", &n);
	int prv = -1;
	int cur = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int t, d; scanf("%d%d", &t, &d);
		if (prv == -1) cur = t;
		else cur += t - prv;
		if (cur >= d) pq.push(d), cur -= d;
		else {
			ans++;
			if (!pq.empty()) {
				int top = pq.top();
				if (top > d) {
					cur += top; pq.pop();
					cur -= d;
					pq.push(d);
				}
			}
		}
		prv = t;
	}
	printf("%d\n", ans);
	return 0;
}