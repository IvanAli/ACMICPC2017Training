#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int n,m;

map < bitset <160> ,int> mp;


int main() {
	
	cin>>n>>m;
	
	string tmp;
	for(int i = 0; i < n; ++i)
	{
		cin>>tmp;
		int cont = 0;
		for(int j = 0; j < m; ++j)
		{
			if(tmp[j] == '1')
				++cont;
		}
		if(cont >= 8 && cont <= 15)
		{
			bitset <160> blank;
			
			for(int j = 0; j < m; ++j)
				if(tmp[j] == '1')
					blank[m-1-j] = 1;
				else
					blank[m-1-j] = 0;
			mp[blank]++;
		}
	}
	
	int maxi = -1;
	bitset <160> blank;
	
	for(auto it = mp.begin(); it != mp.end(); ++it)
	{
		if((*it).second > maxi)
		{
			maxi = (*it).second;
			blank = (*it).first;
		
		}
	
	}
	
	for(int i = m-1; i >= 0; --i)
		cout<<blank[i];

	return 0;
}
