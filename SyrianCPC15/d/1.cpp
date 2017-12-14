#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

map <char,int> mp;


int main() {

	int test;
	scanf("%d",&test);
	
	int k;
	string pal;
	string letr = "AHIMOTUVWXY";
	string res = "";
	string pref = "";
	
	mp['A'] = 0;
	mp['H'] = 1;
	mp['I'] = 2;
	mp['M'] = 3;
	mp['O'] = 4;
	mp['T'] = 5;
	mp['U'] = 6;
	mp['V'] = 7;
	mp['W'] = 8;
	mp['X'] = 9;
	mp['Y'] = 10;
	
	while(test--)
	{
		cin>>k>>pal;
		
		int len = pal.size();
		int idx = len-1;
		int diff = 0;
		res = "";
		pref = "";
		
		while(idx >= 0)
		{
		//cout<<"car: "<<pal[idx]<<endl;
			int val = mp[pal[idx]];
			int mod = k%11;
			int sum = val+mod+diff;
			if(sum >= 11)
				diff = 1;
			else
				diff = 0;
			sum %= 11;
			//cout << "solu: "<<letr[sum]<<endl;
			res += letr[sum];
			
			--idx;
			k /= 11;
		}
		while(k || diff)
		{
			if(k)
				--k;
			int mod = k%11;
			int sum = diff+mod-1;
			if(sum >= 11)
				diff = 1;
			else
				diff = 0;
			//assert(sum != -1);
			sum = (sum+11)%11;
			pref += letr[sum];
			k/=11;
		}
		int lenR = res.size();
		int lenP = pref.size();
		
		for(int i = lenP-1; i >= 0; --i) cout<<pref[i];
		for(int i = lenR-1; i >= 0; --i) cout<<res[i]; cout<<endl;
		
	
	}




	return 0;
}
