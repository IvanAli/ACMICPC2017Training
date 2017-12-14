#include <bits/stdc++.h>
using namespace std;

int n;
map <string,int> mp;

int mark[30];
int abc[30];


int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0);

	cin>>n;
	
	
	string str;
	string res;
	
	int len;
	int cont;
	
	for(int i = 1; i <= n; ++i)
	{
		res = "";
		cin>>str;
		
		len = str.size();
		cont = 0;
		for(int j = 0; j < len; ++j)
		{
			int idx = str[j]-'a';
			
			if(mark[idx] != i)
			{
				mark[idx] = i;
				abc[idx] = cont++;
				res += char(abc[idx]+'a');
			}
			else
				res += char(abc[idx]+'a');
		}
		//cout<<res<<endl;
		
		mp[res]++;
	}

	long long sum = 0;

	for(auto it = mp.begin(); it != mp.end(); ++it)
		sum += (((long long)(*it).second)*((long long)(*it).second-1))>>1;

	cout<<sum<<'\n';

	return 0;
}
