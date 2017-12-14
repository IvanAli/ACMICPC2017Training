#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, n, maxx=-1001, maxy=-1001, minx=10001, miny=100001;
	cin>>t;
	for(int j=0; j<t; j++){
		maxx=-1001;
		maxy=-1001;
		minx=1001;
		miny=1001;
		cin>>n;
		int vertice [2][4*n];
		for(int i=0; i<4*n; i++){
			cin>>vertice[0][i];
			cin>>vertice[1][i];
		}
		for(int i=0; i<4*n; i++){
			if(vertice[0][i]>maxx){
				maxx=vertice[0][i];
			}
			if(vertice[0][i]<minx){
				minx=vertice[0][i];
			}
			if(vertice[1][i]>maxy){
				maxy=vertice[1][i];
			}
			if(vertice[1][i]<miny){
				miny=vertice[1][i];
			}
		}
		cout<<(maxx-minx)*(maxy-miny)<<endl;
	}
	return 0;
}