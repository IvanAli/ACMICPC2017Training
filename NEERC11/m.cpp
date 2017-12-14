#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int m,n,k;
int p[5];
int q[5];

int main()
{
	//IO
	freopen("munich.in","r",stdin);
	freopen("munich.out","w",stdout);
	
	scanf("%d%d%d",&m,&n,&k);
	for(int i = 0; i < 3; ++i)
		scanf("%d",&p[i]);
	for(int i = 0; i < 3; ++i)
		scanf("%d",&q[i]);
	int minC = INT_MAX;
	
	for(int i = 0; i <= m; ++i){
		for(int j = 0; j <= n; ++j){
				int costo = 0;
				costo += (m-i)*min(q[0],p[0]*k);
				costo += (n-j)*min(min(q[0],p[0]*k),min(q[1],p[1]*k));
				costo += (i/5)*min(q[2],p[2]*k);
				costo += (j/10)*min(q[2],p[2]*k);
				
				if((i%5) == 0){
					if((j%10) != 0)
						costo += min(q[2],p[2]*k);
				}
				else if((j%10) == 0){
						if((i%5) != 0)
							costo += min(q[2],p[2]*k);
				}
				else{
					costo += min(q[2],p[2]*k);
					int sobraA = 5-(i%5);
					int sobraCh = (j%10);
					sobraCh = max(0,sobraCh-sobraA*2);
					if(sobraCh != 0)
						costo += min(q[2],p[2]*k);
				}
				minC = min(minC,costo);
		}
	}
	printf("%d\n",minC);	
	return 0;
}
