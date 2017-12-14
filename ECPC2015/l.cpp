#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[1005];
bool wl[1005];

bool ok() {
    for (int i = 0; i < n; i++) if (a[i] % (n * n - n) == 0 || a[i] % (n * n - n) >= n) return true;
    return false;
}

int main() {
    cin >> T;
    while (T--) {
	memset(wl, false, sizeof wl);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (ok()) cout << "Alice" << endl;
	else cout << "Bob" << endl;
    }
    return 0;
}