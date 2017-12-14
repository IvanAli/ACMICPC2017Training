#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n;
int arr[100005];

int main()
{
	int test;
	scanf("%d",&test);
	int caso = 1;

	while(test--)
	{
		scanf("%d",&n);
		for(int i = 0; i < n; ++i)
			scanf("%d",&arr[i]);
		sort(arr,arr+n);
		int sum = 0;
		int cont = 0;
		for(int i = n-1; i >= 0; --i)
		{
			++cont;
			if(cont % 3 != 0)
				sum += arr[i];
		}
		printf("Case #%d: %d\n",caso++,sum);
	}


	return 0;
}
