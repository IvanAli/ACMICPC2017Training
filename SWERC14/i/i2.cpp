#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
int a[105];
char s[105];
long long dpmax[105][105], dpmin[105][105];

long long maxadd(int i, int j, int k) {
	return dpmax[i][k] + dpmax[k + 1][j];
}

long long maxsub(int i, int j, int k) {
	return dpmax[i][k] - dpmax[k + 1][j];
}

long long maxmul(int i, int j, int k) {
	long long ret = dpmax[i][k] * dpmax[k + 1][j];
	ret = max(ret, dpmax[i][k] * dpmin[k + 1][j]);
	ret = max(ret, dpmin[i][k] * dpmax[k + 1][j]);
	ret = max(ret, dpmin[i][k] * dpmin[k + 1][j]);
	return ret;
}

long long maxall(int i, int j, int k) {
	return max(maxadd(i, j, k), max(maxsub(i, j, k), maxmul(i, j, k)));
}

long long minadd(int i, int j, int k) {
	return dpmin[i][k] + dpmin[k + 1][j];
}

long long minsub(int i, int j, int k) {
	return dpmin[i][k] - dpmin[k + 1][j];
}

long long minmul(int i, int j, int k) {
	long long ret = dpmax[i][k] * dpmax[k + 1][j];
	ret = min(ret, dpmax[i][k] * dpmin[k + 1][j]);
	ret = min(ret, dpmin[i][k] * dpmax[k + 1][j]);
	ret = min(ret, dpmin[i][k] * dpmin[k + 1][j]);
	return ret;
}

long long minall(int i, int j, int k) {
	return min(minadd(i, j, k), min(minsub(i, j, k), minmul(i, j, k)));
}

int main() {
//	scanf("%d", &n);
//	for (int i = 0; i < n << 1; i++) scanf("%d%c", a + i, s + i);
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n << 1; i++) {
//		v.pb(i);
		cin >> a[i] >> s[i];
		s[i + 1] = s[i];
		s[i] = '+';
		i++;
//		if (s[i] == '?') {
			
//			s[i] = '+';
//			a[i + 1] = 0;
//			s[i + 1] = '?';
//			i++, n++;
//			i++;
//		}
	}
	n <<= 1;
	for (int i = 0; i < n; i++) a[i + n] = a[i], s[i + n] = s[i];
	int nn = n;
	n <<= 1;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dpmax[i][j] = dpmin[i][j] = 1ll << 62, dpmax[i][j] = -dpmax[i][j];
	for (int i = 0; i < n; i++) dpmax[i][i] = dpmin[i][i] = a[i];
	for (int len = 2; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) for (int j = 1; j < len; j++) {
			if (s[i + j - 1] == '+') {
				dpmax[i][i + len - 1] = max(dpmax[i][i + len - 1], maxadd(i, i + len - 1, i + j - 1));
				dpmin[i][i + len - 1] = min(dpmin[i][i + len - 1], minadd(i, i + len - 1, i + j - 1));
			} else if (s[i + j - 1] == '-') {
				dpmax[i][i + len - 1] = max(dpmax[i][i + len - 1], maxsub(i, i + len - 1, i + j - 1));
				dpmin[i][i + len - 1] = min(dpmin[i][i + len - 1], minsub(i, i + len - 1, i + j - 1));
			} else if (s[i + j - 1] == '*') {
				dpmax[i][i + len - 1] = max(dpmax[i][i + len - 1], maxmul(i, i + len - 1, i + j - 1));
				dpmin[i][i + len - 1] = min(dpmin[i][i + len - 1], minmul(i, i + len - 1, i + j - 1));
			} else if (s[i + j - 1] == '?') {
				dpmax[i][i + len - 1] = max(dpmax[i][i + len - 1], maxall(i, i + len - 1, i + j - 1));
				dpmin[i][i + len - 1] = min(dpmin[i][i + len - 1], minall(i, i + len - 1, i + j - 1));
			} else assert(0); 
		}
	}
	for (int i = 0; i < nn; i += 2) cout << llabs(dpmin[i][nn + i - 1]) << ' ' << llabs(dpmax[i][nn + i - 1]) << endl;
	cout << endl; 
	return 0;
}