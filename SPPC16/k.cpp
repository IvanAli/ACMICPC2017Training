#include <bits/stdc++.h>
#define snd second
#define fst first

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string w;
	cin>>w;
	int len = w.size();
	int a = 0, b = 0;
	for(int i = 0; i < len; ++i)
	{
		char L = tolower(w[i]);
		if(L == 'a'|| L == 'o')
			a += 2;
		if(L == 'n' || L == 'g')
			a++;
		if(L == 'i')
			b+=3;
		if(L == 'w' || L == 'b' || L == 'd')
			b++;
	}
	if(a > b)
	{
		cout<<"Kangaroos"<<endl;
		return 0;
	}
	if(b > a)
	{
		cout<<"Kiwis"<<endl;
		return 0;
	}
		cout<<"Feud continues"<<endl;

	return 0;

}


