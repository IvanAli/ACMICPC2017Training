#include <bits/stdc++.h>
using namespace std;

int n,instr,gap;
vector <int> arr[500];
int x = 0;
int gap;
vector <int> res;
bool mark[500];

int main()
{
	cin>>n;
	
	if(n == 1)
	{
		cout<<"A 1"<<endl;
		return 0;
	}
	
	if(n == 2)
	{
		cout<<"Q 1 1"<<endl;
		int tmp;
		cin>>tmp;
		cout<<"A "<<tmp<<" "<<int((tmp == 1)? 2:1)<<endl;
		return 0;
	
	}
	
	instr = n/2+(n%2==1);
	gap = n/2 - (n%2 == 0);
	
	for(int i = 1; i <= instr; ++i)
	{
		cout<<"Q "<<i<<" "<<i+gap<<endl;
		int num;
		for(int j = i; j <= i+gap; ++j)
		{
			cin>>num;
			arr[x].push_back(num);
		}
		++x;
	}
	
	
	for(int i = 0; i < x; ++i)
	{
		
	}
	
	
	

	return 0;
}

