#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 100005;

bool test(int cur) {
	if (cur <= 1) return false;
	if (cur == 2) return true;
	for (long long i = 2; i * i <= cur; i++) {
		if (cur % i == 0) return false;
	}
	return true;
}

bool ok(int n) {
	int cur = 0;
	int tmp = n;
	while (tmp) {
	
		if(tmp%10 == 0)
			return false;
		cur = cur * 10 + (tmp % 10);
		if(!test(cur))
			return false;
		tmp /= 10;
	}
	return true;
}

int main() {
	for (long long i = 1; i <= 1000000000; i++) {
		if (ok(i)) cout << i << endl;
	}
	return 0;
}
