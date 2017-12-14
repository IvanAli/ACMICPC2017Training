#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <map>  
#include <stack>  
#include <iostream>  
#include <string>  
using namespace std;  
const int MAXN = 1e1 + 5;  
const int MAXM =1e3 + 5;  
typedef long long LL;  
int A[MAXN];  
int n;  
int B[MAXN];  
map<int,int>F;  
bool C() {  
 for(int i = 1; i <= 5; i ++) {  
     for(int j = 1; j < i; j ++) {  
         if(B[i] == B[j]) return false;  
         if(!F[B[i] + B[j]]) return false;  
     }  
 }  
 return true;  
}  
int main() {  
 int cas = 1;  
 while(~scanf("%d", &n)) {  
     while(n --) {  
         F.clear();  
         for(int j = 1; j <= 10; j ++) {  
             scanf("%d", &A[j]);  
             F[A[j]] = 1;  
         }  
         sort(A + 1, A + 10 + 1);  
         for(int i = 10; i > 0; i --) {  
             B[5] = (A[9] - A[2] + A[i]) / 2;  
             B[1] = B[5] - A[9] + A[2];  
             B[2] = A[1] - B[1];  
             B[3] = A[2] - B[1];  
             B[4] = A[10] - B[5];  
             if(C()) {  
                 break;  
             }  
         }  

         printf("Case %d: %d %d %d %d %d\n",cas ++,B[1], B[2], B[3], B[4], B[5]);  
     }  
 }  
 return 0;  
}  