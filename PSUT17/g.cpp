#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n,m;
char arr[200005];
set < pair<int,bool> > st;
int r = 0, g = 0, b = 0;

void compare(int ini, int fin)
{
	for(int i = ini; i <= fin; ++i)
	{
		if(arr[i] == 'R'){--r; ++b;}
		if(arr[i] == 'G'){--g; ++r;}
		if(arr[i] == 'B'){--b; ++g;}
	}
}
void imprime()
{
	printf("%d %d %d\n",r,g,b);
}



int main()
{
	scanf("%d%d%s",&n,&m,arr);

	int ini, fin;

	for(int i = 0; i < n; ++i)
	{
		if(arr[i] == 'R') ++r;
		if(arr[i] == 'G') ++g;
		if(arr[i] == 'B') ++b;
	}

	int I,F;

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d",&ini,&fin);
		--ini; --fin;
		auto iniP = st.lower_bound({ini,0});
		auto finP = st.lower_bound({fin,1});

	  	if(iniP == st.end())
		{
			compare(ini,fin);
			st.insert({ini,0});
			st.insert({fin,1});
			imprime();
			continue;
		}

		int I = -1,F = -1;

		if(finP == st.end())
		{
			finP--;
			compare((*finP).fst+1,fin);
			F = fin;
		}

		if(finP == st.begin())
		{
			compare(ini,fin);
			st.insert({ini,0});
			st.insert({fin,1});
			imprime();
			continue;
		}

		if((*iniP).snd == 0)
		{
			if(iniP == finP)
			{
				compare(ini,fin);
				st.insert({ini,0});
				st.insert({fin,1});
				imprime();
				continue;
			}
			compare(ini,(*iniP-1).fst);
			I = ini;
		}
		else
		{
			iniP--;
			I = (*iniP).fst;
		}

		if(F == -1)
		{
			if((*finP).snd == 0)
			{
				finP--;
				compare((*finP).fst+1,fin);
				F = fin;
			}
			else
			{
				F = (*finP).fst;
			}
		}

		
		



	}


	return 0;
}
