#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 305;

int n;
int dist[N][N];
int a[N][N];

bool ok() {
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][j] != dist[i][j]) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]), dist[i][j] = 1 << 30;
	for (int i = 0; i < n; i++) dist[i][i] = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (a[i][j] > 0) dist[i][j] = a[i][j];
	for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	if (ok()) {
		for (int i = 0; i < n; i++, putchar('\n')) for (int j = 0; j < n; j++) {
			if (j > 0) putchar(' ');
			printf("%d", a[i][j]);
		}
	} else printf("-1\n");
	return 0;
}