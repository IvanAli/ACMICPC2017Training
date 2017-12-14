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
char s[N];

int main() {
 	scanf("%d", &T);
 	while (T--) {
 		scanf("%d%s", &n, s);
 		int gcnt = 0;
 		for (int i = 0; i < n; i++) {
 			if (s[i] == 'D') gcnt++;
 		}
 		if (gcnt & 1) {
 			puts("Y");
 			int las = 0;
 			for (int i = 0; i < n; i++) {
 				if (s[i] == 'D') {
 					for (int j = i; j >= las; j--) printf("%d ", j + 1);
 					las = i + 1;
 					if (i + 1 < n) {
 						if (s[i + 1] == 'D') s[i + 1] = 'B';
 						else s[i + 1] = 'D';
					}
 				}
 			}
 		} else putchar('N');
 		putchar('\n');
 	}
	return 0;
}