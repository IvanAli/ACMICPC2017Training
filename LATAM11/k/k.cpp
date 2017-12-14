#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[3];
	
	while(cin>>a[0]>>a[1]>>a[2] && a[0] != 0)
	{
		sort(a,a+3);
		
		if(a[0] == 13)
		{
			cout<<"*"<<endl;
			continue;
		}
		
		if(a[0] == a[1] && a[0] == a[2])
		{
			int d = a[0]+1;
			
			cout<<d<<" "<<d<<" "<<d<<endl;
			continue;
		
		}
		
		
		if(a[0] == a[1] || a[1] == a[2])
		{
			int p,u;
			
			if(a[0] == a[1])
			{
				p = a[0];
				u = a[2];
			}
			
			if(a[1] == a[2])
			{
				p = a[1];
				u = a[0];
			}
			
			if(p == 13 && u == 12)
			{
				cout<<"1 1 1"<<endl;
				continue;
			}
			
			if(u == 13)
			{
				a[0] = a[1] = p+1;
				a[2] = 1;
				
				sort(a,a+3);
				cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
				continue;
			
			}
			
			a[0] = a[1] = p;
			
			if(u+1 == p)
				a[2] = u+2;
			else
				a[2] = u+1;
			sort(a,a+3);
			cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
		
		
			continue;
		}
		
		cout<<"1 1 2"<<endl;
		
		
	
	}

}