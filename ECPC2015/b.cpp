#include <bits/stdc++.h>
using namespace std;

int q,m;
int sol[105][4];

string opt,res;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		memset(sol,0,sizeof sol);
		cin>>q>>m;
		for(int i = 0; i < m; ++i)
		{
			for(int i = 0; i < q; ++i)
			{
				cin>>opt>>res;

				//0 none //1 true //2 false

				sol[i][int(opt[0]-'A')] = (res[0] == 'T')?1:2;

			}


		}

		for(int i = 0; i < q; ++i)
		{
			bool fl = true;
			for(int h = 0; h < 4; ++h)
			{
				if(sol[i][h] == 1)
				{
					fl = false;
					if(i == 0) cout<<char(h+'A'); else cout<<" "<<char(h+'A');
					break;
				}
			}
			if(fl)
			{
				int cf = 0;
				for(int h = 0; h < 4; ++h)
				{
					if(sol[i][h] == 2)
						cf++;
				}
				if(cf == 3)
				{
					for(int h = 0; h < 4; ++h)
					{
						if(sol[i][h] == 0)
						{
							if(i == 0) cout<<char(h+'A'); else cout<<" "<<char(h+'A');
							break;
						}
					}

				}
				else
					if(i == 0) cout<<"?"; else cout<<" "<<"?";

			}



		}

		cout<<endl;
	}

	return 0;
}
