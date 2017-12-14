#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int maxn = 50005;

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
} vevents[maxn << 1];

struct sevent {
	int y1, y2, id;
	sevent() {}
	sevent(int y1, int y2, int id) : y1(y1), y2(y2), id(id) {}
	bool operator<(const sevent& e) const {
		if (y2 == e.y2) return id < e.id;
		return y2 < e.y2;
	}
};

int n;
int from[maxn];
int rarea[maxn];
int comarea[maxn];

int find(int x) {
	if (x == from[x]) return x;
	return from[x] = find(from[x]);
}

int main() {
	scanf("%d", &n);
	int sz = 0;
	for (int i = 0; i < n; i++) {
		int x, y, w, h; scanf("%d%d%d%d", &x, &y, &w, &h);
		rarea[i] = w * h;
		vevents[sz++] = {x, y, y + h, i, ebegin};
		vevents[sz++] = {x + w, y, y + h, i, eend};
		from[i] = i;
	}
	sort(vevents, vevents + sz);
	set<sevent> activey2;
	for (int i = 0; i < sz; i++) {
		event cur = vevents[i];
		int x, y1, y2, id; etype type; x = cur.x, y1 = cur.y1, y2 = cur.y2, id = cur.id, type = cur.type;
		if (type == ebegin) {
			/*set<sevent>::iterator by1 = lower_bound(activey1.begin(), activey1.end(), sevent(y1, -1));
			set<sevent>::iterator ey1 = upper_bound(activey1.begin(), activey1.end(), sevent(y2, maxn));
			for (auto it = by1; it != ey1; it++) {
				int si = find(it->id), sj = find(id);
				if (si != sj) {
					from[si] = sj;
				}
			}*/
//			set<sevent>::iterator by2 = lower_bound(activey2.begin(), activey2.end(), sevent(y1, y1, -1));
			set<sevent>::iterator by2 = activey2.lower_bound(sevent(y1, y1, -1));
			for (auto it = by2; it != activey2.end(); it++) {
				if (y1 <= it->y1 && y2 >= it->y2 || y1 >= it->y1 && y1 <= it->y2 || y2 >= it->y1 && y2 <= it->y2) {
					int si = find(it->id), sj = find(id);
					if (si != sj) from[si] = sj;
				} else break;
			}
			activey2.insert({y1, y2, id});
		} else if (type == eend) {
			activey2.erase({y1, y2, id});
		}
	}
	for (int i = 0; i < n; i++) comarea[find(i)] += rarea[i];
	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, comarea[i]);
	printf("%d\n", ans); 
	return 0;
}