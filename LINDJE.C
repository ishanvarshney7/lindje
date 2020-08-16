#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
int main()
{
	int date,month,i,year,days_lived=0,day,y,m,age,pdate,pmonth,pyear;
	long int Date,pDate;
	char c='n',ch='n';
	struct date dt;
	clrscr();

	printf("\n\n                                      LINDJE\n\n\n"); /*"birth" in Albanian*/
	printf("HI...\nWelcome to Lindje\n");
	printf("This software will tell you the following informations about your date of birth.\n\n\n");                  //first page
	printf("1. First line will tell you your day of birth. \n");
	printf("2. Second line will tell you your current age. \n");
	printf("3. Third line will tell you the number of days from your birth. \n");
	printf("4. Fourth line will tell your zodiac sign.\n\n\n");
	 printf("Press ENTER to continue");
	 getch();
	 clrscr();

	getdate(&dt);
	pdate=dt.da_day;
	pmonth=dt.da_mon;
	pyear=dt.da_year;
	printf("\n\n\n");
 printf("Your system date is %d-%d-%d \n",pdate,pmonth,pyear);
 printf("Press 'n' if you want to change this date else press 'y' to continue ");
 scanf(" %c",&c);
   while(c=='n')
   {
	printf("\n Enter the new date(in dd/mm/yyyy format, like 04012002) : ");
	scanf("%ld/n",&pDate);
	pdate=pDate/1000000;
	pmonth=pDate/10000 -pdate*100;
	pyear=pDate-pmonth*10000-pdate*1000000;
	if(pdate>31||pmonth>12)
	{
	printf("Invalid Entery!!!");
	exit(0);
	}
	printf("Today is %d-%d-%d\n",pdate,pmonth,pyear);
	printf("Press 'y' if you want to continue else press 'n' to enter the date again ");
	scanf(" %c",&c);
    }
    printf("\n\n");
    while(ch=='n')
      {
	printf("Enter your Date Of Birth(in dd/mm/yyyy format, like 04012002) : ");
	scanf("%ld",&Date);
	date=Date/1000000;
	month=Date/10000 -date*100;
	year=Date-month*10000-date*1000000;
	if(date>31||month>12)
	{
	printf("Invalid Entery!!!");
	exit(0);
	}
	printf("Your enter date is %d-%d-%d\n",date,month,year);
	printf("Press 'y' if you want to continue else press 'n' to enter the date again ");
	scanf(" %c",&ch);
       }
 y = year-1900;
 y = y/4;
 y = y+year-1900;

 switch(month)
 {
 case 1:
 case 10:
 m = 1;
 break;
 case 2:
 case 3:
 case 11:
 m = 4;
 break;
 case 7:
 case 4:
 m = 0;
 break;
 case 5:
 m = 2;
 break;
 case 6:
 m = 5;
 break;
 case 8:
 m = 3;
 break;
 case 9:
 case 12:
 m = 6;
 break;
 }

 y = y + m;
 y = y + date;

 if(( year > 1900 ) && ( year % 4 == 0 ) && ( month < 2 ) )
 y--;
 day = y % 7;
 printf("\n\n\n\n");
 switch(day)
 {
 case 0:

 printf("Day you were born is SATURDAY.\n");
 break;
 case 1:
 printf("Day you were born is SUNDAY.\n");
 break;
 case 2:
 printf("Day you were born is MONDAY.\n");
 break;
 case 3:
 printf("Day you were born is TUESDAY.\n");
 break;
 case 4:
 printf("Day you were born is WEDNESDAY.\n");
 break;
 case 5:
 printf("Day you were born is THURSDAY.\n");
 break;
 case 6:
 printf("Day you were born is FRIDAY.\n");
 break;
 }

	age=pyear-year;
	if(pmonth<month)
	age--;                                //to find the age
	if(pmonth==month&&pdate<date)
	age--;

	for(i=year;i<pyear;i++)
	{
	  if(i%4==0)                   //to find the number of days lived(incomplete)
	  days_lived+=366;
	  else
	  days_lived+=365;
	}
	for(i=month;i<pmonth;i++)
	  {
	   if(i==1)
	   days_lived+=31;
	   if(i==2&&pyear%4==0)
	   days_lived+=29;
	   if(i==2&&pyear%4!=0)
	   days_lived+=28;
	   if(i==3)
	   days_lived+=31;
	   if(i==4)
	   days_lived+=30;
	   if(i==5)
	   days_lived+=31;
	   if(i==6)
	   days_lived+=30;
	   if(i==7)
	   days_lived+=31;
	   if(i==8)
	   days_lived+=31;
	   if(i==9)
	   days_lived+=30;
	   if(i==10)
	   days_lived+=31;
	   if(i==11)
	   days_lived+=30;
	   if(i==12)
	   days_lived+=31;
	  }
	  if(pyear%4==0&&month>2)
	  days_lived+=1;
	days_lived=(pdate-date)+days_lived;
	  if(pmonth<=month)
	    {
	      for(i=pmonth;i<month;i++)
		{
	   if(i==1)
	   days_lived-=31;
	   if(i==2&&pyear%4==0)
	   days_lived-=29;
	   if(i==2&&pyear%4!=0)
	   days_lived-=28;
	   if(i==3)
	   days_lived-=31;
	   if(i==4)
	   days_lived-=30;
	   if(i==5)
	   days_lived-=31;
	   if(i==6)
	   days_lived-=30;
	   if(i==7)
	   days_lived-=31;
	   if(i==8)
	   days_lived-=31;
	   if(i==9)
	   days_lived-=30;
	   if(i==10)
	   days_lived-=31;
	   if(i==11)
	   days_lived-=30;
	   if(i==12)
	   days_lived-=31;
		}
	    }
    printf("You are %d years old.\n",age);
    printf("You had lived %d days from your birth.\n",days_lived);

      if((month==12&&date>=22)||(month==1&&date<=20))
      printf("Your zodiac sign is CAPRICIORN.\n");
      if((month==1&&date>=21)||(month==2&&date<=18))
      printf("Your zodiac sign is AQUARIUS.\n");
      if((month==2&&date>=19)||(month==3&&date<=20))
      printf("Your zodiac sign is PISCES.\n");
      if((month==3&&date>=21)||(month==4&&date<=20))
      printf("Your zodiac sign is ARIES.\n");
      if((month==4&&date>=21)||(month==5&&date<=21))
      printf("Your zodiac sign is TAURUS.\n");
      if((month==5&&date>=22)||(month==6&&date<=21))
      printf("Your zodiac sign is GEMINI.\n");
      if((month==6&&date>=22)||(month==7&&date<=22))
      printf("Your zodiac sign is CANCER.\n");
      if((month==7&&date>=23)||(month==8&&date<=23))
      printf("Your zodiac sign is LEO.\n");
      if((month==8&&date>=24)||(month==9&&date<=22))
      printf("Your zodiac sign is VIRGO.\n");
      if((month==9&&date>=23)||(month==10&&date<=23))
      printf("Your zodiac sign is LIBRA.\n");
      if((month==10&&date>=24)||(month==11&&date<=22))
      printf("Your zodiac sign is SCORPIO.\n");
      if((month==11&&date>=23)||(month==12&&date<=21))
      printf("Your zodiac sign is SAGITTARIUS.\n");

      getch();
return 0;
}
