#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

int n,m;
int mat[1003][1003];
int maxi[1003][1003][4];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n>>m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin>>mat[i][j];
	memset(maxi,-1,sizeof maxi);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			maxi[i][j][0] = max(mat[i][j],max(maxi[i-1][j][0],maxi[i][j-1][0]));
	
	for(int i = 1; i <= n; ++i)
		for(int j = m; j > 0; --j)
			maxi[i][j][1] = max(mat[i][j],max(maxi[i-1][j][1],maxi[i][j+1][1]));

	for(int i = n; i > 0; --i)
		for(int j = m; j > 0; --j)
			maxi[i][j][2] = max(mat[i][j],max(maxi[i+1][j][2],maxi[i][j+1][2]));

	for(int i = n; i > 0; --i)
		for(int j = 1; j <= m; ++j)
			maxi[i][j][3] = max(mat[i][j],max(maxi[i+1][j][3],maxi[i][j-1][3]));
	int mini = INT_MAX;
	int pi,pj;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			int temp = -1;
			temp = max(temp,maxi[i-1][j-1][0]);	
			temp = max(temp,maxi[i-1][j+1][1]);
			temp = max(temp,maxi[i+1][j+1][2]);
			temp = max(temp,maxi[i+1][j-1][3]);
			if(temp < mini)
			{
				mini = temp;
				pi = i;
				pj = j;
			}
		}
	cout<<pi<<" "<<pj<<'\n';	


}
