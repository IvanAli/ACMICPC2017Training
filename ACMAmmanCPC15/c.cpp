#include <iostream>
#include <cstdio>

using namespace std;
string pal;
int temp = 1;
int arr[105];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		cin>>pal;

		for(int i = 0; i < n; ++i)
		{
			if(pal[i] == '*')
			{
				arr[i] = temp;
				arr[min(i+1,n-1)] = temp;
				arr[max(0,i-1)] = temp;
			}
		}
		int sum = 0;
		for(int i = 0; i < n; ++i)
		{
			if(arr[i] != temp)
			{
				int cont = 0;
				while(i < n && arr[i] != temp)
				{
					++cont;
					++i;
				}
				sum += cont/3 + (cont%3 != 0);
			}
		}
		cout<<sum<<endl;
		++temp;
	}

	return 0;
}
