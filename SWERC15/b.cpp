#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > mat;

bool gauss(vector<vector<int> > mat, int N, int M) {
	vector<int> where(M, -1);
	for (int row = 0, col = 0; row < N && col < M; col++) {
		int sel = row;
		for (int i = row; i < N; i++) if (mat[i][col] > mat[sel][col]) sel = i;
		if (mat[sel][col] == 0) continue;
		if (row != sel) for (int i = col; i <= M; i++) swap(mat[row][i], mat[sel][i]);
		where[col] = row;
		for (int i = 0; i < N; i++) {
			if (i == row) continue;
			if (mat[i][col] == 1) for (int j = col; j <= M; j++) mat[i][j] ^= mat[row][j];
		}
		row++;
	}
	vector<int> ans(M, 0);
	for (int i = 0; i < M; i++) if (where[i] != -1) ans[i] = mat[where[i]][M];
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) sum ^= (ans[j] & mat[i][j]);
		if (sum != mat[i][M]) return false;
	}
	return true;
}

bool solve(int x, int y, int z, int t) {
	for (int i = 0; i < 26; i++) {
		fill(mat[t].begin(), mat[t].end(), 0);
		fill(mat[t + 1].begin(), mat[t + 1].end(), 0);
		if (i == x || i == y || i == z) {
			for (int j = 0; j < 2; j++) {
				mat[t][i * 2 + j] = 1;
				mat[t][52] = 0;
				t++;
			}
		} else {
			mat[t][i * 2] = 1;
			mat[t][i * 2 + 1] = 1;
			mat[t][52] = 1;
			t++;
		}
	}
	return gauss(mat, t, 52);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	int ans = 0;
	int t = 0;
	mat = vector<vector<int> >(500, vector<int>(53));
	for (int i = 0; i < n; i++) {
		char m[2];
		int p, r;
		cin >> m >> p >> r;
		p--;
		if (r == 0) {
			for (int j = 0; j < 2; j++) {
				mat[t][(m[j] - 'A') * 2 + p] = 1;
				mat[t][52] = 0;
				t++;
			}
		} else if (r == 1) {
			for (int j = 0; j < 2; j++) {
				mat[t][(m[j] - 'A') * 2 + p] = 1;
				mat[t][52] = 1;
			}
			t++;
		} else if (r == 2) {
			for (int j = 0; j < 2; j++) {
				mat[t][(m[j] - 'A') * 2 + p] = 1;
				mat[t][52] = 1;
				t++;
			}
		}
	}
	for (int i = 0; i < 26; i++) for (int j = i + 1; j < 26; j++) for (int k = j + 1; k < 26; k++) ans += solve(i, j, k, t);
	cout << ans << endl;
	return 0;
}
