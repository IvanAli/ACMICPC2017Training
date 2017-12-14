#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 567;

int n;
int a[maxn];
char s[maxn];
long long dpmax[maxn][maxn], dpmin[maxn][maxn];

long long maxadd(int i, int j, int k) {
	long long ret = dpmax[i][k] + dpmax[k + 1][j];
	ret = max(ret, dpmax[i][k] + dpmin[k + 1][j]);
	ret = max(ret, dpmin[i][k] + dpmax[k + 1][j]);
	ret = max(ret, dpmin[i][k] + dpmin[k + 1][j]);
	return ret;
}

long long maxsub(int i, int j, int k) {
	long long ret = dpmax[i][k] - dpmax[k + 1][j];
	ret = max(ret, dpmax[i][k] - dpmin[k + 1][j]);
	ret = max(ret, dpmin[i][k] - dpmax[k + 1][j]);
	ret = max(ret, dpmin[i][k] - dpmin[k + 1][j]);
	return ret;
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
	long long ret = dpmax[i][k] + dpmax[k + 1][j];
	ret = min(ret, dpmax[i][k] + dpmin[k + 1][j]);
	ret = min(ret, dpmin[i][k] + dpmax[k + 1][j]);
	ret = min(ret, dpmin[i][k] + dpmin[k + 1][j]);
	return ret;
}

long long minsub(int i, int j, int k) {
	long long ret = dpmax[i][k] - dpmax[k + 1][j];
	ret = min(ret, dpmax[i][k] - dpmin[k + 1][j]);
	ret = min(ret, dpmin[i][k] - dpmax[k + 1][j]);
	ret = min(ret, dpmin[i][k] - dpmin[k + 1][j]);
	return ret;
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
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> s[i];
	}
	for (int i = 0; i < n; i++) a[i + n] = a[i], s[i + n] = s[i];
	for (int i = 0; i < n * 2; i++) for (int j = 0; j < n * 2; j++) dpmax[i][j] = dpmin[i][j] = 1ll << 62, dpmax[i][j] = -dpmax[i][j];
	for (int i = 0; i < n * 2; i++) dpmax[i][i] = dpmin[i][i] = a[i];
	for (int len = 2; len <= n * 2; len++) {
		for (int i = 0; i + len <= n * 2; i++) for (int j = 1; j < len; j++) {
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
	for (int i = 0; i < n; i++) cout << llabs(dpmin[i][n + i - 1]) << llabs(dpmax[i][n + i - 1]);
	cout << endl; 
	return 0;
}