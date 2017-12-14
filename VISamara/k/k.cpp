#include <bits/stdc++.h>
using namespace std;

long long n,k;
bool mark[200005];



int main()
{
	cin>>n>>k;
	long long sum = 0;
	long long i;
	int cont = 0;
	for(i = n-1; i >= 0; --i)
	{
		if(sum+i <= k)
		{
			sum += i;
			++cont;
		}
		else 
			break;
	}
	
	int var = n;
	bool fl = true;
	for(int j = 0; j < cont; ++j)
	{
		if(fl)
		{
			fl = false;
			cout<<var;
		}
		else
			cout<<" "<<var;
		mark[var] = true;
		var--;
	}	
	
	long long diff = k-sum;
	
	var = 1+diff;
	if(!mark[var])
	{
	
	if(fl)
		{
			fl = false;
			cout<<var;
		}
		else
			cout<<" "<<var;
	mark[var] = true;
	}
	
	for(int i = 1; i <= n; ++i)
		if(!mark[i])
		{
		if(fl)
		{
			fl = false;
			cout<<i;
		}
		else
			cout<<" "<<i;
		
		
		}
	
	
	
	 
cout<<endl;	
	


	return 0;
}
