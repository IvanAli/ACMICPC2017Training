#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back

using namespace std;

const int N = 1e5;

int val[N + 11];
pair<int, int> curr[N + 11];
int cnt[N + 11];

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k; cin >> n >> k;
	fill(val, val + n, -1);
	fill(curr, curr + n, make_pair(-1, -1));
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	for (int i = 0; i < k; i++) {
		pq.push({0, i});
	}
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		auto fr = pq.top(); pq.pop();
		int desk = fr.snd;
		cout << desk + 1 << " ";
		val[i] = p;
		cnt[desk]++;
		swap(curr[desk].fst, curr[desk].snd);
		curr[desk].snd = i;
		double new_p = (p+(curr[desk].fst == -1 ? p : val[curr[desk].fst]))/2. * (double)cnt[desk];
		//cout << "para " << desk+1 << " newp: " << new_p << endl;
		pq.push({new_p, desk});
	}
	cout << endl;
	return 0;
}
