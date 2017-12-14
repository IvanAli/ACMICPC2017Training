#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 2097153;

char b[25];
bitset<maxn> prime;
vector<int> primes;

int todec() {
	int ret = 0;
	int len = strlen(b);
	for (int i = len - 1, j = 0; i >= 0; i--, j++) {
		if (b[i] == '1') ret |= (1 << j);
	}
	return ret;
}


string tobin(int x) {
	string ret;
	while (x) {
		if (x & 1) ret.pb('1');
		else ret.pb('0');
		x >>= 1;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool pal(int x) {
	string ret = tobin(x);
	int len = ret.size();
	for (int i = 0; i * 2 < len; i++) if (ret[i] != ret[len - i - 1]) return false;
	return true; 
}

int main() {
	prime.set();
	for (long long i = 2; i < maxn; i++) {
		if (prime[i]) {
			if (pal(i)) primes.pb(i);
			for (long long j = i * i; j < maxn; j += i) prime[j] = 0;
		}
	}
	while (scanf("%s", b) == 1) {
		int bb = todec();
		auto it = lower_bound(primes.begin(), primes.end(), bb);
		string ans = tobin(*it);
		printf("%s\n", ans.c_str());
	}
	return 0;
}