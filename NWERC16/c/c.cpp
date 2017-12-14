#include <bits/stdc++.h>

using namespace std;

struct Tri{

	int l,r;
	long double f;
	
	Tri(){}
};

bool operator <(Tri &a, Tri &b)
{
	return a.l < b.l;
}



int n;
Tri arr[105];
int sign = 1;



int main()
{

	int x,y;
	
	cin>>x>>y;
	
	cin>>n;
	
	for(int i = 0; i < n; ++i)
		cin>>arr[i].l>>arr[i].r>>arr[i].f;
	sort(arr,arr+n);
	
	long double sum = 0.0;
	
	int curr = 0;
	int diff;
	
	for(int i = 0; i < n; ++i)
	{
			diff = arr[i].l-curr;
			sum += (long double)diff;
			diff = arr[i].r-arr[i].l;
			sum += ((long double)diff)*arr[i].f;
			curr = arr[i].r;
	}
	
	diff = y - curr;
	sum += (long double)diff;
	
	cout<<fixed<<setprecision(16)<<(long double)x/sum<<endl;
	
	
	
	
	
	
	
	
	



	return 0;
}
