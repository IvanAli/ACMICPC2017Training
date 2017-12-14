#include <bits/stdc++.h>
using namespace std;

int k;
char a[110];
char b[110];

long long fact[105];

int mat[105][105];
int target[105];
int len[105];
int cant[105];


int main() {
	
	fact[0] = 1;
	for(long long i = 1; i <= 100LL; ++i)
		fact[int(i)] = fact[int(i-1)]*i;
	
	while(scanf("%d",&k))
	{
		memset(mat,0,sizeof mat);
		memset(target,0,sizeof target);
		scanf("%s%s",a,b);
		
		int m = strlen(a);
		int div = m/k;
		
		long long res = 1;
		
		for(int i = 0; i < div; ++i)
		{
			int ini = i*k;
			
			for(int j = ini; j < ini+k; ++j)
			{
				for(int p = ini; p < ini+k; ++p)
				{
					if(b[j] == a[p])
					{
						int &pos = mat[j-ini][p-ini];
						if(pos == target[j-ini])
							++pos;
					}
				}
				++target[j-ini];	
			}
		}
		
		memset(len,0,sizeof len);
		for(int i = 0; i < k; ++i)
		{
			for(int j = 0; j < k; ++j)
				if(target[i] == mat[i][j])
					++len[i];
		}
		
		memset(cant,0,sizeof cant);		
		for(int i = 0; i < k; ++i)
			cant[len[i]]++;
		if(cant[0]) 
		{
			printf("0\n"); continue;
		}
		for(int i = 1; i <= k; ++i)
		{
			res *= fact[i]*(long long)(cant[i]/i);
		}
			
		printf("%I64d\n",res);
	}
	
	
	return 0;
}
