#include <bits/stdc++.h>
using namespace std;

int T;
char s[105];

int main() {
	freopen("ghanophobia.in", "r", stdin);
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> s;
		int ee, gg;
		sscanf(s, "%d:%d", &ee, &gg);
		int g = 6, e = 1;
		e += ee;
		g += gg;
		cout << "Case " << tt + 1 << ": ";
		if (e == g) {
			e += 1;
			g += gg;
			if (e > g) cout << "YES" << endl;
			else if (e < g) cout << "NO" << endl;
			else cout << "PENALTIES" << endl;
		} else if (e > g) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}