#include<stdio.h>

static char year_month_days[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
static char leap_month_days[]= {0,31,29,31,30,31,30,31,31,30,31,30,31};
static char *daytab[2]= {year_month_days, leap_month_days};

int day_of_year(int year, int month, int day){
    int leap= (year %4 ==0 && year %100 !=0) || year %400 == 0;
    if(month >12){
        printf("Invalid month: %d\n", month);
        return -1;
    }

    if (day> daytab [leap][month]){
        printf("month:%d\n", month, daytab[leap][month]);
        return -2;
    }
}


void month_day(int year, int yearday, int *pmonth, int *pday){
    int leap= (year %4 ==0 && year %100 != 0) || year%400 == 0;
    if ((!leap && yearday >365) || (leap && yearday >366)){
        *pmonth = 0;
        *pday =0;
        printf("ERROR year: %d\n", year, leap ? 366 : 365);
        return;
    }

    int i;
    for(i=0; yearday > daytab [leap][i]; i++){
        yearday -= daytab [leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int day= day_of_year(2021,2,12);
    printf("day of the year %d\n", day);

    int month_invalid= day_of_year(2021,13,1);
    if(month_invalid == -1){
        printf("warning\n");
    }
    int day_invalid= day_of_year(2021,12,32);
    if(day_invalid == -1){
        printf("warning\n");
    }

    int month,day_month;
    month_day(2021,43, &month, &day_month);
    printf("month: %d ,day: %d\n ", month, day_month);
}