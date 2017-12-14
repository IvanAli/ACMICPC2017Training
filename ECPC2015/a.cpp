#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n;
int arr[15];
int x;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		cin>>n;
		x = 0;
		while(n>0)
		{
			arr[x++] = n%10;
			n/=10;
		}
		reverse(arr,arr+x);
		long double sum = 0.;
		long double prob = 0.;
		//for(int i = 0; i < x; ++i)
		//cout<<arr[i]<<" "; cout<<": "<<endl;
		int F = 1;
		for(int i = 1; i <= x; ++i)
			F*=i;

		while(next_permutation(arr,arr+x))
		{
		//	for(int i = 0; i < x; ++i)
		//	cout<<arr[i]<<" "; cout<<endl;
		//cout<<"prev: "<<sum<<endl;
			prob = 1./F*(sum+1.);

			sum += prob;

			//cout<<sum<<endl;
		}

		cout<<fixed<<setprecision(9)<<prob<<endl;

	}



	return 0;
}
