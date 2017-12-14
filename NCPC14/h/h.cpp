#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
const int maxa = 360000;

int n;
int a[maxn];
int b[maxn];
int aa[maxn], bb[maxn << 1];
int f[maxn];

bool ok() {
	for (int i = 0, j = 0; i < n * 2; i++, j++) {
		while (j > -1 && bb[i] != aa[j]) j = f[j];
		if (j + 1 == n) return true;
	}
	return false;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		if (j == n) j = 0;
		aa[i] = (a[j] - a[i] + maxa) % maxa;
		bb[i] = (b[j] - b[i] + maxa) % maxa;
		bb[i + n] = bb[i];
	}
	f[0] = -1;
	for (int i = 0, j = -1; i < n; i++, j++) {
		while (j > -1 && aa[i] != aa[j]) j = f[j];
		f[i + 1] = j + 1;
	}
	if (ok()) cout << "possible" << endl;
	else cout << "impossible" << endl;
}
