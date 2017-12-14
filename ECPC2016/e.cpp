#include <bits/stdc++.h>
#define snd second
#define fst first
#define endl '\n'
using namespace std;

int n;
int arr[100005];
int dp[100005];
int mark[100005];
int target = 1;
queue <int> Q;
vector <int> ady[100005];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	fstream fs;
	fs.open ("jumping.in", fstream::in );
	int test;
	fs>>test;
	while(test--)
	{
		fs>>n;
	//	memset(dp,-1,sizeof dp);
		for(int i = 1; i <= n; ++i)
		{
			fs>>arr[i];
			ady[i].clear();
		}
		for(int i = 1; i <= n; ++i)
		{
			int d = arr[i];
			if(i+d <= n)
				ady[i+d].push_back(i);
			if(i-d > 0)
				ady[i-d].push_back(i);
		}
		

		dp[n] = 0;
		mark[n] = target;
		Q.push(n);

		while(!Q.empty())
		{
			int curr = Q.front();
			Q.pop();
		
			for(int v : ady[curr])
			{
				if(mark[v] != target)
				{
					mark[v] = target;
					dp[v] = dp[curr]+1;
					Q.push(v);
				}
			}
		}


		for(int i = 1; i <= n; ++i)
			if(mark[i] == target)
				cout<<dp[i]<<endl;
			else
				cout<<"-1"<<endl;
		++target;
	}
	fs.close();
	return 0;

}
