#ifndef DATE_UTILS_H
#define DATE_UTILS_H

#include <string>

// Custom date struct rather than time_t to support a wider range of dates
typedef struct Date {
    int day, month, year;
} Date;

/*
    Provides functions needed by the app relating to dates
*/
class DateUtils{
    private:
        // DoomsdayCalculator class will only work for gregorian dates
        static constexpr int MIN_YEAR = 1583;
        static constexpr int MAX_YEAR = 2200;

        int randomYear();
        int randomMonth();
        int randomDay(Date date);
        int maxDayFrom(int month, bool isLeapYear);

    public:
        Date randomDate();
        bool isLeapYear(int year);
        std::string nameFor(int day);

};

#endif