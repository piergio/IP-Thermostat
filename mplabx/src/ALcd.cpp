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

#include "ALcd.h"

#define ONLY_MSB    0x00
#define FULL_BIT    0x01
#define INIT8BIT    0x30
#define INIT4BIT    0x20
#define TWO_LINE    0x28
#define DISPL_ON    0x0C
#define LCD_CLRS    0x01
#define CURSOR_H    0x02
#define LINE_ONE    0x80
#define LINE_TWO    0xC0
#define ENT_MODE    0x06
#define CS_BLINK    0x01
#define CS__SHOW    0x02
#define SC__LEFT    0x18
#define SC_RIGHT    0x1C
#define CS__LEFT    0x10
#define CS_RIGHT    0x14



#define D4          0x00
#define D5          0x01
#define D6          0x02
#define D7          0x03
#define EN          0x04
#define RS          0x05
#define BL          0x06
#define VEC_SIZE    0x07

AFramework::ALcd::ALcd(volatile AHardwarePort * portD4, const uint32 bitD4,
                       volatile AHardwarePort * portD5, const uint32 bitD5,
                       volatile AHardwarePort * portD6, const uint32 bitD6,
                       volatile AHardwarePort * portD7, const uint32 bitD7,
                       volatile AHardwarePort * portEN, const uint32 bitEN,
                       volatile AHardwarePort * portRS, const uint32 bitRS,
                       volatile AHardwarePort * portBL, const uint32 bitBL){
    m_port[D4] = portD4;
    m_port[D5] = portD5;
    m_port[D6] = portD6;
    m_port[D7] = portD7;
    m_port[EN] = portEN;
    m_port[RS] = portRS;
    m_port[BL] = portBL;
    
    m_bits[D4] = bitD4;
    m_bits[D5] = bitD5;
    m_bits[D6] = bitD6;
    m_bits[D7] = bitD7;
    m_bits[EN] = bitEN;
    m_bits[RS] = bitRS;
    m_bits[BL] = bitBL;
    
    m_attr = DISPL_ON;
    
    for(uint8 i = 0; i < VEC_SIZE; i++){
        m_port[i]->setDigital(m_bits[i]);
        m_port[i]->setOutput(m_bits[i]);
    }
    
    System::delay(25);
    cmdwrt(INIT8BIT, Lo, false);
    System::delay(5);
    cmdwrt(INIT8BIT, Lo, false);
    System::delay(2);
    cmdwrt(INIT8BIT, Lo, false);
    cmdwrt(INIT4BIT, Lo, false);
    cmdwrt(TWO_LINE, Lo);
    cmdwrt(DISPL_ON, Lo);
    cmdwrt(ENT_MODE, Lo);
}

void AFramework::ALcd::lightOn(){
    m_port[BL]->write(m_bits[BL], Hi);
}

void AFramework::ALcd::lightOff(){
    m_port[BL]->write(m_bits[BL], Lo);
}

void AFramework::ALcd::lightToggle(){
    m_port[BL]->latchInvert(m_bits[BL]);
}

bool AFramework::ALcd::setCursorMode(const CursorMode mode){

    switch(mode){
        case CursorShow:
            m_attr |=  CS__SHOW;
            break;
        case CursorHide:
            m_attr &= ~CS__SHOW;
            break;
        case CursorBlink:
            m_attr |=  CS_BLINK;
            break;
        case CursorFixed:
            m_attr &= ~CS_BLINK;
            break;
        default:
            return false;
            break;
    }
    
    cmdwrt(m_attr, Lo);
    return true;
}

bool AFramework::ALcd::shiftScreen(const uint8 pos, const Direction dir){
    
    uint8 cmd;
    
    switch(dir){
        case Left:
            cmd = SC__LEFT;
            break;
        case Right:
            cmd = SC_RIGHT;
            break;
        default:
            return false;
            break;
    }
    
    for(uint8 i = 0; i < pos; i++){
        cmdwrt(cmd, Lo);
    }
    
    return true;
}

void AFramework::ALcd::clear(){
    cmdwrt(LCD_CLRS, Lo);
    setLine(0);
}

bool AFramework::ALcd::setLine(const uint8 line){
    
    switch(line){
        case 0:
            cmdwrt(LINE_ONE, Lo);
            break;
        case 1:
            cmdwrt(LINE_TWO, Lo);
            break;
        default:
            return false;
            break;
    }

    return true;
}

bool AFramework::ALcd::shiftCursor(const uint8 pos, const Direction dir){
    
    uint8 cmd;
    
    switch(dir){
        case Left:
            cmd = CS__LEFT;
            break;
        case Right:
            cmd = CS_RIGHT;
            break;
        default:
            return false;
            break;
    }
    
    for(uint8 i = 0; i < pos; i++){
        cmdwrt(cmd, Lo);
    }
    
    return true;
}

bool AFramework::ALcd::gotoXY(uint8 x, uint8 y){
    
    if(y < 2 && x < 40){
        cmdwrt(CURSOR_H, Lo);
        System::delay(2);
        setLine(y);
        shiftCursor(x, Right);
        return true;
    }
    return false;
}

void AFramework::ALcd::putchar(const char chr){
    cmdwrt(chr, Hi);
}

void AFramework::ALcd::write(const char * str){
    
    uint32 length = AString::strlen(str);
    
    for(uint32 i = 0; i < length; i++){
        if(str[i] == '\n'){
            setLine(1);
        }else{
            putchar(str[i]);
        }
    }
}

void AFramework::ALcd::cmdwrt(unsigned char cmd, const LogicLevel rsVal, bool full){
    
    m_port[RS]->write(m_bits[RS], rsVal);
    m_port[EN]->write(m_bits[EN], Lo);
    System::delay(1);

	for(uint8 i = 0; i < 4; i++){
        m_port[i]->write(m_bits[i], (cmd & (0x10 << i) ? Hi : Lo));
	}

    m_port[EN]->write(m_bits[EN], Hi);
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    asm volatile("nop");
    m_port[EN]->write(m_bits[EN], Lo);
    
    if(full){
        System::delay(1);
        for(uint8 i = 0; i < 4; i++){
            m_port[i]->write(m_bits[i], (cmd & (0x01 << i) ? Hi : Lo));
        }
        
        m_port[EN]->write(m_bits[EN], Hi);
        asm volatile("nop");
        asm volatile("nop");
        asm volatile("nop");
        asm volatile("nop");
        m_port[EN]->write(m_bits[EN], Lo);
    }
    
    System::delay(1);
}

AFramework::ALcd & AFramework::operator<<(ALcd & lcd, const char * str){
    
    lcd.write(str);
    return lcd;
}

AFramework::ALcd & AFramework::operator<<(ALcd & lcd, const AString & str){
    
    lcd.write(str.c_str());
    return lcd;
}

AFramework::ALcd & AFramework::operator<<(ALcd & lcd, const uint8 num){
    
    lcd.write(AString(num).c_str());
    return lcd;
}