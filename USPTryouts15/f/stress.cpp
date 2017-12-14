#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 2005;

int T;
int n, h, k;
long long x[N], y[N], a[N], b[N], pa[N], pb[N];
int asz, bsz;
long long dp[N][N];

void print() {
	for (int i = 0; i < bsz; i++) cerr << '(' << x[b[pb[i]]] << ',' << y[b[pb[i]]] << ')' << endl;
}

bool mem[N / 2][N / 2][505];
bool was[N / 2][N / 2][505];

bool solve(int i, int k, int h) {
	if (k < 0) return false;
	if (h < 0) return false;
	if (i == bsz) return true;
	if (was[i][k][h]) return mem[i][k][h];
	long long ret = false;
	if (h >= x[b[pb[i]]]) ret |= solve(i + 1, k, h - x[b[pb[i]]] + y[b[pb[i]]]);
	ret |= solve(i + 1, k - 1, h);
	was[i][k][h] = true;
	return mem[i][k][h] = ret;
}

long long have[N][N];

int main() {
	cin >> T;
	while (T--) {
		asz = 0, bsz = 0;
		cin >> n >> h >> k;
		for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
		for (int i = 0; i < n; i++) if (x[i] <= y[i]) a[asz++] = i; else b[bsz++] = i;
		for (int i = 0; i < asz; i++) pa[i] = i;
		for (int i = 0; i < bsz; i++) pb[i] = i;
		sort(pa, pa + asz, [&](const int i, const int j) { return x[a[i]] < x[a[j]]; });
		sort(pb, pb + bsz, [&](const int i, const int j) { return y[b[i]] >= y[b[j]]; });
		for (int i = 0; i < asz; i++) {
			if (h < x[a[pa[i]]]) k--;
			else h += y[a[pa[i]]] - x[a[pa[i]]];
		}
		if (k < 0) {
			cout << 'N' << endl;
			continue;
		}
		for (int i = 1; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = 1ll << 42;
		memset(have, 0, sizeof have);
		for (int i = 0; i < bsz; i++) for (int j = k; j >= 0; j--) {
			long long sol;
			sol = dp[i][j] + max(0ll, x[b[pb[i]]] - have[i][j]);
			if (sol < dp[i + 1][j]) {
				dp[i + 1][j] = sol;
				have[i + 1][j] = max(x[b[pb[i]]], have[i][j]) - x[b[pb[i]]] + y[b[pb[i]]];
			}
			if (j > 0) {
				sol = dp[i][j];
				if (sol < dp[i + 1][j - 1]) {
					dp[i + 1][j - 1] = sol;
					have[i + 1][j - 1] = have[i][j];				
				}
			}
		}
		long long ans = dp[bsz][0];
		memset(mem, -1, sizeof mem);
		memset(was, false, sizeof was);
		bool ans2 = solve(0, k, h);
		if (ans <= h) {
			if (!ans2) {
				cerr << "ans1 could but ans2 couldnt" << endl;
				cerr << "n: " << bsz << endl;
				cerr << "k: " << k << endl;
				cerr << "h: " << h << endl;
				print();
				assert(0);
			}
		} else {
			if (ans2) {
				cerr << "ans1 couldnt but ans2 could" << endl;
				cerr << "n: " << bsz << endl;
				cerr << "k: " << k << endl;
				cerr << "h: " << h << endl;
				print();
				assert(0);
			}
		}
	}
	return 0;
}