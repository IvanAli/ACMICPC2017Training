#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

int n;
char str[2020];
char mat[5][16] = {"***************","*.**.**..*.**..","*******..*.****","*.**.**..*.**..", "*.*************"};

int main()
{
	IO
	scanf("%d", &n);
	scanf("%s", str);
	
	
	for(int j = 0; j < 5; ++j, printf("\n")){
		for(int i = 0; i < n; ++i){
			for(int k = 0; k < 3; ++k){
				printf("%c",mat[j][int(str[i]-'A')*3+k]);
			}
		
		}
	
	}

	return 0;
}
