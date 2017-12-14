#include <bits/stdc++.h>

using namespace std;

const int MAX = 100005;
const int M = 123;

char s[M];

struct trie {
  int tree[MAX][26];
  int cnt[MAX];
  int depth[M];
  int sz = 1;

  void clear() {
    memset(tree, 0, sizeof tree);
    memset(cnt, 0, sizeof cnt);
    memset(depth, 0, sizeof depth);
    sz = 1;
  }

  void insert(char *s) {
    int id = 0;
    for (int i = 0; s[i]; i++) {
      int z;
      if ('a' <= s[i] && s[i] <= 'z') z = s[i] - 'a';
      else if ('A' <= s[i] && s[i] <= 'Z') z = s[i] - 'A';
      else assert(0);
      if (tree[id][z] == 0) {
        tree[id][z] = sz++;
      }
      id = tree[id][z];
      cnt[id]++;
      depth[i + 1] = max(depth[i + 1], cnt[id]);
    }
  }

  pair<int, int> go() {
    for (int i = M - 1; i >= 0; i--) {
      if (depth[i] >= 3) {
        return make_pair(i, depth[i]);
      }
    }
    return make_pair(-1, -1);
  }
} tree;

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    printf("Case %d:\n", tc + 1);
    int n;
    scanf("%d", &n);
    tree.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      for (int i = 0; i < len / 2; i++) swap(s[i], s[len - i - 1]);
      tree.insert(s);
    }
    pair<int, int> ans = tree.go();
    if (ans.first == -1) assert(0);
    printf("%d %d\n", ans.first, ans.second);
  }
  return 0;
}