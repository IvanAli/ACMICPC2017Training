#include <bits/stdc++.h>
using namespace std;

int p, k;
int a[105][1005];
int size[105];
int wl[105][1005];

int main() {
    cin >> p >> k;
    for (int i = 0; i < p; i++) {
	int n;
	cin >> n;
	a[i][0] = 1 << 30;
	for (int j = 1; j <= n; j++) cin >> a[i][j];
	size[i] = n;
    }
    for (int i = 0; i < p; i++) {
	for (int j = 1; j <= size[i]; j++) {
	    set<int> st;
	    for (int it = 0; it <= k; it++) {
		if (j - it < 0) break;
		if (j - it - a[i][j - it] < 0) continue;
		st.insert(wl[i][j - it - a[i][j - it]]);
    	    }
	    for (int it = 0; it <= 10; it++) if (!st.count(it)) {
    		wl[i][j] = it;
    		break;	
	    }
	}
    }
    int ans = 0;
    for (int i = 0; i < p; i++) ans ^= wl[i][size[i]];
    if (ans > 0) cout << "Alice can win." << endl;
    else cout << "Bob will win." << endl;
    return 0;
}