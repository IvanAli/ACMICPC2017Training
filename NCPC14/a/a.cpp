#include <bits/stdc++.h>

using namespace std;

struct Tri{
	int u,v;
	
	Tri(){};

};

int n,m;
int state[200005];

int mark[200005];
int color[200005];
int target = 1;

vector <int> ady[200005];

int b,w;

void biparcheck(int nodo)
{

	for(int v: ady[nodo])
	{
		if(mark[v] != target)
		{
			mark[v] = target;
			if(color[nodo] == 0)
			{
				color[v] = 1;
				++b;
			} 
			else
			{
				color[v] = 0;
				++w;
			}
			biparcheck(v);
		
		}
		else
		{
		
			if(color[nodo] == 0 && color[v] == 0)
			{
				b = -1000000;
				w = -1000000;
				return;
			}
			
			if(color[nodo] == 1 && color[v] == 1)
			{
				b = -1000000;
				w = -1000000;
				return;
			}
		
		}
	
	}	


}

Tri pet[200005];
int x = 0;


int main()
{
	cin>>n>>m;
	
	memset(state,-1,sizeof state);
	
	int u,v,s;
	
	int sum = 0;
	
	for(int i = 0; i < m; ++i)
	{	
		cin>>u>>v>>s;
		
		if(s == 0)
		{
			if(state[u] == 1 || state[v] == 1)
			{
				cout<<"impossible"<<endl;
				return 0;
			
			}
			state[u] = 0;
			state[v] = 0;
			continue;
		}
		
		if(s == 2)
		{
			if(state[u] == 0 || state[v] == 0)
			{
				cout<<"impossible"<<endl;
				return 0;
			
			}
			
			if(state[u] == 1)
				sum--;
			if(state[v] == 1)
				sum--;
			
			
			state[u] = 1;
			state[v] = 1;
			sum += 2;
			continue;	
		}
		
		pet[x].u = u;
		pet[x].v = v;
		
		++x;
	
	}
	
	for(int i = 0; i < x; ++i)
	{
		u = pet[i].u;
		v = pet[i].v;
		
		
		if(state[u] == 1)
		{
			if(state[v] == 1)
			{
				cout<<"impossible"<<endl;
				return 0;
			}
			
			state[v] = 0;
			continue;
		}
		
		if(state[u] == 0)
		{
			if(state[v] == 0)
			{
				cout<<"impossible"<<endl;
				return 0;
			}
			
			if(state[v] == 1)
				sum--;
			sum++;
			state[v] = 1;
			continue;
		}
		
		if(state[v] == 1)
		{
			if(state[u] == 1)
			{
				cout<<"impossible"<<endl;
				return 0;
			}
			
			state[u] = 0;
			continue;
		}
		
		if(state[v] == 0)
		{
			if(state[u] == 0)
			{
				cout<<"impossible"<<endl;
				return 0;
			}
			if(state[u] == 1)
				sum--;
			++sum;
			
			state[u] = 1;
			continue;
		}
		
		
		ady[u].push_back(v);
		ady[v].push_back(u);
	}

	
	for(int i = 1; i <= n; ++i)
	{
	
		if(state[i] == -1)
		{
			mark[i] = target;
			color[i] = 0;
			b = 0;
			w = 1;
			
			biparcheck(i);
			
			int tmp = min(b,w);
			
			if(tmp < 0)
			{
			cout<<"impossible"<<endl;
				return 0;
			
			}
			
			sum=+tmp;
			
			target++;
		}
	
	}
	
	cout<<sum<<endl;
	


	return 0;
}
