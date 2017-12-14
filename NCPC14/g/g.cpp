#include <bits/stdc++.h>


using namespace std;

int n,k;
int ady[1005];

int idx[1005]; //blob del pasajero
int mark[1005]; //marcados
int target = 1;

pair <int,int> num[1005]; //guarda scc y lacayo

int scc = 0;
int cierra;
bool ciclo;

int dp[1005][1005];



void dfs(int nodo)
{
	int v = ady[nodo];
	
	
	int hijo = idx[v];
	
	if(hijo != 0)
	{
		idx[nodo] = hijo;
		num[hijo].second++;
		return;
	}
	
	if(mark[v] == target)
	{
		++scc;
		idx[nodo] = scc;
		num[scc].first++;
		ciclo = true;
		cierra = v;
		if(nodo == v)
			ciclo = false;
		return;
	}
	
	
	mark[v] = target;
	dfs(v);
	idx[nodo] = idx[v];
	
	if(ciclo)
	{
		num[idx[nodo]].first++;
		if(nodo == cierra)
			ciclo = false;
	}
	else
		num[idx[nodo]].second++;
}


int coins(int pos, int val)
{
	if(val < 0)
		return 0;
	
	int &ans = dp[pos][val];
	
	if(ans != -1)
		return ans;
		
	if(val == 0)
		return ans = 1;
		
	if(pos == 1)
	{
		if(val >= num[1].first)
		{
			if(num[1].first+num[1].second >= val)
				return ans = 1;
			return ans = 0;
		}
		return ans = 0;
	}
		
		
	int r = coins(pos-1,val);
	if(r == 1)
		return ans = 1;
	
	for(int i = 0; i <= num[pos].second; ++i)
	{
		r = coins(pos-1,val-(num[pos].first+i));
		if(r == 1)
			return ans = 1;
	}	
	
	return ans = 0;

}


int main()
{
	
	cin>>n>>k;
	for(int i = 1; i <= n; ++i)
		cin>>ady[i];
	
	for(int i = 1; i <= n; ++i)
	{
		if(idx[i] == 0)
		{
			mark[i] = target;
			dfs(i);
			++target;
		}
	
	}
	
	//for(int i = 1; i <= scc; ++i)
		//cout<<num[i].first<<" "<<num[i].second<<endl;
	
	memset(dp,-1,sizeof dp);
		
	coins(scc,k);
	
	for(int i = k; i >= 0; --i)
	{
		if(dp[scc][i])
		{
			cout<<i<<endl;
			break;
		
		}
	
	}
	


	return 0;
}
