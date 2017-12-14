#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T, n;
int sz;
int ans[N];

bool pal(string s) {
	int len = s.size();
	for (int i = 0; i * 2 < len; i++) if (s[i] != s[len - i - 1]) return false;
	return true;
}

char to_char(int d) {
	if (0 <= d <= 9) return d + '0';
	if (10 <= d <= 15) return d + 'a';
	assert(0);
	return -1;
}

string to_base(int n, int base) {
	string ret;
	while (n) {
		int digit = n % base;
		char ch = to_char(digit);
		ret.pb(ch);
		n /= base;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		sz = 0;
		for (int i = 2; i <= 16; i++) {
			string s = to_base(n, i);
			if (pal(s)) ans[sz++] = i;
		}
		if (sz == 0) printf("-1");
		for (int i = 0; i < sz; i++) {
			if (i > 0) putchar(' ');
			printf("%d", ans[i]);
		}
		putchar('\n');
	}
	return 0;
}