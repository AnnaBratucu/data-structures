#include <stdio.h>
 
struct date
{
   int month;
   int day;
   int year;
}date;

int valid(date myDate){
	if(myDate.day>=1 && myDate.day<=31 && myDate.month>=1 && myDate.month<=12)
	printf("%s/n","valid");
	return 0;}
 
int tomorow()
{
int tomorrow;
struct date tom;

puts("Enter date");
    scanf("%d",&tom.month);
    scanf("%d",&tom.day);
    scanf("%d",&tom.year);
 
 
tomorrow=tom.day+1;
 
 
printf("Tomorrow's date is: %d/%d/%d \n",tom.month,tomorrow,tom.year % 100);
 
return 0;
}
int yesterday(){
	int yesterday;
	struct date yes;
puts("Enter date");
    scanf("%d",&yes.month);
    scanf("%d",&yes.day);
    scanf("%d",&yes.year);
     
yesterday=yes.day-1;
printf("Yesterday's date is: %d/%d/%d \n",yes.month,yesterday,yes.year % 100);
}
int leap(){
	int ok=0;
	truct date l;

puts("Enter date");
    scanf("%d",&l.month);
    scanf("%d",&l.day);
    scanf("%d",&l.year);
    
    if(l.year%400==0)
    ok=1;
    else ok=0;
    if(ok==1)
    printf("It is a leap year\n");
    else printf("It is not a leap year\n");
}
int main(void){
	date var1;
    date var2;
puts("Enter date in the format m/d/yy\n");
scanf("%d",&var1.month);
scanf("%d",&var1.day);
scanf("%d",&var1.year);
printf("You entered the following date: %d/%d/0%d\n",var1.month,var1.day,var1.year);
valid(var1.date);
var1.day=tomorrow(var1.day);
printf("Tomorrow's date is: %d/%d/0%d \n",var1.month,var1.day,var1.year);
var2.day=yesterday(var1.day);
printf("Yesterday's date is: %d/%d/0%d \n",var2.month,var2.day,var2.year);
leap(var1.data);
}
