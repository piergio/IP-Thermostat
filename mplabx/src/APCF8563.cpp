
#include "APCF8563.h"

#define _PCF8563_R_ADDR                                 0xA3
#define _PCF8563_W_ADDR                                 0xA2

#define _PCF8563_CTRLSTAT1                              0x00
#define _PCF8563_CTRLSTAT2                              0x01
#define _PCF8563_VL_SECONDS                             0x02
#define _PCF8563_MINUTES                                0x03
#define _PCF8563_HOURS                                  0x04
#define _PCF8563_DAYS                                   0x05
#define _PCF8563_WEEKDAYS                               0x06
#define _PCF8563_CENTURY_MONTHS                         0x07
#define _PCF8563_YEARS                                  0x08
#define _PCF8563_MINUTE_ALARM                           0x09
#define _PCF8563_HOUR_ALARM                             0x0A
#define _PCF8563_DAY_ALARM                              0x0B
#define _PCF8563_WEEKDAY_ALARM                          0x0C
#define _PCF8563_CLKOUT_CTRL                            0x0D
#define _PCF8563_TIMER_CONTROL                          0x0E
#define _PCF8563_TIMER                                  0x0F


#define _PCF8563_CTRLSTAT1_TEST1_POSITION               0x07
#define _PCF8563_CTRLSTAT1_TEST1_MASK                   0x80
#define _PCF8563_CTRLSTAT1_TEST1_LENGTH                 0x01

#define _PCF8563_CTRLSTAT1_STOP_POSITION                0x05
#define _PCF8563_CTRLSTAT1_STOP_MASK                    0x20
#define _PCF8563_CTRLSTAT1_STOP_LENGTH                  0x01

#define _PCF8563_CTRLSTAT1_TESTC_POSITION               0x03
#define _PCF8563_CTRLSTAT1_TESTC_MASK                   0x08
#define _PCF8563_CTRLSTAT1_TESTC_LENGTH                 0x01

#define _PCF8563_CTRLSTAT2_TI_TP_POSITION               0x04
#define _PCF8563_CTRLSTAT2_TI_TP_MASK                   0x10
#define _PCF8563_CTRLSTAT2_TI_TP_LENGTH                 0x01

#define _PCF8563_CTRLSTAT2_AF_POSITION                  0x03
#define _PCF8563_CTRLSTAT2_AF_MASK                      0x08
#define _PCF8563_CTRLSTAT2_AF_LENGTH                    0x01

#define _PCF8563_CTRLSTAT2_TF_POSITION                  0x02
#define _PCF8563_CTRLSTAT2_TF_MASK                      0x04
#define _PCF8563_CTRLSTAT2_TF_LENGTH                    0x01

#define _PCF8563_CTRLSTAT2_AIE_POSITION                 0x01
#define _PCF8563_CTRLSTAT2_AIE_MASK                     0x02
#define _PCF8563_CTRLSTAT2_AIE_LENGTH                   0x01

#define _PCF8563_CTRLSTAT2_TIE_POSITION                 0x00
#define _PCF8563_CTRLSTAT2_TIE_MASK                     0x01
#define _PCF8563_CTRLSTAT2_TIE_LENGTH                   0x01

#define _PCF8563_VL_SECONDS_VL_POSITION                 0x07
#define _PCF8563_VL_SECONDS_VL_MASK                     0x80
#define _PCF8563_VL_SECONDS_VL_LENGTH                   0x01

#define _PCF8563_VL_SECONDS_SECONDS_POSITION            0x00
#define _PCF8563_VL_SECONDS_SECONDS_MASK                0x7F
#define _PCF8563_VL_SECONDS_SECONDS_LENGTH              0x07

#define _PCF8563_MINUTES_MINUTES_POSITION               0x00
#define _PCF8563_MINUTES_MINUTES_MASK                   0x7F
#define _PCF8563_MINUTES_MINUTES_LENGTH                 0x07

#define _PCF8563_HOURS_HOURS_POSITION                   0x00
#define _PCF8563_HOURS_HOURS_MASK                       0x3F
#define _PCF8563_HOURS_HOURS_LENGTH                     0x06

#define _PCF8563_DAYS_DAYS_POSITION                     0x00
#define _PCF8563_DAYS_DAYS_MASK                         0x3F
#define _PCF8563_DAYS_DAYS_LENGTH                       0x06

#define _PCF8563_WEEKDAYS_WEEKDAYS_POSITION             0x00
#define _PCF8563_WEEKDAYS_WEEKDAYS_MASK                 0x07
#define _PCF8563_WEEKDAYS_WEEKDAYS_LENGTH               0x03

#define _PCF8563_CENTURY_MONTHS_C_POSITION              0x07
#define _PCF8563_CENTURY_MONTHS_C_MASK                  0x80
#define _PCF8563_CENTURY_MONTHS_C_LENGTH                0x01

#define _PCF8563_CENTURY_MONTHS_MONTHS_POSITION         0x00
#define _PCF8563_CENTURY_MONTHS_MONTHS_MASK             0x1F
#define _PCF8563_CENTURY_MONTHS_MONTHS_LENGTH           0x05

#define _PCF8563_MINUTE_ALARM_AE_M_POSITION             0x07
#define _PCF8563_MINUTE_ALARM_AE_M_MASK                 0x80
#define _PCF8563_MINUTE_ALARM_AE_M_LENGTH               0x01

#define _PCF8563_MINUTE_ALARM_MINUTE_ALARM_POSITION     0x00
#define _PCF8563_MINUTE_ALARM_MINUTE_ALARM_MASK         0x7F
#define _PCF8563_MINUTE_ALARM_MINUTE_ALARM_LENGTH       0x07

#define _PCF8563_HOUR_ALARM_AE_H_POSITION               0x07
#define _PCF8563_HOUR_ALARM_AE_H_MASK                   0x80
#define _PCF8563_HOUR_ALARM_AE_H_LENGTH                 0x01

#define _PCF8563_HOUR_ALARM_HOUR_ALARM_POSITION         0x00
#define _PCF8563_HOUR_ALARM_HOUR_ALARM_MASK             0x3F
#define _PCF8563_HOUR_ALARM_HOUR_ALARM_LENGTH           0x06

#define _PCF8563_DAY_ALARM_AE_D_POSITION                0x07
#define _PCF8563_DAY_ALARM_AE_D_MASK                    0x80
#define _PCF8563_DAY_ALARM_AE_D_LENGTH                  0x01

#define _PCF8563_DAY_ALARM_DAY_ALARM_POSITION           0x00
#define _PCF8563_DAY_ALARM_DAY_ALARM_MASK               0x3F
#define _PCF8563_DAY_ALARM_DAY_ALARM_LENGTH             0x06

#define _PCF8563_WEEKDAY_ALARM_AE_W_POSITION            0x07
#define _PCF8563_WEEKDAY_ALARM_AE_W_MASK                0x80
#define _PCF8563_WEEKDAY_ALARM_AE_W_LENGTH              0x01

#define _PCF8563_WEEKDAY_ALARM_WEEKDAY_ALARM_POSITION   0x00
#define _PCF8563_WEEKDAY_ALARM_WEEKDAY_ALARM_MASK       0x07
#define _PCF8563_WEEKDAY_ALARM_WEEKDAY_ALARM_LENGTH     0x03

#define _PCF8563_CLKOUT_CTRL_FE_POSITION                0x07
#define _PCF8563_CLKOUT_CTRL_FE_MASK                    0x80
#define _PCF8563_CLKOUT_CTRL_FE_LENGTH                  0x01

#define _PCF8563_CLKOUT_CTRL_FD_POSITION                0x00
#define _PCF8563_CLKOUT_CTRL_FD_MASK                    0x03
#define _PCF8563_CLKOUT_CTRL_FD_LENGTH                  0x02

#define _PCF8563_TIMER_CONTROL_TE_POSITION              0x07
#define _PCF8563_TIMER_CONTROL_TE_MASK                  0x80
#define _PCF8563_TIMER_CONTROL_TE_LENGTH                0x01

#define _PCF8563_TIMER_CONTROL_TD_POSITION              0x00
#define _PCF8563_TIMER_CONTROL_TD_MASK                  0x03
#define _PCF8563_TIMER_CONTROL_TD_LENGTH                0x02

#define _PCF8563_TIMER_TIMER_POSITION                   0x00
#define _PCF8563_TIMER_TIMER_MASK                       0xFF
#define _PCF8563_TIMER_TIMER_LENGTH                     0x08


AFramework::APCF8563::APCF8563(volatile AI2CDriver * driver) : m_driver(NULL){
    /*  assegno il driver dell'i2c                                              */
    m_driver = driver;
    /*  se il driver non è NULL e non è aperto                                  */
    if(m_driver && !driver->isOpen()){
        /*  lo apro a frequenza 100KHz                                          */
        driver->open(AI2CDriver::Freq100KHz);
    }
}

bool AFramework::APCF8563::isGood() const{
    /*  leggo del registro VL_SECONDS e faccio l'and con la maschera di VL      */
    return !(bcddec(readreg(_PCF8563_VL_SECONDS) & _PCF8563_VL_SECONDS_VL_MASK));
}

AFramework::uint8 AFramework::APCF8563::seconds() const{
    /*  leggo dal registro VL_SECONDS e faccio l'and con la maschera dei bit    */
    return (bcddec(readreg(_PCF8563_VL_SECONDS) & _PCF8563_VL_SECONDS_SECONDS_MASK));
}

AFramework::uint8 AFramework::APCF8563::minutes() const{
    /*  leggo dal registro MINUTES e faccio l'and con la maschera dei bit       */
    return (bcddec(readreg(_PCF8563_MINUTES) & _PCF8563_MINUTES_MINUTES_MASK));
}

AFramework::uint8 AFramework::APCF8563::hours() const{
    /*  leggo dal registro HOURS e faccio l'and con la maschera dei bit         */
    return (bcddec(readreg(_PCF8563_HOURS) & _PCF8563_HOURS_HOURS_MASK));
}

AFramework::uint8 AFramework::APCF8563::days() const{
    /*  leggo dal registro DAYS e faccio l'and con la maschera dei bit          */
    return (bcddec(readreg(_PCF8563_DAYS) & _PCF8563_DAYS_DAYS_MASK));
}           

AFramework::ADateTime::Weekdays AFramework::APCF8563::weekday() const{
    /*  leggo dal registro WEEKDAYS e faccio l'and con la maschera dei bit      */
    return static_cast<ADateTime::Weekdays>(bcddec(readreg(_PCF8563_WEEKDAYS) & _PCF8563_WEEKDAYS_WEEKDAYS_MASK) + 1);
}

AFramework::ADateTime::Months AFramework::APCF8563::month() const{
    /*  leggo dal registro CENTURY_MONTHS e faccio l'and con la maschera dei bit*/
    return static_cast<ADateTime::Months>(bcddec(readreg(_PCF8563_CENTURY_MONTHS) & _PCF8563_CENTURY_MONTHS_MONTHS_MASK));
}

AFramework::uint8 AFramework::APCF8563::years() const{
    /*  leggo dal registro YEARS e faccio l'and con la maschera dei bit         */
    return bcddec(readreg(_PCF8563_YEARS));
}

bool AFramework::APCF8563::setTime(ADateTime tm) const{
    /*  controllo che il puntatore al driver sia valido                         */
    if(!m_driver){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_VL_SECONDS);
    /*  scrivo i secondi                                                        */
    //    m_driver->write(decbcd(tm.seconds()) | _PCF8563_VL_SECONDS_VL_MASK);
    m_driver->write(decbcd(tm.seconds()) & _PCF8563_VL_SECONDS_SECONDS_MASK);
    /*  scrivo i minuti                                                         */
    m_driver->write(decbcd(tm.minutes()) & _PCF8563_MINUTES_MINUTES_MASK);
    /*  scrivo le ore                                                           */
    m_driver->write(decbcd(tm.hours()) & _PCF8563_HOURS_HOURS_MASK);
    /*  scrivo i giorni                                                         */
    m_driver->write(decbcd(tm.dayOfMonth()) & _PCF8563_DAYS_DAYS_MASK);
    /*  scrivo il giorno della settimana                                        */
    m_driver->write(decbcd(static_cast<uint8>(tm.Weekday()) - 1) & _PCF8563_WEEKDAYS_WEEKDAYS_MASK);
    /*  scrivo il mese                                                          */
    m_driver->write(decbcd(tm.month()) & _PCF8563_CENTURY_MONTHS_MONTHS_MASK);
    /*  scrivo l'anno                                                           */
    m_driver->write(decbcd(tm.year()));
    /*  chiudo la trasmissione                                                  */
    m_driver->stop();
    /*  e ritorno true                                                          */
    return true;
}

AFramework::ADateTime AFramework::APCF8563::currentTime() const{
    
    ADateTime ctime;
    /*  leggo ed imposto i secondi                                              */
    ctime.setSeconds(seconds());
    /*  leggo ed imposto i minuti                                               */
    ctime.setMinutes(minutes());
    /*  leggo ed imposto le ore                                                 */
    ctime.setHours(hours());
    /*  leggo ed imposto l'anno                                                 */
    ctime.setYear(years());
    /*  leggo ed imposto il mese                                                */
    ctime.setMonth(month());
    /*  leggo ed imposto il giorno del mese                                     */
    ctime.setDayOfMonth(days());
    /*  leggo ed imposto il giorno della settimana                              */
    ctime.setWeekday(weekday());
    /*  ritorno il tempo                                                        */
    return ctime;
}

bool AFramework::APCF8563::setAlarm(const uint8 hours, const uint8 minutes, const ADateTime::Weekdays weekday) const{
    
    uint8 ctrl = 0;
    /*  se i parametri non sono validi                                          */
    if((hours > 0x17) || (minutes > 0x3B)){
        /*  ritorno false                                                       */
        return false;
    }
        /*  controllo che il puntatore al driver sia valido                     */
    if(!m_driver){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_CTRLSTAT2);
    /*  invio la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in lettura                                   */
    m_driver->write(_PCF8563_R_ADDR);
    /*  leggo il contenuto del registro ed imposto il flag per l'allarme        */
    ctrl = m_driver->read() | _PCF8563_CTRLSTAT2_AIE_MASK;
    /*  mando la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_CTRLSTAT2);
    /*  scrivo il valore nel registro                                           */
    m_driver->write(ctrl);
    /*  mando la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_MINUTE_ALARM);
    /*  imposto i minuti                                                        */
    m_driver->write(decbcd(minutes) & _PCF8563_MINUTE_ALARM_MINUTE_ALARM_MASK);
    /*  imposto le ore                                                          */
    m_driver->write(decbcd(hours) & _PCF8563_HOUR_ALARM_HOUR_ALARM_MASK);
    /*  cancello l'allarme sul giorno                                           */
        m_driver->write(decbcd(1) | _PCF8563_DAY_ALARM_DAY_ALARM_MASK);    
    /*  se il giorno della settimana è specificato                              */
    if(weekday != ADateTime::NoWeekday){
        /*  imposto l'allarme per il giorno passato come parametro*/
        m_driver->write(decbcd(static_cast<uint8>(weekday) - 1) & _PCF8563_DAY_ALARM_DAY_ALARM_MASK);
    }
    /*  chiudo la trasmissione                                                  */
    m_driver->stop();
    /*  e ritorno true                                                          */
    return true;
}

bool AFramework::APCF8563::stopAlarm() const{
    
    uint8 ctrl = 0;
    /*  controllo che il puntatore al driver sia valido                     */
    if(!m_driver){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_CTRLSTAT2);
    /*  invio la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in lettura                                   */
    m_driver->write(_PCF8563_R_ADDR);
    /*  leggo il contenuto del registro ed cancello i flag per l'allarme        */
    ctrl = m_driver->read() & ~(_PCF8563_CTRLSTAT2_AIE_MASK | _PCF8563_CTRLSTAT2_AF_MASK);
    /*  mando la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_CTRLSTAT2);
    /*  scrivo il valore nel registro                                           */
    m_driver->write(ctrl);
    /*  mando la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_MINUTE_ALARM);
    /*  disabilito l'allarme sui minuti                                         */
    m_driver->write(decbcd(1) | _PCF8563_MINUTE_ALARM_AE_M_MASK);
    /*  disabilito l'allarme sulle ore                                          */
    m_driver->write(decbcd(1) | _PCF8563_HOUR_ALARM_AE_H_MASK);
    /*  disabilito l'allarme sui giorni                                         */
    m_driver->write(decbcd(1) | _PCF8563_DAY_ALARM_AE_D_MASK);
    /*  disabilito l'allarme sui giorni della settimana                         */
    m_driver->write(decbcd(0) | _PCF8563_WEEKDAY_ALARM_AE_W_MASK);
    /*  chiudo la trasmissione                                                  */
    m_driver->stop();
    /*  e ritorno true                                                          */
    return true;
}

bool AFramework::APCF8563::setClockOut(const ClockOut clock){
    /*  controllo che il driver sia ok                                          */
    if(!m_driver){
        /*  se non è così ritorno zero                                          */
        return 0;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(_PCF8563_CLKOUT_CTRL);
    /*  Scrivo il valore passato nel registro                                   */
    m_driver->write(static_cast<uint8>(clock) | _PCF8563_CLKOUT_CTRL_FE_MASK);
    /*  chiudo la trasmissione                                                  */
    m_driver->stop();
    /*  ritorno true                                                            */
    return true;
}

AFramework::uint8 AFramework::APCF8563::bcddec(const uint8 val) const{
    /*  converte un numero da BCD a decimale                                    */
    return ((((val & 0xF0) >> 0x04) * 0x0A) + (val & 0x0F));
}

AFramework::uint8 AFramework::APCF8563::decbcd(const uint8 val) const{
    /*  converte un numero da decimale a BCD                                    */
    return (((val / 0x0A) << 0x04) | (val % 0x0A));
}

AFramework::uint8 AFramework::APCF8563::readreg(const uint8 reg) const{
    
    uint8 val = 0;
    /*  controllo che il driver sia ok                                          */
    if(!m_driver){
        /*  se non è così ritorno zero                                          */
        return 0;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo del PCF in scrittura                                 */
    m_driver->write(_PCF8563_W_ADDR);
    /*  imposto il puntatore al registro                                        */
    m_driver->write(reg);
    /*  mando la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo del PCF in lettura                                   */
    m_driver->write(_PCF8563_R_ADDR);
    /*  leggo il contenuto del registro                                         */
    val = m_driver->read();
    /*  chiudo la trasmissione                                                  */
    m_driver->stop();
    /*  ritorno il valore                                                       */
    return val;
}