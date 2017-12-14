#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n,k;
vector <int> arr[50005];

int main()
{
	IO
	scanf("%d%d", &n, &k);
	
	if(n <= k){
		printf("-1\n"); return 0;
	}
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < k; ++j)
			arr[i].pb(k*i+j);
	int m = n*k;
	int ult = (n-1)*k;
	int idx = 0, row = 0;
	
	for(int i = 0; i < m-k; ++i){
		if(idx >= row*k && idx < row*k+k){
			arr[row].pb(ult++);
			row = (row+1)%n;
		}
		arr[row].pb(idx++);
		row = (row+1)%n;
	}
	
	for(int i = 0; i < n; ++i,printf("\n")){
		printf("%d",arr[i][0]+1);
		for(int j = 1; j < 2*k; ++j){
			printf(" %d",arr[i][j]+1);
		}
	}
	return 0;
}
