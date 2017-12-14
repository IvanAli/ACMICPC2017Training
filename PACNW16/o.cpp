#include <bits/stdc++.h>

using namespace std;

struct Nodo{
	int i, j, c;
	unsigned int w;
	
	Nodo(){}
	
	Nodo(const int &_i, const int &_j, const int &_c, const unsigned int &_w)
	{
		i = _i;
		j = _j;
		c = _c;
		w = _w;
	}
};


bool operator <(const Nodo &a, const Nodo &b)
{
	return a.w > b.w;
}




char maze[55][55];
unsigned int nodos[50][50][51];

Nodo ini,fin;

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};
char dir[4] = {'R','L','D','U'};


char com[55];

int n,m;

priority_queue <Nodo> pq;

bool valido(const int &i, const int &j)
{
	return (i>=0 && j >=0 && i < n && j < m && maze[i][j] != '#');
}

int main()
{
	memset(nodos,-1,sizeof nodos);

	cin>>n>>m;
	
	for(int i = 0 ; i < n; ++i)
		cin>>maze[i];
	cin>>com;
	
	int len = strlen(com);
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			if(maze[i][j] == 'R')
				ini = Nodo(i,j,0,0);
			if(maze[i][j] == 'E')
				fin = Nodo(i,j,0,0);
		}
		
	pq.push(ini);
	nodos[ini.i][ini.j][ini.c] = 0;
	
	Nodo curr;
	
	while(!pq.empty())
	{
		curr = pq.top();
		pq.pop();
		
		if(nodos[curr.i][curr.j][curr.c] == curr.w)
		{
			for(int h = 0; h < 4; ++h)
			{
				int ni = curr.i+di[h];
				int nj = curr.j+dj[h];
				
				if(valido(ni,nj) && curr.w+1 < nodos[ni][nj][curr.c])
				{
					nodos[ni][nj][curr.c] = curr.w+1;
					pq.push(Nodo(ni,nj,curr.c,curr.w+1));
				}
				
			}
			
			for(int i = curr.c; i < len; ++i)
			{
				for(int h = 0; h < 4; ++h)
				{
					if(dir[h] == com[i])
					{
					//cout<<"found: "<<dir[h]<<" "<<curr.i<<" "<<curr.j<<" "<<h<<endl;
						int ni = curr.i+di[h];
						int nj = curr.j+dj[h];
					//cout<<ni<<" "<<nj<<endl;
						
						if(valido(ni,nj))
						{ 
	//					cout<<"valido!"<<endl;
							if(curr.w+i-curr.c < nodos[ni][nj][i+1])
							{
								nodos[ni][nj][i+1] = curr.w+i-curr.c;
								pq.push(Nodo(ni,nj,i+1,curr.w+i-curr.c));	
							}
						}
						else
						{
							if(curr.w+i-curr.c < nodos[curr.i][curr.j][i+1])
							{
								nodos[curr.i][curr.j][i+1] = curr.w+i-curr.c;
								pq.push(Nodo(curr.i,curr.j,i+1,curr.w+i-curr.c));	
							}
						}
					
						break;
					}
				
				}
			
			}
			
			
		
		}
	
	
	}
	
	unsigned int minim = -1;
	/*
	for(int c = 0; c <= len; ++c)
	{
		cout<<c<<":"<<endl<<endl;
		for(int i = 0; i < n; ++i, cout<<endl)
			for(int j = 0; j < m; ++j)
				cout<<nodos[i][j][c]<<" ";
			
	}*/
	
	
	
	for(int i = 0; i <= len; ++i)
	{
		minim = min(minim, nodos[fin.i][fin.j][i]);
		
	//	cout<<nodos[fin.i][fin.j][i]<<" "<<fin.i<<" "<<fin.j<<" "<<i<<endl;
	
	}
	
	cout<<minim<<endl;
	
	
	

  return 0;
}