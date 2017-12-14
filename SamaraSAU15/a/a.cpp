#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1.0);

double a, b, c, r;

double cot(double a) {
//	return 1 / tan(a);
	return cos(a) / sin(a);
}

int main() {
	cin >> a >> b >> c >> r;
	double alpha = acos((a * a + b * b - c * c) / (a * b * 2.));
	double beta = acos((c * c + b * b - a * a) / (b * c * 2.));
	double gamma = acos((c * c + a * a - b * b) / (a * c * 2.));
	double s = (a + b + c) / 2.;
	double tarea = sqrt(s * (s - a) * (s - b) * (s - c));
	double ans = tarea;
	ans -= cot(alpha / 2.0) * r * r;
	ans -= cot(beta / 2.0) * r * r;
	ans -= cot(gamma / 2.0) * r * r;
	ans += ((pi - alpha) / (2.)) * r * r;
	ans += ((pi - beta) / (2.)) * r * r;
	ans += ((pi - gamma) / (2.)) * r * r;
	cout << setprecision(10) << fixed << ans / tarea << endl;
	return 0;
}