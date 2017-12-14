#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

int main() {	
	scanf("%d", &n);
	long long tot = 0;
	for (int i = 0; i < n; i++) {
		int foo; scanf("%d", &foo);
		tot += foo;
		if (i & 1) {
			int top = pq.top();
			if (top < foo) {
				pq.pop();
				pq.push(foo);
			}
		} else {
			pq.push(foo);
		}
	}
	long long ansa = 0, ansb = 0;
	while (!pq.empty()) {
		ansa += pq.top();
		pq.pop();
	}
	ansb = tot - ansa;
	printf("%lld %lld\n", ansa, ansb);
	return 0;
}