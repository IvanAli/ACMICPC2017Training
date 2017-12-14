#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("boysgirls.in", "r", stdin);
	freopen("boysgirls.out", "w+", stdout);
	int n, a, b, x = 0, y = 0, z, p, counter = 0;
	scanf("%i %i %i", &n, &a, &b);
	if ((a != 0) && (b!=0)){
		do{
			z = 2*x - a;
			p = 2*n - 2*x - b;
			if ((p>=n-x)||(z>=x))
				counter = 1;
			else
				counter = 0;
			x++;
		}while(((p < 0) || (z < 0) || (p+z > n-2) || counter)&&(x<= n+1));
		x--;
		if (x == n+1){
			printf("Impossible"); return 0;
		}
		y = n - x;
		if (x >= y){
			for (p; p>=0;p--){
				printf("BG");
				x--;y--;
			}
			while (y > 0){printf("GB");y--;x--;}
			while (x > 0){printf("B");x--;}	
				
		}else{
			for (z; z >= 0; z--){
				printf("GB");
				x--;y--;
			}
			while (x > 0){printf("BG");x--;y--;}
			while (y > 0){printf("G");y--;} 
		}
	}else{
		if (b==0){
			if (a <=n){
				for (a;a;a--)
					printf("B");
			}	
			else
				printf("Impossible");
		}
		if (a==0){
			if (b <=n){
				for (b;b;b--)
					printf("G");
			}	
			else
				printf("Impossible");
		}		
	}
	return 0;
}