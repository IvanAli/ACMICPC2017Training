#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

int gcd(int a, int b)
{
	if(a < b) return gcd(b,a);
	if(b == 0) return a;
	return gcd(b,a%b);
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n,x;
	cin>>n>>x;
	int acum;
	int num;
	cin>>acum;
	n--;
	while(n--)
	{
		cin>>num;
		acum = gcd(acum,num);
	}
	
	if(x % acum == 0)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;




	return 0;

}


