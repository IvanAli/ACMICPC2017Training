#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

const int N = 100005;

int T;

string s; 
int n;

bool ok() {
	for (int i = 0; i * 2 < n; i++) {
		if (s[i] != s[n - i - 1]) return false;
		if (s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' && s[i] != 'O' && s[i] != 'T' && s[i] != 'U' && s[i] != 'V' && s[i] != 'W' &&
		s[i] != 'X' && s[i] != 'Y') return false;
	}
	return true;
}

int main() {
	cin >> T;
	while (T--) {
		cin >> s;
		n = s.size();
		if (ok()) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}