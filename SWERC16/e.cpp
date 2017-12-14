#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define INF 1e9
using namespace std;

const int maxn = 1234;
const int mod = 1000003;

int a, b, n;
int sz;
bool leaf[maxn];
int go[maxn][26];
int fail[maxn];
int memo[25][2][2][2][maxn];

void add(string s) {
	int id = 1;
	for (int i = 0; i < s.size(); i++) {
		int cur = s[i] - 'a';
		if (go[id][cur] == 0) go[id][cur] = ++sz;
		id = go[id][cur];
	}
	leaf[id] = 1;
}

int solve(int len, int i = 0, bool lo = 0, bool up = 0, bool di = 0, int st = 1) {
	if (st >= maxn) assert(0);
	assert(st > 0);
	if (leaf[st]) return 0;
	if (i > len) return 0;
	if (memo[i][lo][up][di][st] != -1) return memo[i][lo][up][di][st];
	int ret = 0;
	if (lo && up && di) ret++;
	for (int j = 0; j < 26; j++) {
		int k = st;
		while (k >= 1 && go[k][j] == 0) k = fail[k];
		(ret += solve(len, i + 1, true, up, di, go[k][j])) %= mod;
		(ret += solve(len, i + 1, lo, true, di, go[k][j])) %= mod;
	}
	for (int j = 0; j <= 9; j++) {
		int k = st;
		if (j == 0) {
			while (k >= 1 && go[k][(int)('o' - 'a')] == 0) k = fail[k];
			(ret += solve(len, i + 1, lo, up, true, go[k][(int)('o' - 'a')])) %= mod;
		} else if (j == 1) {
			while (k >= 1 && go[k][(int)('i' - 'a')] == 0) k = fail[k];
			(ret += solve(len, i + 1, lo, up, true, go[k][(int)('i' - 'a')])) %= mod;
		} else if (j == 3) {
			while (k >= 1 && go[k][(int)('e' - 'a')] == 0) k = fail[k];
			(ret += solve(len, i + 1, lo, up, true, go[k][(int)('e' - 'a')])) %= mod;
		} else if (j == 5) {
			while (k >= 1 && go[k][(int)('s' - 'a')] == 0) k = fail[k];
			(ret += solve(len, i + 1, lo, up, true, go[k][(int)('s' - 'a')])) %= mod;
		} else if (j == 7) {
			while (k >= 1 && go[k][(int)('t' - 'a')] == 0) k = fail[k];
			(ret += solve(len, i + 1, lo, up, true, go[k][(int)('t' - 'a')])) %= mod;
		} else {
			(ret += solve(len, i + 1, lo, up, true, 1)) %= mod;
		}
	}
	return memo[i][lo][up][di][st] = ret;
}

int main() {
	cin >> a >> b;
	cin >> n;
	sz = 1;
	for (int i = 0; i < n; i++) {
		string w;
		cin >> w;
		add(w);
	}
	fail[1] = 0;
	queue<int> q;
	for (int i = 0; i < 26; i++) if (go[1][i] > 0) fail[go[1][i]] = 1, q.push(go[1][i]);
	for (int i = 0; i < 26; i++) go[0][i] = 1;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int c = 0; c < 26; c++) {
			if (go[cur][c] > 0) {
				int nxt = go[cur][c];
				int j = fail[cur];
				while (j >= 1 && go[j][c] == 0) j = fail[j];
				fail[nxt] = go[j][c];
				leaf[nxt] |= leaf[fail[nxt]];
				q.push(nxt);
			}
		}
	}
	memset(memo, -1, sizeof memo);
	int ans = solve(b);
	memset(memo, -1, sizeof memo);
	ans -= solve(a - 1);
	cout << ans << endl;
	return 0;
}
