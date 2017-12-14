#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T, a, b;

int main() {
	cin >> T;
	while (T--) {
		cin >> a >> b;
		if (a >= b) cout << "FunkyMonkeys" << endl;
		else cout << "WeWillEatYou" << endl;
	}
	return 0;
}