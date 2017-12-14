#include <bits/stdc++.h>
using namespace std;
int n,m;
long long mat[50][50];


int main()
{
	int test;
	
	for(int i = 1; i <= 30; ++i)
		for(int j = 1; j <= 30; ++j)
		{
			if(j == 1 || i == 1)
				mat[i][j] = 1LL;
			else
				mat[i][j] = mat[i-1][j]+mat[i][j-1];
		}
	
	
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d%d", &n, &m);
		printf("%lld\n",mat[n][m]);
	}



	return 0;
}

