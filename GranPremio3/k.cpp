#include <bits/stdc++.h>
#define IO ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;
int n;
int target  = 1;
int mat[15][15];
int arr[15];

int main()
{
  //IO
  while(scanf("%d",&n) != EOF){
  
    if(n == 0){
      printf("0\n");
      continue;
    }
    int num,tmp;
    for(int i = 1; i <= n; ++i){
      scanf("%d",&num);
      for(int j = 0; j < num; ++j){
        scanf("%d",&tmp);
        mat[i][tmp] = target;
      }
    }
    
    for(int i = 0; i < n; ++i)
      arr[i] = i+1;
    int mini = n, cont,ant;
    do{
      
      cont = 1;
      ant = -1;
      
      
      for(int i = 0; i < n; ++i){
        for(int j = i-1; j > ant; --j){
          //cout<<"comt: "<<arr[i]<<" "<<arr[j]<<endl;
          if(mat[arr[i]][arr[j]] == target || mat[arr[j]][arr[i]] == target){
            ant = i-1;
            //cout<<"ant: "<<ant<<endl;
            ++cont;
            break;
          }
        }
      }
      mini = min(cont,mini);
     // if(cont == 2){
      //  for(int k = 0; k < n; ++k)
        //  cout<<arr[k]<<" ";cout<<endl;
      //}
    
    }while(next_permutation(arr,arr+n));
    
    printf("%d\n",mini);
    ++target;
  }


  return 0;
}
