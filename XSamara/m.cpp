#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

int n;
int arr[200005];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long sum = 0LL;

	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>arr[i];
	for(int i = 0; i < n; ++i)
		sum += (long long)(arr[i]);

	if(sum < (long long) (n))
	{
		cout<<"YES"<<endl;
		int last = n-1;
		int curr = n-1;
		
		while(curr >= 0)
		{
			while(arr[curr]--)
			{
				cout<<curr+1<<" "<<last+1<<endl;
				last--;
			}
			curr--;
		}

	}
	else
		cout<<"NO"<<endl;
		




	return 0;

}


