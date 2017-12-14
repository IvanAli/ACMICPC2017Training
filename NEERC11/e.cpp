#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define ULL unsigned long long
using namespace std;
int n;
ULL k;
ULL one[1000005];
ULL none[1000005];

int main()
{
	//IO
	
	freopen("express.in","r",stdin);
	freopen("express.out","w",stdout);
	
	scanf("%d%lld",&n,&k);
	
	one[3] = 1LL;

	for(int i = 4; i < n; ++i){
		one[i] = (one[i-1]+one[i-2])%k;
		none[i] = ((none[i-1]+none[i-2])%k+1LL)%k;
	}
	if(n > 3)
		none[n] = ((none[n-1]+none[n-2])%k+1LL)%k;
	else
		one[3] = 0LL;
	ULL sum = 0LL;
	for(int i = 3; i <= n; ++i)
		sum = ((sum+one[i])%k+none[i])%k;
	printf("%lld\n",sum);
	return 0;
}
