#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int MAX = 12345;
const int inf = 1234567;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int x[MAX], y[MAX];
int id[N][N];
int n, m;
char grid[N][N];
map<tuple<int, int, int>, int> dist;

void print() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j > 0) putchar(' ');
      if (id[i][j] > -1) printf("%d", id[i][j]);
      else putchar(grid[i][j]);
    }
    puts("");
  }
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    dist.clear();
    for (int i = 0; i < n; i++) scanf("%s", grid[i]);
    int xs = -1, ys = -1;
    int xe = -1, ye = -1;
    int sz = 0;
    vector<pair<int, int> > cubes, btn;
    memset(id, -1, sizeof id);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] != '#') {
          id[i][j] = sz;
          x[sz] = i;
          y[sz] = j;
          sz++;
        }
        if (grid[i][j] == 'S') {
          xs = i;
          ys = j;
        }
        if (grid[i][j] == 'X') {
          cubes.emplace_back(i, j);
        }
        if (grid[i][j] == 'B') {
          btn.emplace_back(i, j);
        }
        if (grid[i][j] == 'E') {
          xe = i;
          ye = j;
        }
      }
    }
    x[sz] = -1;
    y[sz] = -1;
    if (btn.size() > cubes.size()) {
      puts("impossible");
      continue;
    }
    queue<tuple<int, int, int> > q;
    if ((int) cubes.size() == 0) {
      tuple<int, int, int> t = make_tuple(id[xs][ys], sz, sz);
      q.push(t);
      dist[t] = 0;
    } else if ((int) cubes.size() == 1) {
      tuple<int, int, int> t = make_tuple(id[xs][ys], id[cubes[0].first][cubes[0].second], sz);
      q.push(t);
      dist[t] = 0;
    } else if ((int) cubes.size() == 2) {
      tuple<int, int, int> t = make_tuple(id[xs][ys], id[cubes[0].first][cubes[0].second], id[cubes[1].first][cubes[1].second]);
      q.push(t);
      dist[t] = 0;
    } else assert(0);
    while (!q.empty()) {
      auto ft = q.front(); q.pop();
      int v, s1, s2; tie(v, s1, s2) = ft;
      int xv = x[v], yv = y[v];
      int xs1 = x[s1], ys1 = y[s1];
      int xs2 = x[s2], ys2 = y[s2];
      for (int k = 0; k < 4; k++) {
        int xk = xv + dx[k];
        int yk = yv + dy[k];
        if (0 <= xk && xk < n && 0 <= yk && yk < m) {
          if (id[xk][yk] > -1) {
            int x2k = xv + 2 * dx[k];
            int y2k = yv + 2 * dy[k];
            if (xk == xs1 && yk == ys1) {
              if (0 <= x2k && x2k < n && 0 <= y2k && y2k < m && id[x2k][y2k] > -1 && id[x2k][y2k] != s2) {
                tuple<int, int, int> t = make_tuple(id[xk][yk], id[x2k][y2k], s2);
                if (!dist.count(t)) {
                  dist[t] = dist[ft] + 1;
                  q.push(t);
                }
              }
            } else if (xk == xs2 && yk == ys2) {
              if (0 <= x2k && x2k < n && 0 <= y2k && y2k < m && id[x2k][y2k] > -1 && id[x2k][y2k] != s1) {
                tuple<int, int, int> t = make_tuple(id[xk][yk], s1, id[x2k][y2k]);
                if (!dist.count(t)) {
                  dist[t] = dist[ft] + 1;
                  q.push(t);
                }
              }
            } else {
              tuple<int, int, int> t = make_tuple(id[xk][yk], s1, s2);
              if (!dist.count(t)) {
                dist[t] = dist[ft] + 1;
                q.push(t);
              }
            }
          }
        }
      }  
    }
    int ans = inf;
    if (btn.size() == 0) {
      for (int i = 0; i <= sz; i++) for (int j = 0; j <= sz; j++) {
        tuple<int, int, int> t = make_tuple(id[xe][ye], i, j);
        if (dist.count(t)) {
          ans = min(ans, dist[t]);
        }
      }
    } else if (btn.size() == 1) {
      int btn_id = id[btn[0].first][btn[0].second];
      for (int i = 0; i <= sz; i++) {
        tuple<int, int, int> t = make_tuple(id[xe][ye], btn_id, i);
        if (dist.count(t)) {
          ans = min(ans, dist[t]);
        }
        t = make_tuple(id[xe][ye], i, btn_id);
        if (dist.count(t)) {
          ans = min(ans, dist[t]);
        }
      }
    } else if (btn.size() == 2) {
      int btn1_id = id[btn[0].first][btn[0].second];
      int btn2_id = id[btn[1].first][btn[1].second];
      tuple<int, int, int> t = make_tuple(id[xe][ye], btn1_id, btn2_id);
      if (dist.count(t)) {
        ans = min(ans, dist[t]);
      }
      t = make_tuple(id[xe][ye], btn2_id, btn1_id);
      if (dist.count(t)) {
        ans = min(ans, dist[t]);
      }
    } else assert(0);
    if (ans == inf) puts("impossible");
    else printf("%d\n", ans);
  }
  return 0;
}