#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 75;

int T;
int n;
char s[N];
long long mem[N][10][2][2][2];

bool ok() {
	bool up = true;
	for (int i = 1; i < n; i++) {
		if (s[i] < s[i - 1]) up = false;
		if (s[i] > s[i - 1] && !up) return false; 
	}
	return true;
}

long long solve(int i = 0, int dd = 0, bool low = false, bool up = true, bool t = true) {
	if (i == n) {
		return 1;
	}
	if (mem[i][dd][low][up][t] > -1) return mem[i][dd][low][up][t];
	long long ret = 0;
	if (up) {
		for (int d = dd; d <= (low ? 9 : s[i] - '0'); d++) {
			ret += solve(i + 1, d, low || d < s[i] - '0', true, t);
			if (i + 1 < n) ret += solve(i + 1, d, low || d < s[i] - '0', false, t);
		}
	} else {
		for (int d = (low ? dd - t : min(dd - t, s[i] - '0')); d >= 0; d--) {
			ret += solve(i + 1, d, low || d < s[i] - '0', false, false);
		}
	}
	return mem[i][dd][low][up][t] = ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(mem, -1, sizeof mem);
		scanf("%s", s);
		n = strlen(s);
		if (!ok()) printf("-1\n");
		else printf("%lld\n", solve() - 1);
	}
	return 0;
}