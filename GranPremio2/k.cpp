#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 1000005;

int n, w, k;
int a[N];
int lmax[N], rmax[N], lmin[N], rmin[N];

bool ok() {
	for (int i = 0; i + w < n; i++) {
		int minv = min(rmin[i], lmin[i + w - 1]);
		int maxv = max(rmax[i], lmax[i + w - 1]);
		if (minv < a[i + w] - k) return false;
		if (maxv > a[i + w] + k) return false;
	}
	return true;
}

int main() {
	while (scanf("%d%d%d", &n, &w, &k) && n + w + k > 0) {
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		for (int i = 0; i < n; i++) {
			if (i % w == 0) {
				lmax[i] = lmin[i] = a[i];
				rmin[n - i - 1] = rmax[n - i - 1] = a[i];
			}
			else if (i > 0) {
				lmax[i] = max(lmax[i - 1], a[i]);
				lmin[i] = min(lmin[i - 1], a[i]);
				rmax[n - i - 1] = max(rmax[n - i], a[i]);
				rmin[n - i - 1] = min(rmin[n - i], a[i]);
			}
		}
		if (ok()) printf("Yes.\n");
		else printf("No.\n");
	}
	return 0;
}
