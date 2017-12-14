#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

bitset<N> prime;
vector<int> primes;

void err() {
  puts("No solution");
  exit(0);
}

vector<long long> factorize(long long n) {
  int sum = 0;
  vector<long long> ret;
  for (int i = 0; n > 1 && i < (int) primes.size(); i++) {
    int p = primes[i];
    long long cur = 1;
    while (n % p == 0) {
      n /= p;
      cur *= p;
    }
    if (cur > 1) {
      if (sum + cur > 100000) {
        err();
      }
      sum += cur;
      ret.push_back(cur);
    }
  }
  if (n > 1) {
    if (sum + n <= 100000) {
      sum += n;
      ret.push_back(n);
      n = 1;
    } else {
      err();
    }
  }
  if (n > 1) {
    err();
  }
  return ret;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w+", stdout);
  long long k;
  scanf("%lld", &k);
  prime.set();
  for (int i = 2; i < N; i++) {
    if (prime[i]) {
      primes.push_back(i);
      for (int j = 2; (long long) i * j < N; j++) {
        prime[i * j] = 0;
      }
    }
  }
  if (k == 1) {
    puts("1");
    puts("1");
    return 0;
  }
  vector<long long> fv = factorize(k);
  long long pr = 0;
  int sum = 0;
  for (auto it : fv) sum += it;
  assert(sum <= 100000);
  printf("%d\n", sum);
  for (int i = 0; i < (int) fv.size(); i++) {
    for (long long j = 0; j + 1 < fv[i]; j++) {
      printf("%lld ", pr + j + 2);
    }
    printf("%lld ", pr + 1);
    pr += fv[i];
  }
  puts("");
  return 0;
}