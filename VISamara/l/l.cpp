#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;
char s[maxn];
int n;

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i * 2 < n; i++) {
		if (s[i] != s[n - i - 1]) s[n - i - 1] = s[i];
	}
	printf("%s\n", s);
	return 0;
}