#include <bits/stdc++.h>

using namespace std;

struct Segmento{
	int l, r;
	
	Segmento(){}
};

bool operator <(const Segmento &a, const Segmento &b)
{
	if(a.r == b.r)
		return a.l < b.l;
	return a.r > b.r;
}

Segmento arr[200005];
int n;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>arr[i].l>>arr[i].r;
	sort(arr,arr+n);
	
	
	int maxi = INT_MAX;
	int mini = INT_MIN;
	
	int cont = 0;

	while(cont < n && arr[cont].r >= mini)
	{
		
		maxi = min(maxi,arr[cont].r);
		mini = max(mini,arr[cont].l);
		++cont;
	}
	cout<<cont<<endl;
	




	return 0;
}
