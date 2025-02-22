#include<stdio.h>

int isLeapYear(int year){
    if((year%4==0 && year%100 !=0) ||(year%400==0))
    return 1;
    else
    return 0;
}

int getDaysInMonth(int month, int year){
    if(month== 4 || month==6 || month==9 || month==11)
    return 30;
    else if(month == 2)
    return isLeapYear(year)?29:28;
    else
    return 31;
}

int getTotalDays(int day, int month,int year){
    int totalDays=0;

    for(int y=1900;y<year;y++){
        if(isLeapYear(y))
           totalDays +=366;
        else 
           totalDays +=365;
    }

    for(int m=1; m<month ;m++)
    totalDays += getDaysInMonth(m,year);

    totalDays +=day;

    return totalDays;
}


void getDaysOfWeek(int day, int month, int year){
    int totalDays = getTotalDays(day,month,year);
    int dayIndex = (totalDays)%7;

    if (dayIndex == 1)
       printf("Monday");
    else if (dayIndex == 2)
       printf("Tuesday");
    else if (dayIndex == 3)
       printf("Wednesday");
    else if (dayIndex == 4)
       printf("Thursday");
    else if (dayIndex == 5)
       printf("Friday");
    else if (dayIndex == 6)
       printf("Saturday");
    else
       printf("Sunday");
    
}

int main(){
    int day,month,year;

    printf("Enter date in (DD MM YYYY) format : ");
    scanf("%d %d %d", &day, &month, &year);

    // if(year < 1900 || month <1 || month >12 || day <1 ||day>getDaysInMonth(month, year))
    // printf("Invalid date");

    getDaysOfWeek(day,month,year);

}