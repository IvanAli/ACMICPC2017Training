#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
struct Tri{
	int s,x1,x2;
	Tri(){}
	Tri(const int &_s, const int &_x1, const int &_x2){
		s=_s;
		x1=_x1;
		x2=_x2;
	}
};

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

int n,m;
char str[55][55];
int id[55][55];
pair <int,int> coo[110];
Tri ini;
unsigned int mat[110][110][110];

int main(){
	IO
	int test;
	cin>>test;
	while(test--){
	
		cin>>n>>m;	
		memset(mat,-1,sizeof mat);
		for(int i = 0; i < n; ++i)
			cin>>str[i];
		int cont = 0, b = 0, x = 0;
		coo[0] = {-10,-10};
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < m; ++j){
				if(str[i][j] != '#'){
					id[i][j] = ++cont;
					coo[cont] = {i,j};
					if(str[i][j] == 'B')
						++b;
					if(str[i][j] == 'X'){
						++x;
						if(x == 1)
							ini.x1 = id[i][j];
						if(x == 2)
							ini.x2 = id[i][j];
					}
					if(str[i][j] == 'S')
						ini.s = id[i][j];				
				}
			}
		}
		if(b > x){
			cout<<"impossible"<<endl;
			continue;
		}
		queue <Tri> Q;
		Q.push(ini);
		mat[ini.s][ini.x1][ini.x2] = 0;
	
		bool fl = true;
		while(!Q.empty()){
			Tri a = Q.front();
			Q.pop();
			if(str[coo[a.s].fst][coo[a.s].snd] == 'E'){
		
				int x1i = coo[a.x1].fst;
				int x1j = coo[a.x1].snd;
				int x2i = coo[a.x2].fst;
				int x2j = coo[a.x2].snd;
			
				if(b == 0){
					cout<<mat[a.s][a.x1][a.x2]<<endl;
					fl = false;
					break;
				}
				if(b == 1){
					if(a.x1 != 0 && str[x1i][x1j] == 'B'){
						cout<<mat[a.s][a.x1][a.x2]<<endl;
						fl = false;
						break;
					}
					if(a.x2 != 0 && str[x2i][x2j] == 'B'){
						cout<<mat[a.s][a.x1][a.x2]<<endl;
						fl = false;
						break;
					}
				}
				if(b == 2){
					if(a.x2 != 0 && str[x2i][x2j] == 'B' && a.x1 != 0 && str[x1i][x1j] == 'B'){
						cout<<mat[a.s][a.x1][a.x2]<<endl;
						fl = false;
						break;
					}
				}
			}
			for(int h = 0; h < 4; ++h){
				int ni = di[h]+coo[a.s].fst;
				int nj = dj[h]+coo[a.s].snd;
				if(ni >= 0 && nj >= 0 && ni < n && nj < m && str[ni][nj] != '#'){
					int x1i = coo[a.x1].fst;
					int x1j = coo[a.x1].snd;
					int x2i = coo[a.x2].fst;
					int x2j = coo[a.x2].snd;
					if(ni == x1i && nj == x1j){
						int xi = di[h]+x1i;
						int xj = dj[h]+x1j;
						if(xi >= 0 && xj >= 0 && xi < n && xj < m && str[xi][xj] != '#' && !(xi == x2i && xj == x2j) && mat[id[ni][nj]][id[xi][xj]][a.x2] == -1){
							mat[id[ni][nj]][id[xi][xj]][a.x2] = mat[a.s][a.x1][a.x2]+1;
							Q.push(Tri(id[ni][nj],id[xi][xj],a.x2));
						}
					}
					else if(ni == x2i && nj == x2j){
						int xi = di[h]+x2i;
						int xj = dj[h]+x2j;
						if(xi >= 0 && xj >= 0 && xi < n && xj < m && str[xi][xj] != '#' && !(xi == x1i && xj == x1j) && mat[id[ni][nj]][a.x1][id[xi][xj]] == -1){
							mat[id[ni][nj]][a.x1][id[xi][xj]] = mat[a.s][a.x1][a.x2]+1;
							Q.push(Tri(id[ni][nj],a.x1,id[xi][xj]));
						}
					}
					else{
						if(mat[id[ni][nj]][a.x1][a.x2] == -1){
							mat[id[ni][nj]][a.x1][a.x2] = mat[a.s][a.x1][a.x2]+1;
							Q.push(Tri(id[ni][nj],a.x1,a.x2));
						}
					}
				}
			}
	
		}		
		if(fl)
			cout<<"impossible"<<endl;
		
	}
	
	return 0;
}
