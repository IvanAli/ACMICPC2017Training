nclude <bits/stdc++.h>
#define snd second
#define fst first
#define endl '\n'

using namespace std;

struct Nodo{
	int h,w,d,k;
	Nodo(){}
};

int n, L, U;
Nodo arr[105];
double ady[105][105];

int main()
{

	freopen("walk.in","r",stdin);

	int test;
	scanf("%d",&test);
	//cout<<test<<endl;
	while(test--)
	{
		scanf("%d%d%d",&n,&L,&U);
		for(int i = 1; i <= n; ++i)
		{
			scanf("%d%d%d%d",&arr[i].h,&arr[i].w,&arr[i].d,&arr[i].k);
			ady[0][i] = ady[i][0]  = (double)(arr[i].d);
		}
		for(int i = 1; i <= n; ++i)
			
		



	}
	fclose(stdin);
	return 0;

}
