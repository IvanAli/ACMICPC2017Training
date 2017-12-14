#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n;
int digit[10005];

int main(){
	string str;
	int caso = 1;
	while(cin>>n && n != 0){
		
		map<string, int> mp;
		vector< int > vec;
		memset(digit,0,sizeof digit);
	
		for(int i = 0; i < n; ++i){
			cin>>str;
			mp[str]++;
		}
	
		for(auto it : mp){
			vec.pb(it.snd);
		}	
		int maxi = 0;
		for(auto it : vec){
			for(int i = 0; i < it; ++i){
				digit[i]++;
			}
			maxi = max(maxi, it);
		}
		cout<<"Case "<<caso++<<": ";
		for(int i = maxi-1; i >=0; --i){
			cout<<digit[i];
		}cout<<endl;
	}
	
	
	return 0;
}

