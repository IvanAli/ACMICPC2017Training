#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
using namespace std;

const int maxn = 300005;

int n, l, r, q;
char s[maxn];
deque<char> lef, mid, rig;
bool rev;

int main() {
	scanf("%d%d%d", &n, &l, &r); l--, r--;
	scanf("%s", s);
	scanf("%d", &q);
	for (int i = 0; i < l; i++) lef.pb(s[i]);
	for (int i = l; i <= r; i++) mid.pb(s[i]);
	for (int i = r + 1; i < n; i++) rig.pb(s[i]);
	while (q--) {
		char cmd[1];
		scanf("%s", cmd);
		if (cmd[0] == 'S') {
			char x[1], y[1]; scanf("%s%s", x, y);
			if (x[0] == 'L') {
				if (y[0] == 'L') {
					char back = lef.back();
					lef.pop_back();
					if (rev) mid.pb(back);
					else mid.pf(back);
				} else if (y[0] == 'R') {
					char front;
					if (rev) front = mid.back(), mid.pop_back();
					else front = mid.front(), mid.pop_front();
					lef.pb(front);
				}
			} else if (x[0] == 'R') {
				if (y[0] == 'L') {
					char back;
					if (rev) back = mid.front(), mid.pop_front();
					else back = mid.back(), mid.pop_back();
					rig.pf(back);
				} else if (y[0] == 'R') {
					char front = rig.front();
					rig.pop_front();
					if (rev) mid.pf(front);
					else mid.pb(front);
				}
			}
		} else if (cmd[0] == 'R') {
			rev ^= true;
		} else if (cmd[0] == 'Q') {
			char x[1]; scanf("%s", x);
			if (x[0] == 'L') rev ? putchar(mid.back()) : putchar(mid.front());
			else if (x[0] == 'R') rev ? putchar(mid.front()) : putchar(mid.back());
		} else assert(0);
	}
	putchar('\n');
	return 0;
}