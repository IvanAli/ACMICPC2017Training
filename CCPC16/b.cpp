#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

struct Nodo{
	long long t;
	int idx,curr;
	Nodo(){}
	Nodo(const long long &_t, const int &_idx)
	{
		t = _t;
		idx = _idx;
	}
	Nodo(const long long &_t, const int &_idx, const int &_curr)
	{
		t = _t;
		idx = _idx;
		curr = _curr;
	}
};
bool operator <(const Nodo &a, const Nodo &b)
{
	if(a.t == b.t)
		return a.idx < b.idx;
	return a.t < b.t;
}


bool operator >(const Nodo &a, const Nodo &b)
{
	if(a.t == b.t)
		return a.idx > b.idx;
	return a.t > b.t;
}

int L,n,m;
int w[100005];
int d[100005];
long long washed[1000005];

int main()
{
	int test;
	scanf("%d", &test);
	int caso = 1;
	while(test--)
	{
		scanf("%d%d%d",&L,&n,&m);
		for(int i = 0; i < n; ++i)
			scanf("%d",&w[i]);
		for(int i = 0; i < m; ++i)
			scanf("%d",&d[i]);
		sort(w,w+n);
		sort(d,d+m);

		//Washing
		long long T=0;
		priority_queue <Nodo> later;
		priority_queue < Nodo,vector<Nodo>, greater<Nodo> > now;
		
		int Q = max(0,L-n); 
		int Proc = 0;

		for(int i = 0; i < min(n,L); ++i)
		{
			later.push(Nodo(w[i],i));
			now.push(Nodo(w[i],i));
		}
		
		Nodo h,k;
		long long nT;
		while(Proc != L)
		{
			h = now.top();
			now.pop();

			T = h.t;
			washed[L-1-Proc] = T;
			Proc++;

			if(Q)
			{
				Q--;
				nT = T+(long long)(w[h.idx]);
				now.push(Nodo(nT,h.idx));
				later.push(Nodo(nT,h.idx));
			}
			else
			{
				k = later.top();
				nT = T+(long long)(w[h.idx]);
				if(nT < k.t)
				{
					later.pop();
					now.push(Nodo(nT,h.idx));
					later.push(Nodo(nT,h.idx));
				}
			}
		}


		//Drying
		T=0;
		priority_queue <Nodo> laterD;
		priority_queue < Nodo,vector<Nodo>, greater<Nodo> > nowD;
		
		Proc = 0;
		long long dT;
		int curr = min(m,L);

		for(int i = 0; i < curr; ++i)
		{
			dT = washed[i] + (long long)(d[i]);
			laterD.push(Nodo(dT,i,i));
			nowD.push(Nodo(dT,i,i));
		}
		
		while(Proc != L)
		{
			h = nowD.top();
			nowD.pop();

			T = h.t;
			Proc++;

			if(curr < L)
			{
				nT = max(T,washed[curr])+(long long)(d[h.idx]);
				nowD.push(Nodo(nT,h.idx,curr));
				laterD.push(Nodo(nT,h.idx,curr));
				++curr;
			}
			else
			{
				k = laterD.top();
				nT = max(T,washed[k.curr])+(long long)(d[h.idx]);
				if(nT < k.t)
				{
					laterD.pop();
					nowD.push(Nodo(nT,h.idx,k.curr));
					laterD.push(Nodo(nT,h.idx,k.curr));
				}
			}
		}

		printf("Case #%d: %lld\n",caso++,T);

	}

	return 0;
}
