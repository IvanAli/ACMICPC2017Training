#include <bits/stdc++.h>
using namespace std;

int arr[10] = {14,1,5,3,11,9,7,15,13,6};

int mark[20];



int n;
string tipo;

char sop[3][500];

string otra[3];


int num[105];

int main()
{
	
	mark[14] = 0;
	mark[1]  = 1;
	mark[5]  = 2;
	mark[3]  = 3;
	mark[11]  = 4;
	mark[9]  = 5;
	mark[7]  = 6;
	mark[15]  = 7;
	mark[13]  = 8;
	mark[6]  = 9;
	
	
	while(cin>>n && n!=0)
	{
	
		//cout<<n<<endl;
	
		memset(num,0,sizeof num);
	
		cin>>tipo;
		
		if(tipo[0] == 'S')
		{
			string tmp;
			cin>>tmp;
			
			//cout<<"temp: "<<tmp<<endl;
			
			for(int i = 0; i < n; ++i)
				num[i] = (int)(tmp[i]-'0');
				
			//for(int i = 0; i < n; ++i)
			//	cout<<num[i]<<" "; cout<<endl;
			
				
			for(int i = 0; i < n; ++i)
			{
				int col = i*3;
				int key = arr[num[i]];
				
				//cout<<"key: "<<key<<endl;
				
				for(int j = 0; j < 3; ++j)
				{
					if(key&1)
						sop[j][col] = '*';
					else
						sop[j][col] = '.';
					
					key >>= 1;
					
					if(key&1)
						sop[j][col+1] = '*';
					else
						sop[j][col+1] = '.';
						
					key >>= 1;
					
					if(i != n-1)
						sop[j][col+2] = ' ';
					else
						sop[j][col+2] = 0;
				
				}
				
			}
			
			//cout<<"Respuesta: "<<endl;	
			
			for(int i = 0; i < 3; ++i)
				cout<<sop[i]<<endl;	
		
		
		
		}
		else
		{
			getline(cin,otra[0]);
		
			for(int i = 0; i < 3; ++i)
				getline(cin,otra[i]);
				
			//cout<<"Entrada: "<<endl;
			//for(int i = 0; i < 3; ++i)
			//	cout<<otra[i]<<endl;
			
				
			for(int i = 0; i < n; ++i)
			{
				int col = i*3;
				
				for(int j = 2; j >= 0; --j)
				{
					num[i] *= 2;
					
					if(otra[j][col+1] == '*')
						++num[i];
					
					num[i] *= 2;
					
					if(otra[j][col] == '*')
						++num[i];
				}
				
				
				
				//cout<<"num: "<<num[i]<<endl;
				
				char t = (char) mark[num[i]]+'0';
				cout<<t;
			}
			
			cout<<endl;
			
			
		
		}
		
				
	
	}



	


	return 0;
}