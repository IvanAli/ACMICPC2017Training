#include<bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define fst first
#define snd second
#define pb push_back
using namespace std;

char str[105][105];
char tab[105][105];
int mark[105][105];
int target = 1;
int r,c;

int di[4] = {0,0,1,-1};
int dj[4] = {1,-1,0,0};

bool valido(const int &i, const int &j){
	return (i >= 0 && j >= 0 && i <= r && j <= c);
}

pair<int,int> iniA, iniB;

int main(){
	IO
	cin>>r>>c;
	
	for(int i = 0; i < r; ++i){
		cin>>str[i];
	}
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j){
			tab[i+1][j+1] = str[i][j];
			if(tab[i+1][j+1] == 'A')
				iniA = {i+1,j+1};
			if(tab[i+1][j+1] == 'B')
				iniB = {i+1,j+1};
		}
	queue < pair<int,int> > Q;
	
	for(int j = 0; j <= c+1; ++j){
		tab[0][j] = tab[r+1][j] = '#';
		Q.push({0,j});
		Q.push({r+1,j});
	}
	for(int i = 0; i <= r+1; ++i){
		tab[i][0] = tab[i][c+1] = '#';
		Q.push({i,0});
		Q.push({i,c+1});
	}
	++r; ++c;
	
	while(!Q.empty()){
		pair<int,int> a = Q.front();
		Q.pop();
		for(int h = 0; h < 4; ++h){
			int ni = di[h]+a.fst;
			int nj = dj[h]+a.snd;
			if(valido(ni,nj) && tab[ni][nj] == '.'){
				tab[ni][nj] = '#';
				Q.push({ni,nj});
			}
		}
	}	
	
	Q.push(iniA);
	while(!Q.empty()){
		pair<int,int> a = Q.front();
		Q.pop();
		int cont = 0;
		for(int h = 0; h < 4; ++h){
			int ni = di[h]+a.fst;
			int nj = dj[h]+a.snd;
			if(valido(ni,nj) && tab[ni][nj] == 'X'){
				++cont;
			}
		}
		if(cont <= 2){
			for(int h = 0; h < 4; ++h){
				int ni = di[h]+a.fst;
				int nj = dj[h]+a.snd;
				if(valido(ni,nj) && tab[ni][nj] == 'X'){
					tab[ni][nj] = 'A';
					Q.push({ni,nj});
				}
			}
		}
		else{
			tab[a.fst][a.snd] = '*';
			//cout<<a.fst<<" "<<a.snd<<endl;	
			for(int h = 0; h < 4; ++h){
				int ni = di[h]+a.fst;
				int nj = dj[h]+a.snd;
				if(valido(ni,nj) && tab[ni][nj] == 'A'){
					int nh = h;
					if(nh > 1){ 
						nh-=2;
						nh = (nh+1)%2;
						nh += 2;
					}
					else
						nh = (nh+1)%2;
					//cout<<nh<<endl;
					int nni = di[nh]+a.fst;
					int nnj = dj[nh]+a.snd;
					if(valido(nni,nnj) && tab[nni][nnj] == 'X'){
						tab[nni][nnj] = 'A';
						Q.push({nni,nnj});
					}
					break;
				}
			}
		}
	}
	
	Q.push(iniB);
	while(!Q.empty()){
		pair<int,int> a = Q.front();
		Q.pop();
		for(int h = 0; h < 4; ++h){
			int ni = di[h]+a.fst;
			int nj = dj[h]+a.snd;
			if(valido(ni,nj) && (tab[ni][nj] == 'X' || tab[ni][nj] == '*')){
				tab[ni][nj] = 'B';
				Q.push({ni,nj});
			}
		}
	}
	
	bool fl = true;
	for(int i = 0; i <= r && fl; ++i)
		for(int j = 0; j <= c && fl; ++j){
			if(tab[i][j] == '#'){
				for(int h = 0; h < 4 && fl; ++h){
					int ni = di[h]+i;
					int nj = dj[h]+j;
					if(valido(ni,nj) && tab[ni][nj] == 'A'){
						for(int nh = 0; nh < 4; ++nh){
							int nni = di[nh]+ni;
							int nnj = dj[nh]+nj;
							if(valido(nni,nnj) && tab[nni][nnj] == '.'){
								int cont = 0;
								
								Q.push({nni,nnj});
								++cont;
								tab[nni][nnj] = 'A';
								while(!Q.empty()){
									pair<int,int> a = Q.front();
									Q.pop();
									for(int nnh = 0; nnh < 4; ++nnh){
										int nnni = di[nnh]+a.fst;
										int nnnj = dj[nnh]+a.snd;
										if(valido(nnni,nnnj) && tab[nnni][nnnj] == '.'){
											tab[nnni][nnnj] = 'A';
											++cont;
											Q.push({nnni,nnnj});
										}
									}
								}
								cout<<cont<<" ";
								
								fl = false;
								break;
							}	
						}
					}
				}
			
			
			}
		
		}
		
	fl = true;
	for(int i = 0; i <= r && fl; ++i)
		for(int j = 0; j <= c && fl; ++j){
			if(tab[i][j] == '#'){
				for(int h = 0; h < 4 && fl; ++h){
					int ni = di[h]+i;
					int nj = dj[h]+j;
					if(valido(ni,nj) && tab[ni][nj] == 'B'){
						for(int nh = 0; nh < 4; ++nh){
							int nni = di[nh]+ni;
							int nnj = dj[nh]+nj;
							if(valido(nni,nnj) && tab[nni][nnj] == '.'){
								int cont = 0;
								
								Q.push({nni,nnj});
								++cont;
								tab[nni][nnj] = 'B';
								while(!Q.empty()){
									pair<int,int> a = Q.front();
									Q.pop();
									for(int nnh = 0; nnh < 4; ++nnh){
										int nnni = di[nnh]+a.fst;
										int nnnj = dj[nnh]+a.snd;
										if(valido(nnni,nnnj) && tab[nnni][nnnj] == '.'){
											tab[nnni][nnnj] = 'B';
											++cont;
											Q.push({nnni,nnnj});
										}
									}
								}
								cout<<cont<<" ";
								
								fl = false;
								break;
							}	
						}
					}
				}
			
			
			}
		
		}
	
	int cont = 0;
	for(int i = 0; i <= r; ++i){
		for(int j = 0; j <= c; ++j){
			if(tab[i][j] == '.')
				++cont;
		}
	}
	cout<<cont<<endl;
	
	/*for(int i = 0; i <= r; ++i,cout<<endl)
		for(int j = 0; j <= c; ++j){
			cout<<tab[i][j];
		}*/
	
	
	return 0;
}

