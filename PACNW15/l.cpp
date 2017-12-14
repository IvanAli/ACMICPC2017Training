#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

int n;
long double W;

int main()
{
	cin>>n>>W;

	string pal;
	long double pi, vi;
	long double lastsafe = 0.;
	long double lastprize = 0.;
	long double acum = 1.;
	long double maxi = -1.;

	for(int i = 0; i < n; ++i)
	{
		cin>>pal>>pi>>vi;
		if(pal == "unsafe")
		{
			long double tmp;

			if(fabs(lastsafe-lastprize)>EPS)
				tmp = acum*(pi*log(1.+vi/W)+(1.-pi)*log(1.+lastsafe/W)+log(1.+lastprize/W));
			else
				tmp = acum*(pi*log(1.+vi/W)+(1.-pi)*log(1.+lastsafe/W));
			maxi = max(maxi,tmp);
			acum *= pi;
		}
		else
		{
			if(i == n-1)
			{
				long double tmp;
				if(fabs(lastsafe-lastprize)>EPS)
					tmp = acum*(pi*log(1.+vi/W)+(1.-pi)*log(1.+lastsafe/W)+log(1.+lastprize/W));
				else
					tmp = acum*(pi*log(1.+vi/W)+(1.-pi)*log(1.+lastsafe/W));
				maxi = max(maxi,tmp);
				acum *= pi;
			}

			lastsafe = vi;
			acum *= pi;
		}
		lastprize = vi;

	}

	long double res = (exp(maxi)-1.)*W;
	cout<<"$"<<fixed<<setprecision(2)<<res<<endl;





	return 0;
}
