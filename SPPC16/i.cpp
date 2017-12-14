#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

pair <int,int> arr[100005];
long long tam[100005];
int n;
long long tree[262150];
queue < pair <int,long long> > Q;

long long query(int nodo, int ini, int fin, int b, int e)
{
	if(ini == b && fin == e)
		return tree[nodo];
	if(b > e)
		return -1;
	int limit = (ini+fin)>>1;
	return max(query(nodo<<1,ini,limit,b,min(e,limit)),query(nodo<<1|1,limit+1,fin,max(limit+1,b),e));	
}

void update(int nodo, int ini, int fin, int pos, long long val)
{
	if(ini == fin)
	{
		tree[nodo] = val;
		return;
	}
	int limit = (ini+fin)>>1;
	if(pos <= limit)
		update(nodo<<1,ini,limit,pos,val);
	else
		update(nodo<<1|1,limit+1,fin,pos,val);
	tree[nodo] = max(tree[nodo<<1],tree[nodo<<1|1]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	int a,b;
	for(int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		tam[i] = b-a+1;
		arr[i] = {a, i};
	}	
	sort(arr,arr+n);
	int curr = -1;

	for(int i = 0; i < n; ++i)
	{
		
		if(curr != arr[i].fst)
		{
			while(!Q.empty())
			{
				pair <int,long long> tmp = Q.front();
				update(1,0,n-1,tmp.fst,tmp.snd);
				Q.pop();
			}
			curr = arr[i].fst;
		}
		long long num = query(1,0,n-1,0,arr[i].snd);
		Q.push({arr[i].snd,tam[arr[i].snd]+num});

	}
	
	while(!Q.empty())
	{
		pair <int,long long> tmp = Q.front();
		update(1,0,n-1,tmp.fst,tmp.snd);
		Q.pop();
	}

	cout<<query(1,0,n-1,0,n-1)<<endl;
	return 0;

}


