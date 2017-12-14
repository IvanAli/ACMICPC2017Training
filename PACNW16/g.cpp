#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[55][55];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> grid[i];
	for (int j = 0; j < m; j++) for (int i = n - 1; i >= 0; i--) {
		if (grid[i][j] == 'o') {
			int k = i + 1;
			if (k < n && grid[k][j] == '.') {
				while (grid[k][j] == '.') k++;
				k--;
				grid[k][j] = 'o';
				grid[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cout << grid[i][j];
		cout << endl;
	}
	return 0;
}