#include <bits/stdc++.h>
#define PI 3.14159265359
using namespace std;

int main(){
    int t, n;
    cin>>t;
    for (int i=0; i<t; i++){
        cin>>n;
        int sides[n];
        int sum=0, flag=0;
        double sum2=0;
        int maximside=0;
        for(int j=0; j<n; j++){
            cin>>sides[j];
            sum=sum+sides[j];
            if(sides[j]>maximside){
                maximside=sides[j];
            }
        }
        for(int j=0; j<n; j++){
            if(sum-sides[j]<=sides[j]){
                flag=1;
            }
        }
        sum2=0;
        double high=sum, low=(double)maximside/2, mid, count10=0, aux;
        if(flag==0){
            while(high>low){
                mid=(high+low)/2;
                for(int j=0; j<n; j++){
                    sum2=sum2+2*asin((double)sides[j]/(2*mid));
                }
                if(sum2>=2*M_PI-0.00001){
                    low=mid;
                }
                else{
                    high=mid-0.00001;
                }
                sum2=0;
            }
            aux=mid;
            while(aux>1){
                count10++;
                aux=aux/10;
            }
            cout<<"Case "<<i+1<<": "<<setprecision(4+count10)<<mid<<endl;
        }
        else{
            cout<<"Case "<<i+1<<": "<<"can't form a convex polygon"<<endl;
        }
    }
    return 0;
}
