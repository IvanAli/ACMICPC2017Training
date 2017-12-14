#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define INF 1e9
using namespace std;

int d, r, t;

int main() {
	cin >> d >> r >> t;

	int b = 2*(d+1), c = d*(d+1)-2*(r+t+9);

	int i;
	int det = b*b-8*c;
	for(i = 0; i*i < det; ++i);

	int y = (-b+i)/4;
	int x = d+y;

	cout<<r-((x+1)*x/2-6)<<endl;



	return 0;
}
