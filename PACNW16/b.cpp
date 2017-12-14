#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[20], p[20];
set<int> st;

void solve(int i = 0, int suma = 0, int sumb = 0) {
	if (suma == sumb) for (int j = 0; j < n; j++) st.insert(b[j] + suma + sumb);
	if (i == m) return;
	solve(i + 1, suma + p[i], sumb);
	solve(i + 1, suma, sumb + p[i]);
	solve(i + 1, suma, sumb); 
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < m; i++) cin >> p[i];
	solve();
	for (auto it = st.begin(); it != st.end(); it++) cout << *it << endl;
	return 0;
}