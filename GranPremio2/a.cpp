#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 15;
const int mod = 1e9 + 7;

int n, d;
int x[N], y[N];
vector<vector<int>> a;
vector<vector<int>> graph;

long long dist(int i, int j) {
	return (long long)(x[i] - x[j]) * (x[i] - x[j]) + (long long)(y[i] - y[j]) * (y[i] - y[j]);
}

vector<vector<int>> matsub(vector<vector<int>> a, vector<vector<int>> b) {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] -= b[i][j];
	return a;
}

int add(int a, int b) {
	int ret = a + b;
	if (ret >= mod) ret -= mod;
	return ret;
}

int sub(int a, int b) {
	int ret = a - b;
	if (ret < 0) ret += mod;
	return ret;
}

int mul(int a, int b) {
	return (long long)a * b % mod;
}

int power(int n, int e) {
	int ret = 1, res = n;
	while (e) {
		if (e & 1) ret = mul(ret, res);
		res = mul(res, res);
		e >>= 1;
	}
	return ret;
}

int inv(int n) {
	return power(n, mod - 2);
}

int gauss(vector<vector<int>> a) {
	int det = 1;
	for (int i = 0; i < n - 1; i++) {
		int sel = i;
		for (int j = i + 1; j < n - 1; j++) {
			if (abs(a[sel][i]) > abs(a[i][i])) sel = i;
		}
		if (abs(a[sel][i]) == 0) return 0;
		for (int j = i; j < n - 1; j++) swap(a[sel][j], a[i][j]);
		det = mul(det, abs(a[i][i]));
		for (int j = 0; j < n - 1; j++) {
			if (i == j) continue;
			if (abs(a[j][i]) == 0) continue;
			int c = mul(a[j][i], inv(a[i][i]));
			for (int k = i; k < n - 1; k++) a[j][k] = sub(a[j][k], mul(a[i][k], c));
		}
	}
	return det;
}

int main() {
	while (scanf("%d%d", &n, &d) && n + d > 0) {
		a = vector<vector<int>>(n, vector<int>(n, 0));
		graph = vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			scanf("%d%d", x + i, y + i);
		}
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			if (dist(i, j) <= d * d) {
				graph[i][j] = graph[j][i] = 1;
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			a[i][i] += graph[i][j];
		}
		vector<vector<int>> r = matsub(a, graph);
		int ans = gauss(r);
		printf("%d\n", ans);
	}
	return 0;
}
