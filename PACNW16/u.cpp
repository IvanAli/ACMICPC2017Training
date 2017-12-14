#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
long long all;

int ok() {
	for (int i = 0; i < n; i++) if (a[i] > all / 2) return i;
	return -1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], all += a[i];
	int k = ok();
	if (k == -1) cout << all / 2 << endl;
	else cout << all - a[k] << endl; 
	return 0;
}