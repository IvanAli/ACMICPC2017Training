#include <bits/stdc++.h>
#define snd second
#define fst first
#define pb push_back
#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
struct Punto{
	int x,y;
	bool fl; //0 begin //1 end
	int idx; //segment index
	Punto(){}
	Punto(const int &_x, const int &_y){
		x = _x;
		y = _y;
	}
	Punto(const int &_x, const int &_y, const bool &_fl, const int &_idx){
		x = _x;
		y = _y;
		fl = _fl;
		idx = _idx;
	}
};
bool operator < (const Punto &a, const Punto &b){
	if(a.x == b.x)
		return a.y<b.y;
	return a.x<b.x;
}
struct Seg{
	Punto p1,p2;
	Seg(){}
	Seg(const int &x1, const int &y1, const int &x2, const int &y2, const int &idx){
		p1 = Punto(x1,y1,0,idx);
		p2 = Punto(x2,y2,1,idx);
	}
};

int n,m;
Seg arr[100005];
vector <Punto> vec;
int g[100005];
pair<int,int> val[100005];
bool visit[100005];
int ballon[100005];
int x_ballon[100005];

void dfs(int num){
	if(g[num] == -1){
		val[num].fst = -1;
		val[num].snd = arr[num].p1.y;
		return;
	}
	if(g[num] == -2){
		val[num].fst = (arr[num].p1.y > arr[num].p2.y)? arr[num].p1.x:arr[num].p2.x;
		val[num].snd = -2;
		return;
	}
	
	if(!visit[g[num]]){
		visit[g[num]] = true;
		dfs(g[num]);
	}
	
	pair <int,int> &v = val[g[num]];
	
	if(v.fst == -1){
		val[num].fst = (arr[num].p1.y > arr[num].p2.y)? arr[num].p1.x:arr[num].p2.x;
		val[num].snd = v.snd;
	}
	else{
		val[num].fst = v.fst;
		val[num].snd = v.snd;
	}
}


long long cross(const Punto &a, const Punto &b, const Punto &c){
	long long dx1 = a.x-b.x, dy1 = a.y-b.y;
	long long dx2 = c.x-b.x, dy2 = c.y-b.y;
	return dx1*dy2-dx2*dy1;
}

bool comp(const Punto &a, const Punto &b){
	if(a.y == 0) return true;
	if(b.y == 0) return false;
	if(arr[a.idx].p1.x >= arr[b.idx].p1.x)
		return cross(arr[b.idx].p1,arr[a.idx].p1,arr[b.idx].p2)<0;
	return cross(arr[a.idx].p1,arr[b.idx].p1,arr[a.idx].p2)>0;
}

set <Punto, bool(*)(const Punto&,const Punto&)> st (comp);




int main() {
	cin>>n>>m;
	int x1,y1,x2,y2;
	for(int i = 1; i <= n; ++i){
		cin>>x1>>y1>>x2>>y2;
		if(x2 < x1){
			swap(x1,x2);
			swap(y1,y2);
		}
		arr[i] = Seg(x1,y1,x2,y2,i);
		vec.pb(arr[i].p1);
		vec.pb(arr[i].p2);
	}
	int x;
	for(int i = 1; i <= m; ++i){
		cin>>x_ballon[i];
		vec.pb(Punto(x_ballon[i],0,0,i));
	}
	sort(vec.begin(),vec.end());

	for(Punto v : vec){
	
		if(v.y == 0){
			auto it = st.insert(v);
			auto it2 = it.first;
			auto er = it2;
			++it2;
			if(it2 == st.end())
				ballon[v.idx] = -2;
			else
				ballon[v.idx] = (*it2).idx;
			st.erase(er);
			continue;
		}

		if(!v.fl){
			auto it = st.insert(v);
			auto it2 = it.first;
			if(v.y > arr[v.idx].p2.y){
				++it2;
				if(it2 == st.end())
					g[v.idx] = -2;
				else
					g[v.idx] = (*it2).idx;
			}
		}else{
			auto it = st.find(Punto(arr[v.idx].p1.x,arr[v.idx].p1.y,0,v.idx));
			auto er = it;

			if(v.y > arr[v.idx].p1.y){
				++it;
				if(it == st.end())	
					g[v.idx] = -2;
				else						
					g[v.idx] = (*it).idx;
			}
			else{	
				if(v.y == arr[v.idx].p1.y)	
					g[v.idx] = -1;
			}
			st.erase(er);
		}	

	}	
	
	for(int i = 1; i <= n; ++i){
		if(!visit[i]){
			visit[i] = true;
			dfs(i);
		}
	}
	for(int i = 1; i <= m; ++i){
		if(ballon[i] == -2){
			cout<<x_ballon[i]<<endl;
			continue;
		}
		if(val[ballon[i]].fst == -1)
			cout<<x_ballon[i]<<" "<<val[ballon[i]].snd<<endl;
		else{
			cout<<val[ballon[i]].fst;
			if(val[ballon[i]].snd != -2)
				cout<<" "<<val[ballon[i]].snd;
			cout<<endl; 
		}
	}
	
  return 0;
}
