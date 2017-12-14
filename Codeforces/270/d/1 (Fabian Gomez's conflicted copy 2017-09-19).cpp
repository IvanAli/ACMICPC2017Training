#include <bits/stdc++.h>

using namespace std;

int find(int x) {
  return (x == from[x] ? x : from[x] = find(from[x]));
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    scanf("%d", d[i] + j);
    edges.push_back(make_pair(d[i][j], make_pair(i, j)));
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
    if (i == j) {
      if (d[i][j] > 0) {
        puts("NO");
        return 0;
      }
    } else {
      if (d[i][j] != d[j][i]) {
        puts("NO");
        return 0;
      }
    }
  }
  sort(edges.begin(), edges.end());
  for (int i = 0; i < n; i++) from[i] = i;
  for (int i = 0; i < (int) edges.size(); i++) {
    int w = edges[i].first, a = edges[i].second.first, b = edges[i].second.second;
    int x = find(a), y = find(b);
    if (x != y) {
      from[x] = y;
    }
  }
  return 0;
}