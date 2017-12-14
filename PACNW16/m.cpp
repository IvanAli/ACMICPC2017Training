#include <bits/stdc++.h>

using namespace std;


string alpha;

unsigned int dp[55];


int main()
{
	cin>>alpha;
	
	memset(dp,-1,sizeof dp);
	
	dp[0] = 1;
	
	int len = alpha.size();
	
	for(int i = 0; i < len; ++i)
	{
		if(alpha[i] == 'a')
			dp[i+1] = 0;
	}
	
	
	for(char c = 'b'; c <= 'z'; ++c)
	{
		for(int i = 0; i < len; ++i)
		{
			if(alpha[i] == c)
			{
				for(int j = i; j >= 0; j--)
				{
					dp[i+1] = min(dp[i+1],dp[j]);
				}
			
			}	
		}
		
		for(int i = 0; i < len; ++i)
		{
			if(alpha[i] < c)
				dp[i+1]++;
		}
		dp[0]++;
		
	
	}
	
	
	unsigned int res = -1;
	
	for(int i = 0; i <= len; ++i)
		res = min(res, dp[i]);
	cout<<res<<endl;
	
	
	
	
	

	return 0;
}