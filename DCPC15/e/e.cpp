#include <bits/stdc++.h>

using namespace std;

int n,Q;


int arr[100005];

int tree[3100005][2];
int leaf[3100005];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	
	int test;
	scanf("%d", &test);	
	while(test--)
	{
	
		memset(tree,-1,sizeof tree);
		memset(leaf, -1, sizeof leaf);
		scanf("%d%d", &n, &Q);
		for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
		int nuevo = 1;
		for(int i = 0; i < n; ++i)
		{
			int curr = 0;
			for(int j = 31; j >= 0; --j)
			{
				if(arr[i]&(1<<j))
				{
					if(tree[curr][1] == -1)
					{
						tree[curr][1] = nuevo++;
					}
						curr = tree[curr][1];			
				
				}
				else
				{
					if(tree[curr][0] == -1)
					{
						tree[curr][0] = nuevo++;
					}
						curr = tree[curr][0];
				
				}
			
			}
			if (leaf[curr] == -1) leaf[curr] = i;
		
		}
		
		int num;
		for(int i = 0; i < Q; ++i)
		{
			scanf("%d", &num);
			int curr = 0;
			
			for(int j = 31; j >= 0; --j)
			{
				if(num&(1<<j))
				{
					if(tree[curr][0] != -1)
						curr = tree[curr][0];
					else
						curr = tree[curr][1];
				}
				else
				{
					if(tree[curr][1] != -1)
						curr = tree[curr][1];
					else
						curr = tree[curr][0];
				}
			
			}
			printf("%d\n", leaf[curr] + 1);			
		}
		printf("\n");
	}
	return 0;
}