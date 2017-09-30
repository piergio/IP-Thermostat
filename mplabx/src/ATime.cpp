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

#include "ATime.h"

#define __MS_MAX__  0x000003E7
#define __SS_MAX__  0x0000003B
#define __MM_MAX__  0x0000003B
#define __HH_MAX__  0x00000017

#define __SS_VAL__  0x000003E8
#define __MM_VAL__  0x0000EA60
#define __HH_VAL__  0x0036EE80
#define __DD_VAL__  0x05265C00

AFramework::ATime::ATime() : m_raw(0){

}

AFramework::ATime::ATime(const uint32 dd, const uint8 hh, const uint8 mm, const uint8 ss, const uint16 ms, const bool neg) : ATime(){
    /*  Nulla da commentare                                                     */
    setTime(dd, hh, mm, ss, ms, neg);
}

bool AFramework::ATime::setTime(const uint32 dd, const uint8 hh, const uint8 mm, const uint8 ss, const uint16 ms, const bool neg){
    /*  controllo che vada tutto bene                                           */
    if((ms > __MS_MAX__) || 
       (ss > __SS_MAX__) || 
       (mm > __MM_MAX__) || 
       (hh > __HH_MAX__)){
        return false;
    }
    /*  azzero il tempo grezzo                                                  */
    m_raw = 0;
    /*  setto i millisecondi                                                    */
    prvms(ms);
    /*  setto i secondi                                                         */
    prvss(ss);
    /*  setto i minuti                                                          */
    prvmm(mm);
    /*  setto le ore                                                            */
    prvhh(hh);
    /*  setto i giorni                                                          */
    prvdd(dd);
    /*  se il flag per rendere negativo è true                                  */
    if(neg){
        /*  moltiplico tutto per -1                                             */
        m_raw *= -1;
    }
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ATime::negative(){
    /*  Nulla da commentare                                                     */
    if(m_raw > 0){
        m_raw *= -1;
    }
}

bool AFramework::ATime::posivite(){
    /*  Nulla da commentare                                                     */
    if(m_raw < 0){
        m_raw *= -1;
    }
}

bool AFramework::ATime::isNegative(){
    /*  Nulla da commentare                                                     */
    return (m_raw < 0);
}

bool AFramework::ATime::isPosivite(){
    /*  Nulla da commentare                                                     */
    return (m_raw >= 0);
}

bool AFramework::ATime::setDays(const uint32 dd){
    /*  non è necessario controllare (il limite è imposto dall'intero), per cui */
    /*  setto le ore                                                            */
    prvdd(dd);
    /*  ritrno true                                                             */
    return true;
}

bool AFramework::ATime::setHours(const uint8 hh){
    /*  se il numero passato eccede il limite                                   */
    if(hh > __HH_MAX__){
        /*  ritorno false                                                       */
        return false;
    }
    /*  setto le ore                                                            */
    prvhh(hh);
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ATime::setMinutes(const uint8 mm){
    /*  se il numero passato eccede il limite                                   */
    if(mm > __MM_MAX__){
        /*  ritorno fale                                                        */
        return false;
    }
    /*  setto i minuti                                                          */
    prvmm(mm);
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ATime::setSeconds(const uint8 ss){
    /*  se il numero passato eccede il limite                                   */
    if(ss > __SS_MAX__){
        /*  ritorno false                                                       */
        return false;
    }
    /*  setto i secondi                                                         */
    prvss(ss);
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::ATime::setMSeconds(const uint16 ms){
    /*  se il numero passato eccede il limite                                   */
    if(ms > __MS_MAX__){
        /*  ritorno false                                                       */
        return false;
    }
    /*  setto i millisecondi                                                    */
    prvms(ms);
    /*  ritorno true                                                            */
    return true;
}

AFramework::sint32 AFramework::ATime::days() const{
    /*  Nulla da commentare                                                     */
    return (m_raw / __DD_VAL__);
}

AFramework::sint8 AFramework::ATime::hours() const{
    /*  Nulla da commentare                                                     */
    return ((m_raw % __DD_VAL__) / __HH_VAL__);
}

AFramework::sint8 AFramework::ATime::minutes() const{
    /*  Nulla da commentare                                                     */
    return ((m_raw % __HH_VAL__) / __MM_VAL__);
}

AFramework::sint8 AFramework::ATime::seconds() const{
    /*  Nulla da commentare                                                     */
    return ((m_raw % __MM_VAL__) / __SS_VAL__);
}

AFramework::sint16 AFramework::ATime::mseconds() const{
    /*  Nulla da commentare                                                     */
    return (m_raw % __SS_VAL__);
}

void AFramework::ATime::addDays(const uint32 dd){
    /*  Nulla da commentare                                                     */
    m_raw += (dd * __DD_VAL__);
}

void AFramework::ATime::addHours(const uint32 hh){
    /*  Nulla da commentare                                                     */
    m_raw += (hh * __HH_VAL__);
}

void AFramework::ATime::addMinutes(const uint32 mm){
    /*  Nulla da commentare                                                     */
    m_raw += (mm * __MM_VAL__);
}

void AFramework::ATime::addSeconds(const uint32 ss){
    /*  Nulla da commentare                                                     */
    m_raw += (ss * __SS_VAL__);
}

void AFramework::ATime::addMseconds(const uint32 ms){
    /*  Nulla da commentare                                                     */
    m_raw += ms;
}

void AFramework::ATime::subDays(const uint32 dd){
    /*  Nulla da commentare                                                     */
    m_raw -= (dd * __DD_VAL__);
}

void AFramework::ATime::subHours(const uint32 hh){
    /*  Nulla da commentare                                                     */
    m_raw -= (hh * __HH_VAL__);
}

void AFramework::ATime::subMinutes(const uint32 mm){
    /*  Nulla da commentare                                                     */
    m_raw -= (mm * __MM_VAL__);
}

void AFramework::ATime::subSeconds(const uint32 ss){
    /*  Nulla da commentare                                                     */
    m_raw -= (ss * __SS_VAL__);
}

void AFramework::ATime::subMseconds(const uint32 ms){
    /*  Nulla da commentare                                                     */
    m_raw -= ms;
}

bool AFramework::ATime::operator<(const ATime & tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw < tm.m_raw);
}

bool AFramework::ATime::operator<(const sint32 tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw < tm);
}

bool AFramework::ATime::operator>(const ATime & tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw > tm.m_raw);
}

bool AFramework::ATime::operator>(const sint32 tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw > tm);
}

AFramework::ATime & AFramework::ATime::operator=(const ATime & tm){
    /*  Nulla da commentare                                                     */
    m_raw = tm.m_raw;
    return *this;
}

AFramework::ATime & AFramework::ATime::operator=(const sint32 tm){
    /*  Nulla da commentare                                                     */
    m_raw = tm;
    return *this;
}

bool AFramework::ATime::operator<=(const ATime & tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw <= tm.m_raw);
}

bool AFramework::ATime::operator<=(const sint32 tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw <= tm);
}

bool AFramework::ATime::operator>=(const ATime & tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw >= tm.m_raw);
}

bool AFramework::ATime::operator>=(const sint32 tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw >= tm);
}

AFramework::ATime & AFramework::ATime::operator+=(const ATime & tm){
    /*  Nulla da commentare                                                     */
    m_raw += tm.m_raw;
    return *this;
}

AFramework::ATime & AFramework::ATime::operator+=(const sint32 tm){
    /*  Nulla da commentare                                                     */
    m_raw += tm;
    return *this;
}

AFramework::ATime & AFramework::ATime::operator-=(const ATime & tm){
    /*  Nulla da commentare                                                     */
    m_raw -= tm.m_raw;
    return *this;
}

AFramework::ATime & AFramework::ATime::operator-=(const sint32 tm){
    /*  Nulla da commentare                                                     */
    m_raw -= tm;
    return *this;
}

AFramework::ATime & AFramework::ATime::operator++(){
    /*  Nulla da commentare                                                     */
    m_raw++;
    return *this;
}

AFramework::ATime AFramework::ATime::operator++(const int){
    /*  Nulla da commentare                                                     */
    m_raw++;
    return *this;
}

AFramework::ATime & AFramework::ATime::operator--(){
    /*  Nulla da commentare                                                     */
    m_raw--;
    return *this;
}

AFramework::ATime AFramework::ATime::operator--(const int){
    /*  Nulla da commentare                                                     */
    m_raw--;
    return *this;
}

bool AFramework::ATime::operator==(const ATime & tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw == tm.m_raw);
}

bool AFramework::ATime::operator==(const sint32 tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw == tm);
}

bool AFramework::ATime::operator!=(const ATime & tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw != tm.m_raw);
}

bool AFramework::ATime::operator!=(const sint32 tm) const{
    /*  Nulla da commentare                                                     */
    return (m_raw == tm);
}

void AFramework::ATime::prvdd(const uint32 dd){
    /*  sottraggo i giorni                                                      */
    m_raw -= (days() * __DD_VAL__);
    /*  aggiorno il valore a seconda che il tempo sia positivo o no             */
    m_raw += (isNegative() ? ((dd * __DD_VAL__) * -1) : (dd * __DD_VAL__));
}

void AFramework::ATime::prvhh(const uint8  hh){
    /*  sottraggo le ore                                                        */
    m_raw -= (hours() * __HH_VAL__);
    /*  aggiorno il valore a seconda che il tempo sia positivo o no             */
    m_raw += (isNegative() ? ((hh * __HH_VAL__) * -1) : (hh * __HH_VAL__));
}

void AFramework::ATime::prvmm(const uint8  mm){
    /*  sottraggo i minuti                                                      */
    m_raw -= (minutes() * __MM_VAL__);
    /*  aggiorno il valore a seconda che il tempo sia positivo o no             */
    m_raw += (isNegative() ? ((mm * __MM_VAL__) * -1) : (mm * __MM_VAL__));
}

void AFramework::ATime::prvss(const uint8  ss){
    /*  sottraggo i secondi                                                     */
    m_raw -= (seconds() * __SS_VAL__);
    /*  aggiorno il valore a seconda che il tempo sia positivo o no             */
    m_raw += (isNegative() ? ((ss * __SS_VAL__) * -1) : (ss * __SS_VAL__));
}

void AFramework::ATime::prvms(const uint16 ms){
    /*  sottraggo i millisecondi                                                */
    m_raw -= mseconds();
    /*  aggiorno il valore a seconda che il tempo sia positivo o no             */
    m_raw += (isNegative() ? (ms * -1) : ms);
}

AFramework::ATime AFramework::operator+(const ATime & tm1, const ATime & tm2){
    
    ATime res;
    /*  Nulla da commentare                                                     */
    res.m_raw = tm1.m_raw + tm2.m_raw;
    return res;
}

AFramework::ATime AFramework::operator-(const ATime & tm1, const ATime & tm2){
    
    ATime res;
    /*  Nulla da commentare                                                     */
    res.m_raw = tm1.m_raw - tm2.m_raw;
    return res;
}