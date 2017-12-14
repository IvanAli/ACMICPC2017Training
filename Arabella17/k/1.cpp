#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int a, b, n;
int all[10];
int cnt[10];

void go(int y) {
	for (int i = 0; i < 10; i++) cnt[i] = 0;
	int ret = -1;
	while (y) {
		int d = y % 10;
		cnt[d]++;
		if (ret == -1) ret = d;
		else if (cnt[d] > cnt[ret]) ret = d;
		y /= 10;
	}
	for (int i = 0; i < 10; i++) if (cnt[i] == cnt[ret]) all[i]++;
}

int get() {
	int ret = -1;
	for (int i = 0; i < 10; i++) if (all[i] > 0) {
		if (ret == -1) ret = i;
		else if (all[i] > all[ret]) ret = i;
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		for (int i = 0; i < 10; i++) all[i] = 0;
		scanf("%d%d%d", &a, &b, &n);
		int ans = -1;
		for (int x = 1; ; x++) {
			int y = a * x * x + b * x;
			if (y > n) break;
			go(y);
		}
		ans = get();
		printf("%d\n", ans);
	}
	return 0;
}