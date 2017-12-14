#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int n,m;
char sop[1005][1005];
int fire[1005][1005];
int visit[1005][1005];
int target = 1;

bool valido(const int &i, const int &j)
{
	
	return (i < n && j < m && i >= 0 && j >= 0 && sop[i][j] != '#' && visit[i][j] != target);

}

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

pair <int,int> ini;

int main() {

	int test;
	cin>>test;
	
	while(test--)
	{

		cin>>n>>m;
		
		
		for(int i = 0; i < n; ++i)
			cin>>sop[i];
		
		queue < pair<int,int> > Q;
			
		for(int i = 0; i < n; ++i)
		{
			for(int j = 0; j < m; ++j)
			{
				if(sop[i][j] == 'F')
				{
					Q.push({i,j});
					fire[i][j] = target;
					visit[i][j] = target;
				}
				if(sop[i][j] == 'S')
					ini = {i,j};
			}
		}
		
		Q.push(ini);
		visit[ini.fst][ini.snd] = target;
		
		pair <int,int> a;
		bool fl = true;
		while(!Q.empty())
		{
			a = Q.front();
			Q.pop();
			
			if(sop[a.fst][a.snd] == 'E' && fire[a.fst][a.snd] != target)
			{
				fl = false;
				cout<<"Y"<<endl;
				break;
			}
			
			for(int h = 0; h < 4; ++h)
			{
				int ni = a.fst + di[h];
				int nj = a.snd + dj[h];
				
				if(valido(ni,nj))
				{
					
					if(fire[a.fst][a.snd] == target)
					{
						Q.push({ni,nj});
						visit[ni][nj] = target;
						fire[ni][nj] = target;
					}
					else
					{
						if(fire[ni][nj] != target)
						{
							Q.push({ni,nj});
							visit[ni][nj] = target;
						}
					}
				
				}
				
			}
		}
		
		if(fl)
			cout<<"N"<<endl;
		
		++target;	
	}


	return 0;
}
