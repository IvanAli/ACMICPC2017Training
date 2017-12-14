#include <bits/stdc++.h>
#define pb push_back
#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n;
int m;
int I;
int arr[505];
int ind[505];
int idx[505];
vector <int> ady[505];
set < pair<int,int> > st[505];


int main() {
	
	cin>>n>>m>>I;
	
	for(int i = 1 ; i <= n; ++i){
		cin>>arr[i];
		idx[i] = i;
	}
	int u,v;
	for(int i = 0; i < m; ++i){
		cin>>u>>v;
		ady[u].pb(v);
		ind[v]++;
	}
	
	queue <int> Q;
	for(int i = 1; i <= n; ++i)
		if(ind[i] == 0)
			Q.push(i);
			
	while(!Q.empty()){
		int a = Q.front();
		Q.pop();
		for(int v: ady[a]){
			ind[v]--;
			if(ind[v] == 0)
				Q.push(v);
			for(auto it = st[a].begin(); it != st[a].end(); ++it)
				st[v].insert(*it);
			st[v].insert({arr[a],a});
		}
	}
	

	string opt;
	int a,b;
	for(int i = 0; i < I; ++i){
		cin>>opt;
		if(opt[0] == 'P'){
			cin>>a;
			int len = st[idx[a]].size();
			auto it = st[idx[a]].begin();
			if(len)
				cout<<(*it).first<<endl;
			else
				cout<<"*"<<endl;
		}
		else{
			cin>>a>>b;
			for(int i = 1; i <= n; ++i){
				auto ita = st[i].find({arr[idx[a]],idx[a]});
				auto itb = st[i].find({arr[idx[b]],idx[b]});
				if(ita != st[i].end()){
					st[i].erase(ita);
					st[i].insert({arr[idx[b]],idx[a]});
				}
				if(itb != st[i].end()){
					st[i].erase(itb);
					st[i].insert({arr[idx[a]],idx[b]});
				}
			}
			swap(arr[idx[a]],arr[idx[b]]);
			swap(idx[a],idx[b]);
		}	
	}
	


  return 0;
}
