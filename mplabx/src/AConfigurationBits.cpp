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
#include "ASystemConfig.h"

#ifdef ANTIPODE32MR

    #pragma config PMDL1WAY     = OFF       //Peripheral Module Disable Configuration (Allow multiple reconfigurations)
    #pragma config IOL1WAY      = OFF       //Peripheral Pin Select Configuration (Allow multiple reconfigurations)
    #pragma config FUSBIDIO     = OFF        //USB USID Selection (Controlled by the USB Module)
    #pragma config FVBUSONIO    = OFF        //USB VBUS ON Selection (Controlled by USB Module)
    #pragma config FPLLIDIV     = DIV_6     //PLL Input Divider (6x Divider) 24MHz / 6 = 4MHz
//->    #pragma config FPLLIDIV     = DIV_2     //PLL Input Divider (6x Divider) 24MHz / 6 = 4MHz
    #pragma config FPLLMUL      = MUL_20    //PLL Multiplier (20x Multiplier) 4MHz * 20 = 80MHz
    #pragma config UPLLIDIV     = DIV_6     //USB PLL Input Divider (6x Divider) 24MHz / 6 = 4MHz
//->    #pragma config UPLLIDIV     = DIV_2     //USB PLL Input Divider (6x Divider) 24MHz / 6 = 4MHz
    #pragma config UPLLEN       = OFF        //USB PLL Enable (Enabled)
    #pragma config FPLLODIV     = DIV_2     //System PLL Output Clock Divider (PLL Divide by 2) 80MHz / 2 = 40MHz
    #pragma config FNOSC        = PRIPLL    //Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
//->    #pragma config FNOSC        = FRCPLL    //Oscillator Selection Bits (Primary Osc w/PLL (XT+,HS+,EC+PLL))
    #pragma config FSOSCEN      = OFF       //Secondary Oscillator Enable (Disabled)
    #pragma config IESO         = ON        //Internal/External Switch Over (Enabled)
    #pragma config POSCMOD      = HS        //Primary Oscillator Configuration (HS osc mode)
//->    #pragma config POSCMOD      = OFF        //Primary Oscillator Configuration (HS osc mode)
    #pragma config OSCIOFNC     = OFF       //CLKO Output Signal Active on the OSCO Pin (Disabled)
    #pragma config FPBDIV       = DIV_1     //Peripheral Clock Divisor (Pb_Clk is Sys_Clk/1)
    #pragma config FCKSM        = CSDCMD    //Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
    #pragma config WDTPS        = PS1048576 //Watchdog Timer Postscaler (1:1048576)
    #pragma config WINDIS       = OFF       //Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
    #pragma config FWDTEN       = OFF       //Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
    #pragma config FWDTWINSZ    = WINSZ_25  //Watchdog Timer Window Size (Window Size is 25%)
    #pragma config JTAGEN       = OFF       //JTAG Enable (JTAG Disabled)
    #pragma config ICESEL       = ICS_PGx1  //ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
    #pragma config PWP          = OFF       //Program Flash Write Protect (Disable)
    #pragma config BWP          = OFF       //Boot Flash Write Protect bit (Protection Disabled)
    #pragma config CP           = OFF       //Code Protect (Protection Disabled)


#else

    #error UNDEFINED BOARD OR PROCESSOR

#endif