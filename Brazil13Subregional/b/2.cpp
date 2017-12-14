#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

enum event_t {
  EVENT_BEGIN,
  EVENT_BAL,
  EVENT_END
};

struct event {
  int x, id; event_t type;
  event() {}
  event(int x, int id, event_t type) : x(x), id(id), type(type) {}
  bool operator < (const event &other) const {
    if (x == other.x) return type < other.type;
    return x < other.x;
  }
};

enum shape_t {
  HT,
  LF,
  RG,
  DOT
};

int n, q;
vector<event> events;
pair<int, int> mem[N];
int lx1[N], ly1[N], lx2[N], ly2[N];
shape_t shape[N];
int first[N + N];
int qs[N];

long long cross(int xa, int ya, int xb, int yb) {
  return (long long) xa * yb - (long long) xb * ya;
}

bool cmpy(int i, int j) {
  if (lx1[i] < lx1[j]) {
    return cross(lx2[i] - lx1[i], ly2[i] - ly1[i], lx1[j] - lx1[i], ly1[j] - ly1[i]) > 0;
  } else {
    return cross(lx2[j] - lx1[j], ly2[j] - ly1[j], lx1[i] - lx1[j], ly1[i] - ly1[j]) < 0;
  }
}

multiset<int, bool(*) (int, int)> sy(cmpy);

int find(int id) {
  auto it = sy.find(id);
  it++;
  if (it == sy.end()) return -1;
  return *it;
}

pair<int, int> go(int id) {
  if (mem[id] != make_pair(-1, -1)) return mem[id];
  int nxt = first[id];
  if (nxt == -1) {
    return mem[id] = make_pair(qs[id - n], -1);
  }
  int nxtnxt = first[nxt];
  if (nxtnxt == -1) {
    assert(shape[nxt] != HT);
    if (shape[nxt] == LF) {
      return mem[id] = make_pair(lx1[nxt], -1);
    } else if (shape[nxt] == RG) {
      return mem[id] = make_pair(lx2[nxt], -1);
    }
  } else if (nxt == nxtnxt) {
    if (shape[id] == LF) {
      return mem[id] = make_pair(lx1[id], ly1[nxt]);
    } else if (shape[id] == RG) {
      return mem[id] = make_pair(lx2[id], ly1[nxt]);
    } else if (shape[id] == DOT) {
      return mem[id] = make_pair(qs[id - n], ly1[nxt]);
    }
  }
  return mem[id] = go(nxt);
}

int main() {
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    if (x1 > x2) {
      swap(x1, x2);
      swap(y1, y2);
    }
    lx1[i] = x1, ly1[i] = y1, lx2[i] = x2, ly2[i] = y2;
    if (y1 == y2) shape[i] = HT;
    else if (y1 < y2) shape[i] = RG;
    else shape[i] = LF;
    events.push_back(event(x1, i, EVENT_BEGIN));
    events.push_back(event(x2, i, EVENT_END));
  }
  for (int i = 0; i < q; i++) shape[i + n] = DOT;
  for (int i = 0; i < q; i++) {
    scanf("%d", qs + i);
    events.push_back(event(qs[i], i, EVENT_BAL));
  }
  for (int i = 0; i < n + q; i++) mem[i] = make_pair(-1, -1);
  sort(events.begin(), events.end());
  set<int> sx;
  for (int i = 0; i < (int) events.size(); i++) {
    event e = events[i];
    int x = e.x, id = e.id; event_t type = e.type;
    if (type == EVENT_BEGIN) {
      sy.insert(id);
      sx.insert(id);
      if (shape[id] == LF) {
        first[id] = find(id);
      }
      if (shape[id] == HT) {
        first[id] = id;
      }
    } else if (type == EVENT_END) {
      if (sy.empty()) assert(0);
      if (shape[id] == RG) {
        first[id] = find(id);
      }
      if (shape[id] == HT) {
        first[id] = id;
      }
      auto prit = sy.equal_range(id);
      for (auto it = prit.first; it != prit.second; it++) {
        if (sx.count(*it)) {
          sx.erase(*it);
          sy.erase(it);
          break;
        }
      }
    } else if (type == EVENT_BAL) {
      if (sy.empty()) first[id + n] = -1;
      else first[id + n] = *sy.begin();
    }
  }
  for (int i = 0; i < q; i++) {
    pair<int, int> ans = go(i + n);
    int x = ans.first, y = ans.second;
    if (y == -1) printf("%d\n", x);
    else printf("%d %d\n", x, y);
  }
  return 0;
}