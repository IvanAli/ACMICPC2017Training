#include <bits/stdc++.h>

using namespace std;



int n;
long long dp[1000005];
pair<long long, int> est[1000005];
int maxi = -1;

long long fun(int pos)
{
	//cout<<pos<<endl;
	if(pos > maxi)
		return 0LL;
	long long &ans = dp[pos];
	if(ans != -1LL)
		return ans;

	if(est[pos].first != 0LL)
		ans = max(fun(pos+1),fun(pos+est[pos].second)+est[pos].first);
	else
		ans = fun(pos+1);
	return ans;

}


int main()
{

	cin>>n;
	int m,w;
	long long f;
	for(int i = 0; i < n;++i)
	{
		cin>>m>>f>>w;
		maxi = max(maxi,m);
		est[m] = {f,w};
	}
	for(int i = 1; i <= maxi; ++i)
		dp[i] = -1LL;
	cout<<fun(1)<<endl;





	return 0;
}
