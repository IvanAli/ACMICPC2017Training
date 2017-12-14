#include <bits/stdc++.h>
#define snd second
#define fst first
#define mod 1000000007LL
using namespace std;

long long fact(long long num)
{
	long long res = 1LL;
	for(long long i = 2LL; i <= num; ++i)
		res = (res*i)%mod;
	return res;
}
long long binExp(long long num, long long b)
{
	if(b == 1LL)
		return num;
	if(b == 0LL)
		return 1LL;
	if(b % 2 == 0)
	{
		long long tmp = binExp(num,b/2);
		return (tmp*tmp)%mod;
	}
	return (binExp(num,b-1)*num)%mod;
}

long long binom(long long n, long long k)
{
	long long a = fact(n);
	long long b = (fact(k)*fact(n-k))%mod;
	return (a*binExp(b,mod-2LL))%mod;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	fstream fs;
	fs.open ("galactic.in", fstream::in );
	int test;
	fs>>test;
	while(test--)
	{
		long long n,k;
		fs>>n>>k;
		if(k > n)
		{
			assert(1);
			cout<<"0"<<endl;
			continue;
		}
		long long sum = 0;
		for(long long r = 0; r <= k; ++r)
		 {
		 	long long c = (((binExp(-1,r)*binom(k,r)%mod)*binExp(k-r,n))%mod)%mod;
			//cout<<c<<endl;
			sum = ((sum+c)%mod+mod)%mod;
			//cout<<sum<<endl;
			}
		cout<<sum<<endl;
	}
	fs.close();
	return 0;

}		
