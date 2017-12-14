#include <bits/stdc++.h>
#define pb push_back
using namespace std;

enum etype {
	ebegin,
	eend
};

struct event {
	int x, y1, y2, id;
	etype type;
	event() {}
	event(int x, int y1, int y2, int id, etype type) : x(x), y1(y1), y2(y2), id(id), type(type) {}
	bool operator<(const event& e) const {
		if (x == e.x) {
			if (type == e.type) {
				if (y1 == e.y1) return y2 < e.y2;
				return y1 < e.y1;
			}
			return type < e.type;			
		}
		return x < e.x;
	}
};

struct sevent {
	int y, id;
	sevent() {}
	sevent(int y, int id) : y(y), id(id) {}
	bool operator<(const sevent& e) const {
		if (y == e.y) return id < e.id;
		return y < e.y;
	}
};


const int maxn = 50005;

int n;
vector<event> vevents;
int from[maxn];
int rarea[maxn];
int comarea[maxn];

int find(int x) {
	if (x == from[x]) return x;
	return from[x] = find(from[x]);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, w, h; scanf("%d%d%d%d", &x, &y, &w, &h);
		rarea[i] = w * h;
		vevents.pb({x, y, y + h, i, ebegin});
		vevents.pb({x + w, y, y + h, i, eend});
		from[i] = i;
	}
	sort(vevents.begin(), vevents.end());
	set<sevent> activey1, activey2;
	for (int i = 0; i < vevents.size(); i++) {
		event cur = vevents[i];
		int x, y1, y2, id; etype type; x = cur.x, y1 = cur.y1, y2 = cur.y2, id = cur.id, type = cur.type;
		set<sevent>::iterator by1 = activey1.lower_bound(sevent(y1, -1));
		set<sevent>::iterator ey1 = activey1.upper_bound(sevent(y2, maxn));
		for (auto it = by1; it != ey1; it++) {
			int si = find(it->id), sj = find(id);
			if (si != sj) {
				from[si] = sj;
			}
		}
		set<sevent>::iterator by2 = activey2.lower_bound(sevent(y1, -1));
		set<sevent>::iterator ey2 = activey2.upper_bound(sevent(y2, maxn));
		for (auto it = by2; it != ey2; it++) {
			int si = find(it->id), sj = find(id);
			if (si != sj) {
				from[si] = sj;
			}
		}
		if (type == ebegin) {
			activey1.insert({y1, id});
			activey2.insert({y2, id});
		} else if (type == eend) {
			activey1.erase({y1, id});
			activey2.erase({y2, id});
		}
	}
	for (int i = 0; i < n; i++) comarea[find(i)] += rarea[i];
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, comarea[i]);
	printf("%d\n", ans); 
	return 0;
}