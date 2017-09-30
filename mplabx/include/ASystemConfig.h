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

#ifndef ASYSTEMCONFIG_H
#define ASYSTEMCONFIG_H

#define ANTIPODE32MR

#define __UART_BUFFER_SIZE__     0x00000400 

#if   defined (ANTIPODE32MR)
#   include "Ap32mx270f256d.h"
#elif defined (__32MX270F256B__)
#   define __PORTA_BITS__ 0x001F   //0000 0000 0001 1111
#   define __PORTB_BITS__ 0xEFBF   //1110 1111 1011 1111
#elif defined (__32MX270F256D__)
#   define __PORTA_BITS__ 0x079F   //0000 0111 1001 1111
#   define __PORTB_BITS__ 0xEFBF   //1110 1111 1011 1111
#   define __PORTC_BITS__ 0x03FF   //0000 0011 1111 1111
#endif

#endif // ASYSTEMCONFIG_H
