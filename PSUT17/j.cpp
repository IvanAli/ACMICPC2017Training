#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

int n;
int arr[55];



int main()
{

	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	
	int sum = 0;

	for(int i = 0; i < n; ++i)
		sum += (arr[i]-1+i+1);
	
	if(sum % 7 == 0) printf("yes\n");
	else printf("no\n");

	return 0;
}
