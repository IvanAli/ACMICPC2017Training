#include <bits/stdc++.h>
using namespace std;

const int maxn = 2234567;

int T;
long long n;
long long rep[maxn];

int main() {
	freopen("army.in", "r", stdin);
	for (long long i = 1; i < maxn; i++) {
		rep[i] = rep[i - 1] + i * i;
	}
	cin >> T;
	for (int tt = 0; tt < T; tt++) {
		cin >> n;
		long long low = 0, high = maxn - 1, mid;
		while (low < high) {
			mid = low + high >> 1;
			if (rep[mid] >= n) high = mid;
			else low = mid + 1;
		}
		long long ans = (long long)(low - 1) * (low - 1);
		long long prv = rep[low - 1];
		long long cur = 0;
		long long best = low;
		high = best, low = 0;
		while (low < high) {
			mid = low + high >> 1;
			if (prv + (mid * mid + mid) / 2 >= n) high = mid;
			else low = mid + 1; 	
		}
		ans += low;
		prv += (low * low + low) / 2;
		best--;
		low = 0, high = best;
		while (low < high) {
			mid = low + high + 1 >> 1;
			if (prv + (best * best + best) / 2 - (mid * mid + mid) / 2 >= n) low = mid;
			else high = mid - 1;
		}
		ans += best - low;
		cout << "Case " << tt + 1 << ": " << ans << endl;		
	}
	return 0;
}