#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;
int n;
char a[7],b[7],c[7];
int arr[20];


int main(){
  scanf("%d",&n);
  while(n--){
    scanf("%s%s",a,b);
    printf("Output for %s %s\n[\n",a,b);
    for(int i = 0; i < 4; ++i)arr[i] = 0;
    for(int j = 4; j < 8; ++j)arr[j] = 1;
    
    do{
      stack <int> Q;
      int idx = 0,res=0;
      memset(c,0,sizeof c);
      for(int i = 0; i < 8; ++i){
        if(!arr[i]){
          Q.push(a[idx++]);
        }
        else
        {
          if(!Q.empty()){
            c[res++] = Q.top();
            Q.pop();
          }
          else
            break;
        }
      }
      if(strcmp(b,c) == 0){
        if(!arr[0])printf("i");
        else  printf("o");
        for(int i = 1; i < 8; ++i){
          if(!arr[i]) printf(" i");
          else  printf(" o");
        }
        printf("\n");
      }
      
    }while(next_permutation(arr,arr+8));
    printf("]\n");
  
  }
  
  

  return 0;
}
