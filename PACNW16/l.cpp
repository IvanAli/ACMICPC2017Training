#include <bits/stdc++.h>
#define fst first
#define snd second
using namespace std;

int a[3][2];

bool solve() {
	for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++) {
		if (i == j || i == k || j == k) continue;
		for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) for (int z = 0; z < 2; z++) {
			if (a[i][x] == a[j][y] + a[k][z] && a[j][y ^ 1] == a[k][z ^ 1] && a[i][x] == a[i][x ^ 1] + a[j][y ^ 1]) return true;
		}
	}
	return false; 
}

int main() {
	for (int i = 0; i < 3; i++) for (int j = 0; j < 2; j++) cin >> a[i][j];
	if (solve()) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}