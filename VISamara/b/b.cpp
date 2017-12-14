#include <bits/stdc++.h>
using namespace std;

string pal;

int ocurr[30];

int main()
{
	cin>>pal;
	
	int len = pal.size();
	
	for(int i = 0; i < len; ++i)
		++ocurr[int(pal[i]-'a')];
		
	long double res = 0.;
	
	for(int i = 0; i < len; ++i)
		res += (long double) ocurr[int(pal[i]-'a')] / (long double) len;
		
	cout<<fixed<<setprecision(16)<<res<<endl;
	
	
	
	
	
	


	return 0;
}


