#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 105;

int T, n;
char ss[N][10];
int start[N], finish[N];
set<string> dudes[N];
char dude[10];
set<string> ans;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) dudes[i].clear();
		ans.clear();
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%s%d%d%d", ss[i], &start[i], &finish[i], &t);
			while (t--) {
				scanf("%s", dude);
				dudes[i].insert(string(dude));
			}
		}
		for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
			if (strcmp(ss[i], ss[j]) == 0) assert(0);
			if (start[i] >= start[j] && start[i] <= finish[j] || finish[i] <= finish[j] && finish[i] >= start[j]) {
				for (auto it : dudes[i]) if (dudes[j].count(it)) ans.insert(it);
			}
		}
		printf("%d\n", (int) ans.size());
		for (auto it : ans) printf("%s\n", it.c_str());
	}
	return 0;
}