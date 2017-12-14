#include <bits/stdc++.h>

using namespace std;

enum event_t {
  EVENT_START,
  EVENT_END
};

struct event {
  int x; event_t type;

  event() {}

  event(int x, event_t type) : x(x), type(type) {}

  bool operator < (const event &other) const {
    if (x == other.x) return type < other.type;
    return x < other.x;
  }
};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  int n;
  scanf("%d", &n);
  vector<event> events;
  for (int i = 0; i < n; i++) {
    int a, b; scanf("%d %d", &a, &b);
    events.push_back(event(a, EVENT_START));
    events.push_back(event(b, EVENT_END));
  }
  sort(events.begin(), events.end());
  long long past = 0, future = 0;
  for (auto e : events) {
    if (e.type == EVENT_START) future += e.x;
  }
  long long mndon = 0, mxsum = 0;
  int cnt = 0;
  for (auto e : events) {
    int x = e.x; event_t type = e.type;
    if (future + (long long) x * cnt > mxsum) {
      mndon = x;
      mxsum = future + (long long) x * cnt;
    }
    if (type == EVENT_START) {
      future -= x;
      cnt++;
    } else {
      cnt--;
      past = x;
    }
  }
  printf("%lld %lld\n", mndon, mxsum);
  return 0;
}