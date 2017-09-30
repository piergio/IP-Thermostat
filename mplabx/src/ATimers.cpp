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

#include "ATimers.h"

#include <limits>
#include <cmath>

#if (__HAS_TIMER1__)
    
    extern volatile AFramework::ATMR_w TMR1_w __asm__("TMR1_w") __attribute__((section("sfrs")));
    volatile AFramework::A16bitMasterTimer AFramework::Timer1(&TMR1_w);
    
#endif
    
#if (__HAS_TIMER2__)
    
    extern volatile AFramework::ATMR_w TMR2_w __asm__("TMR2_w") __attribute__((section("sfrs")));
    volatile AFramework::A32bitMasterTimer AFramework::Timer2(&TMR2_w, &AFramework::Timer3);
    
#endif
    
#if (__HAS_TIMER3__)
    
    extern volatile AFramework::ATMR_w TMR3_w __asm__("TMR3_w") __attribute__((section("sfrs")));
    volatile AFramework::A16bitSlaveTimer  AFramework::Timer3(&TMR3_w);
    
#endif

#if (__HAS_TIMER4__)
    
    extern volatile AFramework::ATMR_w TMR4_w __asm__("TMR4_w") __attribute__((section("sfrs")));
    volatile AFramework::A32bitMasterTimer AFramework::Timer4(&TMR4_w, &AFramework::Timer5);
    
#endif
    
#if (__HAS_TIMER5__)
    
    extern volatile AFramework::ATMR_w TMR5_w __asm__("TMR5_w") __attribute__((section("sfrs")));
    volatile AFramework::A16bitSlaveTimer  AFramework::Timer5(&TMR5_w);
    
#endif

/*
 * class AAbstract16bitTimer 
 */
AFramework::AAbstract16bitTimer::AAbstract16bitTimer(volatile ATMR_w * w) : m_reg(w){
#if   defined (__32MX__)
    
    close();
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::setSynchronousInternal16(const volatile double period, const volatile bool idleStop) volatile{
#if   defined (__32MX__)

    /*  uso rawConfig con l'eventuale bit di idle                               */
    rawConfig((idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri              */
    return setpar(period, System::busFrequency());

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::setSynchronousExternal16(const volatile double extFreq, const volatile double period, const volatile bool idleStop) volatile{
#if   defined (__32MX__)

    /*  anche se il timer di tipo b ha il settaggio automatico del bit TSYNC    */
    /*  lo passo ugualmente, alla fine dal datasheet c'e' scritto che nei timer */
    /*  di tipo b questo bit e' non implementato per cui anche se ci scrivo non */
    /*  dovrebbe succedere nulla                                                */
    rawConfig(_TxCON_TSYNC_MASK | _TxCON_TCS_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri              */
    return setpar(period, extFreq);

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::setGated16(const volatile double period, bool idleStop) volatile{
#if   defined (__32MX__)
    
    /*  uso rawConfig impostando la modalita' gated, il bit di sync e           */
    /*  l'eventuale bit di idle                                                 */
    rawConfig(_TxCON_TGATE_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  setto i parametri e ritorno l'errore                                    */
    return setpar(period, System::busFrequency());

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

bool AFramework::AAbstract16bitTimer::open() volatile{
#if   defined (__32MX__)
    
    /*  Controllo che il timer non sia già aperto                               */
    if(isOpen()){
        /*  in questo caso ritorno false                                        */
        return false;
    }
    /*  Altrimenti setto il bit on nel registro                                 */
    m_reg->TxCON.SET = _TxCON_ON_MASK;
    /*  ritorno true                                                            */
    return true;
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif

}

void AFramework::AAbstract16bitTimer::close() volatile{
#if   defined (__32MX__)

    /*  spengo il timer                                                         */
    m_reg->TxCON.CLR = _TxCON_ON_MASK;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::AAbstract16bitTimer::clear() volatile{
#if   defined (__32MX__)

    /*  azzero il registro TMRx                                                 */
    m_reg->TMRx.CLR = Quick::All;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::AAbstract16bitTimer::reset() volatile{
#if   defined (__32MX__)
    
    /*  spengo il timer e cancello tutti i bit                                  */
    m_reg->TxCON.CLR = Quick::All;
    /*  pulisco il registro TMRx                                                */
    m_reg->TMRx.CLR  = Quick::All;
    /*  pulisco il registro PRx                                                 */
    m_reg->PRx.CLR   = Quick::All;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

bool AFramework::AAbstract16bitTimer::isOpen() const volatile{
#if   defined (__32MX__)

    /*  ritorno l'and con il bit on                                             */
    return (m_reg->TxCON.REG & _TxCON_ON_MASK);

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

AFramework::uint32 AFramework::AAbstract16bitTimer::rawTime() const volatile{
#if   defined (__32MX__)

    /*  ritorno il contenuto del registro TMRx                                  */
    return m_reg->TMRx.REG;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::elapsedTime() const volatile{
#if   defined (__32MX__)

    /*  ritorno il tempo grezzo (contenuto del registro TMRx) moltiplicato la   */
    /*  risoluzione                                                             */
    return (m_reg->TMRx.REG * m_res);

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::error() const volatile{
#if   defined (__32MX__)

    /*  ritorno l'errore                                                        */
    return m_err;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::AAbstract16bitTimer::resolution() const volatile{
#if   defined (__32MX__)

    /*  ritorno la risoluzione                                                  */
    return m_res;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::AAbstract16bitTimer::rawConfig(const volatile uint32 b) volatile{
#if   defined (__32MX__)

    /*  resetto il timer                                                        */
    reset();
    /*  configuro per come mi vengono dati i bit                                */
    m_reg->TxCON.SET = b;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

/*
 * class A16bitMasterTimer 
 */
AFramework::A16bitMasterTimer::A16bitMasterTimer(volatile ATMR_w * w) : AAbstract16bitTimer(w){
#if   defined (__32MX__)
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A16bitMasterTimer::setAsynchronousExternal16(const volatile double period, const volatile bool idleStop) volatile{
#if   defined (__32MX__)
#   if !(__HAS_EXTOSC__)

#   warning This board not have an external oscillator.
    
    return std::numeric_limits<double>::min();
        
#else

#   warning Timer function is not fully implemented.

    /*  uso rawcfg impostando la sorgente di clock esterna e l'eventuale        */
    /* bit di idle                                                              */
    rawcfg(TCS_BIT | (idleStop ? SIDL_BIT : Quick::NoOne));
    /*  setto i parametri e ritorno l'errore                                    */
    return setpar(period, System::secFrequency());
        
#endif
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A16bitMasterTimer::setpar(const volatile double t, const volatile double f, const volatile bool w) volatile{
#if   defined (__32MX__)
    
    double per   = std::fabs(t);                              //  valore assoluto del periodo (non si sa mai...)
    double fre   = std::fabs(f);                              //  valore assoluto della frequenza (non si sa mai...) per il periodo
    double val   = fre * per;                                 //  frequenza per periodo (evito di fare una moltiplicazione ogni iterazione)
    double er1   = std::numeric_limits<double>::max();        //  errore iniziale (dovendo cercare il minimo metto a +inf)
    double er2   = 0;                                         //  errore temporaneo (zero va benissimo)
    uint8  PSv   = 0;                                         //  valore prescaler
    uint8  PSt   = 0;                                         //  prescaler temporaneo
    uint16 PRv   = 0;                                         //  valore periodo
    double PRt   = 0;                                         //  periodo temporaneo
    uint16 PSn[] = {0x0001, 0x0008, 0x0040, 0x0100};          //  prescaler per calcoli
    /*  inizio a cercare il minimo errore                                       */
    for(PSt = 0; PSt < 0x04; PSt++){
        /*  setto il valore del periodo temporaneo evitando di sfondarlo        */
        PRt = (val / PSn[PSt]);
        /*  controllo che non sia maggiore del limite                           */
        if(PRt > std::numeric_limits<unsigned short>::max()){
            /*  in questo caso lo tronco al massimo                             */
            PRt = std::numeric_limits<unsigned short>::max();
        /*  altrimenti                                                          */
        }else{
            /*  lo riporto ad un intero                                         */
            PRt = static_cast<unsigned short>(PRt);
        }
        /*  calcolo l'errore                                                    */
        er2 = per - (PRt * PSn[PSt] / fre);
        /*  se l'errore calcolato in valore assoluto è minore del precedente    */
        if(std::fabs(er2) < er1){
            /*  aggiorno il valore del prescaler                                */
            PSv = PSt;
            /*  aggiorno il valore del periodo                                  */
            PRv = PRt;
            /*  aggiorno l'errore in valore assoluto                            */
            er1 = std::fabs(er2);
        }
        /*  se non c'è errore (caso ottimo)                                     */
        if(er2 == 0){
            /*  smetto di iterare                                               */
            break;
        }
    }
    /*  setto il registro PR                                                    */
    m_reg->PRx.SET = PRv;
    /*  configuro il prescaler                                                  */
    m_reg->TxCON.SET = (PSv << _TxCON_16_TCKPS_POSITION);
    /*  imposto la risoluzione                                                  */
    m_res = PSn[PSv] / fre;
    /*  salvo l'errore                                                          */
    m_err = er1;
    /*  ritorno l'errore                                                        */
    return er1;
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

/*
 * class A16bitSlaveTimer
 */
AFramework::A16bitSlaveTimer::A16bitSlaveTimer(volatile ATMR_w * w) : AAbstract16bitTimer(w) {
#if   defined (__32MX__)

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

bool AFramework::A16bitSlaveTimer::isBusy() const volatile{
#if   defined (__32MX__)
    
    return false;
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A16bitSlaveTimer::setpar(const volatile double t, const volatile double f, const volatile bool w) volatile{
#if   defined (__32MX__)

    double per   = std::fabs(t);                              //  valore assoluto del periodo (non si sa mai...)
    double fre   = std::fabs(f);                              //  valore assoluto della frequenza (non si sa mai...) per il periodo
    double val   = fre * per;                                 //  frequenza per periodo (evito di fare una moltiplicazione ogni iterazione)
    double er1   = std::numeric_limits<double>::max();        //  errore iniziale (dovendo cercare il minimo metto a +inf)
    double er2   = 0;                                         //  errore temporaneo (zero va benissimo)
    uint8  PSv   = 0;                                         //  valore prescaler
    uint8  PSt   = 0;                                         //  prescaler temporaneo
    uint16 PSn[] = {0x0001, 0x0002, 0x0004, 0x0008,           //  prescaler per calcoli
                    0x0010, 0x0020, 0x0040, 0x0100};
    double max   = (w ? std::numeric_limits<unsigned int>::max() : std::numeric_limits<unsigned short>::max()); //  massimo
    uint32 PRv   = 0;                                         //  valore periodo
    double PRt   = 0;                                         //  periodo temporaneo
    /*  inizio a cercare il minimo errore                                       */
    for(PSt = 0; PSt < 0x08; PSt++){
        /*  setto il valore del periodo temporaneo evitando di sfondarlo        */
        PRt = (val / PSn[PSt]);
        /*  controllo che non sia maggiore del limite                           */
        if(PRt > max){
            /*  in questo caso lo tronco al massimo                             */
            PRt = max;
        /*  altrimenti                                                          */
        }else{
            /*  lo riporto ad un intero                                         */
            PRt = (w ? static_cast<unsigned int>(PRt) : static_cast<unsigned short>(PRt));
        }
        /*  calcolo l'errore                                                    */
        er2 = per - (PRt * PSn[PSt] / fre);
        /*  se l'errore calcolato in valore assoluto è minore del precedente    */
        if(std::fabs(er2) < er1){
            /*  aggiorno il valore del prescaler                                */
            PSv = PSt;
            /*  aggiorno il valore del periodo                                  */
            PRv = PRt;
            /*  aggiorno l'errore in valore assoluto                            */
            er1 = std::fabs(er2);
        }
        /*  se non c'è errore (caso ottimo)                                     */
        if(er2 == 0){
            /*  smetto di iterare                                               */
            break;
        }
    }
    /*  setto il registro PR                                                    */
    m_reg->PRx.SET = PRv;
    /*  configuro il prescaler                                                  */
    m_reg->TxCON.SET = (PSv << _TxCON_32_TCKPS_POSITION);
    /*  imposto la risoluzione                                                  */
    m_res = PSn[PSv] / fre;
    /*  salvo l'errore                                                          */
    m_err = er1;
    /*  ritorno l'errore                                                        */
    return er1;

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

/*
 * class A32bitMasterTimer
 */
AFramework::A32bitMasterTimer::A32bitMasterTimer(volatile ATMR_w * w, 
                                                 volatile A16bitSlaveTimer * slave) : A16bitSlaveTimer(w), m_slave(slave){
#if   defined (__32MX__)

#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A32bitMasterTimer::setSynchronousInternal32(const volatile double period, const volatile bool idleStop) volatile{
#if   defined (__32MX__)
    
    /*  resetto il timer slave associato                                        */
    m_slave->reset();
    /*  uso rawConfig con l'eventuale bit di idle                               */
    rawConfig(_TxCON_T32_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri in modalità  */
    /*  32-bit                                                                  */
    return setpar(period, System::busFrequency(), true);
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif    
}

double AFramework::A32bitMasterTimer::setSynchronousExternal32(const volatile double extFreq, const volatile double period, const volatile bool idleStop) volatile{
#if   defined (__32MX__)
    
    /*  resetto il timer slave associato                                        */
    m_slave->reset();
    /*  uso rawConfig con l'eventuale bit di idle                               */
    rawConfig(_TxCON_TCS_MASK | _TxCON_T32_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri in modalità  */
    /*  32-bit                                                                  */
    return setpar(period, extFreq, true);
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

double AFramework::A32bitMasterTimer::setGated32(const volatile double period, bool idleStop) volatile{
#if   defined (__32MX__)

    /*  resetto il timer slave associato                                        */
    m_slave->reset();
    /*  uso rawConfig con l'eventuale bit di idle                               */
    rawConfig(_TxCON_TGATE_MASK | _TxCON_T32_MASK | (idleStop ? _TxCON_SIDL_MASK : Quick::NoOne));
    /*  richiamo setpar che calcola il valore ottimo dei parametri in modalità  */
    /*  32-bit                                                                  */
    return setpar(period, System::busFrequency(), true);
    
#elif defined (__32MZ__)
#   error   Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif   
}