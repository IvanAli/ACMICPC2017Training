#include <bits/stdc++.h>
using namespace std;

const int maxknm = 250005;
const int maxk = 505;
const int maxn = 505;
const int maxm = 505;

int k, n, m;
//char grid[maxk][maxn][maxm];
vector<vector<vector<char>>> grid;
//int ans[3500][3500];
//bool was[3500][3500];
vector<vector<int>> ans;
vector<vector<bool>> was;
int t[maxknm];
int p[maxknm];
//char s[maxknm];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> k >> n >> m;
	grid = vector<vector<vector<char>>>(k + 5, vector<vector<char>>(n + 5, vector<char>(m + 5)));
	ans = vector<vector<int>>(n + 5, vector<int>(m + 5));
	was = vector<vector<bool>>(n + 5, vector<bool>(m + 5));
	if ((long long)k * n * m > 200000) assert(0);
	assert(grid.size() == k + 5);
	assert(grid[0].size() == n + 5);
	assert(grid[0][0].size() == m + 5);
	assert(ans.size() == n + 5);
	assert(ans[0].size() == m + 5);
	for (int it = 0; it < k; it++) {
		p[it] = it;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < m; j++) grid[it][i][j] = s[j] - '0';
		}
	}
	sort(p, p + k, [&](const int& a, const int& b) {
		int cnta = 0, cntb = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnta += grid[a][i][j], cntb += grid[b][i][j];
		return cnta > cntb;
	});
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) was[i][j] = grid[p[0]][i][j];
	for (int it = 0; it < k; it++) {
		int where = p[it];
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			if (grid[where][i][j] == 1 && !was[i][j]) return cout << "IMPOSSIBLE" << endl, 0;
			was[i][j] = grid[where][i][j];
			ans[i][j] += grid[where][i][j];
		}
		t[where] = it + 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j > 0) cout << ' ';
			cout << ans[i][j];
		}
		cout << '\n';
	}
	for (int i = 0; i < k; i++) {
		if (i > 0) cout << ' ';
		cout << t[i];
	}
	cout << '\n';
	return 0;
}