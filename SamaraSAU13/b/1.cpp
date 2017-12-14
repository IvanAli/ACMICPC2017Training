#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define y0 yoloswag
using namespace std;

const int N = 200005;

int n;
long long x[N], y[N];

long long tarea(int i, int j, int k) {
	i %= n;
	j %= n;
	k %= n;
	long long x0 = x[i], y0 = y[i];
	long long x1 = x[j], y1 = y[j];
	long long x2 = x[k], y2 = y[k];
	long long ret = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
	if (ret < 0) return ret; 
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lld%lld", x + i, y + i);
	long long ans = 1ll << 60;
	long long area = 0;
	for (int i = 0; i < n; i++) {
		area += x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
	}
	if (area < 0) area = -area;
	long long cur = 0;
	int aa = -1, bb = -1;
	for (int i = 0, j = 0; i < n; i++) {
		while (true) {
			long long t = tarea(i, j, j + 1);
			if (2 * (cur + t) > area) break; 	
			cur += t;
			j++;
			if (j == n) j = 0;
		}
		long long t = tarea(i, j, j + 1);
		if (llabs(area - 2 * cur) < ans) {
//			assert(area - (area - cur) >= 0);
			ans = llabs(area - 2 * cur);
			aa = i, bb = j;
		}
		if (llabs(area - 2 * (cur + t)) < ans) {
//			assert(area - (area - cur - t) >= 0);
			ans = llabs(area - 2 * (cur + t));
			aa = i, bb = j + 1;
		}
		cur -= tarea(i, i + 1, j);
	}
	printf("%d %d\n", aa + 1, bb + 1);
	return 0;
}