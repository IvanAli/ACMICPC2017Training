#include <bits/stdc++.h>

using namespace std;

struct Tri{
	int last, curr, next, nnext;
	
	Tri(){}
	
	Tri(const int &_last, const int &_curr, const int &_next, const int &_nnext)
	{
		last = _last;
		curr = _curr;
		next = _next;
		nnext = _nnext;
	
	}


};
bool operator < (const Tri &a, const Tri &b)
{
	if(a.last == b.last)
	{
		if(a.curr == b.curr)
		{
			if(a.next == b.next)
				return a.nnext < b.nnext;
			return a.next < b.next;
		}
		return a.curr < b.curr;
	}
	return a.last < b.last;
	

}



int n;
int a[200005];
int b[200005];

int da[200005];
int db[200005];

map < Tri , int > mp;


int main()
{
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	for(int i = 0; i < n; ++i)
		cin>>b[i];
		
	sort(a,a+n);
	sort(b,b+n);
	
	da[0] = 360000-a[n-1]+a[0];
	
	for(int i = 1; i < n; ++i)
		da[i] = a[i]-a[i-1]; 
	
	
	db[0] = 360000-b[n-1]+b[0];
	
	for(int i = 1; i < n; ++i)
		db[i] = b[i]-b[i-1]; 
		
	for(int i = 0; i < n; ++i)
		mp[Tri(da[(i-1+n)%n],da[i],da[(i+1)%n],da[(i+2)%n])]++;
	
	bool fl = true;
	
	for(int i = 0; i < n; ++i)
	{
		Tri tmp = Tri(db[(i-1+n)%n],db[i],db[(i+1)%n],db[(i+2)%n]);
		
		auto it = mp.find(tmp);
		
		if(it == mp.end())
		{
			fl = false;
			break;
		}
		
		if( (*it).second == 0 )
		{
			fl = false;
			break;
		}
		
		(*it).second--;
	
	}
	
	if(fl) cout<<"possible"<<endl;
	else 	cout<<"impossible"<<endl;
		

	return 0;

}
