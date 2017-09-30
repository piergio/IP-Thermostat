

#include "AI2CDriver.h"
#include <cmath>

#if __HAS_I2C_1__    
    extern volatile AFramework::AI2C_w I2C1_w __asm__("I2C1_w") __attribute__((section("sfrs")));
    volatile AFramework::AI2CDriver AFramework::I2C1(&I2C1_w, &__SDA1_PORT__, __SDA1_GPIO__, &__SCL1_PORT__, __SCL1_GPIO__);
#endif

#if __HAS_I2C_2__
    extern volatile AFramework::AI2C_w I2C2_w __asm__("I2C2_w") __attribute__((section("sfrs")));
    volatile AFramework::AI2CDriver AFramework::I2C2(&I2C2_w, &__SDA2_PORT__, __SDA2_GPIO__, &__SCL2_PORT__, __SCL2_GPIO__);
#endif

#define __I2C_FREQ_100KHz__ 0x000186A0
#define __I2C_FREQ_400KHz__ 0x00061A80
#define __I2C_PGD_DELAY__   0.000000104

AFramework::AI2CDriver::AI2CDriver(volatile AI2C_w * w, 
                                   volatile AHardwarePort * SDAPort, 
                                   const uint32 SDA, 
                                   volatile AHardwarePort * SCLPort, 
                                   const uint32 SCL) : 
                                                        m_reg(w),
                                                        m_SDAPort(SDAPort),
                                                        m_SDA(SDA),
                                                        m_SCLPort(SCLPort),
                                                        m_SCL(SCL), 
                                                        m_flg(false){
    close();
}

bool AFramework::AI2CDriver::open(const I2CFreq freq, const bool idleStop) volatile{
    uint32 baud = 0;
    uint32 conf = _I2CxCON_ON_MASK;
    /*  Imposto il baudrate (vedi datasheet)                                    */
    baud = std::round((((1.0 / (2 * (freq == Freq100KHz ? __I2C_FREQ_100KHz__ : __I2C_FREQ_400KHz__))) - __I2C_PGD_DELAY__) * System::busFrequency()) - 2);
    /*  se la frequenza di clock e' 100KHz                                      */
    if(freq == Freq100KHz){
        /*  abilito il controllo sullo slew-rate                                */
        conf |= _I2CxCON_DISSLW_MASK;
    }
    /*  se deve essere stoppato in idle                                         */
    if(idleStop){
        /*  imposto il bit                                                      */
        conf |= _I2CxCON_SIDL_MASK;
    }
    /*  se per qualche motivo assurdo non riesco a settare i pin come digitali  */   
    if(!m_SDAPort->setDigital(m_SDA) || !m_SCLPort->setDigital(m_SCL)){
        /*  ritorno false                                                       */
        return false;
    }
    /*  Metto basso SDA                                                         */
    m_SDAPort->write(m_SDA, Lo);
    /*  Metto basso SCL                                                         */
    m_SCLPort->write(m_SCL, Lo);
    /*  Pulisco il registro I2CxCON                                             */
    m_reg->I2CxCON.CLR = Quick::All;
    /*  Pulisco il registro I2CxBRG                                             */
    m_reg->I2CxBRG.CLR = Quick::All;
    /*  Imposto il baudrate                                                     */
    m_reg->I2CxBRG.SET = baud;
    /*  Scrivo la configurazione è accendo il modulo                            */
    m_reg->I2CxCON.REG = conf;
    /*  imposto il flag di open a true                                          */
    m_flg = true;
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AI2CDriver::isOpen() volatile{
    /*  ritorno il flag                                                         */
    return m_flg;
}

void AFramework::AI2CDriver::close() volatile{
    /*  Cancello il contenuto del registro I2CxCON                              */
    m_reg->I2CxCON.CLR  = Quick::All;
    /*  Cancello il contenuto del registro I2CxSTAT                             */
    m_reg->I2CxSTAT.CLR = Quick::All;
    /*  Cancello il contenuto del registro I2CxADD                              */
    m_reg->I2CxADD.CLR  = Quick::All;
    /*  Cancello il contenuto del registro I2CxMSK                              */
    m_reg->I2CxMSK.CLR  = Quick::All;
    /*  Cancello il contenuto del registro I2CxTRN                              */
    m_reg->I2CxTRN.CLR  = Quick::All;
}

bool AFramework::AI2CDriver::start() volatile{
    /*  se il modulo non è attivo                                               */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  abilito l'invio della sequenza di start                                 */
    m_reg->I2CxCON.SET = _I2CxCON_SEN_MASK;
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che la sequenza di start sia stata inviata                      */
    while(m_reg->I2CxCON.isHi(_I2CxCON_SEN_MASK));
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AI2CDriver::stop() volatile{
    /*  se il modulo non è attivo                                               */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  abilito l'invio della sequenza di stop                                  */
    m_reg->I2CxCON.SET = _I2CxCON_PEN_MASK;
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che la sequenza di start sia stata inviata                      */
    while(m_reg->I2CxCON.isHi(_I2CxCON_PEN_MASK));
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AI2CDriver::restart() volatile{
    /*  se il modulo non è attivo                                               */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  abilito l'invio della sequenza di stop                                  */
    m_reg->I2CxCON.SET = _I2CxCON_RSEN_MASK;
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che la sequenza di start sia stata inviata                      */
    while(m_reg->I2CxCON.isHi(_I2CxCON_RSEN_MASK));
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AI2CDriver::write(const uint8 data) volatile{
    /*  se il modulo non è attivo                                               */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  Scrivo il dato nel registro transmit                                    */
    m_reg->I2CxTRN.REG = static_cast<uint32>(data);
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che avvenga la trasmissione                                     */
    while(m_reg->I2CxSTAT.REG &_I2CxSTAT_TRSTAT_MASK);
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che il buffer si sia svuotata                                   */
    while(m_reg->I2CxSTAT.REG & (_I2CxSTAT_TBF_MASK));
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto l'ack                                                           */
    while(m_reg->I2CxSTAT.REG & (_I2CxSTAT_ACKSTAT_MASK));
    /*  ritorno true                                                            */
    return true;
}

AFramework::uint8 AFramework::AI2CDriver::read() volatile{
    /*  abilito la ricezione                                                    */
    m_reg->I2CxCON.SET = _I2CxCON_RCEN_MASK;
    /*  piccolo delay                                                           */
 //   asm volatile("nop");
    /*  aspetto che la ricezione completata                                     */
    while(m_reg->I2CxCON.REG &(_I2CxCON_RCEN_MASK));
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che il buffer di ricezione sia pieno                            */
    while(!(m_reg->I2CxSTAT.REG & _I2CxSTAT_RBF_MASK));
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  ritorno il dato opportunamente troncato                                 */
    return static_cast<uint8>(m_reg->I2CxRCV.REG & 0xFF);
}

bool AFramework::AI2CDriver::nack() volatile{
    /*  se il modulo non è attivo                                               */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  imposto il bit per la trasmissione di un nack                           */
    m_reg->I2CxCON.SET = _I2CxCON_ACKDT_MASK;
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  avvio la trasmissione del nack                                          */
    m_reg->I2CxCON.SET = _I2CxCON_ACKEN_MASK;
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che la sequenza sia stata inviata                               */
    while(m_reg->I2CxCON.isHi(_I2CxCON_ACKEN_MASK));
    /*  ritorno true                                                            */
    return true;
}

bool AFramework::AI2CDriver::ack() volatile{
    /*  se il modulo non è attivo                                               */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  imposto il bit per la trasmissione di un nack                           */
    m_reg->I2CxCON.CLR = _I2CxCON_ACKDT_MASK;
    /*  piccolo delay                                                           */
 //   asm volatile("nop");
    /*  avvio la trasmissione del nack                                          */
    m_reg->I2CxCON.SET = _I2CxCON_ACKEN_MASK;
    /*  piccolo delay                                                           */
//    asm volatile("nop");
    /*  aspetto che la sequenza sia stata inviata                               */
    while(m_reg->I2CxCON.isHi(_I2CxCON_ACKEN_MASK));
    /*  ritorno true                                                            */
    return true;
}