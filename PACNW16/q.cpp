#include <bits/stdc++.h>

using namespace std;

int n,k;
priority_queue <int> pq;

int arr[305];


int main()
{

	cin>>n>>k;
	
	for(int i = 0; i < n; ++i)
		cin>>arr[i];
	
	for(int i = 0; i < k; ++i)
		pq.push(-arr[i]);
		
	long long cont = 0;
	
	int pen = 0;
	
	int idx = k;
	
	while(!pq.empty())
	{
		int curr = pq.top();
		pq.pop();
		
		pen += -curr;
		cont += (long long) pen;
		
		if(idx < n)
			pq.push(-arr[idx++]);
		
	}
	
	cout<<cont<<endl;
	


	return 0;
}