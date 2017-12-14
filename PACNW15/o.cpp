#include <bits/stdc++.h>

using namespace std;

int n,m;
char sop[505][505];
queue < pair<int,int> > cola;
int mark[505][505];

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

bool valido(const int &i, const int &j)
{
	return (i >= 0 && j >= 0 && i < n && j < m);
}

int main()
{
	cin>>n>>m;
	for(int i = 0; i < n; ++i)
		cin>>sop[i];

	mark[0][0] = 1;
	cola.push({0,0});
	pair <int,int> a;
	while(!cola.empty())
	{
		a = cola.front();
		cola.pop();
		for(int h = 0; h < 4; h++)
		{
			int ni = a.first+di[h]*int(sop[a.first][a.second]-'0');
			int nj = a.second+dj[h]*int(sop[a.first][a.second]-'0');
			if(valido(ni,nj) && mark[ni][nj] == 0)
			{
				mark[ni][nj] = mark[a.first][a.second]+1;
				cola.push({ni,nj});
			}
		}
	}

	if(mark[n-1][m-1] == 0) cout<<"IMPOSSIBLE"<<endl;
	else cout<<mark[n-1][m-1]-1<<endl;





	return 0;
}
