#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;
int mapa[12][12][12];
int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	fstream fs;
	fs.open ("commandos.in", fstream::in );
	int test;
	fs>>test;
	while(test--)
	{
		fs>>n;
		int f,y,x,h;
		memset(mapa,0,sizeof mapa);
		for(int i = 0; i < n; ++i)
		{
			fs>>f>>y>>x>>h;
			mapa[f][y][x] = h;
		}
		for(int i = 10; i > 0; --i)
			for(int j = 1; j <= 10; ++j)
				for(int k = 1; k <= 10; ++k)
					mapa[i][j][k] += max(mapa[i+1][j][k],max(mapa[i][j-1][k],mapa[i][j][k-1]));
		cout<<mapa[1][10][10]<<endl;

	}
	fs.close();
	return 0;

}
