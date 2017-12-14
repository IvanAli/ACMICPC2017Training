#include <bits/stdc++.h>
#define snd second
#define fst first
#define pb push_back
using namespace std;

int n,m;
long long w[100005];
int head[100005];
vector <int> forest[100005];
char str[2];
int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int a,b;
	long long weight;
	int lena, lenb;
	int fa,fb;
	while(scanf("%d%d",&n,&m) && n != 0)
	{
		memset(w,0,sizeof w);
		for(int i = 1; i <= n; ++i)
		{
			forest[i].clear();
			forest[i].pb(i);
			head[i] = i;
		}
		
		for(int i = 0; i < m; ++i)
		{
			scanf("%s",str);
			if(str[0] == '!')
			{
				scanf("%d%d%lld",&a,&b,&weight);
				if(head[a] != head[b])
				{
					fa = head[a];
					fb = head[b];
					lena = forest[fa].size();
					lenb = forest[fb].size();

					if(lena < lenb)
					{
						long long diff = weight - (w[b]-w[a]);
						for(int v : forest[fa])
						{
							w[v] -= diff;
							head[v] = fb;
							forest[fb].pb(v);
						}
					}
					else
					{
						long long diff = weight - (w[b]-w[a]);
						for(int v : forest[fb])
						{
							w[v] += diff;
							head[v] = fa;
							forest[fa].pb(v);
						}
					
					}
				}
			}
			else
			{
				scanf("%d%d",&a,&b);
				if(head[a] != head[b])
					printf("UNKNOWN\n");
				else
					printf("%lld\n",w[b]-w[a]);
			}
		}

	}


	return 0;

}


