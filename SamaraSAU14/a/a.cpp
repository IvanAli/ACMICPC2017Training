#include <bits/stdc++.h>
using namespace std;

struct Tri{
	int arr[3];
	Tri(){}
	Tri(const int &a, const int &b, const int &c)
	{
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
		sort(arr,arr+3);
	}
};

bool operator <(const Tri &a, const Tri &b)
{
	return a.arr[0] < b.arr[0] && a.arr[1] < b.arr[1];
}

int n;
set <Tri> st;
Tri num[200005];
int turno[200005];
set <int> st2;

int main()
{
	cin>>n;
	
	int a,b,c;
	int cont = 0;
	for(int i = 0; i < n; ++i)
	{
		cin>>a>>b>>c;
		
		assert(a!=b);
		assert(a!=c);
		assert(b!=c);
		
		auto it = st2.find(a);
		assert(it == st2.end());
		it = st2.find(b);
		assert(it == st2.end());
		it = st2.find(c);
		assert(it == st2.end());
		st2.insert(a);
		st2.insert(b);
		st2.insert(c);
		
		num[i] = Tri(a,b,c);
		st.insert(num[i]);
	}
	
	
	Tri temp;
	for(int i = 0; i < n; ++i)
	{
		st.erase(num[i]);
		temp.arr[0] = num[i].arr[1];
		temp.arr[1] = num[i].arr[2];
		auto it = st.lower_bound(temp);
		if(it == st.end())
			turno[cont++]=i+1;
		else
		{
			it = st.lower_bound(num[i]);
			if(it == st.end())
				turno[cont++]=i+1;
			
		}
		
		st.insert(num[i]);
	}
	
	cout<<cont<<endl;
	assert(cont != 0);
	if(cont != 0) cout<<turno[0];
	for(int i = 1; i < cont; ++i)
		cout<<" "<<turno[i];
	cout<<endl;


	return 0;
}
