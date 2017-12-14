#include <bits/stdc++.h>
#define y1 sadkasodk
#define pb push_back
#define fst first
#define snd second
using namespace std;

const int maxn = 100005;

int k;
map<pair<int, int>, int> xy;
map<pair<int, pair<int, int> >, int> xyz;
int fromxy[maxn];
int fromxyz[maxn];
set<pair<int, int> > exy;
set<pair<int, int> > exyz;
int xycnt, xyzcnt;

int findxy(int x) {
	if (x == fromxy[x]) return x;
	return fromxy[x] = findxy(fromxy[x]);
}

int findxyz(int x) {
	if (x == fromxyz[x]) return x;
	return fromxyz[x] = findxyz(fromxyz[x]);
}

int main() {
	cin >> k;
	bool okxy = true, okxyz = true;
	for (int i = 0; i < k; i++) {
		int x1, y1, z1, x2, y2, z2;
		cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
		if (!xyz.count({x1, {y1, z1}})) xyz[{x1, {y1, z1}}] = xyzcnt++;
		if (!xyz.count({x2, {y2, z2}})) xyz[{x2, {y2, z2}}] = xyzcnt++;
		if (!xy.count({x1, y1})) xy[{x1, y1}] = xycnt++;
		if (!xy.count({x2, y2})) xy[{x2, y2}] = xycnt++;
		int u, v;
		u = xy[{x1, y1}], v = xy[{x2, y2}];
		if (u != v) exy.insert({min(u, v), max(u, v)});
		u = xyz[{x1, {y1, z1}}], v = xyz[{x2, {y2, z2}}];
		if (u != v) exyz.insert({min(u, v), max(u, v)});
	}
	for (int i = 0; i < xycnt; i++) fromxy[i] = i;
	for (int i = 0; i < xyzcnt; i++) fromxyz[i] = i;
	for (auto e : exy) {
		int x, y;
		x = findxy(e.fst);
		y = findxy(e.snd);
		if (x != y) fromxy[x] = y;
		else okxy = false;
	}
	for (auto e : exyz) {
		int x, y;
		x = findxyz(e.fst);
		y = findxyz(e.snd);
		if (x != y) fromxyz[x] = y;
		else okxyz = false;
	}
	if (okxyz) cout << "No true closed chains" << endl;
	else cout << "True closed chains" << endl;
	if (okxy) cout << "No floor closed chains" << endl;
	else cout << "Floor closed chains" << endl;
	return 0;
}
