#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define fst first
#define snd second
using namespace std;

const int N = 100005;

int n;
pair <int, int> arr[500005];
int izq[500005];
int der[500005];
double sqr(double num)
{
	return num*num;
}

double dist(pair <double, double> a, pair <double, double> b)
{
	return sqrt(sqr(a.fst-b.fst)+sqr(a.snd-b.snd));
}


int main() {

	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n+2; ++i)
			scanf("%d%d",&arr[i].snd,&arr[i].fst); //pair h,x
		
		stack < pair <int,int> > Q;
		
		Q.push({arr[0].fst,0}); //pair h,i
		izq[0] = 0;
		
		pair <int,int> a;
		
		for(int i = 1; i < n+2; ++i)
		{
			while(!Q.empty())
			{
				a = Q.top();
				if(a.fst <= arr[i].fst)
					Q.pop();
				else
					break;
			}
			
			if(Q.empty())
				izq[i] = i;
			else
				izq[i] = a.snd;
			Q.push({arr[i].fst,i});
		}
		
		while(!Q.empty())
			Q.pop();
		
		Q.push({arr[n+1].fst,n+1}); //pair h,i
		der[n+1] = n+1;
		
		for(int i = n; i >= 0; --i)
		{
			while(!Q.empty())
			{
				a = Q.top();
				if(a.fst <= arr[i].fst)
					Q.pop();
				else
					break;
			}
			
			if(Q.empty())
				der[i] = i;
			else
				der[i] = a.snd;
			Q.push({arr[i].fst,i});
		}
		
		for(int i = 1; i < n+1; ++i)
		{
			printf("%d %d %.4lf %.4lf\n", izq[i], der[i], dist(arr[i],arr[izq[i]]), dist(arr[i],arr[der[i]]));
		}
		
	
	}



	return 0;
}
