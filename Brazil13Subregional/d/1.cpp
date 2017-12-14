#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int n,m;
vector <int> inp;
vector <int> outp;
deque <int> OutQ;
deque <int> RevQ;

bool operator ==(deque <int> a, deque <int> b){
	if(a.size() != b.size())
		return false;
	for(int i = 0; i < int(a.size()); ++i){
		if(a[i] != b[i]) return false;
	}
	return true;
}

set < deque <int> > st;

//int cont = 0;
void dfs(deque <int> Q){
	auto it = st.find(Q);
	if(it != st.end())
		return;

	//++cont;
	
	//for(int v : Q)
		//cout<<v<<" ";cout<<endl;
	int sz = Q.size();
	if((Q == OutQ || Q == RevQ)){
		cout<<"S"<<endl;
		exit(0);
	}
	for(int i = 1; i < sz; ++i){
		deque <int> tmp;
		int idx = 1;
		for(int j = i; j < sz+i-1; ++j){
			if(j-idx >= 0)
				tmp.pf(Q[j]+Q[j-idx]);
			else
				if(j < sz)
					tmp.pf(Q[j]);
			idx += 2;
		}
		/*if(pos == 0){
		cout<<"T: ";
		for(int v : tmp)
		cout<<v<<" ";cout<<endl;
		}*/
		dfs(tmp);
	}
	st.insert(Q);
}


int main() {
	IO
	
	int sumI = 0;
	int sumO = 0;
	
	cin>>n;
	int num;
	
	for(int i = 0; i < n; ++i){
		cin>>num;
		inp.pb(num);
		sumI += num;
	}
	cin>>m;
	for(int i = 0; i < m; ++i){
		cin>>num;
		outp.pb(num);
		sumO += num;
	}
	
	if(sumI != sumO){
		cout<<"N"<<endl;
		return 0;
	}
	deque <int> Q;
	for(int i = 0; i < n; ++i){
		Q.pb(inp[i]);
	}
	
	for(int i = 0; i < m; ++i){
		OutQ.pb(outp[i]);
	}
	for(int i = m-1; i >= 0; --i){
		RevQ.pb(outp[i]);
	}
	dfs(Q);
//	cout<<cont<<endl;
	cout<<"N"<<endl;

  return 0;
}
