#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

	int n,p,Q;
	set <int> st;

int main() {

	cin>>n>>p;
	
	int num;
	for(int i = 0; i < n; ++i)
	{
		cin>>num;
		st.insert(num);
	}
	
	auto it = st.begin();
	for(int i = 0; i < p-1; ++i)
		++it;
	
	cin>>Q;
	string pal; 
	
	
	while(Q--)
	{
		cin>>pal;
		if(pal == "print")
			cout<<(*it)<<endl;
		else if(pal == "moveLeft")
		{
			if(it != st.begin())
				--it;
		}
		else if(pal == "moveRight")
		{
			++it;
			if(it == st.end())
				--it;
		}
		else if(pal == "insertRight")
		{
			cin>>num;
			st.insert(it,num);
		}
		else
		{
			cin>>num;
			st.insert(it,(*it));
			(*it) = num;
			++it;
		}
	
	}
	
	

	return 0;
}
