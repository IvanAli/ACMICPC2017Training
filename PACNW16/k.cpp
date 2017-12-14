#include <bits/stdc++.h>
using namespace std;

int a[6];
int b[6];

int main() {
	int coincidencia_mayor=0, coincidencia_igual=0;
	for (int i = 0; i < 6; i++) cin >> a[i];
	for (int i = 0; i < 6; i++) cin >> b[i];
	for(int i =0; i<6; i++){
		for(int j=0; j<6; j++){
			if(a[i]>b[j]){
				coincidencia_mayor++;
			}
			else if(a[i]==b[j]){
				coincidencia_igual++;
			}
		}
	}
	if(coincidencia_igual>0){
		printf("%.5f", (float)coincidencia_mayor/(36-coincidencia_igual));
	}
	else{
		printf("%.5f", (float)coincidencia_mayor/36);
	}
	return 0;
}