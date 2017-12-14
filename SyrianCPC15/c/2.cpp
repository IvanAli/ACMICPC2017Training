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
int tree[N << 3][26];
int all[N << 3][26];
vector<string> ss;
char s[N];
int sz;
int size[N << 3];


void tadd() {
	int v = 0;
	for (int i = 0; s[i]; i++) {
		int to = s[i] - 'a';
		if (!tree[v][to]) tree[v][to] = sz++;
		v = tree[v][to];
	}
	size[v] = 1;
}

void calc(int v = 0) {
	for (int i = 0; i < 26; i++) {
		if (tree[v][i] > 0) {
			calc(tree[v][i]);
			size[v] += size[tree[v][i]]; 
		}
		all[v][i] = size[v];
	}
}

int solve(int k) {
	int ret = 1 << 30;
	int v = 0;
	int tot = 0;
	for (int i = 0; i < ss[k].size(); i++) {
		int to = ss[k][i] - 'a';
		if (to > 0) tot += all[v][to - 1];
		assert(tree[v][to] > 0);
		v = tree[v][to];
	}
	v = 0;
	for (int i = 0; i < ss[k].size(); i++) {
		ret = min(ret, 1 + tot + i);
		ret = min(ret, 1 + size[v] - tot + i);
		int to = ss[k][i] - 'a';
		if (to > 0) tot -= all[v][to - 1];
		v = tree[v][to];
	}
	ret = min(ret, (int) ss[k].size() + 1);
	return ret;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(tree, 0, sizeof tree);
		memset(size, 0, sizeof size);
		memset(all, 0, sizeof all);
		ss.clear();
		sz = 1;
		for (int i = 0; i < n; i++) {
			scanf("%s", s);
			ss.pb(string(s));
			tadd();
		}
		calc();
		for (int i = 0; i < n; i++) {
			if (i > 0) putchar(' ');
			printf("%d", solve(i));
		}
		putchar('\n');
	}
	return 0;
}