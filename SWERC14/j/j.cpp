#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1234567;

int hp, wp, hm, wm;
int sz, wsz, elem;
int go[maxn][2];
int fail[maxn];
int wfail[maxn];
int leaf[maxn];
int grid[2005][2005];
int pat[2005][2005];
int which[2005];

int add(string s) {
	int cur = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		int d = s[i] == 'x' ? 0 : 1;
		if (!go[cur][d]) go[cur][d] = ++sz;
		cur = go[cur][d];
	}
	if (leaf[cur] != -1) return leaf[cur];
	leaf[cur] = elem++;
}

int main() {
	cin >> hp >> wp >> hm >> wm;
	memset(leaf, -1, sizeof leaf);
	memset(pat, -1, sizeof pat);
	for (int i = 0; i < hp; i++) {
		string w; cin >> w;
		int key = add(w);
		which[wsz++] = key;
	}
	for (int i = 0; i < hm; i++) {
		string w; cin >> w;
		for (int j = 0; j < wm; j++) grid[i][j] = w[j] == 'x' ? 0 : 1;
	}
	queue<int> q;
	fail[0] = -1;
	for (int i = 0; i < 2; i++) if (go[0][i]) q.push(go[0][i]);
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int i = 0; i < 2; i++) {
			int f = fail[v];
			int to = go[v][i];
			if (to) {
				while (f > -1 && !go[f][i]) f = fail[f];
				if (f < 0) f = 0;
				f = go[f][i];
				fail[to] = f;
				q.push(to);
			}
		}
	}
	for (int i = 0; i < hm; i++) for (int j = 0, k = 0; j < wm; j++) {
		while (k > -1 && !go[k][grid[i][j]]) k = fail[k];
		if (k > -1) k = go[k][grid[i][j]];
		else k = 0;
		if (leaf[k] > -1) pat[i][j] = leaf[k];
	}
	wfail[0] = -1;
	for (int i = 0, j = -1; i < wsz; i++, j++) {
		while (j > -1 && which[i] != which[j]) j = wfail[j];
		wfail[i + 1] = j + 1;
	}
	int ans = 0;
	for (int j = 0; j < wm; j++) for (int i = 0, k = 0; i < hm; i++, k++) {
		while (k > -1 && pat[i][j] != which[k]) k = wfail[k];
		if (k + 1 == wsz) ans++, k = wfail[k + 1], k--;
	}
	cout << ans << endl;
	return 0;
}