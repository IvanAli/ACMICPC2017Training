#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 100005;

long long num;

int main() {

	long long pot;
	long long res;
	int r;

	while(scanf("%lld",&num) && num != 0LL)
	{
	
		pot = 1LL;
		res = 1LL;
		r = 0;
		while(num != 1LL)
		{

			if(r == 0)
			{

				if(num % 2LL == 1LL)
					r = 1;
				num = (num+1LL)/2LL;
			}
			else
			{
				res += pot;
				if(num % 2LL == 1LL)
					r = 0;
				num = num/2LL;
			}
			
		
			pot *= 2;
		}
		
		printf("%lld\n",res);
	
	}


	return 0;
}
