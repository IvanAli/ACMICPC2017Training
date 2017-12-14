#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[55];
char name[55][15];
int v[3];
char a[55][1005];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> p[i];
	for (int i = 0; i < n; i++) cin >> name[i];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] -= '0';
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) {
		int pi = p[i], pj = p[j], pk = p[k];
		int si = 0, sj = 0, sk = 0;
		int cnt = 0;
		for (int it = 0; it < m; it++) {
			if (a[i][it]) si++;
			if (a[j][it]) sj++;
			if (a[k][it]) sk++;
		}
		cnt += min(si, pi) + min(sj, pj) + min(sk, pk);
		for (int it = 0; it < m; it++) {
			if (a[i][it] + a[j][it] + a[k][it] == 2) {
				if (a[i][it] + a[j][it] == 2) {
					if (pi > pj && pi > 0) cnt -= 1, pi--;
					else if (pj > 0) cnt -= 1, pj--;
				}
				if (a[i][it] + a[k][it] == 2) {
					if (pi > pk && pi > 0) cnt -= 1, pi--;
					else if (pk > 0) cnt -= 1, pk--;
				}
				if (a[j][it] + a[k][it] == 2) {
					if (pj > pk && pj > 0) cnt -= 1, pj--;
					else if (pk > 0) cnt -= 1, pk--;
				}
				// cnt -= 1;
			}
			if (a[i][it] + a[j][it] + a[k][it] == 3) {
				int b[3] = {0, 1, 2};
				sort(b, b + 3);
				if (b[2] == 0 && pi > 0) cnt -= 2, pi--;
				if (b[2] == 1 && pj > 0) cnt -= 2, pj--;
				if (b[2] == 2 && pk > 0) cnt -= 2, pk--;
				// cnt -= 2;
			}
		}
		if (ans < cnt) {
			ans = cnt;
			v[0] = i, v[1] = j, v[2] = k;
		}
	}
	cout << ans << endl;
	for (int i = 0; i < 3; i++) cout << name[v[i]] << " ";
	cout << endl;
	return 0;
}
