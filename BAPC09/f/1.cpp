#include <bits/stdc++.h>

using namespace std;

const int N = 12345;
const int mod = 11;

int st[12], fin[12];
int year[N];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int sub(int a, int b) {
  int ret = a - b;
  if (ret < 0) ret += mod;
  return ret;
}

int mul(int a, int b) {
  return a * b % mod;
}

int power(int x, int e) {
  int ret = 1, res = x;
  while (e) {
    if (e & 1) ret = mul(ret, res);
    res = mul(res, res);
    e >>= 1;
  }
  return ret;
}

int inv(int x) {
  return power(x, mod - 2);
}

class gaussian_elimination {
  public:
  int n, m;
  vector<vector<int> > a;
  vector<int> where;
  vector<int> ans;

  gaussian_elimination(vector<vector<int> > a) : a(a) {
    n = (int) a.size();
    m = (a.empty() ? 0 : (int) a[0].size());
    where.resize(m, -1);
    ans.resize(m - 1, 0);
  }

  pair<vector<int>, int> solve() {
    for (int row = 0, col = 0; row < n && col + 1 < m; col++) {
      int sel = row;
      int sel_col = col;
      for (int j = col + 1; j + 1 < m; j++) {
        if (year[j] < year[sel_col]) sel_col = j;
      }
      if (col != sel_col) for (int i = 0; i < n; i++) swap(a[i][col], a[i][sel_col]);
      for (int i = row + 1; i < n; i++) {
        if (abs(a[i][col]) > abs(a[sel][col])) sel = i;
//        if (a[i][col] > 0 && year[i] < year[sel]) sel = i;
      }
      if (a[sel][col] == 0) {
        continue;
      }
      if (row != sel) swap(a[row], a[sel]);
      where[col] = row;
      for (int i = 0; i < n; i++) {
        if (i == row) continue;
        int c = mul(a[i][col], inv(a[row][col]));
        for (int j = col; j < m; j++) {
          a[i][j] = sub(a[i][j], mul(a[row][j], c));
        }
      }
      row++;
    }
    for (int i = 0; i + 1 < m; i++) {
      if (where[i] > -1) {
        ans[i] = mul(a[where[i]][m - 1], inv(a[where[i]][i])); 
      }
    }
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j + 1 < m; j++) {
        sum = add(sum, mul(a[i][j], ans[j]));
      }
      if (sum != a[i][m - 1]) return make_pair(ans, 0);
    }
    for (int i = 0; i + 1 < m; i++) if (where[i] == -1) return make_pair(ans, (int) 1e9);
    return make_pair(ans, 1);
  } 

};

void print(vector<vector<int> > &a) {
  int n = a.size(), m = a[0].size();
  fprintf(stderr, "n: %d m: %d\n", n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) fprintf(stderr, "%d ", a[i][j]);
    fprintf(stderr, "\n");
  }
  fputs("-------__", stderr);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) {
    int n; scanf("%d", &n);
    for (int i = 0; i < 11; i++) scanf("%d", st + i);
    for (int i = 0; i < 11; i++) scanf("%d", fin + i);
    vector< vector<int> > a(11, vector<int>(n + 1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 11; j++) {
        scanf("%d", &a[j][i]);
      }
      scanf("%d", year + i);
    }
    for (int i = 0; i < 11; i++) a[i][n] = sub(fin[i], st[i]);
//    print(a);
    gaussian_elimination ge(a);
    auto sol = ge.solve();
    if (sol.second == 0) {
      puts("unreachable");
      continue;
    }
    vector<int> ve = sol.first;
    int ans = 12345;
    for (int i = 0; i < n; i++) ans = min(ans, year[i]);
    for (int i = 0; i < (int) ve.size(); i++) {
      if (ve[i] > 0) ans = max(ans, year[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}