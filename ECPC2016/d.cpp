#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

long long fact(long long num)
{
	long long res = 1LL;
	for(long long i = 2LL; i <= num; ++i)
		res *= i;
	return res;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	fstream fs;
	fs.open ("popcorn.in", fstream::in );
	int test;
	fs>>test;
	while(test--)
	{
		long long n,m;
		fs>>n>>m;
		//cout<<n<<" "<<m<<endl;
		cout<<fact(n)/(fact(m)*fact(n-m))<<endl;
	}
	fs.close();
	return 0;

}


