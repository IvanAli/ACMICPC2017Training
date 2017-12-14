#include <bits/stdc++.h>

using namespace std;

int a[5];
int b[5];

int main()
{
	for(int i = 0; i < 3; ++ i)
		cin>>a[i];
	for(int i = 0; i < 3; ++ i)
		cin>>b[i];
	sort(a,a+3);sort(b,b+3);

	if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[2]*a[2] == a[0]*a[0]+a[1]*a[1]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;





	return 0;
}
