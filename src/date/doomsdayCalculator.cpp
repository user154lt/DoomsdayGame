#include "date/doomsdayCalculator.h"

DoomsdayCalculator::DoomsdayCalculator(DateUtils &dateUtils) :
    dateUtils(dateUtils)
{

}


int DoomsdayCalculator::dayOfWeekFor(Date date){
    int anchorDay = anchorDayFor(date.year);
    int doomsday = doomsdayFor(date.month, dateUtils.isLeapYear(date.year));
    return dayOfWeekFor(doomsday, date.day, anchorDay);
}

int DoomsdayCalculator::anchorDayFor(int year){
    int centuryDay = centuryDayFromDigits(year / 100);
    int lastDigits = year % 100;
    int a = lastDigits / 12;
    int b = lastDigits % 12;
    int c = (lastDigits % 12) / 4;
    return centuryDay + ((a + b + c) % 7);
}

int DoomsdayCalculator::centuryDayFromDigits(int centuryDigits){
    return 5 * (centuryDigits % 4) % 7 + 2;
}

int DoomsdayCalculator::doomsdayFor(int month, bool isLeapYear){
    int result;
    if (month != 2 && month % 2 == 0){
        result = month;
    } else{
        switch (month){
            case 1:
                result = (isLeapYear) ? 4 : 3;
                break;
            case 2:
                result = (isLeapYear) ? 29 : 28;
                break;
            case 3:
                result = 14;
                break;
            case 5:
                result = 9;
                break;
            case 7:
                result = 11;
                break;
            case 9:
                result = 5;
                break;
            case 11:
                result = 7;
                break;
        }
    }
    return result;
}

int DoomsdayCalculator::dayOfWeekFor(int doomsday, int dayOfMonth, int anchorDay){
    int distance = distanceFromDoomsday(doomsday, dayOfMonth);
    int result = (doomsday > dayOfMonth) ? anchorDay - distance : anchorDay + distance;
    return rangeDayOfWeek(result);
}

int DoomsdayCalculator::distanceFromDoomsday(int doomsday, int dayOfMonth){
    int result = (doomsday > dayOfMonth) ? doomsday - dayOfMonth : dayOfMonth - doomsday;
    return result % 7;
}

int DoomsdayCalculator::rangeDayOfWeek(int dayOfWeek){
    int result = dayOfWeek;
    if(dayOfWeek < 0){
        result = 7 + dayOfWeek;
    } else if(dayOfWeek > 6){
        result = 0 + (dayOfWeek % 7);
    }
    return result;
}