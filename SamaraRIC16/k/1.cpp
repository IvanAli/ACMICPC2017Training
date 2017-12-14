#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int n;
char ss[6][6] = {"aba", "acb", "bac", "bca", "cab", "cba"};
char ans[N];
int p[N];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 6; i++) p[i] = i;
	int sz = 0;
	do {
		for (int i = 0; i < 6; i++) for (int j = 0; j < 3; j++) ans[sz++] = ss[i][j];
	} while (next_permutation(p, p + 6));
	for (int i = 0; i < n; i++) printf("%c", ans[i]);
	putchar('\n');
	return 0;
}