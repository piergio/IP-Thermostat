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

#ifndef AINTERRUPTSOURCE_H
#define AINTERRUPTSOURCE_H

#include "ACommons.h"
#include "ARegisterDefs.h"

namespace AFramework{
    
    class AInterruptSource{
        public:
            AInterruptSource(const uint8 IFSVec, const uint8 IECVec, const uint8  IPCVec, const uint32 IFSMask, const uint32 IECMask, const uint32 IPPos, const uint32 ISPos);
            bool enableInterrupt(const Priority p, const SubPriority s = Isp0);
            bool disableInterrupt() volatile;
            bool hasInterruptOccurred() volatile;
            bool clearFlag() volatile;
        private:
            static volatile AINT_w * m_int_reg;
            uint8  m_ifsvec;
            uint8  m_iecvec;
            uint8  m_ipcvec;
            uint32 m_ifsmask;
            uint32 m_iecmask;
            uint32 m_ippos;
            uint32 m_ispos;
    };

}

#endif // AINTERRUPTSOURCE_H
