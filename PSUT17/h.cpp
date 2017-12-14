#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;
int n,m;
int arr[10005];
int pos[10005];
int a,b;
int cont = 0;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d",&arr[i]);
		pos[arr[i]] = i;
	}

	for(int i = 0; i < m; ++i)
	{
		scanf("%d%d",&a,&b);
		int num = abs(pos[b]-pos[a]-1);
		if(!(num % 2 == 0 && (n-num-2) % 2 == 0))
			++cont;
	}

	printf("%d\n",cont);

	return 0;
}
