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

#ifndef ATIMERS_H
#define	ATIMERS_H

#include "ACore.h"
#include "AInterruptSource.h"

namespace AFramework{
    
    class AAbstract16bitTimer{
        public:
            AAbstract16bitTimer(volatile ATMR_w * w);
            void rawConfig(const volatile uint32 b) volatile;
            double setSynchronousInternal16(const volatile double period, const volatile bool idleStop = false) volatile;
            double setSynchronousExternal16(const volatile double extFreq, const volatile double period, const volatile bool idleStop = false) volatile;
            double setGated16(const volatile double period, const volatile bool idleStop = false) volatile;
            bool open() volatile;
            void close() volatile;
            void clear() volatile;
            void reset() volatile;
            bool isOpen() const volatile;
            uint32 rawTime() const volatile;
            double elapsedTime() const volatile;
            double error() const volatile;
            double resolution() const volatile;
            bool enableInterrupt(const Priority pr, const SubPriority sp) volatile;
            bool disableInterrupt() volatile;
            bool hasInterruptOccurred() volatile;
            bool clearFlag() volatile;
            
        protected:
            virtual double setpar(const volatile double t, const volatile double f, const volatile bool w = false) volatile = 0;
            volatile ATMR_w * m_reg;
            volatile double   m_res;
            volatile double   m_err;
    };
    
    class A16bitMasterTimer : public AAbstract16bitTimer{
        public:
            A16bitMasterTimer(volatile ATMR_w * w);
            double setAsynchronousExternal16(const volatile double period, const volatile bool idleStop = false) volatile;
        private:
            double setpar(const volatile double t, const volatile double f, const volatile bool w = false) volatile;
    };
    
    class A16bitSlaveTimer : public AAbstract16bitTimer{
        public:
            A16bitSlaveTimer(volatile ATMR_w * w);
            bool isBusy() const volatile;
        protected:
            double setpar(const volatile double t, const volatile double f, const volatile bool w = false) volatile;
            volatile bool m_flg;
    };
    
    class A32bitMasterTimer : public A16bitSlaveTimer{
        public:
            A32bitMasterTimer(volatile ATMR_w * w, volatile A16bitSlaveTimer * slave);
            double setSynchronousInternal32(const volatile double period, const volatile bool idleStop = false) volatile;
            double setSynchronousExternal32(const volatile double extFreq, const volatile double period, const volatile bool idleStop = false) volatile;
            double setGated32(const volatile double period, const volatile bool idleStop = false) volatile;
        private:
            volatile A16bitSlaveTimer * m_slave;
    };
    
#if (__HAS_TIMER1__)    
    extern volatile A16bitMasterTimer Timer1;
#endif
#if (__HAS_TIMER2__)
    extern volatile A32bitMasterTimer Timer2;
#endif
#if (__HAS_TIMER3__)
    extern volatile A16bitSlaveTimer  Timer3;
#endif
#if (__HAS_TIMER4__)
    extern volatile A32bitMasterTimer Timer4;
#endif
#if (__HAS_TIMER5__)
    extern volatile A16bitSlaveTimer  Timer5;
#endif
}
#endif	/* ATIMERS_H */

