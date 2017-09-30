#ifndef ADATETIME_H
#define	ADATETIME_H

#include "ACommons.h"
#include "AString.h"

namespace AFramework{

    class ADateTime{
        public:
            enum Weekdays{
                NoWeekday,
                Sunday,
                Monday,
                Tuesday,
                Wednesday,
                Thursday,
                Friday,
                Saturday
            };
            
            enum Months{
                NoMonth,
                January,
                February,
                March,
                April,
                May,
                June,
                July,
                August,
                September,
                October,
                November,
                December
            };
            
            ADateTime();
            
            Weekdays Weekday() const;
            uint8 dayOfMonth() const;
            Months month() const;
            uint16 year() const;
            uint8 hours() const;
            uint8 minutes() const;
            uint8 seconds() const;
            
            bool setWeekday(const Weekdays weekday);
            bool setDayOfMonth(const uint8 dayOfMonth);
            bool setMonth(const Months month);
            bool setYear(const uint8 year);
            bool setHours(const uint8 hours);
            bool setMinutes(const uint8 minutes);
            bool setSeconds(const uint8 seconds);
            
            AString timeToString() const;
            AString dateToString() const;
        private:
            uint8    m_hours;
            uint8    m_minutes;
            uint8    m_seconds;
            uint8    m_dayOfMonth;
            Months   m_month;
            uint8    m_year;
            Weekdays m_weekday;
    };
}

#endif	/* ADATETIME_H */

