#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int a,b,p,e;
int arr[5005];
int indeg[5005];
int lista[5005];

vector <int> ady[5005];
queue < pair< int,int > > cola;



int main()
{
	ios_base::sync_with_stdio(); cin.tie(0);
	cin>>a>>b>>e>>p;

	int x,y;

	for(int i = 0; i < p; ++i)
	{
		cin>>x>>y;
		++indeg[y];
		ady[x].push_back(y);
	}

	for(int i = 0; i < e; ++i)
	{
		if(indeg[i] == 0)
			cola.push({i,0});
	}

	int  curr = 0;
	int idx = 0;
	pair <int , int > nodo;

	int cont = 0;

	while(!cola.empty())
	{
		if(cont >= b)
			break;
		nodo = cola.front();
		cola.pop();


		if(nodo.second == curr)
		{
			if(nodo.first == e)
				continue;
			lista[idx++] = nodo.first;
			bool fl = true;
			for(int tmp : ady[nodo.first])
			{
				--indeg[tmp];
				if(indeg[tmp] == 0)
				{
					cola.push({tmp,curr+1});
					fl = false;
				}
			}
			if(fl)	cola.push({e,curr+1});
		}
		else
		{
			if(cont < a)
			{
				if(cont+idx <= a)
				{
					cont += idx;
					for(int i = 0; i < idx; ++i)
						arr[lista[i]] = 1;
				}
				else
				{
					if(cont+idx <= b)
					{
						cont += idx;
						for(int i = 0; i < idx; ++i)
							arr[lista[i]] = 2;
					}
					else
					{
						for(int i = 0; i < idx; ++i)
							arr[lista[i]] = 3;
						break;
					}
				}
			}
			else
			{
					if(cont+idx <= b)
					{
						cont += idx;
						for(int i = 0; i < idx; ++i)
							arr[lista[i]] = 2;
					}
					else
					{
						for(int i = 0; i < idx; ++i)
							arr[lista[i]] = 3;
						break;
					}
			}
			if(nodo.first == e)
			{
				idx = 0;
				++curr;
				continue;
			}
			lista[0] = nodo.first;
			++curr;
			idx = 1;
			bool fl = true;
			for(int tmp : ady[nodo.first])
			{
				--indeg[tmp];
				if(indeg[tmp] == 0)
				{
					cola.push({tmp,curr+1});
					fl = false;
				}
			}
			if(fl) cola.push({e,curr+1});
		}
	}
	int c1= 0, c2 =0, c0=0;
	for(int i = 0; i < e; ++i)
	{
		//cout<<arr[i]<<" ";
		if(arr[i] == 1)
			c1++;
		if(arr[i] == 2)
			c2++;
		if(arr[i] == 0)
		    c0++;
	}//cout<<endl;

	cout<<c1<<endl<<c1+c2<<endl<<c0<<endl;




	return 0;
}
