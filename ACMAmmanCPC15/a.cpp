#include <bits/stdc++.h>
using namespace std;

int T, n;
string s[105];
int x[105], y[105];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i] >> x[i] >> y[i];
		}
		for (int i = 0; i < n; i++) {
			if (x[i] > x[ans]) ans = i;
			else if (x[i] == x[ans]) {
				if (y[i] < y[ans]) ans = i;
			}
		}
		cout << s[ans] << endl;
	}
	return 0;
}
