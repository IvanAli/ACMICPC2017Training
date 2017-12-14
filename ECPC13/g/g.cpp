#include <bits/stdc++.h>

using namespace std;

int n;

int dp[1005][1005][4];

int dfs(int level, int half, int turn)
{
	cout<<level<<" "<<half<<" "<<turn<<endl;

	int &ans = dp[level][half][turn];
	
	if(ans != -1)
	{ 
	return ans;
	}
	
	
	if(turn == 0 || turn == 1 || turn == 3)
	{
		if(level == 1 && half == 0)
			return ans = 1;
		if(level == 0 && half == 1)
			return ans = 1;
			
		if(level > 0)
		{
			int r = dfs(level-1,half,(turn+1)%4);
			if(r == 0)
				return ans = 1;
			r = dfs(level-1,half+1,(turn+1)%4);
			if(r == 0)
				return ans = 1;
		}
		if(half > 0)
		{
			int r = dfs(level,half-1,(turn+1)%4);
			if(r == 0)
				return ans = 1;
		}
			
		cout<<level<<" "<<half<<" "<<turn<<" "<<"looser"<<endl;	
		return ans = 0;
	}
	
	
			
			int r = dfs(level,half,(turn+1)%4);
			if(r == 0)
				return ans = 1;
			r = dfs(level,half+1,(turn+1)%4);
			if(r == 0)
				return ans = 1;
		
		if(half > 0)
		{
			int r = dfs(level+1,half-1,(turn+1)%4);
			if(r == 0)
				return ans = 1;
		}
		
		cout<<level<<" "<<half<<" "<<turn<<" "<<"looser"<<endl;	
		return ans = 0;
	
	
	
	
	
}



int main()
{
	memset(dp,-1,sizeof dp);

	fstream fin;
	
	fin.open("jenga.in",fstream::in);
	
	int test;
	
	cin>>test;
	
	int caso = 1;
	
	int temp = 1;
	
	cout<<dfs(4,0,0)<<endl;
	
//	for(int temp = 1; temp <= 100; temp++)
//	{
//		cout<<temp<<": "<<dfs(temp-1,0,0)<<endl;
//	}
	
	
	while(test--)
	{
		cin>>n;
		n = (n-1)*2;
	
	
	
	
		if(n%4 == 1 || n%4 == 2)
			cout<<"Case "<<caso++<<": Bakkar"<<endl;
		else
			cout<<"Case "<<caso++<<": Wahdan"<<endl;
	}
	
	


	return 0;
}