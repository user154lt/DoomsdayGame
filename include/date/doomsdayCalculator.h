#ifndef DOOMSDAY_CALCULATOR_H
#define DOOMSDAY_CALCULATOR_H

#include "date/dateUtils.h"

/*
    Class that implements the doomsday algorithm, if time.h is used for finding out the 
    day of the week for an arbitary date then the date range is limited to around +/-78
    years from 1970 as time_t can only hold -2147483648 to 2147483647 secs range round
    the epoch.
*/
class DoomsdayCalculator{

    private:

        DateUtils &dateUtils;

        int anchorDayFor(int year);
        int centuryDayFromDigits(int centuryDigits);
        int doomsdayFor(int month, bool isLeapYear);
        int dayOfWeekFor(int anchorDay, int dayOfMonth, int doomsday);
        int distanceFromDoomsday(int anchorDay, int dayOfMonth);
        int rangeDayOfWeek(int dayOfWeek);

    public:
        DoomsdayCalculator(DateUtils &dateUtils);
        int dayOfWeekFor(Date date);
        
};

#endif