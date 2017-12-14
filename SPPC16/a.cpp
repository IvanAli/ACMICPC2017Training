#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

pair <int,int> pos(int n)
{
	if(n == 1)
		return {0,0};
	int root = ceil(sqrt(n));
	root += (root%2 == 0);
	int len = root*root;
	int tmp = len;
	int i,j;
	int ronda = (root-1)/2;
	if(n >= tmp-(root-1))
	{
		i = ronda-(tmp-n);
		j = -ronda;
		return {i,j};
	}
	tmp -= (root-1);
	if(n >= tmp-(root-1))
	{
		i = -ronda;
		j = -ronda+(tmp-n);
		return {i,j};
	}
	tmp -= (root-1);
	if(n >= tmp-(root-1))
	{
		i = -ronda+(tmp-n);
		j = ronda;
		return {i,j};
	}
	tmp -= (root-1);
	i = ronda;
	j = ronda-(tmp-n);
	return {i,j};
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int a,b;
	cin>>a>>b;
	pair <int,int> ma = pos(a);
	pair <int,int> mb = pos(b);
	int md = abs(ma.fst-mb.fst) + abs(ma.snd-mb.snd);
	cout<<md<<endl; 	
	return 0;

}


