#include <bits/stdc++.h>
using namespace std;

struct Nodo{

	pair <int, int> p[4];
	Nodo(){};
	Nodo(const int &r0, const int &c0, const int &r1, const int &c1, const int &r2, const int &c2, const int &r3, const int &c3)
	{
		p[0] = {r0,c0};
		p[1] = {r1,c1};
		p[2] = {r2,c2};
		p[3] = {r3,c3};
	}
};

bool operator < (const Nodo &a, const Nodo &b)
{
	if(a.p[0] == b.p[0])
	{
		if(a.p[1] == b.p[1])
		{
			if(a.p[2] == b.p[2])
				return a.p[3] < b.p[3];
			return a.p[2] < b.p[2];
		}
	
		return a.p[1] < b.p[1];
	}
	
	return a.p[0] < b.p[0];
}


int v,n,m,l;
map <Nodo, int> mp;
char sop[15][15];

Nodo ini;

pair <int,int> sig[15][15][4]; //r,l,d,u
int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
pair <int,int> fin;


bool valido(const int &i, const int &j)
{
	return (i >= 0 && i < n && j >= 0 && j < m && sop[i][j] != 'W');
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>v>>m>>n>>l;
	
	int ni,nj;
	
	for(int i = 0; i < n; ++i)
		cin>>sop[i];
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			if(sop[i][j] == '1')
				ini.p[0] = {i,j};
			if(sop[i][j] == '2')
				ini.p[1] = {i,j};
			if(sop[i][j] == '3')
				ini.p[2] = {i,j};
			if(sop[i][j] == '4')
				ini.p[3] = {i,j};
			if(sop[i][j] == 'X')
				fin = {i,j};
		}
		
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			if(sop[i][j] != 'W')
			{
				for(int h = 0; h < 4; ++h)
				{
					int curr = 0;
					
					while(1)
					{
						ni = i+di[h]*curr;
						nj = j+dj[h]*curr;
						
						if(valido(ni,nj))
						{
							sig[i][j][h] = {ni,nj};
							++curr;
						}
						else
							break;
					}
				}
			
			}
		
		
		}		
		
	queue <Nodo> Q;
	mp[ini] = 0;
	Q.push(ini);
	Nodo a,tmp;

	
	while(!Q.empty())
	{
		a = Q.front();
		
	//	cout<<a.p[0].first<<" "<<a.p[0].second<<" "<<a.p[1].first<<" "<<a.p[1].second<<endl;
		
		Q.pop();
		
		auto it = mp.find(a);
		
		if(a.p[0] == fin)
		{
			cout<<(*it).second<<'\n';
			return 0;
		}
		
		for(int k = 0; k < v; ++k)
		{
			for(int h = 0; h < 4; ++h)
			{
				ni = sig[a.p[k].first][a.p[k].second][h].first;
				nj = sig[a.p[k].first][a.p[k].second][h].second;
				
				for(int k2 = 0; k2 < v; ++k2)
				{
					if(k != k2)
					{
						if(a.p[k2].first==ni)
						{
							if(h == 0 && a.p[k2].second > a.p[k].second)
								nj = min(nj,a.p[k2].second-1);
							if(h == 1 && a.p[k2].second < a.p[k].second)
								nj = max(nj,a.p[k2].second+1);	
						}
						
						if(a.p[k2].second==nj)
						{
							if(h == 2 && a.p[k2].first > a.p[k].first)
								ni = min(ni,a.p[k2].first-1);
							if(h == 3 && a.p[k2].first < a.p[k].first)
								ni = max(ni,a.p[k2].first+1);	
						}
					
					}
				}
				
				
				tmp = a;
				tmp.p[k].first = ni;
				tmp.p[k].second = nj;
				
				auto it2 = mp.find(tmp);
				
				if(it2 == mp.end() && (*it).second+1 <= l)
				{
					mp[tmp] = (*it).second+1;
					Q.push(tmp);
				}
				
				
				
				
				
			}
		
		}
	}
	
	cout<<"NO SOLUTION"<<endl;
	
	
	


	return 0;
}
