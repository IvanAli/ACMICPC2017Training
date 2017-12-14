#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;
const double pi = acos(-1.0);

double a, l;
int T;
int n;

vector<vector<double>> mul(vector<vector<double>> a, vector<vector<double>> b) {
	vector<vector<double>> ret(3, vector<double>(3));
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) {
		ret[i][j] += a[i][k] * b[k][j];
	}
	return ret;
}
 
vector<vector<double>> power(int e) {
	vector<vector<double>> ret(3, vector<double>(3));
	vector<vector<double>> res(3, vector<double>(3));
	for (int i = 0; i < 3; i++) ret[i][i] = 1;
	res[0][0] = cos(a); res[0][1] = -sin(a); res[1][0] = sin(a); res[1][1] = cos(a); res[0][2] = l; res[2][2] = 1;
	while (e) {
		if (e & 1) ret = mul(ret, res);
		res = mul(res, res);
		e >>= 1;
	}
	return ret;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> l >> n;
		a *= pi;
		a /= 180.;
		vector<vector<double>> res = power(n);
		double x = res[0][2];
		double y = res[1][2];
		cout << setprecision(5) << fixed << x << ' ' << y << endl;
	}
	return 0;
}