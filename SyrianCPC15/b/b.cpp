#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int test;
int n,m;

int main(){
	IO
	cin>>test;
	while(test--){
		cin>>n>>m;
		n++;
		int tmp = 1;
		int cont = 0;
		
		while(tmp < n && tmp < m){
			tmp *= 2;
			++cont;
		}
		
		if(tmp >= n){
			cout<<cont<<endl;
			continue;
		}
		int sobra = n-tmp;
		cout<<cont+sobra/m+(sobra%m != 0)<<endl;
		
	}

	return 0;
}

