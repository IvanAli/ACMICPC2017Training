#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;


int n;
map<int,int> mp;

vector < pair <int,int> > arr;

int main() {


	cin>>n;
	int cant = 0;
	
	int num;
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		mp[num]++;
	}
	
	for(auto it = mp.begin(); it != mp.end(); ++it)
		arr.pb({max(0,(*it).first-(*it).second+1),(*it).second});
	
	sort(arr.begin(),arr.end());
	for(pair <int,int> v : arr)
	{
		if(v.fst <= cant)
			cant += v.snd;
	}
	cout<<cant<<endl;
	
	
	

	return 0;
}
