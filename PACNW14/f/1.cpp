#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;
const int mod = 1e9 + 9;

int T;
int n, m;
vector<vector<int>> v;
vector<vector<int>> graph;

int add(int a, int b) {
	int ret = a + b;
	if (ret >= mod) ret -= mod;
	return ret;
}

int mul(int a, int b) {
	return (long long) a * b % mod;
}

vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
	if (a[0].size() != b.size()) assert(0);
	vector<vector<int>> ret(vector<vector<int>>(a.size(), vector<int>(b[0].size())));
	for (int i = 0; i < a.size(); i++) for (int j = 0; j < b[0].size(); j++) for (int k = 0; k < b.size(); k++) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
	return ret;
}

vector<vector<int>> power(vector<vector<int>> a, int e) {
	vector<vector<int>> ret(vector<vector<int>>(1 << (n << 1), vector<int>(1 << (n << 1)))); 
	vector<vector<int>> res = a; 
	for (int i = 0; i < 1 << (n << 1); i++) ret[i][i] = 1;
	while (e) {
		if (e & 1) ret = matmul(ret, res);
		res = matmul(res, res);	
		e >>= 1;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		if (m == 1) {
			printf("%d\n", 1 << n);
			continue;
		}
		graph = vector<vector<int>>(1 << (n << 1), vector<int>(1 << (n << 1)));
		v = vector<vector<int>>(1 << (n << 1), vector<int>(1));
		
		for (int msk1 = 0; msk1 < 1 << (n << 1); msk1++) for (int msk2 = 0; msk2 < 1 << (n << 1); msk2++) {
			int lef = msk1 & ((1 << n) - 1);
			int mid = msk1 >> n;
			if (lef << 2 & mid) continue;
			if ((msk2 & ((1 << n) - 1)) != mid) continue;
			int rig = msk2 >> n;
			if (mid << 2 & lef) continue;
			if (lef << 1 & rig) continue;
			if (rig << 1 & lef) continue;
			if (mid << 2 & rig) continue;
			if (rig << 2 & mid) continue;
			graph[msk1][msk2] = 1;
		}
		for (int msk1 = 0; msk1 < 1 << n; msk1++) for (int msk2 = 0; msk2 < 1 << n; msk2++) {
			if (msk1 & (msk2 << 2)) continue;
			if (msk2 & (msk1 << 2)) continue;
			v[msk1 | msk2 << n][0] = 1;
		}
		if (m - 2 > 0) {
			vector<vector<int>> mat = power(graph, m - 2);
			v = matmul(mat, v);
		}
		int ans = 0;
		for (int i = 0; i < 1 << (n << 1); i++) {
			ans = add(ans, v[i][0]);
		}
		printf("%d\n", ans);
	}
	return 0;
}