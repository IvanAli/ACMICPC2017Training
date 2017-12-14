#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define LL long long
using namespace std;

int n,k;
int arr[100005];
long long sum;
int maxi;
int main(){
  while(scanf("%d%d",&n,&k)!=EOF){
  //cout<<n<<" "<<k<<endl;
    sum = 0LL;
    maxi = -1;
    for(int i = 0; i < n; ++i){
      scanf("%d",&arr[i]);
      sum += (LL)(arr[i]);
       maxi = max(maxi,arr[i]);
      //cout<<arr[i]<<" ";
    }//cout<<endl;
    LL ini = (LL)(maxi), fin = sum, limit, sol = -1LL; 
    while(ini <= fin){
      limit = (ini+fin)>>1;
     // cout<<"limit: "<<limit<<endl;
      LL tmp = 0LL;
      int cnt = 1;
      for(int i = 0; i < n; ++i){
        if(tmp+(LL)(arr[i]) > limit){
          ++cnt;
          tmp = arr[i];
          if(cnt > k)
            break;
        }
        else
          tmp += (LL)(arr[i]);
      }
     // cout<<"cnt: "<<cnt<<endl;
      if(cnt <= k){
        sol = limit;
        fin = limit-1LL;
      }
      else
        ini = limit+1LL;
    }
     printf("%lld\n",sol);
  }
  

  
  

  return 0;
}
