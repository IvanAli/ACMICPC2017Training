#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n;
int h[N];

bool ok() {
	for (int i = 0; i + 1 < n; i++) if (h[i] != h[i + 1]) return false;
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", h + i), h[i] %= 2;
		if (ok()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}