#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n;

int main()
{
	IO
	cin>>n;
	if(n%2 == 0)
		cout<<"4 "<<n-4<<endl;
	else
		cout<<"9 "<<n-9<<endl;
	

	return 0;
}
