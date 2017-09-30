/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               Università KORE Enna
*   @e-mail:    milazzo.ga@gmail.com
*               info@antipode-dev.org
*******************************************************************************
*   Software Licence:
*******************************************************************************
*
*   This file is part of AFramework.
*
*   AFramework is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   AFramework is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with AFramework. If not, see <http://www.gnu.org/licenses/>.
*
*   Copyright 2015, 2016 Milazzo Giuseppe
*
*/

#ifndef ATIME_H
#define ATIME_H

#include "ACommons.h"

namespace AFramework{
    
    class ATime{
        friend ATime operator+(const ATime & tm1, const ATime & tm2);
        friend ATime operator-(const ATime & tm1, const ATime & tm2);
        public:
            ATime();
            ATime(const uint32 dd, const uint8 hh, const uint8 mm, const uint8 ss, const uint16 ms, const bool neg = false);
            bool setTime(const uint32 dd, const uint8 hh, const uint8 mm, const uint8 ss, const uint16 ms, const bool neg = false);
            bool negative();
            bool posivite();
            bool isNegative();
            bool isPosivite();
            bool setDays(const uint32 dd);
            bool setHours(const uint8 hh);
            bool setMinutes(const uint8 mm);
            bool setSeconds(const uint8 ss);
            bool setMSeconds(const uint16 ms);
            sint32 days() const;
            sint8 hours() const;
            sint8 minutes() const;
            sint8 seconds() const;
            sint16 mseconds() const;
            void addDays(const uint32 dd);
            void addHours(const uint32 hh);
            void addMinutes(const uint32 mm);
            void addSeconds(const uint32 ss);
            void addMseconds(const uint32 ms);
            void subDays(const uint32 dd);
            void subHours(const uint32 hh);
            void subMinutes(const uint32 mm);
            void subSeconds(const uint32 ss);
            void subMseconds(const uint32 ms);
            
            bool operator<(const ATime & tm) const;
            bool operator<(const sint32 tm) const;
            
            bool operator>(const ATime & tm) const;
            bool operator>(const sint32 tm) const;
            
            ATime & operator=(const ATime & tm) ;
            ATime & operator=(const sint32 tm) ;
            
            bool operator<=(const ATime & tm) const;
            bool operator<=(const sint32 tm) const;
            
            bool operator>=(const ATime & tm) const;
            bool operator>=(const sint32 tm) const;
            
            ATime & operator+=(const ATime & tm);
            ATime & operator+=(const sint32 tm);
            
            ATime & operator-=(const ATime & tm);
            ATime & operator-=(const sint32 tm);
            
            ATime & operator++();
            ATime operator++(const int);
            
            ATime & operator--();
            ATime operator--(const int);
            
            bool operator==(const ATime & tm) const;
            bool operator==(const sint32 tm) const;
            
            bool operator!=(const ATime & tm) const;
            bool operator!=(const sint32 tm) const;
        private:
            void prvdd(const uint32 dd);
            void prvhh(const uint8  hh);
            void prvmm(const uint8  mm);
            void prvss(const uint8  ss);
            void prvms(const uint16 hh);
            sint64 m_raw;
    };
    ATime operator+(const ATime & tm1, const ATime & tm2);
    ATime operator-(const ATime & tm1, const ATime & tm2);
}

#endif // ATIME_H

