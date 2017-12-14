#include <bits/stdc++.h>

using namespace std;

int divisor[5005];
int dp[5001][5001];
int res[5001][5001];
int sum[5001][5001];
const int mod = 1000000007;


int comb(int n, int k)
{
	int &ans = dp[n][k];
	if(ans != -1) return ans;
	if(k == 0) return ans = 1;
	if(k >= n) return ans = 1;
	return ans = (comb(n-1,k)+comb(n-1,k-1))%mod; 
}


int main()
{
	memset(dp,-1,sizeof dp);
	memset(res,-1,sizeof res);
	
	for(int i = 1; i <= 5000; ++i)
	{
		for(int j = 1; j*j <= i; ++j)
		{
			if(i%j == 0)
				divisor[i] += 2-(j*j==i);
		}
		divisor[i]--;
	}
	
	for(int i = 1; i <= 5000; ++i)
		for(int j = 1; j <= 5000; ++j)
			res[i][j] = comb(divisor[i],j);
	
	for(int i = 1; i <= 5000; ++i)
	{
		long long tmp = 1LL;
		for(int j = 1; j <= 5000; ++j)
		{
			tmp = (tmp*(long long)res[j][i])%mod;
			res[j][i] = (int) tmp;
		}
	}
	
	for(int i = 1; i <= 5000; ++i)
		for(int j = 1; j <= 5000; ++j)
			sum[i][j] = min(j,divisor[i]);
			
	for(int i = 1; i <= 5000; ++i)
		for(int j = 1; j <= 5000; ++j)
			sum[j][i] = (sum[j][i] + sum[j-1][i])%mod;
		
	
	

	
	int test;
	scanf("%d", &test);
	int n,k;
	
	while(test--)
	{
		scanf("%d%d",&n,&k);
		
		printf("%d %d\n",sum[n][k],res[n][k]);
	}
		
		
	
	
	
	



	return 0;
}
