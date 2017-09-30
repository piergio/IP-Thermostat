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

#ifndef AIODEVICE_H
#define	AIODEVICE_H

#include "ACore.h"

namespace AFramework{

    class AIODevice{
        public:
            virtual bool open() volatile = 0;
            virtual bool close() volatile = 0;
            virtual bool isOpen() const volatile = 0;
            virtual uint32 read() const volatile = 0;
            virtual bool write(const uint32 & val) volatile = 0;
            virtual char getChar() const volatile = 0;
            virtual bool putChar(const char & chr) volatile = 0;
        protected:
            virtual uint32 devnum() const volatile = 0;
    };
}

#endif	/* AIODEVICE_H */
