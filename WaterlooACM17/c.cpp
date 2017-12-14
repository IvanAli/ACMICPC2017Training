#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
//#define endl '\n'
using namespace std;
struct Nodo{
	int vL, vR, vU, vD;
	Nodo(){}
};

int n;
map <int,set < tuple<int,int,int> > >  mpx;
map <int,set < tuple<int,int,int> > >  mpy;
Nodo arr[100005];


int main()
{
	IO
	scanf("%d", &n);
	int x,y,v;
	int sum = 0;
	scanf("%d%d%d", &x, &y, &v);
	mpx[x].insert(make_tuple(y,v,0));
	mpy[y].insert(make_tuple(x,v,0));
	printf("0\n");
	for(int i = 1; i < n; ++i){
		scanf("%d%d%d", &x, &y, &v);
		auto mpit = mpx.find(x);
		if(mpit != mpx.end()){
			auto it = (*mpit).snd.lower_bound(make_tuple(y,0,0));
			if(it != (*mpit).snd.end()){
				arr[i].vU = get<1>(*it);
				int pos = get<2>(*it);
				sum -= max(arr[pos].vU,arr[pos].vD);
				arr[pos].vD = v;
				sum += max(arr[pos].vU,arr[pos].vD);	
			}
			if(it != (*mpit).snd.begin()){
				it--;
				if(it != (*mpit).snd.end()){
					arr[i].vD = get<1>(*it);
					int pos = get<2>(*it);
					sum -= max(arr[pos].vU,arr[pos].vD);
					arr[pos].vU = v;
					sum += max(arr[pos].vU,arr[pos].vD);
				}
			}
			sum += max(arr[i].vU,arr[i].vD);
			(*mpit).snd.insert(make_tuple(y,v,i));
		}
		else
			mpx[x].insert(make_tuple(y,v,i));
		
		mpit = mpy.find(y);
		if(mpit != mpy.end()){
			auto it = (*mpit).snd.lower_bound(make_tuple(x,0,0));
			if(it != (*mpit).snd.end()){
				arr[i].vR = get<1>(*it);
				int pos = get<2>(*it);
				sum -= max(arr[pos].vL,arr[pos].vR);
				arr[pos].vL = v;
				sum += max(arr[pos].vL,arr[pos].vR);	
			}
			if(it != (*mpit).snd.begin()){
				it--;
				if(it != (*mpit).snd.end()){
					arr[i].vL = get<1>(*it);
					int pos = get<2>(*it);
					sum -= max(arr[pos].vL,arr[pos].vR);
					arr[pos].vR = v;
					sum += max(arr[pos].vL,arr[pos].vR);
				}
			}
			sum += max(arr[i].vL,arr[i].vR);
			(*mpit).snd.insert(make_tuple(x,v,i));
		}
		else
			mpy[y].insert(make_tuple(x,v,i));
		printf("%d\n",sum);
	}
	return 0;
}
