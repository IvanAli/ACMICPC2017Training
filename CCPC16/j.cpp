#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int G;
char worr[100];
char score[5][20][100];
char fin[20][100];

int main()
{
	int test;
	scanf("%d", &test);

	while(test--)
	{
		scanf("%d%s", &G, worr);
		for(int i = 0; i < 5; ++i)
			for(int j = 0; j < 20; ++j)
				scanf("%s",score[i][j]);
		for(int i = 0; i < 20; ++i)
			scanf("%s",fin[i]);


		for(int x = 0; x <= G; ++x)
			for(int y = 0; y <= G-x; ++y)
			{
				
				int cx = 0;
				int reg = 0;
				int place = 0;
				set <string> st;
				while(cx != x)
				{
					
				
				}



			
			}

	
	}


	return 0;
}
