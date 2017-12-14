#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 1005;
const int ADD = 0;
const int SUB = 1;
const int MUL = 2;
const int MINUS = 3;

int T;
char s[N];
bool have[10];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int n = strlen(s);
		bool ok = false;
		for (int i = 0; i < 10; i++) have[i] = 0;
		for (int i = 0; s[i]; i++) if ('0' <= s[i] && s[i] <= '9') have[s[i] - '0'] = true;
		int last = -1;
		for (int d = 0; d < 10; d++) {
			if (have[d]) continue;
			long long a = 0, b = 0;
			long long cur = 0;
			int type = -1;
			bool minus = false;
			for (int i = 0; s[i]; i++) {
				if (s[i] == '+') {
					type = ADD;
					if (cur == 0) {
						if (i - last > 2) break;
					}
					if (minus) {
						cur = -cur, minus = false;
						if (cur == 0) break;
					}
					a = cur;
					cur = 0;
					last = i;
				} else if (s[i] == '-') {
					if (i == 0 || s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '*' || s[i - 1] == '=') {
						minus = true;
						continue;
					}
					if (cur == 0) {
						if (i - last > 2) break;
					}
					type = SUB;
					if (minus) {
						cur = -cur, minus = false;
						if (cur == 0) break;
					}
					a = cur;
					cur = 0;
					last = i;
				} else if (s[i] == '*') {
					type = MUL;
					if (minus) {
						cur = -cur, minus = false;
						if (cur == 0) break;
					}
					if (cur == 0) {
						if (i - last > 2) break;
					}
					a = cur;
					cur = 0;
					last = i;
				} else if (s[i] == '=') {
					if (minus) {
						cur = -cur, minus = false;
						if (cur == 0) break;
					}
					if (cur == 0) {
						if (i - last > 2) break;
					}
					b = cur;
					cur = 0;
					last = i;
				} else {
					cur *= 10;
					if ('0' <= s[i] && s[i] <= '9') cur += s[i] - '0';
					else cur += d;
				}
			}
			if (minus) {
				cur = -cur, minus = false;
				if (cur == 0) continue;
			}
			if (cur == 0) {
				if (n - last > 2) continue;
			}
			if (type == ADD) {
				if (a + b == cur) {
					ok = true;
					printf("%d\n", d);
					break;
				}
			} else if (type == SUB) {
				if (a - b == cur) {
					ok = true;
					printf("%d\n", d);
					break;
				}
			} else if (type == MUL) {
				if (a * b == cur) {
					ok = true;
					printf("%d\n", d);
					break;
				}
			} else assert(0);
		}
		if (!ok) printf("-1\n");
	}
	return 0;
}