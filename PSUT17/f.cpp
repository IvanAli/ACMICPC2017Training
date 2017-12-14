#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

char arr[2000005];
map <char,int> mp;
		
int mid[5][5];
int endi[5][5];

int main()
{

	mp['R'] = 0;
	mp['B'] = 1;
	mp['G'] = 2;

	scanf("%s",arr);

	int len = strlen(arr);
	if(len == 3)
	{
		printf("0\n");
		return 0;
	}


	int r = 0, b = 0, g = 0;

	for(int i = 0; i < 3; ++i)
	{
		if(arr[i] == 'R') ++r;
		if(arr[i] == 'B') ++b;
		if(arr[i] == 'G') ++g; 
	}

	if(r == 1 && b == 1 && g == 1)
	{
		printf("1\n");
		return 0;
	}

	r = b = g = 0;

	for(int i = len-3; i < len; ++i)
	{
		if(arr[i] == 'R') ++r;
		if(arr[i] == 'B') ++b;
		if(arr[i] == 'G') ++g; 
	}

	if(r == 1 && b == 1 && g == 1)
	{
		printf("1\n");
		return 0;
	}

	r = b = g = 0;

	for(int i = 0; i < 3; ++i)
	{
		if(arr[i] == 'R') ++r;
		if(arr[i] == 'B') ++b;
		if(arr[i] == 'G') ++g; 
	}

	for(int i = 3; i < len+3; ++i)
	{	
		int curr = i%len;
		int prev = (i-3+len)%len;
		if(arr[curr] == 'R') ++r;
		if(arr[curr] == 'B') ++b;
		if(arr[curr] == 'G') ++g;
		if(arr[prev] == 'R') --r;
		if(arr[prev] == 'B') --b;
		if(arr[prev] == 'G') --g;
		if(r == 1 &&  b == 1 && g == 1)
		{
			printf("2\n");
			return 0;
		}
	}

	for(int i = 2; i < len-1; ++i)
	{
		mid[mp[arr[i]]][mp[arr[i-1]]] = 1;
		mid[mp[arr[i-1]]][mp[arr[i]]] = 1;
	}
	
	endi[mp[arr[0]]][mp[arr[1]]] = 1;
	endi[mp[arr[len-1]]][mp[arr[len-2]]] = 1;

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j)
		{
			if(endi[i][j])
			{
				for(int k = 0; k < 3; ++k)
					for(int p = 0; p < 3; ++p)
					{
						if(mid[k][p])
						{
							if((k == (i+1)%3 && p == (i+2)%3)||(p == (i+1)%3 && k == (i+2)%3))
							{
								printf("3\n");
								return 0;
							}
							for(int h = 0; h < 3; ++h)
							{
								if(h != i && h != j && i != j && (k == h || p == h))
								{
									printf("3\n");
									return 0;
								}
							}
						}
					
					}
			
			}
		
		}

	printf("4\n");



	return 0;
}
