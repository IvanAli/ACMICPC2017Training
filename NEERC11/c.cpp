#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n,Q;
vector <int> arr;
char str[100];
int main()
{
	//IO
	//freopen("cbt.in","r",stdin);
	//freopen("cbt.out","w",stdout);
	scanf("%d%d", &n, &Q);
	
	for(int i = 30; i >= 0; --i)
		if(n&(1<<i))
			arr.pb(i);
	int m = arr.size();
	int num;
	for(int i = 0; i < Q; ++i){
		scanf("%s",str);
		if(str[0] == 'A'){
			scanf("%d",&num);
			int idx = 0;
			int offset = 0;
			while(idx < m){
				if(num >= (1<<arr[idx])+offset){
					printf("R");
					offset += (1<<arr[idx++]);
				}
				else{
					if(idx != m-1)
						printf("L");
					break;
				}
			}

			if(idx < m){
				int pot = (1<<arr[idx]);
				int ini = offset, fin = offset+pot-1;
				while(ini < fin){
					int limit = (ini+fin)/2;
					if(num <= limit){
						printf("L");
						fin = limit;
					}	
					else{
						printf("R");
						ini = limit+1;
					}
				}
			}
			printf("\n");
		}
		else{
			scanf("%s",str);
			int idx = 0;
			int c = 0;
			int len = strlen(str);
			int offset = 0;
			while(idx < m && c < len){
				if(str[c] == 'L'){
					c++;
					break;
				}
				offset += (1<<arr[idx++]);
				c++;
			}
			if(idx == m){
				idx--;
				c--;
				offset -= (1<<arr[idx]);
			}
			int pot = (1<<arr[idx]);
			while(c < len){
					if(str[c] == 'R')
						offset += pot/2;
					pot /= 2;
					c++;
			}
			printf("%d\n",offset);
		}
	}
		


	return 0;
}
