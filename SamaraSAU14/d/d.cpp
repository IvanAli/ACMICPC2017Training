#include <bits/stdc++.h>
using namespace std;

const int maxn = 200005;

int n;
string ss[3];
int have[maxn][26];
int ans[maxn];

int main() {
	cin >> n;
	for (int i = 0; i < 3; i++) cin >> ss[i];
	for (int j = 0; j < n; j++) for (int i = 0; i < 3; i++) {
		have[j][ss[i][j] - 'a']++;
		if (have[j][ans[j]] < have[j][ss[i][j] - 'a']) ans[j] = ss[i][j] - 'a'; 
	}
	for (int i = 0; i < n; i++) cout << (char)(ans[i] + 'a');
	cout << endl;
	return 0;
}