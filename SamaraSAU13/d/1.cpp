#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int arr[1000005];

int main() {

	arr[1] = 1;
	int k;
	cin>>k;
	
	for(int i = 2; i <= k; ++i)
	{
		arr[i]++;
		for(int j = i+i; j <= k; j+=i)
			arr[j] += arr[i];
	}
	
	cout<<arr[k]<<endl;


	return 0;
}
