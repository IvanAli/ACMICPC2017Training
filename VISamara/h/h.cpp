#include <bits/stdc++.h>
using namespace std;

long double sqr(long double num)
{
	return num*num;
}

long double dist(pair <int,int> a, pair <int,int> b)
{
	return (long double)sqrt(sqr(a.first-b.first)+sqr(a.second-b.second));
}

pair <int,int> a[3];
pair <int,int> b[3];

long double distA[3];
long double distB[3];

long double angleA[3];
long double angleB[3];

long double eps = 1e-8;

int main()
{
	for(int i = 0; i < 3; ++i)
		cin>>a[i].first>>a[i].second;
	
	for(int i = 0; i < 3; ++i)
		cin>>b[i].first>>b[i].second;	

	for(int i = 0; i < 3; ++i)
		distA[i] = dist(a[i],a[(i+1)%3]);
	
	for(int i = 0; i < 3; ++i)
		distB[i] = dist(b[i],b[(i+1)%3]);
		
	for(int i = 0; i < 3; ++i)
		angleA[i] = acos( (sqr(distA[i])-sqr(distA[(i+1)%3])-sqr(distA[(i+2)%3]))/(-2.*distA[(i+1)%3]*distA[(i+2)%3]) );

	
	for(int i = 0; i < 3; ++i)
		angleB[i] = acos( (sqr(distB[i])-sqr(distB[(i+1)%3])-sqr(distB[(i+2)%3]))/(-2.*distB[(i+1)%3]*distB[(i+2)%3]) );
		
	sort(angleA,angleA+3);
	sort(angleB,angleB+3);
	

	for(int i = 0; i < 3; ++i)
		if(fabs(angleA[i]-angleB[i]) > eps)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	
	cout<<"YES"<<endl;
	return 0;
}
