#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct Two{
	int num,pos;
	Two(){}
	Two(const int &_num, const int &_pos){
		num = _num;
		pos = _pos;
	}
};
bool operator <(const Two &a, const Two &b){
	if(a.num == b.num)
		return a.pos < b.pos;
	return a.num > b.num;
}

int n;
int arr[200005];

int idx = 0;
set< Two > st;

vector <int> res[200005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d",&arr[i]);
	}
	
	for(int i = 0; i < n; ++i){
	
		auto it = st.lower_bound(Two(arr[i],0));
		if(it == st.end()){
			++idx;
			res[idx].pb(arr[i]);
			st.insert(Two(arr[i],idx));
		}
		else{
			//cout<<"it "<<(*it).num<<" "<<(*it).pos<<endl;
			int pos = (*it).pos;
			st.erase(it);
			st.insert(Two(arr[i],pos));
			res[pos].pb(arr[i]);
		}
		
		/*for(auto it2 : st){
			cout<<it2.num<<" "<<it2.pos<<endl;
		}cout<<endl<<endl;*/
	}
	
	for(int i = 1; i <= idx; ++i){
		for(int v : res[i])
			printf("%d ",v);
		printf("\n");
	}
	

	return 0;
}
