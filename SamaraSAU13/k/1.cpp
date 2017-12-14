#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 200005;

char s[N];

int main() {
	scanf("%s", s);
	int cnt = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) return printf("IMPOSSIBLE\n"), 0;
	}
	printf("%s", s);
	for (int i = 0; i < cnt; i++) putchar(')');
	putchar('\n');
	return 0;
}