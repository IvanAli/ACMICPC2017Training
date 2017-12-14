#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int ga1, ga2, gb1, gb2;
int ea1, ea2, eb1, eb2;

int main() {
	scanf("%d%d%d%d", &ga1, &ga2, &gb1, &gb2);
	scanf("%d%d%d%d", &ea1, &ea2, &eb1, &eb2);
	vector<int> g, e;
	for (int i = ga1; i <= ga2; i++) for (int j = gb1; j <= gb2; j++) g.pb(i + j);
	for (int i = ea1; i <= ea2; i++) for (int j = eb1; j <= eb2; j++) e.pb(i + j);
	int gcnt = 0, ecnt = 0;
	for (auto gg : g) for (auto ee : e) {
		if (gg > ee) gcnt++;
		else if (ee > gg) ecnt++;
	}
	if (gcnt > ecnt) printf("Gunnar\n");
	else if (ecnt > gcnt) printf("Emma\n");
	else printf("Tie\n");
	return 0;
}
