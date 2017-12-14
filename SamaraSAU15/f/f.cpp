#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main() {
	scanf("%d%d%d", &a, &b, &c);
	if (c <= b) printf("Take another envelope\n");
	else printf("Stay with this envelope\n");
	return 0;
}