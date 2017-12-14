#include <bits/stdc++.h>
using namespace std;

long long s;
int n;

map<long long , int> mp;

int main()
{
	cin>>n>>s;
	
	long long num;
	long long acum = 0;
	long long x;
	
	long long cont = 0;
	
	mp[0]++;
	
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		acum += num;
		
		
		x = acum-s;
		auto it = mp.find(x);
		if(it != mp.end())
			cont += (*it).second;
//		if (acum == s)
		mp[acum]++;
	
	}
	
	cout<<cont<<endl;
	

	return 0;
}
