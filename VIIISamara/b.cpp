#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

long long p, n, x;

int gety(int n) {
	return n / p;
}

int getx(int n) {
	return n % p;
}

int allrows() {
	return min(n, p);
}

int allcols() {
	return gety(n) + 1;
}

int manh(int p) {
	return getx(p) + gety(p);
}

int stress() {
	unordered_map<int, int> dist;
	dist.reserve(1000000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({manh(0), 0});
	dist[0] = 0;
	while (!q.empty()) {
		auto ft = q.top(); q.pop();
		int cur = ft.second;
		int nxt;
		if (cur == x) {
			return dist[cur];
		}
		nxt = cur + 1;
		if (nxt > n) nxt = n;
		int cost = dist[cur];
		if (!dist.count(nxt) || cost + 1 < dist[nxt]) {
			dist[nxt] = dist[cur] + 1;
			q.push({dist[nxt] + manh(nxt), nxt});
		}
		nxt = cur - 1;
		if (nxt < 0) nxt = 0;
		if (!dist.count(nxt) || cost + 1 < dist[nxt]) {
			dist[nxt] = dist[cur] + 1;
			q.push({dist[nxt] + manh(nxt), nxt});
		}
		nxt = cur + p;
		if (nxt > n) nxt = n;
		if (!dist.count(nxt) || cost + 1 < dist[nxt]) {
			dist[nxt] = dist[cur] + 1;
			q.push({dist[nxt] + manh(nxt), nxt});
		}
		nxt = cur - p;
		if (nxt < 0) nxt = 0;
		if (!dist.count(nxt) || cost + 1 < dist[nxt]) {
			dist[nxt] = dist[cur] + 1;
			q.push({dist[nxt] + manh(nxt), nxt});
		}
	}
	return -1;
}

int manhattan(int a, int b) {
	return abs(getx(a) - getx(b)) + abs(gety(a) - gety(b));
}

void test() {
	srand(time(0));
	for (int i = 0; i < 3000; i++) {
		n = rand()%1000 + 1;
		p = rand()%1000 + 1;
		x = rand()%n + 1;
		// auto ans1 = stress();

		int ans = getx(x) + gety(x);
		ans = min(ans, allrows() - getx(x) + gety(x) + 1);
		ans = min(ans, allcols() + manhattan(n, x));
		// cerr << "caso " << i << endl;
		// fprintf(stderr, "case: p: %lld n: %lld x: %lld\n", p, n, x);
		// fprintf(stderr, "ans: %d ans1: %d\n", ans, ans1);
		// assert(ans == ans1);

	}

}

int main() {
	// test();
	cin >> p >> n >> x;
	// cout << stress() << endl;
	int ans = getx(x) + gety(x);
	ans = min(ans, allrows() - getx(x) + gety(x) + 1);
	ans = min(ans, allcols() + manhattan(n, x));
	// cerr << getx(x) << endl;
	// cerr << gety(x) << endl;
	// int ans = getx(x) + gety(x);
	// ans = min(ans, allrows() - getx(x) + gety(x) + 1);
	cout << ans << endl;
	return 0;
}
