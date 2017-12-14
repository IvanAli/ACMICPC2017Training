#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int x;
int n;
int arr[1000005];
map <int,int> mp;


int main() {
	
	while(scanf("%d",&x) != EOF)
	{
		scanf("%d",&n);
		mp.clear();
		x*=10000000;
		
		for(int i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
			mp[arr[i]]++;
		}
		
		int maxi = -1;
		int l1, l2;
		int diff;
		for(int i = 0; i < n; ++i)
		{
			diff = x-arr[i];
			map <int,int>::iterator it = mp.find(diff);
			if(it != mp.end())
			{
				if(diff == arr[i])
				{
					if((*it).second > 1)
					{
						int tmp = abs(diff-arr[i]);
						if(tmp > maxi)
						{
							maxi = tmp;
							l1 = diff;
							l2 = arr[i];
						}
					}
				}
				else
				{
					int tmp = abs(diff-arr[i]);
					if(tmp > maxi)
					{
						maxi = tmp;
						l1 = diff;
						l2 = arr[i];
					}
				}
			}
		}
		
		if(maxi != -1)
		{
			if(l2 < l1) swap(l1,l2);
			printf("yes %d %d\n",l1,l2);
		}
		else
			printf("danger\n");
	}
	
	return 0;
}
