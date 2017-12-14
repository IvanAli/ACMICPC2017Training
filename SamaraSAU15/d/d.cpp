#include <bits/stdc++.h>

using namespace std;

int n,m;

map <int,int> mp;

int color[100005];
int res;
bool fl = true;

int main()
{

	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	cin>>n;
	
	for(int i = 1; i <= n; ++i)
	{
		cin>>color[i];
		mp[color[i]]++;
	}
	
	if(mp.size() == 1)
	{
		res = 0;
		fl = false;
		return cout << 0 << endl, 0;
	}

	cin>>m;
	
	int k,x;
	
	//for(auto it = mp.begin(); it != mp.end(); ++it)
		//cout<<(*it).first<<" "<<(*it).second<<endl;
	
	for(int i = 1; i <= m; ++i)
	{
		cin>>k>>x;
		
		mp[color[k]]--;
		color[k] = x;
		mp[color[k]]++;
		if (mp[color[k]] == n) return cout << i << endl, 0;
		//cout<<"mapa:"<<endl;
		//for(it = mp.begin(); it != mp.end(); ++it)
		//cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	return cout << -1 << endl, 0;
	if(fl)
		cout<<"-1"<<'\n';
	else
		cout<<res<<'\n';
	
	return 0;
}
