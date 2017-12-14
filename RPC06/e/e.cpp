#include <bits/stdc++.h>
using namespace std;
int n;
int res[100005];
int target = 1;

int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d", &n);
		printf("0.");
		res[1] = target;
		int num = 10;
		
		bool fl = true;

		while(fl && num)
		{	
			int div = num/n;
			int mod = num%n;
			
			printf("%d",div);
			num = mod*10;
			
			if(res[mod] != target)
				res[mod] = target;
			else
				fl = false;
		}
		printf("\n");



		target++;
	}



	return 0;
}




