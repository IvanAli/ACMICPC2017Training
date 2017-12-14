#include <bits/stdc++.h>
using namespace std;

const int maxn = 500005;
int n;
char s[maxn];
int memo[maxn][
bool solve(int i = 0, int o = 0) {
	int c = i - o;
	if (o < c) return false;
	if (i == n) return o == c;
	if (s[i] == '(') return solve(i + 1, o + 1);
	else if (s[i] == ')') return solve(i + 1, o);
	else {
		if (solve(i + 1, o + 1)) {
			s[i] = '(';
			return true;
		}
		if (solve(i + 1, o)) {
			s[i] = ')';
			return true;
		}
	}
	return false;
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	if (solve()) printf("%s\n", s);
	else printf("Impossible\n");
	return 0;
}