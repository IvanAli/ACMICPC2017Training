#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
using namespace std;

char date[20];
char hour[20];
int maxD[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int mat[31][12][100];
int DL[31][12][100];

int main()
{
	int test;
	scanf("%d",&test);
	
	int day = 0, month = 0, year = 0, week = 0;
	int fl = 0;
	while(1)
	{
		int tmp = year+2007;
		if(tmp%4 == 0)
		{
			if(tmp%100 != 0)
				maxD[1] = 29;
			else
			{
				if(tmp%400 == 0)
					maxD[1] = 29;
				else
					maxD[1] = 28;
			}
		}
		else
			maxD[1] = 28;

		
		mat[day][month][year] = week;

		if(week == 6 && month == 2 && day-7 >= 0 && day-14 < 0)
		{
			DL[day][month][year] = 2;
			fl = 1;
		}
		else
		{
			if(week == 6 && month == 10 && day-7 < 0)
			{
				DL[day][month][year] = 3;
				fl = 0;
			}
			else
				DL[day][month][year] = fl;
		}

		week = (week+1)%7;

		day++;
		if(day == maxD[month])
		{
			day = 0;
			month++;
			if(month == 12)
			{
				month = 0;
				year++;
				if(year == 94)
					break;
			}
		}
	}

	int caso = 1;

	while(test--)
	{
		scanf("%s%s",date,hour);
		
		int anno = int(date[0]-'0')*1000+int(date[1]-'0')*100+int(date[2]-'0')*10+int(date[3]-'0');
		int mes = int(date[5]-'0')*10+int(date[6]-'0');
		int dia = int(date[8]-'0')*10+int(date[9]-'0');

		int hora = int(hour[0]-'0')*10+int(hour[1]-'0');
		int min = int(hour[3]-'0')*10+int(hour[4]-'0');
		int seg = int(hour[6]-'0')*10+int(hour[7]-'0');

		anno -= 2007;
		mes--;
		dia--;

		int state = DL[dia][mes][anno];
		
		if(state == 0)
			printf("Case #%d: PST\n",caso++);
		if(state == 1)	
			printf("Case #%d: PDT\n",caso++);
		if(state == 2)
		{
			if(hora == 2)					
				printf("Case #%d: Neither\n",caso++);
			if(hora < 2)
				printf("Case #%d: PST\n",caso++);
			if(hora > 2)
				printf("Case #%d: PDT\n",caso++);
		}
		if(state == 3)
		{	
			if(hora == 1)					
				printf("Case #%d: Both\n",caso++);
			if(hora < 1)
				printf("Case #%d: PDT\n",caso++);
			if(hora > 1)
				printf("Case #%d: PST\n",caso++);
		}

	}

	return 0;
}
