#include <bits/stdc++.h>
using namespace std;


int n;
int a[55];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (i + 1 < n && a[i] == a[i + 1]) ans++, i++;
		if (i + 1 < n && a[i] > a[i + 1]) {
			while (i + 2 < n && a[i + 1] >= a[i + 2]) {
				ans++;
				i++;
			}
		} else if (i + 1 < n && a[i] < a[i + 1]) {
			while (i + 2 < n && a[i + 1] <= a[i + 2]) {
				ans++;
				i++;
			}
		}
		
	}
	cout << n - ans << endl;	
	return 0;
}