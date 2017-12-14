#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100005];

int main()
{
	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);

	int x = 1000000000;

	for(int i = 0; i < n/2; ++i)
		x = min(x,arr[i]+arr[n-1-i]);
	cout<<x<<endl;




	return 0;
}
