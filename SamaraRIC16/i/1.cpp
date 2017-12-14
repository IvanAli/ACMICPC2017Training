#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int n;
long long d,c;
long long arr[1005];
long long dp[1005];
int main() {

	cin>>n>>d>>c;
	
	for(int i = 1; i <= n ; ++i)
		cin>>arr[i];
	
	for(int i = 1; i <= n; ++i)
	{
		dp[i] = LLONG_MAX;
		long long sum = 0;
		for(int j = i-1; j >= 0; --j)
		{
			dp[i] = min(dp[i],dp[j]+c*sum+d);
			sum += arr[i]-arr[j];
			//cout<<sum<<endl;		
		}
	}
	//for(int i = 1; i <= n; ++i)
		//cout<<dp[i]<<" "; cout<<endl;
	
	cout<<dp[n]<<endl;
	

	return 0;
}
