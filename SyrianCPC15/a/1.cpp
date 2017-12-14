#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int n;
long long num;
long long sum;
long long mini;
long long res;

int main() {
	int test;
	scanf("%d",&test);
	char op[2];
	
	while(test--)
	{
		scanf("%d",&n);
		sum = 0LL;
		mini = LLONG_MAX;
		while(n--)
		{
			
			scanf("%lld%s",&num,op);
			
			if(op[0] == '+')
				sum += num+25LL;
			else
				mini = min(mini,sum+num+25LL);
		}
		res = mini-sum;
		printf("%lld\n",res);
	}




	return 0;
}
