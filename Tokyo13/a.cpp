#include <bits/stdc++.h>
#define snd second
#define fst first
#define pb push_back
using namespace std;

vector < pair<int,int> > par[20005];
int p,q;

int main()
{
//	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int test;
	scanf("%d",&test);

	for(int i = 0; i*i <= 20000; ++i)
		for(int j = i; i*i + j*j <= 20000; ++j)
		{
			int tmp = i*i+j*j;
			par[tmp].pb({i,j});
			par[tmp].pb({-i,j});
			par[tmp].pb({i,-j});
			par[tmp].pb({-i,-j});
			par[tmp].pb({j,i});
			par[tmp].pb({-j,i});
			par[tmp].pb({j,-i});
			par[tmp].pb({-j,-i});
		}

	while(test--)
	{
		scanf("%d%d",&p,&q);

		vector < pair <int, int> > fbd;
		fbd.pb({1,0});
		fbd.pb({0,1});
		fbd.pb({-1,0});
		fbd.pb({0,-1});
		fbd.pb({p,q});
		fbd.pb({-q,p});
		fbd.pb({-p,-q});
		fbd.pb({q,-p});
	//	cout<<"fbd: "<<endl;
	//	for (pair <int,int> v : fbd)
	//	{
	//		cout<<v.fst<<" "<<v.snd<<endl;
	//	}cout<<endl<<endl;


		int num = p*p+q*q;
		bool fl = true;
		for(int i = 1; i*i <= num && fl; ++i)
		{
			int d = i;
			
			for( pair <int,int> v : par[d] )
			{
				int m = v.fst;
				int n = v.snd;
				
				int c1 = m*p+n*q;
				int c2 = m*q-n*p;
				int sqr = n*n+m*m;
				if(c1%sqr == 0 && c2%sqr == 0)
				{
					bool cl = false;
					for( pair<int,int > u : fbd )
					{
						if(v == u)
						{
							cl = true;
							break;
						}
					}

					if(!cl)
					{
						fl = false;
					//	cout<<m<<" !  "<<n<<endl;
					//	cout<<sqr<<" divides "<<c1<<" "<<c2<<endl;
						break;
					}
				
				}

			}

			d = num/i;
			for( pair <int,int> v : par[d] )
			{
				int m = v.fst;
				int n = v.snd;
				
				int c1 = m*p+n*q;
				int c2 = m*q-n*p;
				int sqr = n*n+m*m;
				if(c1%sqr == 0 && c2%sqr == 0)
				{
					bool cl = false;
					for( pair<int,int > u : fbd )
					{
						if(v == u)
						{
							cl = true;
							break;
						}
					}

					if(!cl)
					{
						fl = cl;
					//	cout<<m<<" !  "<<n<<endl;
					//	cout<<sqr<<" divides "<<c1<<" "<<c2<<endl;
						break;
					}
				
				}

			}


		
		}
		if(fl)
			printf("P\n");
		else
			printf("C\n");


	}

	return 0;

}


