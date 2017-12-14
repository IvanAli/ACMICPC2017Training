#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

int n,m;
int telep[200005];
int bonus[200005];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	long long sol = 0;

	for(int i = 0; i < n; ++i)
		cin>>telep[i];
	for(int i = 0; i < m; ++i)
		cin>>bonus[i];

	int idx = 0;
	while(idx < m && bonus[idx] <= telep[0])
		++idx;
	if(idx != 0)
		sol += 2LL*((long long)(telep[0])-(long long)(bonus[0]));
	int T = 0;
	while(idx < m && T < n-1)
	{
		long long mini = (long long)(telep[T+1])-(long long)(telep[T]);
		long long ref = 0LL;
		while(idx < m && bonus[idx] <= telep[T+1])
		{
			long long tmp = 2LL*((long long)(telep[T+1])-(long long)(bonus[idx])+ref);
			mini = min(mini,tmp);
			ref = (long long)(bonus[idx])-(long long)(telep[T]);
			++idx;
		}
		mini = min(mini,2LL*ref);
		sol += mini;
		T++;
	}
	if(idx < m)
		sol += 2LL*((long long)(bonus[m-1])-(long long)(telep[n-1]));
	cout<<sol<<'\n';

	return 0;

}


