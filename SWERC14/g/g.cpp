#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

const int maxn = 505;

int n;
int x[2][maxn], y[2][maxn];
map<int, int> hh[2], vv[2];
int szh[2], szv[2];
int fail[maxn << 1], f2[maxn << 1], f3[maxn << 1], f4[maxn << 1];
int xa[maxn << 1], ya[maxn << 1], xb[maxn], yb[maxn];

bool eq1(int xa, int ya, int xb, int yb) {
	return xa == xb && ya == yb;
}

bool eq2(int xa, int ya, int xb, int yb) {
	return xa == -xb && ya == -yb;
}

bool eq3(int xa, int ya, int xb, int yb) {
	return xa == yb && ya == xb;
}

bool eq4(int xa, int ya, int xb, int yb) {
	return xa == -yb && ya == -xb;
}

bool eq5(int xa, int ya, int xb, int yb) {
	return xa == -yb && ya == xb;
}

bool eq6(int xa, int ya, int xb, int yb) {
	return xa == yb && ya == -xb;
}

bool eq7(int xa, int ya, int xb, int yb) {
	return xa == xb && ya == -yb;
}

bool eq8(int xa, int ya, int xb, int yb) {
	return xa == -xb && ya == yb;
}

bool ok() {
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq1(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq2(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq3(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq4(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq5(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq6(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq7(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	for (int i = 0, j = 0; i < n << 1; i++, j++) {
		while (j > -1 && !eq8(xa[i], ya[i], xb[j], yb[j])) j = fail[j]; 
		if (j + 1 == n) return true;
	}
	return false;
}

int main() {
	for (int i = 0; i < 2; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) scanf("%d%d", x[i] + j, y[i] + j);
	}
	for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) {
		int k = j + 1;
		if (k == n) k = 0;
		if (x[i][j] == x[i][k]) hh[i][x[i][j]];
		else if (y[i][j] == y[i][k]) vv[i][y[i][j]];	
	}
	for (int i = 0; i < 2; i++) for (auto &it : hh[i]) it.snd = szh[i]++;
	for (int i = 0; i < 2; i++) for (auto &it : vv[i]) it.snd = szv[i]++;
	for (int i = 0; i < 2; i++) for (int j = 0; j < n; j++) {
		x[i][j] = hh[i][x[i][j]];
		y[i][j] = vv[i][y[i][j]];
	}
	for (int i = 0; i < n; i++) {
		int j = i + 1;
		if (j == n) j = 0;
		xa[i] = xa[i + n] = x[0][i] - x[0][j];
		ya[i] = ya[i + n] = y[0][i] - y[0][j];
		xb[i] = x[1][i] - x[1][j];
		yb[i] = y[1][i] - y[1][j];
	}
	fail[0] = -1;
	for (int i = 0, j = -1; i < n; i++, j++) {
		while (j > -1 && !eq1(xb[i], yb[i], xb[j], yb[j])) j = fail[j];
		fail[i + 1] = j + 1;
	}
	if (ok()) printf("yes\n");
	else printf("no\n");
	return 0;
}