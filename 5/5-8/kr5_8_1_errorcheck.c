#include <stdio.h>

static char daytab[2][13] = {
    	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);

int main()
{
    	int pmonth, pday;
    
	printf("- day_of_year -\n\n");
    
	printf("10.10.2013: %d\n", day_of_year(2013, 10, 10)); /*non leap*/
    	printf("10.10.2000: %d\n", day_of_year(2000, 10, 10)); /*leap*/
    	printf("40.10.2013: %d\n\n", day_of_year(2013, 10, 40)); /*error = -1*/
    
	printf("- month_year -\n\n");
    
	month_day(2001, 365, &pmonth, &pday);      /*non leap*/
    	printf("month: %d, date: %d\n", pmonth, pday);
   	month_day(2000, 366, &pmonth, &pday);    /*leap*/
    	printf("month: %d, date: %d\n", pmonth, pday);
    	month_day(2000, 367, &pmonth, &pday);    /*error = -1*/
    	printf("month: %d, date: %d\n", pmonth, pday);
    
	return 0;
}

int day_of_year(int year, int month, int day)
{
    	int i, leap;
    
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    	if(month < 1 || month > 12){
        	return -1;
    	}
    	if(day < 1 || day > daytab[leap][month]){
        	return -1;
    	}
    	for(i = 1; i < month; i++) {
        	day += daytab[leap][i];
    	}
    	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    	int i, leap;
    
    	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    	if(yearday < 1 || yearday > 366 || (leap == 0 && yearday > 365)) {
  		*pmonth = -1;
  		*pday = -1;
 		return;
     	}
    	for(i = 1; i <= 12 && yearday > daytab[leap][i]; i++){
 		yearday -= daytab[leap][i];
    	}
    	*pmonth = i;
    	*pday = yearday;
}
