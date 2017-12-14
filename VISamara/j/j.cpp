#include <bits/stdc++.h>
using namespace std;

int n,k,x;
int arr[200005];
bool nodo[200005];

vector < vector < vector < int > > > ady;
vector < vector <int> > mark;


int main()
{
	cin>>n;
	for(int i = 1; i <= n; ++i)
		cin>>arr[i];

	
	cin>>k;	
	
	ady.resize(k+1);
	mark.resize(k+1);
	
	for(int i = 0; i <= k; ++i)
	{
		ady[i].resize(n+1);
		mark[i].resize(n+1);
	}

	int num;
	for(int i = 1; i <= k; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			cin>>num;
			ady[i][j].push_back(num);
		}
	}

	cin>>x;
	int pos;
	for(int i = 1; i <= n; ++i)
		if(x == arr[i])
		{
			pos = i;
			break;
		}	

	queue <int> Q;
	Q.push(pos);
	int a;
	while(!Q.empty())
	{
		a = Q.front();
		Q.pop();
		
		if(!nodo[a])
			nodo[a] = true;
		else
			continue;
		
		if(a == 1)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		
		for(int i = 1; i <= k; ++i)
		{
			if(mark[i][a] == 0)
			{
				queue <int> Q2;
				mark[i][a] = 1;
				Q2.push(a);
				
				int b;
				while(!Q2.empty())
				{
					b = Q2.front();
					Q2.pop();
					for(int v : ady[i][b])
					{
						if(mark[i][v] == 0)
						{
							Q2.push(v);
							Q.push(v);
							mark[i][v] = 1;
						}
					
					}	
				}		
			}
		
		}
			
	}		
	
	
	cout<<"NO"<<endl;
	return 0;
}
