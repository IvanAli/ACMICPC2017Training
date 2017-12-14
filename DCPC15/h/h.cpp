#include <bits/stdc++.h>
using namespace std;

int n, c1, n1, c2, n2;

int gcd(int a, int b, long long& x, long long& y) {
	if (b == 0) {
		x = 1, y = 0;
		return a;
	}
	int ret = gcd(b, a % b, x, y);
	int x1, y1;
	x1 = y;
	y1 = x - (a / b) * y;
	x = x1;
	y = y1;
	return ret;
}


int main() {
	while (cin >> n && n > 0) {
		bool s = false;
		cin >> c1 >> n1 >> c2 >> n2;
		int a = n1, b = n2;
		long long x, y;
		int g = gcd(n1, n2, x, y);
		if (n % g > 0) cout << "failed" << endl;
		else if (x < 0 && y < 0) cout << "failed" << endl;
		else {
			int t = n / g;
			x *= t;
			y *= t;
			if (x >= 0 && y >= 0) {
				if (c1 * b > c2 * a) swap(a, b), swap(x, y), swap(c1, c2), s = true;
				long long l = y / (a / g);
				x += l * (b / g);
				y -= l * (a / g);
				assert(y >= 0);
				if (s) swap(x, y);
				cout << x << " " << y << endl;
			} else if (x < 0 && y >= 0) {
				long long l = y / (a / g);
				x += l * (b / g);
				y -= l * (a / g);
				if (x < 0) cout << "failed" << endl;
				else {
					if (c1 * b > c2 * a) swap(a, b), swap(x, y), swap(c1, c2), s = true;
					l = y / (a / g);
					x += l * (b / g);
					y -= l * (a / g);
					assert(y >= 0);
					if (s) swap(x, y);
					cout << x << " " << y << endl; 
				}		
			} else if (x >= 0 && y < 0) {
				long long l = x / (b / g);
				x -= l * (b / g);
				y += l * (a / g);
				if (y < 0) cout << "failed" << endl;
				else {
					if (c1 * b > c2 * a) swap(a, b), swap(x, y), swap(c1, c2), s = true;
					l = y / (a / g);
					x += l * (b / g);
					y -= l * (a / g);
					assert(y >= 0);
					if (s) swap(x, y);
					cout << x << " " << y << endl; 
				}
			}
		}			
	}
	return 0;
}