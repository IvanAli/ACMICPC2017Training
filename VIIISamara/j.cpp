#include <bits/stdc++.h>
#define end asijdiasjd
using namespace std;

const int inf = 1e9 + 5;
const int maxn = 100005;

int n, m, k;
int beg[maxn], end[maxn];
int w[maxn], f[maxn];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < m; i++) cin >> f[i];
	for (int i = 0; i < n; i++) beg[i] = inf;
	int t = 0;
	for (int i = 0, j = 0; i < n; j++) {
		if (w[i] == f[j]) {
			if (end[t] - beg[t] + 1 >= k) t++;
			beg[t] = min(beg[t], i);
			end[t] = max(end[t], i);
			i++;
		} else {
			if (beg[t] < inf) t++;
		}
	}
	cout << t + 1 << endl;
	for (int i = 0; i <= t; i++) {
		cout << end[i] - beg[i] + 1;
		for (int j = beg[i]; j <= end[i]; j++) cout << " " << j + 1;
		cout << endl;
	}
	return 0;
}
