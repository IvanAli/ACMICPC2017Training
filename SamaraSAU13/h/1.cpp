#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int n;

int main() {
	scanf("%d", &n);
	int mx = 1;
	for (int i = 0; i < n; i++) {
		int foo; scanf("%d", &foo);
		mx = max(mx, foo);
	}
	for (int i = 0; i <= 30; i++) if (mx + 1 == 1 << i) return printf("Mike\n"), 0;
	printf("Constantine\n");  
	return 0;
}