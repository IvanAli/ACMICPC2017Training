#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;
int n;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n == 2 || n == 3) printf("second\n");
		else printf("first\n");
	}
	return 0;
}