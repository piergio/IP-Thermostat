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
#ifndef ACOMMONS_H
#define ACOMMONS_H

#include "ASystemConfig.h"

#define __BIT_0__   0x0001
#define __BIT_1__   0x0002
#define __BIT_2__   0x0004
#define __BIT_3__   0x0008
#define __BIT_4__   0x0010
#define __BIT_5__   0x0020
#define __BIT_6__   0x0040
#define __BIT_7__   0x0080
#define __BIT_8__   0x0100
#define __BIT_9__   0x0200
#define __BIT_A__   0x0400
#define __BIT_B__   0x0800
#define __BIT_C__   0x1000
#define __BIT_D__   0x2000
#define __BIT_E__   0x4000
#define __BIT_F__   0x8000


namespace AFramework{
    
    typedef unsigned char                   uchar;
    typedef signed char                     schar;
    typedef unsigned char                   uint8;
    typedef signed char                     sint8;
    typedef unsigned short int              uint16;
    typedef signed short int                sint16;
    typedef unsigned int                    uint32;
    typedef signed int                      sint32;
    typedef unsigned long long              uint64;
    typedef signed long long                sint64;
    
    namespace Quick{
        const volatile uint32 All   = 0xFFFFFFFF;
        const volatile uint32 NoOne = 0x00000000;
    }
    
    enum LogicLevel{
        Lo,
        Hi,
        Unknown
    };
    
    enum Priority{
        Ip1 = 1,
        Ip2,
        Ip3,
        Ip4,
        Ip5,
        Ip6,
        Ip7
    };
    
    enum SubPriority{
        Isp0,
        Isp1,
        Isp2,
        Isp3,
    };
    
    const uint32 bit0  = 0x0001;
    const uint32 bit1  = 0x0002;
    const uint32 bit2  = 0x0004;
    const uint32 bit3  = 0x0008;
    const uint32 bit4  = 0x0010;
    const uint32 bit5  = 0x0020;
    const uint32 bit6  = 0x0040;
    const uint32 bit7  = 0x0080;
    const uint32 bit8  = 0x0100;
    const uint32 bit9  = 0x0200;
    const uint32 bit10 = 0x0400;
    const uint32 bit11 = 0x0800;
    const uint32 bit12 = 0x1000;
    const uint32 bit13 = 0x2000;
    const uint32 bit14 = 0x4000;
    const uint32 bit15 = 0x8000;
    
}
#endif // ACOMMONS_H
