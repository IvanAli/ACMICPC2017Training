#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;
char mat[200002][26];
int n,m;
pair <int,int> arr[200002];


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>mat[i];
	cin>>m;
	for(int i = 0; i < m; ++i)
		cin>>arr[i].fst>>arr[i].snd;

	int curr = 1;
	int cont = 0;

	for(int i = m-1; i >= 0; --i)
	{
		if(arr[i].fst == curr)
		{
			++cont;
			curr = arr[i].snd; 
		}
	}

	while(cont--)
		cout<<"I_love_";
	cout<<mat[curr-1]<<"\n";


}
