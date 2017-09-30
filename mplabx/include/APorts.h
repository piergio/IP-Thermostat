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

#ifndef APORTS_H
#define APORTS_H

#include "ACommons.h"
#include "ARegisterDefs.h"

namespace AFramework{
    
    class AHardwarePort{
        public:
            
            AHardwarePort(volatile APORT_w * w);
            
            uint32 adcStatus() const volatile;
            bool isAnalog(const uint32 gpio) const volatile;
            bool setDigital(const uint32 gpio) volatile;
            bool setAnalog(const uint32 gpio) volatile;
            
            uint32 ioStatus() const volatile;
            bool isInput(const uint32 gpio) const volatile;
            bool setInput(const uint32 gpio) volatile;
            bool setOutput(const uint32 gpio) volatile;
            
            uint32 read() const volatile;
            LogicLevel read(const uint32 gpio) const volatile;
            bool portWrite(const uint32 value) volatile;
            bool portWrite(const uint32 gpio, const LogicLevel value) volatile;
            bool portInvert(const uint32 gpio) volatile;
            
            uint32 latchRead() const volatile;
            LogicLevel latchRead(const uint32 gpio) const volatile;
            bool write(const uint32 value) volatile;
            bool write(const uint32 gpio, const LogicLevel value) volatile;
            bool latchInvert(const uint32 gpio) volatile;
            
            uint32 openDrainStatus() const volatile;
            bool isOpenDrain(const uint32 gpio) const volatile;
            bool setOpenDrain(const uint32 gpio) volatile;
            bool setStandard(const uint32 gpio) volatile;
            
            uint32 pullUpStatus() const volatile;
            bool isPullUpEnabled(const uint32 gpio) const volatile;
            bool enablePullUp(const uint32 gpio) volatile;
            bool disablePullUp(const uint32 gpio) volatile;
            
            uint32 pullDownStatus() const volatile;
            bool isPullDownEnabled(const uint32 gpio) const volatile;
            bool enablePullDown(const uint32 gpio) volatile;
            bool disablePullDown(const uint32 gpio) volatile;
            
            bool isInterrutptEnabled() const volatile;
            void enableInterrupt(const uint32 gpio, const Priority pri, const SubPriority sub = Isp0, const bool idleStop = false) volatile;
            void disableInterrupt() volatile;
            uint32 changeNoticeStatus() const volatile;
            bool hasInterruptOccurred(const uint32 gpio) const volatile;
            void resetInterruptFlag(const uint32 gpio = Quick::All) volatile;
        private:
            volatile APORT_w *  m_reg;
    };

#   if  (__HAS__PORTA__)
        extern volatile AHardwarePort PortA;
#   endif

#   if  (__HAS__PORTB__)
        extern volatile AHardwarePort PortB;
#   endif
    
#   if  (__HAS__PORTC__)
        extern volatile AHardwarePort PortC;
#   endif
    
#   if  (__HAS__PORTD__)
        extern volatile AHardwarePort PortD;
#   endif
    
#   if  (__HAS__PORTE__)
        extern volatile AHardwarePort PortE;
#   endif
    
#   if  (__HAS__PORTF__)
        extern volatile AHardwarePort PortF;
#   endif
    
#   if  (__HAS__PORTG__)
        extern volatile AHardwarePort PortG;
#   endif

#   if  (__HAS__PORTH__)
        extern volatile AHardwarePort PortH;
#   endif
    
#   if  (__HAS__PORTJ__)
        extern volatile AHardwarePort PortJ;
#   endif

#   if  (__HAS__PORTK__)
        extern volatile AHardwarePort PortK;
#   endif
    
}
#endif // APORTS_H
