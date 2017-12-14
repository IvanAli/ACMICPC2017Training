#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
char s[maxn];
int a[maxn],b[maxn];
int three[2], one[2];
int n;

int solve() {
  for (int i = 0; i < 2; i++) {
    three[i] = 0;
    one[i] = 0;
  }
  int ok;
  ok = false;
  for (int i = 0; i < n; i++) {
    if (s[i] == '3') three[ok]++;
    else ok = true;
  }
  ok = false;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '1') one[ok]++;
    else ok = true;
  }
  return min(three[1], one[1]);
//  printf("%d\n", min(three[1], one[1]));
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%s",s))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        n=strlen(s);
        a[0]=(s[0]=='1');
        b[n-1]=(s[n-1]=='3');
        for(int i=1;i<n;i++)a[i]=a[i-1]+(s[i]=='1');
        for(int i=n-2;i>=0;i--)b[i]=b[i+1]+(s[i]=='3');
        int ans=b[0];
        for(int i=0;i<n;i++)ans=min(ans,a[i]+b[i+1]);
        if (ans != solve()) {
          printf("%s\n", s);
          assert(0);
        }
        // printf("%d\n",ans);
    }
    return 0;
}