#include <bits/stdc++.h>

using namespace std;

int arr[30];
string p;


int main()
{
	cin>>p;
	int len = p.size();
	for(int i = 0; i < len; ++i)
		arr[(int)(p[i]-'a')]++;
	
	
	bool fl = true;
	
	if(len%2 == 1)
		fl = false;
		
	for(int i = 0; i < 26; ++i)
		if(len-arr[i] < arr[i])
			fl = false;

	if(fl) cout<<"YES"<<endl;
	else	cout<<"NO"<<endl;

	return 0;
}
