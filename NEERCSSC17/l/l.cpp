#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n;
int id[1005][1005];
vector < set<int> > arr[1005];
bool visit[1005];
int item[1005];
set <int> blank;
char str[100005];
char tmp[10];
vector < pair<int,int> > res;


int trans(){
	int idx = 0;
	int num = 0;
	while(tmp[idx] != '\0'){
		num *= 10;
		num += (tmp[idx]-'0');
		++idx;
	}
	return num;
}

int main(){

	scanf("%d", &n);
	
	queue <int> Q;
	
	for(int i = 1; i <= n; ++i){
	//cout<<i<<endl;
		scanf("%s",str);
		//cout<<str<<endl;
		int idx = 0; int lista = 0;
		
		while(str[idx] != '\0'){
			
			int c = 0;
			while(str[idx] != ':'){
				tmp[c] = str[idx];
				idx++;
				c++;
			}
			tmp[c] = '\0';
			idx++;
			
			arr[i].pb(blank);
			
			int cant = trans();
			if(cant == n-1){
				Q.push(i);
			//	cout<<i<<"f"<<endl;
				visit[i] = true;
			}
			for(int j = 0; j < cant; ++j){
				c = 0;
				while(str[idx] != '-' && str[idx] != ',' && str[idx] != '\0'){
					tmp[c] = str[idx];
					idx++;
					c++;
				}
				if(str[idx] != '\0')
					++idx;
				tmp[c] = '\0';
				int num = trans();
				//cout<<num<<endl;
				id[i][num] = lista;
				arr[i][lista].insert(num);
			}
			++lista;
		}
		item[i] = lista;
	}
	
	
	if(Q.empty()){
		cout<<"-1"<<endl;
		return 0;
		}
	cout<<n-1<<endl;
	int last = 0;
	while(!Q.empty()){
		int a = Q.front();
		Q.pop();
		last = a;
		
		for(int i = 1; i <= n; ++i){
			if(!visit[i]){
				int pos = id[i][a];
				auto it = arr[i][pos].find(a);
				if(it != arr[i][pos].end()){
					arr[i][pos].erase(a);
					if(arr[i][pos].size() == 0){
					res.pb({i,a});
												//printf("%d %d\n",i,a);
						item[i]--;
						if(item[i] <= 1){

							//visit[i] = true;
							Q.push(i);
						}
					}
				}
			}
		
		}
		
	}
	//cout<<last<<endl;
	for(pair<int,int> v: res){
		if(v.second != last){
			cout<<v.first<<" "<<v.second<<endl;
		
		}
	
	}

	return 0;
}
