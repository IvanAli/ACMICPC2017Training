#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n;
int arr[10005];
int mark[1400005];
int pos[1400005];

int main()
{
	//IO
	freopen("injurious.in","r",stdin);
	freopen("injurious.out","w",stdout);

	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d",&arr[i]);
	int sum;
	int target = 1;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			sum = arr[i]+arr[j];
			if((sum&1)==0 && mark[sum>>1] == target){
				printf("Yes\n%d %d %d\n",i+1,pos[sum>>1]+1,j+1);
				return 0;
			}
			mark[arr[j]] = target;
			pos[arr[j]] = j;
		}
		++target;
	}
	printf("No\n");
	return 0;
}
