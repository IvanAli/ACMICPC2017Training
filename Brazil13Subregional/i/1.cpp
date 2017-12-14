#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n,c,t1,t2;
int arr[2005];
set < pair<int,int> > st;

int dp[2005];

int mod;

int dfs(int pos){
	int &ans = dp[pos];
	if(ans != -1)
		return ans;
	if((pos >= n) && (pos%n >= mod))
		return 0;
	ans = INT_MAX;
	auto it = st.upper_bound({arr[pos]+t1,2500});
	if(it != st.end())
		ans = min(ans,dfs((*it).second)+t1);
	it = st.upper_bound({arr[pos]+t2,2500});
	if(it != st.end())
		ans = min(ans,dfs((*it).second)+t2);
	if(ans == INT_MAX)
		ans = min(t1,t2);
	return ans;
}

int main() {

	IO
	cin>>n>>c>>t1>>t2;
	for(int i = 0; i < n; ++i){
		cin>>arr[i];
		arr[i+n] = c+arr[i];
		st.insert({arr[i],i});
		st.insert({arr[i+n],i+n});
	}

	int mini = INT_MAX;
	for(int i = 0; i < n; ++i){
		memset(dp,-1,sizeof dp);
		mod = i;
		mini = min(mini, dfs(i));
	}
	
	cout<<mini<<endl;

  return 0;
}
