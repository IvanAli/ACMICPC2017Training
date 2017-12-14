#include <bits/stdc++.h>
using namespace std;

int n;
string s1, s2;

int main() {
	scanf("%d", &n);
	cin >> s1 >> s2;
	int ans = 0;
	bool flip = false;
	for (int i = 0; i < n; i++) {
		if (flip) {
			if (s1[i] == '0') s1[i] = '1';
			else if (s1[i] == '1') s1[i] = '0';
		}
		if (s1[i] != s2[i] && flip) {
			if (s1[i] == '0') s1[i] = '1';
			else if (s1[i] == '1') s1[i] = '0';
			flip = false;
		}
		if (s1[i] != s2[i]) {
			ans++;
			flip = true;
		}
	}
	printf("%d\n", ans);
	return 0;
}