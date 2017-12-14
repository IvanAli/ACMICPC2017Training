#include <bits/stdc++.h>

using namespace std;

int w,h;
int ax,ay,bx,by;


int main()
{

	fstream fin, fout;
	
	fin.open("anniversary.in",fstream::in);
	fout.open("anniversary.out",fstream::out);

	fin>>w>>h>>ax>>ay>>bx>>by;
	
	if(ax!=bx)
		fout<<ax<<" 0 "<<bx<<" "<<h<<endl; 
	else
		fout<<"0 "<<ay<<" "<<w<<" "<<by<<endl;
	
	fin.close(); fout.close();

	return 0;
}