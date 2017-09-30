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

#include <cstring>
#include "ACore.h"
#include "AInterruptSource.h"

#define __CORE_TICK_RATE__      0x03E8
#define __STATUS_LED_H_TIME__   0x0032
#define __STATUS_LED_L_TIME__   0x03B6

/********************************************************************************/
//  CLASS ACoreTimer
/********************************************************************************/

class AFramework::System::ACoreTimer : public AFramework::AInterruptSource{
    public:
        ACoreTimer(const uint8  IFSVec, 
                   const uint8  IECVec, 
                   const uint8  IPCVec, 
                   const uint32 IFSMask, 
                   const uint32 IECMask, 
                   const uint32 IPPos, 
                   const uint32 ISPos);
        void ctopen(const volatile AFramework::uint32 p);
        void ctsync(const volatile AFramework::uint32 p);
        void ctconf(const volatile AFramework::uint32 p);
};

AFramework::System::ACoreTimer::ACoreTimer(const uint8  IFSVec, 
                                           const uint8  IECVec, 
                                           const uint8  IPCVec, 
                                           const uint32 IFSMask, 
                                           const uint32 IECMask, 
                                           const uint32 IPPos, 
                                           const uint32 ISPos) : AInterruptSource(IFSVec, 
                                                                                  IECVec,
                                                                                  IPCVec,
                                                                                  IFSMask,
                                                                                  IECMask,
                                                                                  IPPos,
                                                                                  ISPos){
}

void AFramework::System::ACoreTimer::ctopen(volatile AFramework::uint32 p){
#if   defined (__32MX__)

	/*  cancello il contenuto del registro count nel coprocessore               */
    asm volatile("mtc0   $0,$9");
    /*  setto il periodo nel registro compare del coprocessore                  */
    asm volatile("mtc0   %0,$11" : "+r"(p));

#elif defined (__32MZ__)
#   error   Core Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

void AFramework::System::ACoreTimer::ctsync(volatile AFramework::uint32 p){
#if   defined (__32MX__)

    volatile AFramework::uint32 o;
    /*  leggo il vecchio valore del registro compare dal coprocessore           */
    asm volatile("mfc0   %0, $11" : "=r"(o));
    /*  aggiorno per il nuovo match                                             */
    p += o;
    /*  setto il periodo nel registro compare del coprocessore                  */
    asm volatile("mtc0   %0,$11" : "+r"(p));

#elif defined (__32MZ__)
#   error   Core Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif    
}

void AFramework::System::ACoreTimer::ctconf(volatile AFramework::uint32 p){
#if   defined (__32MX__)

    volatile AFramework::uint32 t;
    /*  leggo il valore del registro count dal coprocessore                     */
    asm volatile("mfc0   %0, $9" : "=r"(t));
    /*  aggiorno per il nuovo match                                             */
    t += p;
    /*  setto il periodo nel registro compare del coprocessore                  */
    asm volatile("mtc0   %0,$11" : "+r"(t));

#elif defined (__32MZ__)
#   error   Core Timer module is not currently available.
#else
#   error   Unknown architecture.
#endif
}

extern "C"{
    
    void __ISR(_CORE_TIMER_VECTOR, IPL7AUTO) CoreTimerHandler(){
        /*  Aggiorno il tempo                                                   */
        AFramework::System::updateTime();
    }   

}

extern volatile AFramework::AINT_w     INT_w     __asm__("INT_w")     __attribute__((section("sfrs")));
extern volatile AFramework::ARPI_w     RPI_w     __asm__("RPI_w")     __attribute__((section("sfrs")));
extern volatile AFramework::ARPO_w     RPO_w     __asm__("RPO_w")     __attribute__((section("sfrs")));
extern volatile AFramework::ADEVSPEC_w DEVSPEC_w __asm__("DEVSPEC_w") __attribute__((section("sfrs")));

const AFramework::uint32 AFramework::System::Freq40MHz(0x02625A00U);
const AFramework::uint32 AFramework::System::Freq32KHz(0x00008000U);


AFramework::System::Segment *        AFramework::System::m_heap_head(NULL);
AFramework::System::ACoreTimer       AFramework::System::m_coreTimer(_IFSVEC_CTIF_POSITION, _IECVEC_CTIE_POSITION, _IPCVEC_CTIP_POSITION, _IFS_CTIF_MASK, _IEC_CTIE_MASK, _IPC_CTIP_POSITION, _IPC_CTIS_POSITION);
AFramework::uint32                   AFramework::System::m_ledGpio(0);
AFramework::uint32                   AFramework::System::m_toggle_delay(__STATUS_LED_L_TIME__);
AFramework::uint32                   AFramework::System::m_ct_rate(0);
double                               AFramework::System::m_pri_clock(0);
double                               AFramework::System::m_sec_clock(0);
double                               AFramework::System::m_bus_clock(0);
size_t                               AFramework::System::m_heap_size(0);
size_t                               AFramework::System::m_heap_busy(0);
size_t                               AFramework::System::m_xc32_offs(8);
bool                                 AFramework::System::m_init_flag(false);
bool                                 AFramework::System::m_toggle_flag(true);
AFramework::ATime                    AFramework::System::m_alive;
AFramework::ATime                    AFramework::System::m_toggle;
volatile AFramework::AHardwarePort * AFramework::System::m_ledPort(NULL);
volatile AFramework::AINT_w *        AFramework::System::m_int_reg(&INT_w);
volatile AFramework::ARPI_w *        AFramework::System::m_rpi(&RPI_w);
volatile AFramework::ARPO_w *        AFramework::System::m_rpo(&RPO_w);
volatile AFramework::ADEVSPEC_w *    AFramework::System::m_dev(&DEVSPEC_w);

/********************************************************************************/
//  Global Operators
/********************************************************************************/

void * operator new(size_t size){
    return AFramework::System::malloc(size);
}

void * operator new[](size_t size){
    return AFramework::System::malloc(size);
}

void operator delete(void* addr){
    AFramework::System::free(addr);
}

void operator delete[](void* addr){
    AFramework::System::free(addr);
}

/********************************************************************************/
//  CLASS Segment
/********************************************************************************/

class AFramework::System::Segment{
    public:
        void    *   data ();
        Segment *   vNext();
        uint32      m_stat : 0x01;
        uint32      m_size : 0x1F;
        Segment *   m_next;
};

void * AFramework::System::Segment::data(){
    /*  Per evitare di inserire nella classe un altro campo (il puntatore void  */
    /*  data) ho preferito dare direttamente l'indirizzo calcolandolo in fun-   */
    /*  zione dell'offset di memoria. Sommando 1 all'indirizzo di m_next che è  */
    /*  di tipo void * (4 bytes) mi sposto di 4 bytes in memoria, successiva-   */
    /*  mente restituisco l'indirizzo come void *.                              */
    return (reinterpret_cast<void *>(&m_next + 1));
}

AFramework::System::Segment * AFramework::System::Segment::vNext(){
    /*  Calcolo l'indirizzo virtuale a cui dovrebbe trovarsi ipoteticamente il  */
    /*  prossimo blocco: partendo da data() che fornisce la memoria utile allo  */
    /*  utilizzatore aggiungo un offset di size() bytes.                        */
    return (reinterpret_cast<Segment *>(reinterpret_cast<uint32>(data()) + m_size));
}

/********************************************************************************/
//  CLASS System
/********************************************************************************/

bool AFramework::System::init(size_t heapSize, volatile AHardwarePort * ledPort, const uint32 ledGpio, const double & systemClock, const double & peripheralClock, const double & secondaryOsc){
    /*  Controllo che la funzione non sia già stata chiamata                    */
    if(m_init_flag){
        /*  in questo caso restituisco false                                    */
        return false;
    }
    /*  se heapSize non è abbastanza grande da permettere l'allocazione di al-  */
    /*  meno un intero                                                          */
    if(heapSize < m_xc32_offs + sizeof(Segment) + 4){
        /*  ritorno false (pena underflow)                                      */
        return false;
    }
    /*  se il clock di sistema è zero                                           */
    if(!systemClock){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se il clock del bus delle periferiche è zero                            */
    if(!peripheralClock){
        /*  ritorno false                                                       */
        return false;
    }
    /*  se il bit passato per il led non è valido                               */
    if((ledGpio == 0) || (ledGpio & (ledGpio - 1)) || ledGpio > bit15){
        /*  ritorno false                                                       */
        return false;
    }
    /*  Sottraggo alla dimensione dell'heap passata l'overhead del compilatore  */
    heapSize -= m_xc32_offs;
    /*  Provo ad allocare tutto l'heap alla testa della lista                   */
    m_heap_head = static_cast<Segment *>(std::malloc(heapSize));
    /*  Se la testa è NULL allora l'allocazione è fallita                       */
    if(!m_heap_head){
        /*  Ed in questo caso restituisco false                                 */
        return false;
    }
    /*  Se l'allocazione è riuscita setto la dimensione dell'heap reale         */
    m_heap_size = heapSize;
    /*  e azzero la memoria                                                     */
    memset(m_heap_head, 0x00, heapSize);
    /*  Imposto il blocco come libero                                           */
    m_heap_head->m_stat = 0;
    /*  Imposto la dimensione del blocco                                        */
    m_heap_head->m_size = m_heap_size - sizeof(Segment);
    /*  Aggiorno lo spazio occupato                                             */
    m_heap_busy += sizeof(Segment);
    /*  Imposto il puntatore al blocco successivo a NULL                        */
    m_heap_head->m_next = NULL;
    /*  imposto il clock di sistema                                             */
    m_pri_clock = systemClock;
    /*  imposto l'oscillatore secondario (può andarmi bene anche zero che con-  */
    /*  sidero come non connesso)                                               */
    m_sec_clock = secondaryOsc;
    /*  imposto il clock del bus delle periferiche                              */
    m_bus_clock = peripheralClock;
    
    /*
        @todo: Thread queue is currently unimplemented
    */
    
    /*  assegno il gpio del led                                                 */
    m_ledGpio = ledGpio;
    /*  assegno la porta del led                                                */
    m_ledPort = ledPort;
    /*  se la porta è valida                                                    */
    if(m_ledPort){
        /*  setto il gpio come digitale                                         */
        m_ledPort->setDigital(m_ledGpio);
        /*  spengo l'open drain                                                 */
        m_ledPort->setStandard(m_ledGpio);
        /*  setto il gpio come uscita                                           */
        m_ledPort->setOutput(m_ledGpio);
    }
    /*  abilito l'interrupt sul timer della cpu                                 */
    m_coreTimer.enableInterrupt(Ip7);
    /*  imposto il valore da mettere nel timer della cpu per onda quadra a 1KHz */
    m_ct_rate = static_cast<uint32>(m_pri_clock) / 0x02 / __CORE_TICK_RATE__;
    /*  Imposto il flag di avvenuta inizializzazione                            */
    m_init_flag = true;
    /*  Abilito lo scheduler                                                    */
    scwake();
    /*  inizializzo il timer della cpu                                          */
    m_coreTimer.ctopen(m_ct_rate);
    /*  abilito gli interrupt                                                   */
    enableInterrupt();
    /*  disabilito jtag                                                         */
    m_dev->CFGCON.REG = 0;
    /*  e restituisco true                                                      */
    return true;
}

void AFramework::System::kill(){

    std::free(m_heap_head);
}

bool AFramework::System::free(void * ptr){
    
    Segment *   nav = NULL;
    Segment *   pre = NULL;
    bool        flg = false;
    /*  Controllo che il framework sia stato inizializzato correttamente        */
    if(!m_init_flag){
        /*  se non è così non esiste ancora l'heap e quindi non c'è nulla da    */
        /*  liberare per cui restituisco false                                  */
        return false;
    }
    /*  Controllo che l'indirizzo non sia NULL                                  */
    if(!ptr){
        /*  in questo caso setto ritorno false                                  */
        return false;
    }
    /*  se invece tutto è stato inizializzato correttamente, disabilito lo      */
    /*  scheduler,                                                              */
    scsusp();
    /*  assegno la testa della lista ad un puntatore temporaneo                 */
    nav = m_heap_head;
    /*  e scorro la lista                                                       */
    while(nav){
        /*  se l'indirizzo passato corrisponde ad un indirizzo di memoria che   */
        /*  risiede nell'heap (scorro cercando una corrispondenza)              */
        if(nav->data() == ptr){
            /*  setto il blocco come libero                                     */
            nav->m_stat = 0;            
            /*  aggiorno lo spazio occupato                                     */
            m_heap_busy -= nav->m_size;
            /*  cancello la memoria                                             */
            memset(nav->data(), 0x00, nav->m_size);
            /*  imposto il flag per la deframmentazione a true                  */
            flg = true;
            /*  e smetto di scorrere la lista                                   */
            break;
        }
        /*  altriment sposto il puntatore precedente e continuo a scorrere      */
        pre = nav;
        nav = nav->m_next;
    }
    /*  se ho trovato corrispondenze devo deframmentare la memoria guardando    */
    /*  i blocchi precedente e successivo                                       */
    if(flg){
        /*  per cui se il precedente blocco non è NULL (questo significa che a  */
        /*  sinistra c'è qualcosa) ed inoltre non è occupato (funziona sempre   */
        /*  per lo short-evaluation, ovvero se fallisce la prima condizione     */
        /*  il secondo confronto non viene eseguito)                            */
        if(pre && pre->m_stat == 0){
            /*  sposto il puntatore temporaneo al blocco precedente             */
            nav = pre;
            /*  ricalcolo la dimensione del blocco                              */
            nav->m_size += sizeof(Segment) + nav->m_next->m_size;
            /*  aggiorno lo spazio occupato                                     */
            m_heap_busy -= sizeof(Segment);
            /*  assegno al successivo di nav il successivo del blocco eliminato */
            nav->m_next = nav->m_next->m_next;
            /*  e pulisco la memoria                                            */
            memset(nav->data(), 0x00, nav->m_size);
        }
        /*  sempre per il discorso relativo al primo if sopra adesso devo       */
        /*  controllare a destra, infatti se questo blocco è non NULL e libero  */
        /*  devo ricompattare, per cui                                          */
        if(nav->m_next && nav->m_next->m_stat == 0){
            /*  se è così, setto la dimensione di nav calcolando la nuova       */
            nav->m_size += sizeof(Segment) + nav->m_next->m_size;
            /*  aggiorno lo spazio occupato                                     */
            m_heap_busy -= sizeof(Segment);
            /*  ed al successivo di nav assegno il prossimo successivo          */
            nav->m_next = nav->m_next->m_next;
            /*  pulisco la memoria azzerandola                                  */
            memset(nav->data(), 0x00, nav->m_size);
        }
    }
    /*  riabilito lo scheduler                                                  */
    scwake();
    /*  e restituisco il valore del flag, infatti se non ho trovato corrispon-  */
    /*  denze questo sarà false, altrimenti true                                */
    return flg;
}

size_t AFramework::System::memstat(){
    /*  Nulla da commentare                                                     */
    return m_heap_size - m_heap_busy;
}

size_t AFramework::System::heapSize(){
    /*  Nulla da commentare...                                                  */
    return m_heap_size;
}

void * AFramework::System::malloc(size_t size){
    Segment *   nav = NULL;
    Segment *   seg = NULL;
    size_t      max = 0;
    bool        flg = false;
    /*  Controllo che l'heap sia stato inizializzato correttamente e che la di- */
    /*  mensione richiesta non sia zero                                         */
    if(!m_init_flag || !size){
        /*  se così non è restituisco NULL (non ho dove/cosa allocare!)         */
        return NULL;
    }
    /*  se la dimensione richiesta non raggiunge i 4 byte (indirizzamento a     */
    /*  32 bit)                                                                 */
    if(size % 4){
        /*  allineo il blocco al più vicino multiplo di 4 byte                  */
        size += (4 - (size % 4));
    }
    /*  Se invece è tutto ok disabilito lo scheduler                            */
    scsusp();
    /*  e assgno un puntatore temporaneo alla testa                             */
    nav = m_heap_head;
    /*  ed inizio a scorrere la lista                                           */
    while(nav){
        /*  se il blocco a cui sto puntando è libero                            */
        if(nav->m_stat == 0){
            /*  controllo se ne esiste uno di dimensione esatta                 */
            if(nav->m_size == size){
                /*  se trovo questo blocco lo imposto come occupato             */
                nav->m_stat = 1;
                /*  aggiorno lo spazio occupato                                 */
                m_heap_busy += size;
                /*  riabilito lo scheduler                                      */
                scwake();
                /*  e restituisco il puntatore ai dati                          */
                return nav->data();
            /*  se invece il blocco ha dimensione maggiore di quella richiesta  */
            /*  ricerco il massimo tra i blocchi liberi (facendo così evito di  */
            /*  scorrere due volte la lista)                                    */
            }else if(nav->m_size > size && nav->m_size > max){
                /*  Se trovo questo blocco, imposto un flag a true              */
                flg = true;
                /*  aggiorno la dimensione del blocco massimo                   */
                max = nav->m_size;
                /*  salvo in un puntatore temporaneo l'indirizzo di detto       */
                /*  blocco                                                      */
                seg = nav;
            }
        }
        /*  altrimenti continuo a scorrere fino a che non finisco la lista      */
        nav = nav->m_next;
    }
    /*  A navigazione ultimata, se il blocco richiesto esiste il flag sarà true */
    /*  il puntatore temporaneo seg conterrà l'indirizzo del massimo, per cui   */
    if(flg){
        /*  (solo per questione di coerenza di stile lavoro di nuovo con nav)   */
        nav = seg;
        /*  imposto la dimensione a quella richiesta                            */
        nav->m_size = size;
        /*  lo imposto come come occupato                                       */
        nav->m_stat = 1;
        /*  aggiorno lo spazio occupato                                         */
        m_heap_busy += size;
        /*  successivamente imposto il blocco successivo assegnando l'indirizzo */
        /*  calcolato a seg                                                     */
        seg = nav->vNext();
        /*  imposto il blocco come libero                                       */
        seg->m_stat = 0;
        /*  imposto il puntatore al blocco successivo al successivo di nav      */
        /*  (questo indirizzo non è stato modificato)                           */
        seg->m_next = nav->m_next;
        /*  imposto la dimensione del nuovo blocco                              */
        seg->m_size = max - size - sizeof(Segment);
        /*  aggiorno lo spazio occupato                                         */
        m_heap_busy += sizeof(Segment);
        /*  imposto il successivo di nav (il blocco allocato) a seg ricostru-   */
        /*  endo la lista                                                       */
        nav->m_next = seg;
        /*  riabilito lo scheduler                                              */
        scwake();
        /*  ed infine restituisco l'indirizzo dei dati                          */
        return nav->data();
    }
    /*  se invece il blocco richiesto non esiste riabilito lo scheduler         */
    scwake();
    /*  e restituisco NULL                                                      */
    return NULL;
}

double AFramework::System::priFrequency(){
    /*  nulla da commentare                                                     */
    return m_pri_clock;
}

double AFramework::System::priPeriod(){
    /*  per evitare eccezzioni della cpu ritorno il risultato della divisione   */
    /*  se la frequenza è diversa da zero, altrimenti zero.                     */
    return (m_pri_clock ? (1 / static_cast<double>(m_pri_clock)) : 0);
}

double AFramework::System::secFrequency(){
    /*  nulla da commentare                                                     */
    return m_sec_clock;
}

double AFramework::System::secPeriod(){
    /*  per evitare eccezzioni della cpu ritorno il risultato della divisione   */
    /*  se la frequenza è diversa da zero, altrimenti zero.                     */
    return (m_sec_clock ? (1 / static_cast<double>(m_sec_clock)) : 0);
}

double AFramework::System::busFrequency(){
    /*  nulla da commentare                                                     */
    return m_bus_clock;
}

double AFramework::System::busPeriod(){
    /*  per evitare eccezzioni della cpu ritorno il risultato della divisione   */
    /*  se la frequenza è diversa da zero, altrimenti zero.                     */
    return (m_bus_clock ? (1 / static_cast<double>(m_bus_clock)) : 0);
}

void AFramework::System::enableInterrupt(){
#if   defined (__32MX__)
    
    m_int_reg->INTCON.SET = _INTCON_MVEC_MASK;
    asm volatile("ei");
    
#elif defined (__32MZ__)
#   error   Interrupt module is not currently available.
#else
#   error   Unknown architecture.
#endif   
}

void AFramework::System::disableInterrupt(){
#if   defined (__32MX__)
    
    asm volatile("di");
    m_int_reg->INTCON.CLR = _INTCON_MVEC_MASK;
    
#elif defined (__32MZ__)
#   error   Interrupt module is not currently available.
#else
#   error   Unknown architecture.
#endif       
}

void AFramework::System::updateTime(){
    /*  aggiorno il timer della cpu                                             */
    m_coreTimer.ctsync(m_ct_rate);
    /*  incremento l'orologio di sistema                                        */
    m_alive++;
    if(m_alive - m_toggle >= m_toggle_delay){
        /*  salvo il tempo                                                      */
        m_toggle = m_alive;
        /*  inverto il flag                                                     */
        m_toggle_flag = !m_toggle_flag;
        /*  inverto il led se la porta non è null                               */
        if(m_ledPort){
            m_ledPort->latchInvert(m_ledGpio);
        }
        if(!m_toggle_flag){
            m_toggle_delay = __STATUS_LED_H_TIME__;
        }else{
            m_toggle_delay = __STATUS_LED_L_TIME__;
        }
    }
    m_coreTimer.clearFlag();
}

void AFramework::System::delay(const uint32 ms){
    
    ATime t = m_alive;
    
    while(m_alive - t < ms){
        asm volatile("nop");
    }
}

AFramework::uint32 AFramework::System::currentCentury(){
    /*  temporanea                                                              */
    return 0x14;
}

bool AFramework::System::outputMap(const uint32 gpio, const uint32 output){
    
    /*  controllo che la periferica passata sia un output                       */
    if(!(output & _OUT)){
        /*  se non così non è ritorno false                                     */
        return false;
    }
    /*  controllo che di non uscire fuori dal vettore                           */
    if((gpio & _PPS_V_POS_MASK) >= __RPOVEC_MAX__){
        /*  in questo caso ritorno false                                        */
        return false;
    }
    /*  contollo che le periferica sia compatibile con il gpio                  */
    if(!((gpio & output) & _PPS_GROUP_MASK)){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  cancello il bit iolock                                                  */
    m_dev->CFGCON.REG ^= _CFGCON_IOLOCK_MASK;
    /*  mappo l'output                                                          */
    m_rpo->RPn[gpio & _PPS_V_POS_MASK].REG = ((output & _PPS_VALUE_MASK) >> _PPS_VALUE_POSITION);
    /*  setto il bit iolock                                                     */
    m_dev->CFGCON.REG |= _CFGCON_IOLOCK_MASK;
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::System::inputMap(const uint32 gpio, const uint32 input){
    
    /*  controllo che di non uscire fuori dal vettore                           */
    if((input & _PPS_V_POS_MASK) >= __RPIVEC_MAX__){
        /*  in questo caso ritorno false                                        */
        return false;
    }
    /*  contollo che le periferica sia compatibile con il gpio                  */
    if(!((gpio & input) & _PPS_GROUP_MASK)){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  cancello il bit iolock                                                  */
    m_dev->CFGCON.REG ^= _CFGCON_IOLOCK_MASK;
    /*  mappo l'output                                                          */
    m_rpi->RPn[input & _PPS_V_POS_MASK].REG = ((gpio & _PPS_VALUE_MASK) >> _PPS_VALUE_POSITION);
    /*  setto il bit iolock                                                     */
    m_dev->CFGCON.REG |= _CFGCON_IOLOCK_MASK;
    /*  ritorno true                                                            */
    return true;
}

AFramework::ATime AFramework::System::aliveTime(){
    /*  ritorno il tempo di vita                                                */
    return m_alive;
}

void AFramework::System::scsusp(){
/*
    @todo: Scheduler suspend is currently unimplemented
*/
}

void AFramework::System::scwake(){
/*
    @todo: Scheduler wake-up is currently unimplemented
*/
}

bool AFramework::System::chkspc(size_t size, const bool& autoLock){
    Segment * nav = NULL;
    /*  controllo che il framework sia stato inizializzato correttamente e che  */
    /*  dimensione richiesta non sia zero                                       */
    if(!m_init_flag || !size){
        /*  se così non è non ho nulla da controllare e restituisco false       */
        return false;
    }
    /*  se invece tutto è ok disabilito lo scheduler                            */
    scsusp();
    /*  se la dimensione richiesta non raggiunge i 4 byte (indirizzamento a     */
    /*  32 bit)                                                                 */
    if(size % 4){
        /*  allineo il blocco al più vicino multiplo di 4 byte                  */
        size += (4 - (size % 4));
    }
    /*  assegno la testa della lista ad un puntatore temporanero                */
    nav = m_heap_head;
    /*  ed inizio a navigare la lista alla ricerca di un blocco di dimensione   */
    /*  abbastanza grande (faccio il confronto più lasco per velocizzare)       */
    while(nav){
        /*  se esiste abbastanza spazio                                         */
        if(nav->m_size >= size && !nav->m_stat){
            /*  riabilito lo scheduler se autolock è false                      */
            if(!autoLock){
                scwake();
            }
            /*  e restituisco true                                              */
            return true;
        }
        /*  altrimenti continuo a scorrere                                      */
        nav = nav->m_next;
    }
    /*  se invece il blocco di dimensione richiesta non esiste, riabilito lo    */
    /*  scheduler                                                               */
    scwake();
    /*  e restituisco false                                                     */
    return false;
}
