#include <bits/stdc++.h>
using namespace std;


int main() {
	srand(time(0));
	int t = 100000;
	cout << t << endl;
	for (int i = 0; i < t; i++) {
		int b = rand() % 100000 + 1;
		b = max(b, 2);
		int a = rand() % b;
		a = max(a, 1);
		cout << a << " " << b << endl;
	}
	return 0;
}