#include<bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
//#define endl '\n'
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

long long dp[300][300];

long long dfs(int n, int maxnum){

	if(n < 0 || maxnum < 0)
		return 0;
			//cout<<n<<" "<<maxnum<<endl;
	long long &ans = dp[n][maxnum];
	
	if(ans != -1)
		return ans;
	if(n <= 1)
		return ans = 1;
	ans = 0;
	int tmp = min(n,maxnum);
	while(tmp > 0){
		ans += dfs(n-tmp,tmp);
		tmp--;
	}
	return ans;
}

int main(){
	IO
	int n;
	
	while(cin>>n && n){
		memset(dp,-1,sizeof dp);
		long long res = 0;

		int tmp = n;
		while(tmp > 0){
			//cout<<"tmp: "<<tmp<<endl;
			res += dfs((n-tmp)/2,tmp);
			if(n%2 == 0){
				res += dfs((n-tmp)/2,tmp/2);
			}
			tmp -= 2;
		}
		cout<<res<<endl;
	}
	

	return 0;
}
