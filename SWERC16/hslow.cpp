#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define INF 1e9
using namespace std;

int a[32][32][32][32];
int d, h;
vector<vector<int> > perm;

void gen(int i, int cur, vector<int>& v) {
	if (i == d) {
		perm.pb(v);
		return;
	}
	v.pb(cur);
	gen(i + 1, cur, v);
	if (cur + 1	< d) gen(i + 1, cur + 1, v);
	v.pop_back();
}

int main() {
	cin >> d >> h;
	vector<int> v;
	gen(0, 0, v);
	cerr << "perm siz: " << perm.size() << endl;
	for (auto i : perm) {
		for (auto j : i) cerr << j << " ";
		cerr << endl;
	}
	// a[0][0][0][0] = 1;
	// for (int w = 0; w < 6; w++) for (int z = 0; z < 6; z++) for (int y = 0; y < 6; y++) for (int x = 0; x < 6; x++) {
	// 	int& ref = a[x][y][z][w];
	// 	if (w > 0) ref += a[x][y][z][w - 1];
	// 	if (z > 0) ref += a[x][y][z - 1][w];
	// 	if (y > 0) ref += a[x][y - 1][z][w];
	// 	if (x > 0) ref += a[x - 1][y][z][w];
	// }
	// for (int w = 0; w < 6; w++) for (int z = 0; z < 6; z++) {
	// 	cout << "For w = " << w << " and z = " << z << endl;
	// 	for (int x = 0; x < 6; x++) {
	// 		for (int y = 0; y < 6; y++) cout << a[x][y][z][w] << " ";
	// 		cout << endl;
	// 	}
	// }

	return 0;
}
