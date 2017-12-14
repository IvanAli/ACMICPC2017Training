#include <bits/stdc++.h>
#define fst first
#define pb push_back
#define snd second
using namespace std;

const int maxc = 1000005;

int T;
int c, m;
int have[maxc];
priority_queue<pair<long long, int> > pq;

int main() {
	cin >> T;
	while (T--) {
		memset(have, 0, sizeof have);
		vector<int> ans;
		cin >> c >> m;
		for (int i = 0; i < c; i++) {
			int foo; cin >> foo;
			have[foo]++;
		}
		while (!pq.empty()) pq.pop();
		for (long long i = 1; i < maxc; i++) if (have[i]) pq.push({i * have[i], i});
		while (!pq.empty() && m > 0) {
			auto top = pq.top(); pq.pop();
			ans.pb(top.snd);
			m -= top.fst;
		}
		if (m > 0) cout << "Impossible" << endl;
		else {
			sort(ans.begin(), ans.end());
			for (auto i : ans) cout << i << " ";
			cout << endl;
		}
	}
	return 0;
}