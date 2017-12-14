#include <bits/stdc++.h>
using namespace std;

int n;
int arr[100005];
long long dp[100005];
long long dp2[100005];
long long num[100005];
long long num2[100005];

int main(){

	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &arr[i]);
	long long act = arr[1];
	num[1] = act;
	for(int i = 2; i <= n; ++i){
		dp[i] = dp[i-1];
		if(arr[i] <= act){
			dp[i] += (act-(long long)(arr[i]-1));
			++act;
		}
		else
			act = arr[i];
		num[i] = act;
	}
	
		/*for(int i = 1; i <= n; ++i){
			cout<<dp[i]<<" ";
		}cout<<endl;*/
	
	act = arr[n];
	num2[n] = act;
	for(int i = n-1; i >= 1; --i){
		dp2[i] = dp2[i+1];
		if(arr[i] <= act){
			dp2[i] += (act-(long long)(arr[i]-1));
			++act;
		}
		else
			act = arr[i];
		num2[i] = act;
	}
	
	/*for(int i = 1; i <= n; ++i){
			cout<<dp2[i]<<" ";
		}cout<<endl;*/
		
	/*for(int i = 1; i <= n; ++i){
			cout<<num[i]<<" ";
		}cout<<endl;
			for(int i = 1; i <= n; ++i){
			cout<<num2[i]<<" ";
		}cout<<endl;*/
	long long mini = LLONG_MAX;
	
	for(int i = 1; i <= n; ++i){
		mini = min(mini, dp[i]+dp2[i+1]+abs(num[i]-num2[i]));
		mini = min(mini, dp[i-1]+dp2[i]+abs(num[i]-num2[i]));		
	}	
	printf("%lld\n",mini);


	return 0;
}
