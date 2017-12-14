#include <bits/stdc++.h>

using namespace std;

int m;
int n;
int mask;
int dp[(1<<15)];

void trans(int bitmask)
{

	for(int i = m; i >= 1; --i)
		if(bitmask&(1<<i))
			cout<<'1';
		else
			cout<<'0';
	cout<<endl;

}

int dfs(int bitmask)
{
	int &ans = dp[bitmask];
	
	if(ans != -1)
		return ans;
	
	if(bitmask&(1<<m))
	{
		//cout<<"looser: "<<bitmask<<endl;
		return 0;
	}
	
	bool fl = true;
	
	for(int i = 1; i <= m; ++i)
	{
		if(bitmask&(1<<i))
		{
			for(int j = i+1; j <= m; ++j)
			{
				if((bitmask&(1<<j))==0)
				{
					int temp = bitmask;
					temp |= (1<<j);
					temp ^= (1<<i);
					int r = dfs(temp);
					if(r == 0)
						fl = false;	 
				}
			
			}
		
		
		}
	}
	
	if(!fl)
	{
		cout<<"winner: ";
		trans(bitmask);
		return ans = 1;
	}
	//cout<<"looser: "<<bitmask<<endl;
	return ans = 0;

}


int main()
{
	cin>>m>>n;
	
	int num;
	
	mask = 0;
	
	memset(dp,-1,sizeof dp);
	
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		
		mask |= (1<<num);
	
	}
	
	dfs(mask);
	
	
	



}
