#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 1111
char s[maxn];
int a[maxn],b[maxn];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while(~scanf("%s",s))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n=strlen(s);
        a[0]=(s[0]=='1');
        b[n-1]=(s[n-1]=='3');
        for(int i=1;i<n;i++)a[i]=a[i-1]+(s[i]=='1');
        for(int i=n-2;i>=0;i--)b[i]=b[i+1]+(s[i]=='3');
        int ans=b[0];
        for(int i=0;i<n;i++)ans=min(ans,a[i]+b[i+1]);
        printf("%d\n",ans);
    }
    return 0;
}