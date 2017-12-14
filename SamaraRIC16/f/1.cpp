#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int n,m;
string sop[100005];
long long row[100005];
long long col[100005];
long long added[100005];

int main() {

	cin>>n>>m;
	
	int cont1 = 0;
	bool fl = false;
	int x = 0;
	
	for(int i = 0; i < n; ++i)
		cin>>sop[i];
		
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			if(sop[i][j] == '.')
			{
				cont1++;
				if(fl)
					++x;
				else
				{
					fl = true;
					x = 1;
				}
			}
			else
			{
				fl = false;
				row[x]++;
				x = 0;
			}
		}
		row[x]++;
		x = 0;
	}
	
	fl = false;
	x = 0;
	
	for(int j = 0; j < m; ++j)
	{
		for(int i = 0; i < n; ++i)
		{
			if(sop[i][j] == '.')
			{
				if(fl)
					++x;
				else
				{
					fl = true;
					x = 1;
				}
			}
			else
			{
				fl = false;
				col[x]++;
				x = 0;
			}
		}
		col[x]++;
		x = 0;
	}
	
	int maxi = max(n,m);
	long long cant = 0;
	long long acum = 0;
	
	for(int i = maxi; i >= 2; --i)
	{
		added[i] += acum;
		acum += cant;
		acum += row[i]*2;
		cant += row[i];
	}
	
	acum = cant = 0;
	
	
	
	for(int i = maxi; i >= 2; --i)
	{
		added[i] += acum;
		acum += cant;
		acum += col[i]*2;
		cant += col[i];
	}
	cout<<cont1;
	for(int i = 2; i <= maxi; ++i)
	{
		cout<<" "<<col[i]+row[i]+added[i];
		//cout<<i<<": "<<col[i]<<" "<<row[i]<<" "<<added[i]<<endl;
	}
	cout<<endl;

	return 0;
}
