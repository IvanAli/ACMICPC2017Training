#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;
int n;
double maxi = 0;
double a,b,c,d;

int main()
{
	//IO
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		double ratio = (fabs(a-c)*fabs(b-d))/(2.*(fabs(a-c)+fabs(b-d)));
		maxi = max(maxi,ratio);
	}
	printf("%lf\n",maxi);
	return 0;
}
