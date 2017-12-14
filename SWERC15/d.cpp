#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[45];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) b[i + j]++;
	int k = 0;
	for (int i = 2; i <= 40; i++) if (b[k] < b[i]) k = i;
	for (int i = k; b[i] == b[k]; i++) cout << i << endl;
	return 0;
}
