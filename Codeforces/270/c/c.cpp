#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

bool cmp(const string &a, const string &b){
//cout<<a<<", "<<b<<endl;
	int len = min(a.size(),b.size());
	for(int i = 0; i < len; ++i){
		if(a[i] > b[i])
			return false;
		if(a[i] < b[i])
			return true;
	}
	return (a.size() <= b.size());
}

int n;
string arr[100005][2];
string handle = "";

int main()
{
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>arr[i][0]>>arr[i][1];
		if(cmp(arr[i][1],arr[i][0])){
			swap(arr[i][0],arr[i][1]);
			}
	}
	
	int num;
	for(int i = 0; i < n; ++i){
		cin>>num; num--;
		if(cmp(handle,arr[num][0])){
			handle = arr[num][0];
		}
		else{
			if(cmp(handle,arr[num][1]))
				handle = arr[num][1];
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;

	return 0;
}
