#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 1005;

int T;
int n;
char s[N];
bool have[256];
bool pal[N][N];

int main() {
	scanf("%d", &T);
	have['A'] = 1;
	have['H'] = 1;
	have['I'] = 1;
	have['M'] = 1;
	have['O'] = 1;
	have['T'] = 1;
	have['U'] = 1;
	have['V'] = 1;
	have['W'] = 1;
	have['X'] = 1;
	have['Y'] = 1;
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) pal[i][j] = 0;
		for (int i = 0; i < n; i++) if (have[s[i]]) pal[i][i] = 1;
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i + len <= n; i++) {
				if (len == 2) {
					if (i + 1 < n && s[i] == s[i + 1] && have[s[i]]) pal[i][i + 1] = 1; 
					continue;
				}
				if (i + len - 1 < n && s[i] == s[i + len - 1] && have[s[i]] && pal[i + 1][i + len - 2]) pal[i][i + len - 1] = 1;
			}	
		}
		int ans = 0;
		for (int i = 0; i < n; i++) for (int j = i; j < n; j++) if (pal[i][j]) ans = max(ans, j - i + 1);
		printf("%d\n", ans);
	}
	return 0;
}