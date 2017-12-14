#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int n;
pair <int,int> arr[200005];
priority_queue < pair<int,int> > pq;


int main() {

		scanf("%d",&n);
		int ti,ci;
		for(int i = 0; i < n; ++i)
		{
			scanf("%d%d",&ti,&ci);
			arr[i] = {ti,ci};
		}
		sort(arr,arr+n);
		ti = arr[0].fst; //tiempo inicial
		int curr = ti; //timepo actual
		
		int idx = 0;
		bool fl = true;
		
		while(idx < n)
		{
			while(idx < n && arr[idx].fst == curr)
			{
				pq.push({arr[idx].snd+(ti-curr),idx});
				++idx;
			}
			pair <int,int> a = pq.top();
			pq.pop();
			if(fl)
			{
				cout<<a.snd+1;
				fl = false;
			}
			else
				cout<<" "<<a.snd+1;
			if(idx < n)
				curr = arr[idx].fst;
		}
		while(!pq.empty())
		{
			pair <int,int> a = pq.top();
			pq.pop();
			if(fl)
			{
				cout<<a.snd+1;
				fl = false;
			}
			else
				cout<<" "<<a.snd+1;
		
		}
		
		cout<<endl;				
		
		
		


	return 0;
}
