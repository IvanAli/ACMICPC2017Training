#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
using namespace std;

int n;
vector<pair<string, string> > v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string first, last;
		cin >> first >> last;
		v.pb({last, first});
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i.snd << " " << i.fst << endl;
	}
	return 0;
}
