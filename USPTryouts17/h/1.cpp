#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int xs, ys, xd, yd;
char dir[2];

int main() {
  scanf("%d %d %s", &xs, &ys, dir);
  scanf("%d %d", &xd, &yd);
  int xx = abs(xs - xd);
  int yy = abs(ys - yd);
  int d = 0;
  if (dir[0] == 'N') d = 0;
  if (dir[0] == 'E') d = 1;
  if (dir[0] == 'S') d = 2;
  if (dir[0] == 'O') d = 3;
  bool okx = 0, oky = 0;
  int ans = 0;
  vector<int> moves;
  if (xs == xd) okx = true;
  if (ys == yd) oky = true;
  while (!okx || !oky) {
    if (!okx) if (xs + xx * dx[d] == xd) {
      moves.push_back(xx);
      okx = true;
    }
    if (!oky) if (ys + yy * dy[d] == yd) {
      moves.push_back(yy);
      oky = true;
    }
    if (!okx || !oky) moves.push_back(-1);
    d++;
    if (d == 4) d = 0;
  }
  printf("%d\n", (int) moves.size());
  for (auto it : moves) {
    if (it > -1) printf("A %d\n", it);
    else printf("D\n");
  }
  return 0;
}         