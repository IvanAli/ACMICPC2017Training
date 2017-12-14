#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 200005;

int n;
int a[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) {
		if (i > 0) putchar(' ');
		if (i > 0) printf("%d", a[i] - a[i - 1]);
		else printf("%d", a[i]);
	}
	putchar('\n');
	return 0;
}