#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int mod = 1000000;                

long long n, m, l;

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod) ret -= mod;
  return ret;
}

int mul(int a, int b) {
  return (long long) a * b % mod;
}

vector<vector<int>> mat_mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  int n = (int) a.size();
  int m = (int) b[0].size();
  assert((int) a[0].size() == (int) b.size());
  int o = (int) a[0].size();
  vector<vector<int>> ret(n, vector<int>(m));
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < o; k++) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
  return ret;
}

vector<vector<int>> power(vector<vector<int>> res, long long e) {
  vector<vector<int>> ret(2, vector<int>(2));
  for (int i = 0; i < 2; i++) ret[i][i] = 1;
  while (e) {
    if (e & 1) ret = mat_mul(ret, res);
    res = mat_mul(res, res);
    e >>= 1;
  }
  return ret;
}


int main() {
  scanf("%lld %lld %lld", &n, &m, &l);
  vector<vector<int>> mat(2, vector<int>(2));
  mat[0][0] = m % mod, mat[0][1] = l % mod, mat[1][0] = 1;
  vector<vector<int>> col(2, vector<int>(1));
  col[0][0] = m % mod, col[1][0] = 1;
  long long t = n / 5;
  vector<vector<int>> res = power(mat, t - 1);
  vector<vector<int>> ans = mat_mul(res, col);
  printf("%06d\n", ans[0][0]);
  return 0;
}