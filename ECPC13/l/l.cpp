#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 10005;

int T;
int n;
char ch[maxn];
int len[maxn], mul[maxn], add[maxn];
vector<pair<int, int> > state[26];
bool bravo[maxn];

int main() {
	freopen("mahdi.in", "r", stdin);
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		for (int i = 0; i < 26; i++) state[i].clear();
		memset(bravo, false, sizeof bravo);
		char c; int lent, mult, addt;
		cin >> c >> lent >> mult >> addt;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> ch[i] >> len[i] >> mul[i] >> add[i]; 
			state[ch[i] - 'a'].pb({i, 0});
		}
		for (int i = 0; i < lent; i++, c = (((c - 'a') * mult + i * addt) % 26) + 'a') {
			vector<pair<char, pair<int, int> > > v;
			while (!state[c - 'a'].empty()) {
				auto cur = state[c - 'a'].back();
				char nxt = (((c - 'a') * mul[cur.fst] + (cur.snd + 1) * add[cur.fst]) % 26) + 'a';
				if (cur.snd + 1 < len[cur.fst]) v.pb({nxt, {cur.fst, cur.snd + 1}});
				else bravo[cur.fst] = true;
				state[c - 'a'].pop_back();
				ch[cur.fst] = nxt;
			}
			for (auto i : v) state[i.fst - 'a'].pb({i.snd.fst, i.snd.snd});
		}
		cout << "Case " << tc + 1 << ":" << endl;
		for (int i = 0; i < n; i++) {
			if (bravo[i]) cout << "BRAVO" << endl;
			else cout << "REPEAT" << endl;
		}
	}
	return 0;
}