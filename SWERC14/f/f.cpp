#include <bits/stdc++.h>
using namespace std;

struct Event{
	int x, yi, yf;
	bool type;
	Event(){}
	Event(const int &_x, const int &_yi, const int &_yf, const bool &_type)
	{
		x = _x;
		yi = _yi;
		yf = _yf;
		type = _type;
	}
};

struct Nodo{
	int x, yi, yf, i;
	Nodo(){}
	Nodo(const int &_x, const int &_yi, const int &_yf, const int &_i)
	{
		x = _x;
		yi = _yi;
		yf = _yf;
		i = _i;
	}
};

bool operator <(const Nodo &a, const Nodo &b)
{
	if(a.yi == b.yi)
		return a.x > b.x;
	return a.yi < b.yi;
}

bool operator <(const Event &a, const Event &b)
{
	if(a.x == b.x)
	{
		if(a.type == b.type)
			return a.yi < b.yi;
		return a.type < b.type;
	}
	return a.x < b.x;
}

int n;
Event arr[100005];
set <nodo> st;
int area[50005];
int idx = 0;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	
	int x,y,w,h;
	
	for(int i = 0; i < n; ++i)
	{
		cin>>x>>y>>w>>h;
		Event[i] = Event(x,y,y+h,0);
		Event[n+i] = Event(x+w,y,y+h,1);
	}

	sort(arr,arr+(n<<1));
	
	for(int i = 0; i < n; ++i)
	{
		if(Event[i].type == 0)
		{
			auto it = st.lower_bound(Nodo(Event[i].x,Event[i].yi,0,0));
			if(it != st.end())
			{
				if(Event[i].yf >= (*it).yi)
				{
					if(Event[i].yf == (*it).yi)
					{
						
					
					}
				
				
				}
			
			}
		
		}
	
	
	}	
	
		



	return 0;
}
