#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 1005;
const long long inf = 1ll << 42;

int T;
int n, h, k;
long long x[N], y[N], a[N], b[N], pa[N], pb[N];
int asz, bsz;
long long mem[N][N][505];

long long solve(int i, int k, int h) {
	if (k < 0) return inf;
	if (h < 0) return inf;
	if (i == bsz) {
		return 0;
	}
	if (mem[i][k][h] > -1) return mem[i][k][h];
	long long ret = inf;
	ret = min(ret, solve(i + 1, k, h - x[b[pb[i]]] + y[b[pb[i]]]));
	ret = min(ret, solve(i + 1, k - 1, h));
	return mem[i][k][h] = ret;
	return ret;
}

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
		sort(pb, pb + bsz, [&](const int i, const int j) { return y[b[i]] > y[b[j]]; });
		for (int i = 0; i < asz; i++) {
			if (h < x[a[pa[i]]]) k--;
			else h += y[a[pa[i]]] - x[a[pa[i]]];
		}
		if (k < 0) {
			cout << 'N' << endl;
			continue;
		}
		memset(mem, -1, sizeof mem);
		long long ans = solve(0, k, h);
		if (ans < inf) cout << 'Y' << endl;
		else cout << 'N' << endl;
	}
	return 0;
}