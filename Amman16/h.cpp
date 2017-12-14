#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

char s[maxn];
int T, c, k;

bool ok() {
	int cnt = 0;
	for (int i = 0; i < c; i++) {
		if (s[i] == '0') cnt++;
		else cnt = 0;
		if (cnt == k + 1) return true;
	} 
	return false;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &c, &k);
		scanf("%s", s);
		if (ok()) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
