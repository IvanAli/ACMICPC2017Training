#include <bits/stdc++.h>

using namespace std;

int n;
pair <int,int> arr[35];

int main()
{

	cin>>n;
	for(int i = 0; i < n; ++i)
	{
		cin>>arr[i].first;
		arr[i].second = i+1;
	}
	
	sort(arr,arr+n);
	
	int sum = 0;
	for(int i = 0; i < n-1; ++i)
		sum+=arr[i].first;
	
	if(sum < arr[n-1].first)
		cout<<"impossible"<<endl;
	else
	{
		cout<<arr[n-1].second;
		for(int i = n-2; i >= 0; --i)
			cout<<" "<<arr[i].second; cout<<endl;
			
	
	}
	
	
	
	
	
	
	
	
	

	return 0;
}
