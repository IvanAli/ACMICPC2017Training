#include <bits/stdc++.h>
using namespace std;

int n;
char ins[15];
int ope[15];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int x;
		cin >> s >> x;
		if (s == "ADD") ins[i] = '+';
		else if (s == "SUBTRACT") ins[i] = '-';
		else if (s == "MULTIPLY") ins[i] = '*';
		else if (s == "DIVIDE") ins[i] = '/';
		else assert(0);
		ope[i] = x;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		int cur = i;
		for (int j = 0; j < n; j++) {
			if (ins[j] == '+') {
				cur += ope[j];
			} else if (ins[j] == '-') {
				if (cur - ope[j] < 0) {
					ans++;
					break;
				}
				cur -= ope[j];
			} else if (ins[j] == '*') {
				cur *= ope[j];
			} else if (ins[j] == '/') {
				if (cur % ope[j] != 0) {
					ans++;
					break;
				}
				cur /= ope[j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
