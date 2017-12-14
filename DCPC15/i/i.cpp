
#include <bits/stdc++.h>

using namespace std;

struct Circle{
	int x,y,r;
	Circle(){}

	Circle(const int &_x, const int &_y, const int &_r)
	{
		x = _x;
		y = _y;
		r = _r;
	}

};


long double euler(Circle &a, Circle &b)
{
	long long x = a.x-b.x;
	x *= x;
	long long y = a.y-b.y;
	y *= y;

	long double sum = x;
	sum += y;
	
	long double dist = sqrt( sum );
	
	return dist;

}


int test(Circle &a, Circle &b)
{
	long double dist = euler(a,b);
	long double ra = a.r;
	long double rb = b.r;
	
	if(ra-dist >= 0 && rb-dist >= 0)
		return 1;
	if(ra-dist >= 0)
		return 2;
	if(rb-dist >= 0)
		return 3;
	return 0;
}

int manhatan(Circle &a, Circle &b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}


int n;
Circle pt[105];
vector < pair<int, int >  > ady[105];

unsigned long long val[105];



int main()
{

	int T;
	cin>>T;
	
	while(T--)
	{
		cin>>n;
		int x,y,r;
		for(int i = 0; i < n; ++i)
		{
			ady[i].clear();
			cin>>x>>y>>r;
			pt[i] = Circle(x,y,r);
		}
		ady[n].clear();
		ady[n+1].clear();
		
		memset(val,-1,sizeof val);
		
		cin>>x>>y; r = 0;
		pt[n] = Circle(x,y,r);
		cin>>x>>y;
		pt[n+1] = Circle(x,y,r);
		n+=2;
		
		for(int i = 0; i < n; ++i)
			for(int j = i+1; j < n; ++j)
			{
				if( i == n-1 || j == n-1 || i == n-2 || j == n-2 )
				{
					int dist = manhatan(pt[i],pt[j]);
					ady[i].push_back({j,dist});
					ady[j].push_back({i,dist});
				}
				else
				{
					int dist = manhatan(pt[i],pt[j]);
					int res = test(pt[i],pt[j]);
					
					if(res)
					{
						int dist2 = min(dist,2);
						
						if(res == 1)
						{
							ady[i].push_back({j,dist2});
							ady[j].push_back({i,dist2});
						}
						else if(res == 2)
						{
							ady[i].push_back({j,dist2});
							ady[j].push_back({i,dist});
						}
						else
						{
							ady[i].push_back({j,dist});
							ady[j].push_back({i,dist2});
						}
					}
					else
					{
						ady[i].push_back({j,dist});
						ady[j].push_back({i,dist});
					
					}
				}
			}
			
		
		priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
		
		pq.push({n-2,0});
		val[n-2] = 0;
		
		while(!pq.empty())
		{
			pair<int, int> curr = pq.top();
			pq.pop();
			
			if(curr.second == val[curr.first])
			{
				for(pair <int, int> v : ady[curr.first] )
				{
					unsigned long long sum = curr.second+v.second;
					if(val[v.first] > sum)
					{
						val[v.first] = sum;
						pq.push({v.first,val[v.first]});
					
					}
				
				}
			
			
			}
			
			
		
		}
		
		cout<<val[n-1]<<endl;
		
			
		
		
	
	}


	return 0;

}