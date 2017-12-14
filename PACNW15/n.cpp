#include <bits/stdc++.h>

using namespace std;

int n,k;
string tmp;
int num;
int edif[105];

int main()
{
	cin>>n>>k;

	edif[k] = 2;
	edif[1] = 1;

	for(int i = 0; i < n; ++i)
	{
		cin>>num>>tmp;
		if(tmp == "SAFE")
		{
			for(int j = num; j >= 1; --j )
				edif[j] = 1;
		}
		else
			for(int j = num; j <= k; ++j)
				edif[j] = 2;

	}

	//for(int i = 1; i <= k; ++i)
	//cout<<edif[i]<<" "; cout<<endl;


	int pi;
	for(int i = k; i >= 1; --i)
	{
		if(edif[i] != 1)
			pi = i;
	}
	cout<<pi<<" ";
	for(int i = 1; i <= k; ++i)
		if(edif[i] != 2)
			pi = i;
	cout<<pi<<endl;




	return 0;
}
