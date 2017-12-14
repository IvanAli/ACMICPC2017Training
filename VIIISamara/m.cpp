#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q; cin >> n >> q; n++;
	for (int i = 0; i < q; i++) {
		int k, l; cin >> k >> l;
		int r = n % (k+l);
		int g = n / (k+l);
		//cout << "r: " << r << " g: " << g << endl;
		cout << 2*g - 1 + (r > 0 ? 1 : 0)*(1 + (r > k ? 1 : 0)) << " ";
	}
	cout << endl;
	return 0;
}
