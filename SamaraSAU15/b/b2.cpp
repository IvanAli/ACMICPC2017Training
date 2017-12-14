// this doesn't work D:
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 105;

int n;
set<int> have[maxn];
int match[maxn];
int used[maxn];


bool solve(int v) {
	for (int i = 0; i < n; i++) {
		if (used[i]) continue;
		used[i] = 1;
		if (match[i] == -1 || solve(match[i])) {
			match[i] = v;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n;
	memset(match, -1, sizeof match);
	int times = 0;
	for (int i = 0; i < n; i++) {
		memset(used, 0, sizeof used);
		times += solve(i);
	}
	assert(times == n);
	vector<pair<int, int>> query;
	for (int i = 0; i < n; i++) {
		assert(match[i] > -1);
		if (match[i] < i) query.pb({match[i], i});
	}
	sort(query.begin(), query.end(), [&](const pair<int, int>& a, const pair<int, int> b) { return a.snd - a.fst > b.snd - b.fst; });
	for (int i = 0; i < query.size(); i++) {
		pair<int, int> q = query[i];
		int l = q.fst, r = q.snd - 1;
		cout << 'Q' << ' ' << l + 1 << ' ' << r + 1 << endl;
		cout.flush();
		set<int> res;
		for (int j = 0; j < r - l + 1; j++) {
			int foo; cin >> foo; foo--;
			res.insert(foo);
			for (int it = 0; it < 100; it++) {
				if (it >= l && it <= r) have[it].insert(foo);
				else have[it].erase(foo);
			}
		}
		for (int j = 0; j < n; j++) {
			if (!res.count(j)) for (int it = 0; it < 100; it++) {
				if (it >= l && it <= r) have[it].erase(j);
				else have[it].insert(j);
			}
		}
	}
	cout << 'A';
	for (int i = 0; i < n; i++) {
		assert(have[i].size() == 1);
		cout << ' ';
		cout << *have[i].begin();
	}
	cout << endl;
	return 0;
}