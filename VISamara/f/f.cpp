#include <bits/stdc++.h>
using namespace std;

int n,m,k,t;
int person[200005];
int vault[200005];



int main()
{

	cin>>n>>m>>k>>t;
	
	for(int i = 0; i < n; ++i)
		cin>>person[i];
	for(int i = 0; i < m; ++i)
		cin>>vault[i];
		
	sort(person,person+n);
	sort(vault,vault+m);
	
	int idx = 0;
	int cont = 0;
	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < k && idx < n; ++j)
		{
			if(abs(person[idx]-vault[i]) <= t)
			{
				++idx;
				++cont;
			}
			else
			{
				j = j-1;
				if(vault[i] > person[idx])
					++idx;
				else
					break;
			}
		}
	
	}
	
	cout<<cont<<endl;
	

	return 0;
}
