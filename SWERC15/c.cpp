#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

int T;
int n;
int a[maxn];

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long> > pq;
		for (int i = 0; i < n; i++) cin >> a[i], pq.push(a[i]);
		long long ans = 0;
		while (!pq.empty()) {
			long long f = pq.top(); pq.pop();
			ans += f;
			if (pq.empty()) break;
			long long s = pq.top(); pq.pop();
			ans += s;
			pq.push(f + s);
		}
		for (int i = 0; i < n; i++) ans -= a[i];
		cout << ans << endl;
	}
	return 0;
}
