#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 1000005;
vector<long long> primes;
bitset<maxn> prime;

int main() {
	prime.set();
	for (long long i = 2; i < maxn; i++) {
		if (prime[i]) {
			primes.pb(i);
			for (long long j = i * i; j < maxn; j += i) prime[j] = 0;
		}
	} 
	cout << primes.size() << endl;
	return 0;
}
