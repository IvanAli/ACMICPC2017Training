#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 400005;

int n, p, q;
int a[N];
int lef[N], rig[N];
char cmd[15];

int main() {
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	for (int i = 0; i < n; i++) lef[i] = i - 1, rig[i] = i + 1;
	lef[0] = 0;
	rig[n - 1] = n - 1;
	p--;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", cmd);
//		printf("command: %s pos: %d\n", cmd, p);
		if (cmd[0] == 'i') {
			int foo;
			scanf("%d", &foo);
			if (cmd[6] == 'L') {
				int tmp = lef[p];
				lef[p] = n;
				a[n] = foo;
				if (tmp == p) lef[n] = n;
				else {
					lef[n] = tmp;
					rig[tmp] = n;
				}
				
				rig[n] = p;
				n++;
			} else if (cmd[6] == 'R') {
				int tmp = rig[p];
				rig[p] = n;
				a[n] = foo;
				if (tmp == p) rig[n] = n;
				else {
					lef[tmp] = n;
					rig[n] = tmp;
				}
				
				lef[n] = p;
				
				
				n++;
			} else assert(0);
		} else if (cmd[0] == 'm') {
			if (cmd[4] == 'L') p = lef[p];
			else if (cmd[4] == 'R') p = rig[p];
			else assert(0);
		} else if (cmd[0] == 'p') printf("%d\n", a[p]);
		else assert(0);
	}
	return 0;
}