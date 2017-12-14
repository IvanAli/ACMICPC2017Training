#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int T, n;
int a[maxn];

int main() {
	freopen("cubes.in", "r", stdin);
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, greater<int>());
		cout << "Case " << tt + 1 << ":" << endl;
		deque<int> q1, q2;
		for (int i = 0, k = 0; i < n; i++, k ^= 1) {
			if (k & 1) q1.push_front(a[i]);
			else q2.push_back(a[i]);
		}
		bool ok;
		vector<int> v;
		while (!q1.empty()) {
			if (ok) cout << " ";
			int ft = q1.back(); q1.pop_back();
			v.push_back(ft);
		}
		while (!q2.empty()) {
			int ft = q2.back(); q2.pop_back();
			v.push_back(ft);
		}		
		for (int i = 0; i < v.size(); i++) {
			if (i > 0) cout << " ";
			cout << v[i];
		}	
		cout << endl;
	}
	return 0;
}