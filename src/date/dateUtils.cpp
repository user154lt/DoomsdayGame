#include "date/dateUtils.h"
#include "esp_random.h"

/*
    Random date functions use % operator to range the random numbers
    it's really not a great way to get random numbers but for the purposes
    of a game it will do
*/
Date DateUtils::randomDate(){
    Date result;
    result.year = randomYear();
    result.month = randomMonth();
    result.day = randomDay(result);
    return result;
}

int DateUtils::randomYear(){
    uint16_t random = esp_random();
    int totalYears = MAX_YEAR - MIN_YEAR;
    int result = (random % totalYears) + MIN_YEAR;
    return result;
}

int DateUtils::randomMonth(){
    uint16_t random = esp_random();
    int result = (random % 12) + 1;
    return result;
}

int DateUtils::randomDay(Date date){
    uint16_t random = esp_random();
    int maxDay = maxDayFrom(date.month, isLeapYear(date.year));
    int result = (random % maxDay) + 1;
    return result;
}

int DateUtils::maxDayFrom(int month, bool isLeapYear){
    int result;
    if(month == 2){
        result = (isLeapYear) ? 29 : 28;
    } else if(
        month == 1 || month == 3 || month == 5 || month == 7
        || month == 8 || month == 10 || month == 12
    ){
        result = 31;
    } else{
        result = 30;
    }
    return result;
}


bool DateUtils::isLeapYear(int year){
    return ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
}


std::string DateUtils::nameFor(int day){
    std::string result;
    switch(day){
        case 0:
            result = "Sun";
            break;
        case 1:
            result = "Mon";
            break;
        case 2:
            result = "Tue";
            break;
        case 3:
            result = "Wed";
            break;
        case 4:
            result = "Thu";
            break;
        case 5:
            result = "Fri";
            break;
        case 6:
            result = "Sat";
            break;
    }
    return result;
}