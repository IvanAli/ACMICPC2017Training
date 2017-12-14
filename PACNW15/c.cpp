#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
vector<vector<int> > vv;
int p[1005];
string ss[1005];

int main() {
	cin >> n;
	getchar();
	int maxlen = 0;
	for (int i = 0; i < n; i++) {
		p[i] = i;
		string s;
		getline(cin, s);
		string name;
		int j;
		for (j = 0; j < s.size(); j++) {
			if (s[j] == ':') break;
			name += s[j];
		}
		ss[i] = name;
		string w;
		vector<int> v;
		int len = 0;
		while (j < s.size()) {
			if (s[j] == ' ') {
				if (w == "upper") v.pb(2);
				if (w == "lower") v.pb(0);
				if (w == "middle") v.pb(1);
				w = "";
				len++;
			} else w += s[j];
			j++;
		}
		maxlen = max(maxlen, len);
		vv.pb(v);
	}
	for (int i = 0; i < n; i++) reverse(vv[i].begin(), vv[i].end());
	for (int i = 0; i < n; i++) while (vv[i].size() < maxlen) vv[i].pb(1);
	assert(vv.size() == n);
	sort(p, p + n, [&](int i, int j) {
		bool ret = lexicographical_compare(vv[i].begin(), vv[i].end(), vv[j].begin(), vv[j].end());
		if (!ret) {
			if (vv[i].size() != vv[j].size()) return false;
			for (int ii = 0; ii < vv[i].size(); ii++) if (vv[i][ii] > vv[j][ii]) return false;
			return !lexicographical_compare(ss[i].begin(), ss[i].end(), ss[j].begin(), ss[j].end());
		}
		return ret;
	});
	for (int i = 0; i < n; i++) cout << ss[p[n - i - 1]] << endl;
	return 0;
}
