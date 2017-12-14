#include <bits/stdc++.h>
using namespace std;

int w, h, b;
// int have[1000005];
set<int> have;
int grid[105][105];
int gg[105][105];

int main() {
	cin >> w >> h >> b;
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> grid[i][j];
	int ans = 0;
	int cnt = 9;
	for (int bb = 0; bb < b; bb++) {
		// memset(have, 0, sizeof have);
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) {
			int sum = 0;
			for (int ii = 0; ii < 3; ii++) {
				int x = i + ii - 1;
				if (x < 0) x += h;
				else if (x >= h) x -= h;
				for (int jj = 0; jj < 3; jj++) {
					int y = j + jj - 1;
					if (y < 0) y += w;
					else if (y >= w) y -= w;
					sum += grid[x][y];
				}
			}
			// if (sum % 9 == 0) sum /= 9;
			gg[i][j] = sum;
		}
		for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) grid[i][j] = gg[i][j];
		// cerr << "grid at b = " << bb << endl;
		// for (int i = 0; i < h; i++) {
		// 	for (int j = 0; j < w; j++) fprintf(stderr, "%d/%d ", grid[i][j], cnt);
		// 	cerr << endl;
		// }
		// cnt *= 9;
	}
	for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) have.insert(grid[i][j]);
	ans = have.size();
	// for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) have[grid[i][j]] = 1;
	// for (int i = 0; i < 505; i++) ans += have[i];
	cout << ans << endl;
	return 0;
}
