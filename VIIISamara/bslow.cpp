#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int p, n, x;
map<int, int> dist;

int main() {
	cin >> p >> n >> x;
	queue<int> q;
	q.push(0);
	dist[0] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		int nxt;
		if (cur == x) {
			return cout << dist[cur] << endl, 0;
		}
		nxt = cur + 1;
		if (nxt > n) nxt = n;
		if (!dist.count(nxt)) {
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
		nxt = cur - 1;
		if (nxt < 0) nxt = 0;
		if (!dist.count(nxt)) {
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
		nxt = cur + p;
		if (nxt > n) nxt = n;
		if (!dist.count(nxt)) {
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
		nxt = cur - p;
		if (nxt < 0) nxt = 0;
		if (!dist.count(nxt)) {
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
	assert(0);
	return 0;
}
