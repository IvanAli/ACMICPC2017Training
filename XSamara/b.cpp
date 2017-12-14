#include <bits/stdc++.h>
#define snd second
#define fst first
#define pb  push_back
using namespace std;

char inp[200005];
vector <int> pos;
char P[15] = "happiness";


int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%s",inp);

	int len = strlen(inp);

	for(int i = 0; i < len; ++i)
	{
		bool fl = true;
		int j;
		for(j = i; j < i+9; ++j)
		{
			if(j >= len || inp[j] != P[j-i])
			{
				fl = false;
				break;
			}
		
		}
		if(fl)
			pos.pb(i);
		else
		{
			if(i != j)
				i = j-1;

		}

		//cout<<i<<endl;
	}

	int n = pos.size();
	if(n==0)
	{
		if(len > 2 && inp[0] == 'a' && inp[1] == 'h')
			cout<<"YES"<<endl<<"1 3"<<endl;
		else	
			cout<<"YES"<<endl<<"1 2"<<endl;
		return 0;
	}
	if(n > 2)
		cout<<"NO"<<endl;
	else
	{
		if(n==1)
		{
			cout<<"YES"<<endl;
			cout<<pos[0]+1<<" "<<pos[0]+2<<endl;
		}
		else
		{
			if(n==2)
			{
				cout<<"YES"<<endl;
				cout<<pos[0]+1<<" "<<pos[1]+2<<endl;
			}				
		}

		
	}


	


	return 0;

}


