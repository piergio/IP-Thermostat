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

#include "APorts.h"

#   if  (__HAS__PORTA__)
        extern volatile AFramework::APORT_w PORTA_w __asm__("PORTA_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortA(&PORTA_w);
#   endif

#   if  (__HAS__PORTB__)
        extern volatile AFramework::APORT_w PORTB_w __asm__("PORTB_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortB(&PORTB_w);
#   endif
    
#   if  (__HAS__PORTC__)
        extern volatile AFramework::APORT_w PORTC_w __asm__("PORTC_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortC(&PORTC_w);
#   endif
    
#   if  (__HAS__PORTD__)
        extern volatile AFramework::APORT_w PORTD_w __asm__("PORTD_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortD(&PORTD_w);
#   endif
    
#   if  (__HAS__PORTE__)
        extern volatile AFramework::APORT_w PORTE_w __asm__("PORTE_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortE(&PORTE_w);
#   endif
    
#   if  (__HAS__PORTF__)
        extern volatile AFramework::APORT_w PORTF_w __asm__("PORTF_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortF(&PORTF_w);
#   endif
    
#   if  (__HAS__PORTG__)
        extern volatile AFramework::APORT_w PORTG_w __asm__("PORTG_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortG(&PORTG_w);
#   endif

#   if  (__HAS__PORTH__)
        extern volatile AFramework::APORT_w PORTH_w __asm__("PORTH_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortH(&PORTH_w);
#   endif
    
#   if  (__HAS__PORTJ__)
        extern volatile AFramework::APORT_w PORTJ_w __asm__("PORTJ_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortJ(&PORTJ_w);
#   endif

#   if  (__HAS__PORTK__)
        extern volatile AFramework::APORT_w PORTK_w __asm__("PORTK_w") __attribute__((section("sfrs")));
        volatile AFramework::AHardwarePort AFramework::PortK(&PORTK_w);
#   endif

AFramework::AHardwarePort::AHardwarePort(volatile APORT_w * w) : m_reg(w){
    /*  imposto tutto come digitale                                             */
    m_reg->ANSELx.SET   = Quick::All;
    /*  imposto tutto come ingresso                                             */
    m_reg->TRISx.SET   = Quick::All;
    /*  azzero il registro LATx                                                 */
    m_reg->LATx.CLR    = Quick::All;
    /*  setto tutto con l'open-drain disattivato                                */
    m_reg->ODCx.CLR    = Quick::All;
    /*  disabilito tutti i pull-up                                              */
    m_reg->CNPUx.CLR   = Quick::All;
    /*  disabilito tutti i pull-down                                            */
    m_reg->CNPDx.CLR   = Quick::All;
    /*  disabilito la periferica change-notice                                  */
    m_reg->CNCONx.CLR  = Quick::All;
    /*  azzero il registro dell'enable per la periferica change-notice          */
    m_reg->CNENx.CLR   = Quick::All;
    /*  azzero il registro dei flag per la periferica change-notice             */
    m_reg->CNSTATx.CLR = Quick::All;
}

AFramework::uint32 AFramework::AHardwarePort::adcStatus() const volatile{
    return m_reg->ANSELx.val();
}

bool AFramework::AHardwarePort::isAnalog(const uint32 gpio) const volatile{
    return m_reg->ANSELx.isHi(gpio);
}

bool AFramework::AHardwarePort::setDigital(const uint32 gpio) volatile{
    return m_reg->ANSELx.clr(gpio);
}

bool AFramework::AHardwarePort::setAnalog(const uint32 gpio) volatile{
    return m_reg->ANSELx.set(gpio);

}

AFramework::uint32 AFramework::AHardwarePort::ioStatus() const volatile{
    return m_reg->TRISx.val();
}

bool AFramework::AHardwarePort::isInput(const uint32 gpio) const volatile{
    return m_reg->TRISx.isHi(gpio);
}

bool AFramework::AHardwarePort::setInput(const uint32 gpio) volatile{
    return m_reg->TRISx.set(gpio);
}

bool AFramework::AHardwarePort::setOutput(const uint32 gpio) volatile{
    return m_reg->TRISx.clr(gpio);
}

AFramework::uint32 AFramework::AHardwarePort::read() const volatile{
    return m_reg->PORTx.REG;
}

AFramework::LogicLevel AFramework::AHardwarePort::read(const uint32 gpio) const volatile{
    return (m_reg->PORTx.REG & gpio ? Hi : Lo);
}

bool AFramework::AHardwarePort::portWrite(const uint32 value) volatile{
    m_reg->PORTx.CLR = Quick::All;
    return m_reg->PORTx.set(value);
}

bool AFramework::AHardwarePort::portWrite(const uint32 gpio, const LogicLevel value) volatile{
    if(value == Hi){
        return m_reg->PORTx.set(gpio);
    }else if(value == Lo){
        return m_reg->PORTx.clr(gpio);
    }
}

bool AFramework::AHardwarePort::portInvert(const uint32 gpio) volatile{
    return m_reg->PORTx.inv(gpio);
}

AFramework::uint32 AFramework::AHardwarePort::latchRead() const volatile{
    return m_reg->LATx.REG;
}

AFramework::LogicLevel AFramework::AHardwarePort::latchRead(const uint32 gpio) const volatile{
    return (m_reg->LATx.REG & gpio ? Hi : Lo);
}

bool AFramework::AHardwarePort::write(const uint32 value) volatile{
    m_reg->LATx.CLR = Quick::All;
    return m_reg->LATx.set(value);
}

bool AFramework::AHardwarePort::write(const uint32 gpio, const LogicLevel value) volatile{
    if(value == Hi){
        return m_reg->LATx.set(gpio);
    }else if(value == Lo){
        return m_reg->LATx.clr(gpio);
    }
}

bool AFramework::AHardwarePort::latchInvert(const uint32 gpio) volatile{
    return m_reg->LATx.inv(gpio);
}

AFramework::uint32 AFramework::AHardwarePort::openDrainStatus() const volatile{
    return m_reg->ODCx.REG;
}

bool AFramework::AHardwarePort::isOpenDrain(const uint32 gpio) const volatile{
    return m_reg->ODCx.isHi(gpio);
}

bool AFramework::AHardwarePort::setOpenDrain(const uint32 gpio) volatile{
    return m_reg->ODCx.set(gpio);
}

bool AFramework::AHardwarePort::setStandard(const uint32 gpio) volatile{
    return m_reg->ODCx.clr(gpio);
}

AFramework::uint32 AFramework::AHardwarePort::pullUpStatus() const volatile{
    return m_reg->CNPUx.REG;
}

bool AFramework::AHardwarePort::isPullUpEnabled(const uint32 gpio) const volatile{
    return m_reg->CNPUx.isHi(gpio);
}

bool AFramework::AHardwarePort::enablePullUp(const uint32 gpio) volatile{
    m_reg->CNPDx.CLR = gpio;
    return m_reg->CNPUx.set(gpio);
}

bool AFramework::AHardwarePort::disablePullUp(const uint32 gpio) volatile{
    return m_reg->CNPUx.clr(gpio);
}

AFramework::uint32 AFramework::AHardwarePort::pullDownStatus() const volatile{
    return m_reg->CNPDx.REG;
}

bool AFramework::AHardwarePort::isPullDownEnabled(const uint32 gpio) const volatile{
    return m_reg->CNPDx.isHi(gpio);
}

bool AFramework::AHardwarePort::enablePullDown(const uint32 gpio) volatile{
    m_reg->CNPUx.CLR = gpio;
    return m_reg->CNPDx.set(gpio);
}

bool AFramework::AHardwarePort::disablePullDown(const uint32 gpio) volatile{
    return m_reg->CNPDx.clr(gpio);
}

bool AFramework::AHardwarePort::isInterrutptEnabled() const volatile{
/*
    @todo: Change notice is not currently available
 */
}

void AFramework::AHardwarePort::enableInterrupt(const uint32 gpio, const Priority pri, const SubPriority sub, const bool idleStop) volatile{
/*
    @todo: Change notice is not currently available
 */
}

void AFramework::AHardwarePort::disableInterrupt() volatile{
/*
    @todo: Change notice is not currently available
 */
}

AFramework::uint32 AFramework::AHardwarePort::changeNoticeStatus() const volatile{
/*
    @todo: Change notice is not currently available
 */
}

bool AFramework::AHardwarePort::hasInterruptOccurred(const uint32 gpio) const volatile{
/*
    @todo: Change notice is not currently available
 */
}

void AFramework::AHardwarePort::resetInterruptFlag(const uint32 gpio) volatile{
/*
    @todo: Change notice is not currently available
 */
}
