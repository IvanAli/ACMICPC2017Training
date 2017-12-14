#include <bits/stdc++.h>
using namespace std;


int n,m;

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

char sop1[505][505];
char sop2[505][505];

int mark[505][505];
int target = 1;

int expand1[505][505];
int expand2[505][505];

bool valido1(const int &i, const int &j)
{
	return (i < n && i >= 0 && j < m && j >= 0 && sop1[i][j] != '#' && mark[i][j] != target);
}

bool valido2(const int &i, const int &j)
{
	return (i < n && i >= 0 && j < m && j >= 0 && sop2[i][j] != '#' && mark[i][j] != target);
}

void dfs(int i, int j)
{
	if(i == 0 && j == 0)
	{
		cout<<"YES"<<endl;
		exit(0);
	}
	for(int h = 0; h < 4; ++h)
	{
		int ni = i+di[h];
		int nj = j+dj[h];
		
		if(valido1(ni,nj) && valido2(ni,nj) && expand1[ni][nj] == expand2[ni][nj] && expand1[ni][nj] == expand1[i][j]-1)
		{
			mark[ni][nj] = target;
			dfs(ni,nj);
		}	
	
	}


}


int main()
{
	cin>>n>>m;
	
	for(int i = 0; i < n; ++i)
		cin>>sop1[i];	
	for(int i = 0; i < n; ++i)
		cin>>sop2[i];	

	queue < pair<int,int> > Q;
	
	Q.push({0,0});
	mark[0][0] = target;
	expand1[0][0] = 0;
	pair <int,int> act;

	while(!Q.empty())
	{
		act = Q.front();
		Q.pop();
		
		for(int h = 0; h < 4; ++h)
		{
			int ni = act.first+di[h];
			int nj = act.second+dj[h];

			if(valido1(ni,nj))
			{
				Q.push({ni,nj});
				mark[ni][nj] = target;
				expand1[ni][nj] = expand1[act.first][act.second]+1;
			}
		}
		
	}
	
	++target;
	
	Q.push({0,0});
	mark[0][0] = target;
	expand2[0][0] = 0;

	while(!Q.empty())
	{
		act = Q.front();
		Q.pop();
		
		for(int h = 0; h < 4; ++h)
		{
			int ni = act.first+di[h];
			int nj = act.second+dj[h];
			if(valido2(ni,nj))
			{
				Q.push({ni,nj});
				mark[ni][nj] = target;
				expand2[ni][nj] = expand2[act.first][act.second]+1;
			}
		}
		
	}
	
	++target;
	/*
	for(int i = 0; i < n; ++i,cout<<endl)
		for(int j = 0; j < m; ++j)
			cout<<expand1[i][j]<<" "; cout<<endl<<endl;
	for(int i = 0; i < n; ++i,cout<<endl)
		for(int j = 0; j < m; ++j)
			cout<<expand2[i][j]<<" ";*/
	
	if(expand1[n-1][m-1] != expand2[n-1][m-1])
	{
		cout<<"NO"<<endl;
		return 0;
	}
	
	mark[n-1][m-1] = target;
	dfs(n-1,m-1);
	cout<<"NO"<<endl;
	
	return 0;
}
