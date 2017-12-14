#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
		long long int a,b,c,n,m,aux;
		cin>>a>>b>>c>>n>>m;
		if(m<n){
			aux=m;
			m=n;
			n=aux;
			aux=a;
			a=b;
			b=aux;
		}
		if(n<a+c){
			cout<<n;
		}
		else{
			if(m<b+c){
				cout<<m;
			}
			else{
				cout<<a+b+c;
			}
		}
	return 0;

}


