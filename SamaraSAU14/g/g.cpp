#include <bits/stdc++.h>
using namespace std;

long long n;
set<long long> st;

int main() {
	scanf("%lld", &n);
	for (long long i = 0; i * i <= n; i++) st.insert(i * i);
	for (long long i = 0; i * i <= n; i++) {
		if (st.count(n - i * i)) return printf("Yes\n"), 0;
	}
	printf("No\n");
	return 0;
}