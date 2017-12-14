#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

const int mod = 1e9 + 7;

int n, k;

vector<vector<int64> > mult(vector<vector<int64> > a, vector<vector<int64> > b) {
	vector<vector<int64> > ret(3, vector<int64>(3));
	int n = a.size();
	int m = b[0].size();
	int p = a[0].size();
	assert(a[0].size() == b.size());
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < p; k++) (ret[i][j] += (a[i][k] * b[k][j]) % mod) %= mod;
	return ret;
}

vector<vector<int64> > power(int e) {
	vector<vector<int64> > ret(3, vector<int64>(3));
	vector<vector<int64> > res(3, vector<int64>(3));
	for (int i = 0; i < 3; i++) ret[i][i] = 1;
	res[0][0] = 2;
	res[0][1] = 0;
	res[0][2] = 0;
	res[1][0] = 2;
	res[1][1] = 1;
	res[1][2] = 0;
	res[2][0] = 1;
	res[2][1] = 0;
	res[2][2] = 1;
	while (e) {
		if (e & 1) ret = mult(ret, res);
		res = mult(res, res);
		e >>= 1;
	}
	return ret;
}

int main() {
	cin >> n >> k;
	int g = n / (k + 1);
	vector<vector<int64> > ans(3, vector<int64>(3));
	for (int i = 0; i < 3; i++) ans[i][i] = 1;
	ans = power(g);
	vector<vector<int64> > mat(3, vector<int64>(3));
	int m = n % (k + 1);
	mat[0][0] = (m > 0 ? 2 * m - 1 : 0);
	mat[0][1] = k;
	mat[0][2] = 1;
	mat[1][0] = 0;
	mat[1][1] = 0;
	mat[1][2] = 0;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 0;
	ans = mult(mat, ans);
	cout << (ans[0][0]) % mod << endl;
}
