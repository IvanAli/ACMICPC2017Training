#include <bits/stdc++.h>
using namespace std;

int const N = 94713;

string s;
const string t = "1234321";

set<string> have;
int n;

bool ok() {
	bool up = true;
	for (int i = 1; i < n; i++) {
		if (s[i] < s[i - 1]) up = false;
		if (s[i] > s[i - 1] && !up) return false; 
	}
	return true;
}

bool ok2() {
	int low = false;
	for (int i = 0; i < n; i++) {
		if (s[i] > t[i] && !low) return false;
		low |= s[i] < t[i];
	}
	return true;
}

int main() {
	for (int i = 0; i < N; i++) {
		cin >> s;
		n = s.size();
		if (have.count(s)) {
			fprintf(stderr, "%s repeat\n", s.c_str());
			assert(0);
		}
		if (!ok()) {
			fprintf(stderr, "%s is not ok\n", s.c_str());
			assert(0);
		}
		if (!ok2()) {
			fprintf(stderr, "%s is big\n", s.c_str());
			assert(0);
		}
//		have[n] = 1;
		have.insert(s);
	}
	fprintf(stderr, "set size: %d\n", (int) have.size());
	return 0;
}