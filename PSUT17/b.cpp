#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;
char arr[200005];
int smile[200005];
int nsmile[200005];


int main()
{
	scanf("%s",arr);

	char prev = '#';
	int len = strlen(arr);

	for(int i = 1; i <= len; ++i)
	{
		nsmile[i] = nsmile[i-1];
		if(arr[i-1] == ':' && prev == '(')
			++nsmile[i];
		prev = arr[i-1];
	}
	
	prev = '#';

	for(int i = len; i > 0; --i)
	{
		smile[i] = smile[i+1];
		if(arr[i-1] == ':' && prev == ')')
			++smile[i];
		prev = arr[i-1];
	}

	char mirr0,mirr;

	if(arr[0] == '(')
		mirr0 = ')';
	else if(arr[0] == ')')
		mirr0 = '(';
	else
		mirr0 = ':';
	
	int maxi = 0;

	for(int i = 1; i <= len; ++i)
	{
		int v = nsmile[i]+smile[i+1];
		if(mirr0 == ':' && arr[i] == ')')
			++v;
		maxi = max(maxi,v);
	}


	printf("%d\n",maxi);

	return 0;
}
