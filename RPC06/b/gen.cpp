#include <bits/stdc++.h>
using namespace std;


int main() {
  srand(time(0));
  int T = 1234;
  cout << T << endl;
  for (int tc = 0; tc < T; tc++) {
    int n = rand() % 123;
    int k = (n > 0 ? rand() % n : 0);
    cout << n << ' ' << k << endl;
  }
  return 0;
}