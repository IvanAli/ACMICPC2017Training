#include <bits/stdc++.h>
using namespace std;
struct Tri{
	int u, v;
	unsigned int w;
	Tri(){}
};

int n,m;

vector < pair<unsigned int,int> > ady[10005]; //w,v

unsigned int dist[10005];
unsigned int dist2[10005];
priority_queue < pair< unsigned int, int > , vector<pair<unsigned int, int>>, greater<pair<unsigned int, int>>> Q;

Tri edges[250005];

int main()
{

	memset(dist,-1,sizeof dist);
	memset(dist2,-1,sizeof dist2);

	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		ady[u].push_back({w,v});
		ady[v].push_back({w,u});
		
		edges[i].u = u;
		edges[i].v = v;
		edges[i].w = w;
		
	}
	
	dist[0] = 0;
	Q.push({0,0});
	
	pair <unsigned int, int> a;
	int cost, nodo, diff;
	
	while(!Q.empty())
	{
		a = Q.top();
		Q.pop();
		cost = a.first;
		nodo = a.second;
		
		if(cost == dist[nodo]){
			for(pair <unsigned int, int> v : ady[nodo]){
				diff = cost+v.first;
				if(diff<dist[v.second]){
					dist[v.second] = diff;
					Q.push({diff,v.second});
				}	
			}
		}
	}
	
	dist2[n-1] = 0;
	Q.push({0,n-1});
	
	while(!Q.empty())
	{
		a = Q.top();
		Q.pop();
		cost = a.first;
		nodo = a.second;
		
		if(cost == dist2[nodo]){
			for(pair <unsigned int, int> v : ady[nodo]){
				diff = cost+v.first;
				if(diff<dist2[v.second]){
					dist2[v.second] = diff;
					Q.push({diff,v.second});
				}	
			}
		}
	}
	
	int sum = 0;
	
	for(int i = 0; i < m; ++i){
		u = edges[i].u;
		v = edges[i].v;
		w = edges[i].w;
		
		int r1 = dist[u]+w+dist2[v];
		int r2 = dist[v]+w+dist2[u];
		
		if(r1 == dist[n-1] || r2 == dist[n-1]){
		//	cout<<u<<" "<<v<<" "<<w<<endl;
			sum += w;
		}
	}
	
	printf("%d\n",sum<<1);
	
	
	



	return 0;
}

