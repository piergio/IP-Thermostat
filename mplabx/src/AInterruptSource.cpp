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

#include "AInterruptSource.h"

extern volatile AFramework::AINT_w INT_w __asm__("INT_w") __attribute__((section("sfrs")));

volatile AFramework::AINT_w * AFramework::AInterruptSource::m_int_reg(&INT_w);

AFramework::AInterruptSource::AInterruptSource(const uint8 IFSVec, const uint8 IECVec, const uint8  IPCVec, const uint32 IFSMask, const uint32 IECMask, const uint32 IPPos, const uint32 ISPos){
    m_ifsvec  = IFSVec;
    m_iecvec  = IECVec;
    m_ipcvec  = IPCVec;
    m_ifsmask = IFSMask;
    m_iecmask = IECMask;
    m_ippos   = IPPos;
    m_ispos   = ISPos;
}

bool AFramework::AInterruptSource::enableInterrupt(const Priority p, const SubPriority s){
    /*  cancello il flag di interrupt                                           */
    m_int_reg->IFS[m_ifsvec].CLR = m_ifsmask;
    /*  imposto le priorità dell'interrupt                                      */
    m_int_reg->IPC[m_ipcvec].SET = ((p << m_ippos) | (s << m_ispos));
    /*  abilito l'interrupt                                                     */
    m_int_reg->IEC[m_iecvec].SET = m_iecmask;
}

bool AFramework::AInterruptSource::disableInterrupt() volatile{
    m_int_reg->IEC[m_iecvec].CLR = m_iecmask;
}

bool AFramework::AInterruptSource::hasInterruptOccurred() volatile{
    return m_int_reg->IFS[m_ifsvec].isHi(m_ifsmask);
}

bool AFramework::AInterruptSource::clearFlag() volatile{
    m_int_reg->IFS[m_ifsvec].CLR = m_ifsmask;
}
