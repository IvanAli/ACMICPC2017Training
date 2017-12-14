#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 100005;

int T;
int n, k;
int a[N];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++) scanf("%d", a + i);
		printf("Yes.\n");
	}
	return 0;
}
