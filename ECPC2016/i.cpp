#include <bits/stdc++.h>
#define snd second
#define fst first
#define endl '\n'

using namespace std;

struct Tri{
	double x,y,r;
	Tri(){}
	Tri(const double &_x, const double &_y, const double &_r)
	{
		x = _x;
		y = _y;
		r = _r;
	}

};

double sqr(double num)
{
	return num*num;
}

int n;
double m;
Tri arr[100005];

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0); 

	//fstream fs;
	//fs.open ("walk.in", fstream::in );

	//fs.tie(0);

	freopen("walk.in","r",stdin);

	int test;
	scanf("%d",&test);
	//cout<<test<<endl;
	while(test--)
	{
		scanf("%d%lf",&n,&m);
		double x,y,r;
		for(int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf",&x,&y,&r);
			arr[i] = Tri(x,y,r);
		}
		vector < pair<double, pair<bool,int> > > timeL;
	
		for(int i = 0; i < n; ++i)
		{
			if(arr[i].y+arr[i].r <= m && arr[i].y-arr[i].r >= -m)
			{
				double xinf = arr[i].x - sqrt( sqr(m-arr[i].r)-sqr(arr[i].y) );	
				double xsup = arr[i].x + sqrt( sqr(m-arr[i].r)-sqr(arr[i].y) );
				timeL.push_back({xinf,{false,i}});
				timeL.push_back({xsup,{true,i}});
			}
		}
		sort(timeL.begin(),timeL.end());
		double dist = 0LL;
		double maxi = 0LL;

		for(auto v : timeL)
		{
			if(!v.snd.first)
			{
				dist += arr[v.snd.snd].r;
				maxi = max(maxi,dist);
			}
			else
				dist -= arr[v.snd.snd].r;
		}
		long long sol = round(maxi);
		printf("%lld\n",sol);

	}
	fclose(stdin);
	return 0;

}
