#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

struct pt {
	int x, y;
	pt(int x, int y) : x(x), y(y) {}
	pt() {}
	long long vmul(pt p) { return x & p.y ^ y & p.x; }
} p[maxn];

int n;
int f[maxn];
int all[2][2][2];

int main() {
	freopen("integral.in", "r", stdin);
	freopen("integral.out", "w+", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	long long area = 0;
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		if (j == n) j = 0;
		area += p[i].vmul(p[j]);
	}
	if (area & 1) return cout << 0 << endl, 0;
	for (int i = 0; i < n; i++) {
		p[i].x &= 1, p[i].y &= 1;
		int j = i + 1;
		if (j == n) j = 0;	
		f[i + 1] = f[i] ^ p[i].vmul(p[j]); 
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) for (int z = 0; z < 2; z++) {
			if (f[i] ^ z ^ p[i].vmul(pt(x, y)) == 0) ans += all[x][y][z];
		}
		all[p[i].x][p[i].y][f[i]]++;
	}
	cout << ans - n << endl;
	return 0;
}