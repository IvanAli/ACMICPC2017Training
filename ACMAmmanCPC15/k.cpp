#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,k;
int arr[100005];


int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
		memset(arr,0,sizeof arr);
		cin>>n>>k;
		int num;

		for(int i = 0; i < n; ++i)
		{
			cin>>num;
			++arr[num];
		}
		bool fl = true;
		for(int i = 1; i <= 100000; ++i)
		{
			if(arr[i] > 0 && k%i == 0 && arr[k/i] > 0)
			{
				if(i*i == k  && arr[i] == 1)
					continue;
					fl = false;
					cout<<i<<" "<<k/i<<endl;
					break;
			}
		}
		if(fl) cout<<"-1"<<endl;


	}

	return 0;
}
