#include <bits/stdc++.h>
using namespace std;

char s[15];
int a, b, c;

int main() {
	fgets(s, 15, stdin);
	sscanf(s, "%d + %d = %d", &a, &b, &c);
	if (a + b == c) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}