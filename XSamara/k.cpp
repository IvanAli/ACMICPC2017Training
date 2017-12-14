#include <bits/stdc++.h>
#define snd second
#define fst first
#define pb push_back

using namespace std;

struct Tri{
	int a,b,c;
	Tri(){}
	Tri(const int &_a, const int &_b, const int &_c)
	{
		a = _a;
		b = _b;
		c = _c;
	}
};


struct Event{
	int moment,idx;
	bool fl;
	Event(){}
	Event(const int &_moment, const int &_idx, const bool &_fl)
	{
		moment = _moment;
		idx = _idx;
		fl = _fl;
	}
};

bool operator < (Event &a, Event &b)
{
	if(a.moment == b.moment)
		return a.fl > b.fl;
	return a.moment < b.moment;
}

int n;
Tri arr[200005];

long long maxVal = 0;
int maxNode = 0;
long long timeTot = 0;

long long val[200005];
long long timeI[200005];

int parent[200005];
set < pair <int, pair<long long, long long>  > > st;

vector <Event> sweep;
vector <int> res;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n;	
	int a,b,c;
	for(int i = 1; i <= n; ++i)
	{
		cin>>a>>b>>c;
		arr[i] = Tri(a,b,c);
	}

	for(int i = 1; i <= n; ++i)
	{
		sweep.pb(Event(arr[i].a,i,false));
		sweep.pb(Event(arr[i].b,i,true));
	}

	sort(sweep.begin(),sweep.end());

	int len = sweep.size();
	Event curr;

	for(int k = 0; k < len; ++k)
	{
		curr = sweep[k];
		if(!curr.fl)
		{
			val[curr.idx] = (long long)(arr[curr.idx].c)+(long long)(maxVal);
			timeI[curr.idx] = (long long)(arr[curr.idx].b)-(long long)(arr[curr.idx].a)+timeTot;
			st.insert({curr.idx,{val[curr.idx],timeI[curr.idx]}});
			parent[curr.idx] = maxNode;
		}
		else
		{
			auto it = st.find({curr.idx,{val[curr.idx],timeI[curr.idx]}});
			st.erase(it);
			if(maxVal < val[curr.idx])
			{
				maxVal = val[curr.idx];
				timeTot = timeI[curr.idx];
				maxNode = curr.idx;
			}
			else
			{
				if(maxVal == val[curr.idx])
				{
					if(timeTot > timeI[curr.idx])
					{
						timeTot = timeI[curr.idx];
						maxNode = curr.idx;
					}
				}
			}
			
		}
	}

	
	int tmpNode = maxNode;
	while(tmpNode)
	{
		res.pb(tmpNode);
		tmpNode = parent[tmpNode];
	}
	cout<<res.size()<<" "<<maxVal<<" "<<timeTot<<endl;
	bool fl = true;
	int S = res.size();
	for(int i = S-1; i >= 0; --i)
		if(fl)
		{
			fl = false;
			cout<<res[i];
		}
		else
			cout<<" "<<res[i];
	cout<<endl;
	return 0;

}


