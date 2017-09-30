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

#ifndef ALCD_H
#define	ALCD_H

#include "ACore.h"
#include "AString.h"

namespace AFramework{

    class ALcd{
        public:
            enum CursorMode{
                CursorShow,
                CursorHide,
                CursorBlink,
                CursorFixed,
            };
            
            enum Direction{
                Left,
                Right
            };
            
            ALcd(volatile AHardwarePort * portD4, const uint32 bitD4,
                 volatile AHardwarePort * portD5, const uint32 bitD5,
                 volatile AHardwarePort * portD6, const uint32 bitD6,
                 volatile AHardwarePort * portD7, const uint32 bitD7,
                 volatile AHardwarePort * portEN, const uint32 bitEN,
                 volatile AHardwarePort * portRS, const uint32 bitRS,
                 volatile AHardwarePort * portBL, const uint32 bitBL);

            void lightOn();
            void lightOff();
            void lightToggle();
            bool setCursorMode(const CursorMode mode);
            bool shiftScreen(const uint8 pos, const Direction dir);
            void clear();
            bool setLine(const uint8 line);
            bool shiftCursor(const uint8 pos, const Direction dir);
            bool gotoXY(const uint8 x, const uint8 y);
            void putchar(const char chr);
            void write(const char * str);
            
        private:
            void cmdwrt(unsigned char cmd, const LogicLevel rsVal, bool full = true);
            volatile AHardwarePort * m_port[0x07];
            uint32 m_bits[0x07];
            uint8  m_attr;
    };
    
    ALcd & operator<<(ALcd & lcd, const char * str);
    ALcd & operator<<(ALcd & lcd, const AString & str);
    ALcd & operator<<(ALcd & lcd, const uint8 num);
}

#endif	/* ALCD_H */

