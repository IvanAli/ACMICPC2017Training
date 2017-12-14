#include <bits/stdc++.h>
using namespace std;

long long arr[300005];
long long n,k;

int main(){

	cin>>n>>k;
	for(int i = 1; i <= n+1; ++i){
		arr[i] = arr[i-1]+(long long)(i);
	}
	
	if(k > arr[n-1]){
		printf("Impossible\n");
		return 0;
	}
	
	long long tot = n;
	for(int i = 0; i <= n; ++i){
		if(arr[i+1] > k){
			long long diff = arr[i+1]-k;
			for(int j = 0; j < i+1; ++j)
				printf("(");
			printf(")");
			for(int j = 1; j < i+1; ++j){
				if(j == diff){
					printf("()");
				}
				printf(")");
			}
			long long rest = n-(i+1)-(k>arr[i]);
			for(int j = 0; j < rest; ++j)
				printf("()");
			printf("\n");
			break;
		}
	}
	

	return 0;
}
