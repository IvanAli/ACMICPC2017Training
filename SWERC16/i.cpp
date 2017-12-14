#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 200;
const int maxm = maxn * maxn;
// const int maxm = 19900;
const int maxt = 505;
const long long inf = 1e14;

int n, a, r, t;
long long mat[maxt][maxm + 1];
vector<pair<int, long long> > graph[maxn + 5];
long long dist[maxn + 5];
// int ma[maxn + 5][maxn + 5];
map<pair<int, int>, int> ma;
map<int, pair<int, int> > mb;
int cnt;

long long power(long long base, int ex, int md = 1e9) {
	long long ret = 1;
	long long cur = base;
	while (ex) {
		if (ex & 1) (ret *= cur) %= md;
		(cur *= cur) %= md;
		ex >>= 1;
	}
	return ret;
}

long long inv(long long x) {
	return power(x, 11, 13);
}

vector<long long> gauss() {
	int n = t, m = cnt;
	int where[m];
	memset(where, -1, sizeof where);
	for (int row = 0, col = 0; row < n && col < m; col++) {
		int sel = row;
		// for (int i = row; i < n; i++) if (llabs(mat[i][col]) > llabs(mat[sel][col])) sel = i;
		for (int i = row; i < n; i++) if (mat[i][col] > mat[sel][col]) sel = i;
		if (mat[sel][col] == 0) continue;
		where[col] = row;
		if (sel != row) for (int i = col; i <= m; i++) swap(mat[sel][i], mat[row][i]);
		for (int i = 0; i < n; i++) {
			if (i == row) continue;
			long long c = (mat[i][col] * inv(mat[row][col])) % 13;
			for (int j = col; j <= m; j++) mat[i][j] = (mat[i][j] - ((mat[row][j] * c) % 13) + 13) % 13;
		}
		row++;
	}
	vector<long long> ans(m, 0);
	for (int i = 0; i < m; i++) if (where[i] > -1) ans[i] = (inv(mat[where[i]][i]) * mat[where[i]][m]) % 13;
	for (int i = 0; i < n; i++) {
		long long sum = 0;
		for (int j = 0; j < m; j++) (sum += ((mat[i][j] * ans[j]) % 13)) %= 13;
		if (sum != mat[i][m]) return vector<long long>();
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	// cin >> n >> a >> r >> t;
	scanf("%d%d%d%d", &n, &a, &r, &t);
	a--, r--;
	// int cnt = 0;
	// for (int i = 0; i < maxn; i++) for (int j = i + 1; j < maxn; j++) ma[i][j] = cnt++;
	// memset(ma, -1, sizeof ma);
	vector<int> v;
	for (int i = 0; i < t; i++) {
		int d, p;
		// cin >> d >> p;
		scanf("%d%d", &d, &p);
		int prev = -1;
		for (int j = 0; j < p; j++) {
			int foo;
			// cin >> foo;
			scanf("%d", &foo);
			foo--;
			if (prev != -1) {
				int x = min(prev, foo);
				int y = max(prev, foo);
				if (!ma.count({x, y})) ma[{x, y}] = cnt, mb[cnt] = {x, y}, cnt++;
				// if (ma[x][y] == -1) ma[x][y] = cnt, mb[cnt] = {x, y}, cnt++;
				// mat[i][ma[x][y]]++;
				(mat[i][ma[{x, y}]] += 1) %= 13;
			}
			prev = foo;
		}
		// mat[i][maxm] = d;
		v.pb(d);
	}
	for (int i = 0; i < v.size(); i++) mat[i][cnt] = v[i];
	// for (int i = 0; i < t; i++) {
	// 	for (int j = 0; j < 300; j++) cerr << mat[i][j] << " ";
	// 	cerr << "| " << mat[i][maxm] << endl;
	// }
	vector<long long> ans = gauss();
	assert(!ans.empty());
	for (int i = 0; i < ans.size(); i++) {
		auto z = mb[i];
		int x = z.fst, y = z.snd;
		if (ans[i] == 0) continue;
		// fprintf(stderr, "%d to %d\n", x, y);
		graph[x].pb({y, ans[i]});
		graph[y].pb({x, ans[i]});
	}
	// for (int i = 0, k = 0; i < maxn; i++) for (int j = i + 1; j < maxn; j++, k++) {
	// 	if (ans[k] == 0) continue;
	// 	// assert(k < ans.size());
	// 	// fprintf(stderr, "%d to %d: %lld\n", i, j, ans[k]);
	// 	graph[i].pb({j, ans[k]});
	// 	graph[j].pb({i, ans[k]});
	// }
	// for (int i = 0; i < t; i++) {
	// 	for (int j = 0; j < maxm; j++) cerr << mat[i][j] << " ";
	// 	cerr << "| " << mat[i][maxn] << endl;
	// }
	for (int i = 0; i < n; i++) dist[i] = inf;
	priority_queue<int, vector<pair<int, long long> >, greater<pair<int, long long> > > pq;
	pq.push({0, a});
	dist[a] = 0;
	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		int cur = top.snd;
		long long d = top.fst;
		if (d > dist[cur]) continue;
		for (auto to : graph[cur]) {
			int nxt = to.fst;
			long long dd = to.snd;
			if (dist[cur] + dd < dist[nxt]) dist[nxt] = dist[cur] + dd, pq.push({dist[nxt], nxt});
		}
	}
	// cout << dist[r] << endl;
	printf("%lld\n", dist[r]);
	return 0;
}
