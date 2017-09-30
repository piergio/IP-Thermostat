#include "ADateTime.h"

AFramework::ADateTime::ADateTime() : m_hours(0),
                                     m_minutes(0),
                                     m_seconds(0),
                                     m_dayOfMonth(0),
                                     m_month(NoMonth),
                                     m_year(0),
                                     m_weekday(NoWeekday){

}
            
AFramework::ADateTime::Weekdays AFramework::ADateTime::Weekday() const{
    
    return m_weekday;
}

AFramework::uint8 AFramework::ADateTime::dayOfMonth() const{

    return m_dayOfMonth;
}

AFramework::ADateTime::Months AFramework::ADateTime::month() const{

    return m_month;
}

AFramework::uint16 AFramework::ADateTime::year() const{
    return m_year;
}

AFramework::uint8 AFramework::ADateTime::hours() const{
    return m_hours;
}

AFramework::uint8 AFramework::ADateTime::minutes() const{
    return m_minutes;
}

AFramework::uint8 AFramework::ADateTime::seconds() const{
    return m_seconds;
}
            
bool AFramework::ADateTime::setWeekday(const Weekdays weekday){
    if((static_cast<int>(weekday) > 7)){
        return false;
    }
    m_weekday = weekday;
    return true;   
}

bool AFramework::ADateTime::setDayOfMonth(const uint8 dayOfMonth){
    
    bool   flg = false;
    uint8  tmp = 0;
    uint32 yrs = m_year + (System::currentCentury() * 100);
    
    switch(m_month){
        case January:
        case March:
        case May:
        case July:
        case August:
        case October:
        case December:
            tmp = 1;
            break;    
        case April:
        case June:
        case September:
        case November:
            tmp = 2;
            break;
        case February:
            tmp = 3;
            break;
        default:
            return false;
    }
    
    if(tmp == 1 && dayOfMonth < 32){
        flg = true;
    }
    if(tmp == 2 && dayOfMonth < 31){
        flg = true;
    }
    if((tmp == 3) && ((dayOfMonth == 29 && ((yrs % 4 == 0 && yrs % 100 != 0) || yrs % 400 == 0)) || (dayOfMonth < 29))){
        flg = true;
    }
    if(flg){
        m_dayOfMonth = dayOfMonth;
    }
    return flg;
}

bool AFramework::ADateTime::setMonth(const Months month){ 
    if(static_cast<int>(month) > 12){
        return false;
    }
    m_month = month;
    return true;
}

bool AFramework::ADateTime::setYear(const uint8 year){
    if(year > 99){    
        return false;
    }
    m_year = year;
    return true;
}

bool AFramework::ADateTime::setHours(const uint8 hours){
    if(hours > 23){    
        return false;
    }
    m_hours = hours;
    return true;
}

bool AFramework::ADateTime::setMinutes(const uint8 minutes){
    if(minutes > 59){    
        return false;
    }
    m_minutes = minutes;
    return true;
}

bool AFramework::ADateTime::setSeconds(const uint8 seconds){
    if(seconds > 59){    
        return false;
    }
    m_seconds = seconds;
    return true;
}
            
AFramework::AString AFramework::ADateTime::timeToString() const{

    char str[0x09] = {0};
    
    str[0x00] = ((m_hours / 10) == 0 ? '0' : (m_hours / 10 + 0x30));
    str[0x01] = ((m_hours % 10) == 0 ? '0' : (m_hours % 10 + 0x30));
    str[0x02] = ':';
    str[0x03] = ((m_minutes / 10) == 0 ? '0' : (m_minutes / 10 + 0x30));
    str[0x04] = ((m_minutes % 10) == 0 ? '0' : (m_minutes % 10 + 0x30));
    str[0x05] = ':'; 
    str[0x06] = ((m_seconds / 10) == 0 ? '0' : (m_seconds / 10 + 0x30));
    str[0x07] = ((m_seconds % 10) == 0 ? '0' : (m_seconds % 10 + 0x30));
    str[0x08] = 0x00;
    
    return AString(str);
}

AFramework::AString AFramework::ADateTime::dateToString() const{
    
    char str[0x09] = {0};
    
    str[0x00] = ((m_dayOfMonth / 10) == 0 ? '0' : (m_dayOfMonth / 10 + 0x30));
    str[0x01] = ((m_dayOfMonth % 10) == 0 ? '0' : (m_dayOfMonth % 10 + 0x30));
    str[0x02] = '/';
    str[0x03] = ((m_month / 10) == 0 ? '0' : (m_month / 10 + 0x30));
    str[0x04] = ((m_month % 10) == 0 ? '0' : (m_month % 10 + 0x30));
    str[0x05] = '/'; 
    str[0x06] = ((m_year / 10) == 0 ? '0' : (m_year / 10 + 0x30));
    str[0x07] = ((m_year % 10) == 0 ? '0' : (m_year % 10 + 0x30));
    str[0x08] = 0x00;
    
    return AString(str);

}

