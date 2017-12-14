#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int b[26];
string s;

int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) b[s[i] - 'a']++;
	vector<int> v;
	for (int i = 0; i < 26; i++) if (b[i] > 0) v.pb(b[i]);
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < (int)v.size() - 2; i++) ans += v[i];
	cout << ans << endl;
	return 0;
}
