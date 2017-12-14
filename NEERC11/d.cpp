#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int k,r;
pair <int,int> arr[1005];
int game[2005];
int maxbone[10];
bool single[10];
int doble[10];

int main()
{
	//IO
	freopen("domino.in","r",stdin);
	freopen("domino.out","w",stdout);
	
	scanf("%d%d",&k,&r);
	int sum = 0;
	for(int i = 0; i < k; ++i){
		scanf("%d%d", &arr[i].fst, &arr[i].snd);
		sum += arr[i].fst + arr[i].snd;
	}
	for(int i = 0; i < 2*r; ++i)
		scanf("%d", &game[i]);
		
	for(int i = 0; i < k; ++i){
		maxbone[arr[i].fst] = max(maxbone[arr[i].fst],arr[i].snd+arr[i].fst);
		maxbone[arr[i].snd] = max(maxbone[arr[i].snd],arr[i].fst+arr[i].snd);
		single[arr[i].fst] = true;
		single[arr[i].snd] = true;
		if(arr[i].fst == arr[i].snd)
			doble[arr[i].fst]++;
	}
	
	int maxi = 0;
	int ini = game[0], fin = game[2*r-1];

	if(single[ini])
		maxi = max(maxi,maxbone[ini]); 
	if(single[fin])
		maxi = max(maxi,maxbone[fin]);
	if(doble[ini] && doble[fin] && !(ini == fin && doble[ini] == 1))
	 	maxi = max(maxi,2*ini+2*fin);

	if(maxi == sum)
		printf("-1\n");
	else
		printf("%d\n",sum-maxi);
	
	return 0;
}
