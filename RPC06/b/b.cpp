#include <bits/stdc++.h>
using namespace std;
long long n,k;

int main()
{
	int test;
	
	scanf("%d",&test);
	while(test--)
	{
		scanf("%lld%lld", &n, &k);
		++n;
		++k;
		
		long long det = n - (k-1LL);
		//cout << det<< endl;
		
		long long sig = 1LL;
		
		long long res = 0LL;
		
		for(long long i = k; i > 0; --i)
		{
			res += (det)*(i*i*i)*sig;
			sig *= -1;
			det = max(0LL,det-1LL);
		}
		
		 
		
		printf("%lld\n",res);
	}



	return 0;
}

