#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;


int main() {

	int p,q;
	
	cin>>p>>q;
	
	if(p < q)
		swap(p,q);
		
	double maxi = double(p)/100.;
	double mini = double(q)/100.;
	
	double res = 0.5*(maxi+mini)+(maxi-mini)/6.;
	cout<<fixed<<setprecision(16)<<res<<endl;



	return 0;
}
