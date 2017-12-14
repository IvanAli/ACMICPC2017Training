#include <bits/stdc++.h>

using namespace std;

int mes[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int prefix[15];

int transform(int d, int m, int y)
{
	return y*365+prefix[m-1]+d;
}


pair<int,int> arr[105];


int main()
{
	fstream fin,fout;
	
	fin.open("king.in",fstream::in);
	fout.open("king.out",fstream::out);


	prefix[0] = 0;
	for(int i = 1; i <= 12; ++i)
		prefix[i] = prefix[i-1]+mes[i];
		
	int king, kd,km,ky,n;
	
	fin>>kd>>km>>ky>>n;
	
	king = transform(kd,km,ky);
	
	//fout<<king<<endl;
	
	for(int i = 0; i < n; ++i)
	{
		fin>>kd>>km>>ky;
		arr[i] = {king-transform(kd,km,ky),i+1};
	}
	
	sort(arr,arr+n);
	bool fl = true;
	for(int i = 0; i < n; ++i)
	{
	//	fout<<arr[i].first<<" "<<arr[i].second<<endl;
	
		if(arr[i].first >= 6570)
		{
			fout<<arr[i].second<<endl;
			fl = false;
			break;
			
		}
	
	}
	if(fl)
		fout<<"-1"<<endl;
	
	

	fin.close();
	fout.close();


	return 0;
}