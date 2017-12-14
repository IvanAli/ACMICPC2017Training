#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int M = 5005;
const int Y = 366;

long long dp[Y][M][2];
int pb[M];
int st[M], fin[M], id[M], cost[M];
int pr[M];

//set< pair<int, int> > st[N];
vector< pair<pair<int, int>, int> > hotel[N];
tuple<int, int, int> from[Y][M][2];
vector<int> ve_ans;


void build(int i, int j, int k) {
  if (i == 0) return;
  int ii, jj, kk; tie(ii, jj, kk) = from[i][j][k];
  if (dp[ii][jj][kk] != dp[i][j][k]) ve_ans.push_back(j);
  build(ii, jj, kk);
}

int main() {
  int y, n, s;
  scanf("%d %d %d", &y, &n, &s);
  int h, m;
  scanf("%d %d", &h, &m);
  for (int i = 0; i < m; i++) {
    pb[i] = i;
  }
//  memset(have, -1, sizeof have);
  for (int i = 0; i < m; i++) {
    int w, b, e, c;
    scanf("%d %d %d %d", &w, &b, &e, &c);
    w--;
    id[i] = w;
    st[i] = b;
    fin[i] = e;
    cost[i] = c;
//    st[id].insert(make_pair(fin[i], i));
    hotel[id[i]].push_back(make_pair(make_pair(fin[i], st[i]), i));
   // segs_b[i] = seg(id, b, e, c);
   // segs_e[i] = seg(id, b, e, c);
  }
  for (int i = 0; i < m; i++) {
    sort(hotel[i].begin(), hotel[i].end());
  }
  sort(pb, pb + m, [&](const int i, const int j) {
    if (st[i] == st[j]) return fin[i] < fin[j];
    return st[i] < st[j];
  });
  /*
  sort(segs_a, segs_a + m, [&](const seg &a, const seg &b) {
    if (a.b == b.b) return a.e < b.e;
    return a.b < b.b;
  });
  sort(segs_b, segs_b + m, [&](const seg &a, const seg &b) {
    if (a.e == b.e) return a.b < b.b;
    return a.e < b.e;
  });
  */
  memset(pr, -1, sizeof pr);
  for (int i = 0; i < m; i++) {
    int w = pb[i];
    for (int j = 0; j < h; j++) {
      if (hotel[j].empty()) continue;
      int low = 0, high = (int) hotel[j].size() - 1, mid;
      if (j == id[w]) {
        while (low < high) {
          mid = low + high + 1 >> 1;
          if (hotel[j][mid].first.first < st[w]) low = mid;
          else high = mid - 1;
        }
        if (hotel[j][low].first.first < st[w]) {
          if (pr[w] == -1 || hotel[j][low].first.first > pr[w]) pr[w] = hotel[j][low].second;
        }
      } else {
        while (low < high) {
          mid = low + high + 1 >> 1;
          if (hotel[j][mid].first.first <= st[w]) low = mid;
          else high = mid - 1;
        }
        if (hotel[j][low].first.first <= st[w]) {
          if (pr[w] == -1 || hotel[j][low].first.first > pr[w]) pr[w] = hotel[j][low].second;
        }
      }
    }
  }
  for (int i = 0; i < Y; i++) for (int j = 0; j < M; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = (long long) 1e18;
  for (int k = 0; k < 2; k++) dp[0][0][k] = 0;
  for (int i = 1; i < Y; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (k == 0) { // night
          int days = fin[pb[j]] - st[pb[j]];
          assert(days > 0);
          if (cost[pb[j]] + (i - days >= 0 ? dp[i - days][pr[pb[j]] + 1][k] : 0) < dp[i][pb[j] + 1][k]) {
            dp[i][pb[j] + 1][k] = min(dp[i][pb[j] + 1][k], cost[pb[j]] + (i - days >= 0 ? dp[i - days][pr[pb[j]] + 1][k] : 0));
            from[i][pb[j] + 1][k] = make_tuple(i - days, pr[pb[j]] + 1, k);
   //         have[i][pb[j] + 1][k] = 1;
          }
          if (j > 0) {
            if (dp[i][pb[j - 1] + 1][k] < dp[i][pb[j] + 1][k]) {
              dp[i][pb[j] + 1][k] = min(dp[i][pb[j] + 1][k], (j > 0 ? dp[i][pb[j - 1] + 1][k] : 0));
              from[i][pb[j] + 1][k] = make_tuple(i, pb[j - 1] + 1, k);
            }
          }
        } else { // stays
          if (cost[pb[j]] + (i - 1 >= 0 ? dp[i - 1][pr[pb[j]] + 1][k] < dp[i][pb[j] + 1][k] : 0)) {
            dp[i][pb[j] + 1][k] = min(dp[i][pb[j] + 1][k], cost[pb[j]] + (i - 1 >= 0 ? dp[i - 1][pr[pb[j]] + 1][k] : 0));
            from[i][pb[j] + 1][k] = make_tuple(i - 1, pr[pb[j]] + 1, k);
 //           have[i][pb[j] + 1][k] = 1;
          }
          if (j > 0) {
            if (dp[i][pb[j - 1] + 1][k] < dp[i][pb[j] + 1][k]) {
              dp[i][pb[j] + 1][k] = min(dp[i][pb[j] + 1][k], (j > 0 ? dp[i][pb[j - 1] + 1][k] : 0));
              from[i][pb[j] + 1][k] = make_tuple(i, pb[j - 1] + 1, k);
            }
          }
        }
      }
    }
  }
  long long ans = (long long) 1e18;
  int ii = -1, jj = -1, kk = -1;
  bool what = false; // night
  for (int i = n; i < Y; i++) for (int j = 1; j <= m; j++) {
    if (dp[i][j][0] < ans) {
      ans = min(ans, dp[i][j][0]);
      ii = i, jj = j, kk = 0;
    }
  }
  for (int i = s; i < Y; i++) for (int j = 1; j <= m; j++) {
    if (dp[i][j][1] < ans) {
      ans = min(ans, dp[i][j][1]);
      what = true;
      ii = i, jj = j, kk = 1;
    }
  }
  if (ans >= (long long) 1e18) {
    puts("IMPOSSIBLE");
  } else {
    assert(ii > -1 && jj > -1 && kk > -1);
    build(ii, jj, kk);
    sort(ve_ans.begin(), ve_ans.end());
    if (what) puts("STAYS");
    else puts("NIGHTS");
 //   printf("%lld\n", ans);
   printf("%d\n", (int) ve_ans.size());
    for (int i = 0; i < (int) ve_ans.size(); i++) {
      if (i > 0) putchar(' ');
      printf("%d", ve_ans[i]);
    }
//    printf("%lld\n", ans);
  }
  return 0;
}