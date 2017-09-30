            
#include "ACore.h"
#include "A24LC512.h"
#include "AUARTDriver.h"


#define _24LC512_LOW_ADDRESS_MASK   0x07

#define _24LC512_UPPER_ADDRESS      0xA0

#define _24LC512_READ_ADDRESS       (m_address | 0x01)
#define _24LC512_WRITE_ADDRESS      m_address

#define _24LC512_UPPER_ADDRESS_MASK 0xFF00
#define _24LC512_LOWER_ADDRESS_MASK 0x00FF


AFramework::A24LC512::A24LC512(volatile AI2CDriver * driver, const uint8 lowAddress) : m_driver(NULL){
    /*  assegno il driver dell'i2c                                              */
    m_driver = driver;
    /*  se il driver non è NULL e non è aperto                                  */
    if(m_driver && !driver->isOpen()){
        /*  lo apro a frequenza 100KHz                                          */
        driver->open(AI2CDriver::Freq100KHz);
    }
    /*  imposto l'indirizzo                                                     */
    m_address = _24LC512_UPPER_ADDRESS | (lowAddress & _24LC512_LOW_ADDRESS_MASK);
}

char AFramework::A24LC512::read(const uint16 address){
    char res = 0x00;
    /*  controllo che il puntatore al driver sia valido                         */
    if(!m_driver){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo in scrittura                                         */
    m_driver->write(_24LC512_WRITE_ADDRESS);
    /*  imposto gli MSB dell'indirizzo                                          */
    m_driver->write(static_cast<uint8>((address & _24LC512_UPPER_ADDRESS_MASK) >> 0x08));
    /*  imposto gli LSB dell'indirizzo                                          */
    m_driver->write(static_cast<uint8>(address & _24LC512_LOWER_ADDRESS_MASK));
    /*  mando la sequenza di restart                                            */
    m_driver->restart();
    /*  scrivo l'indirizzo in lettura                                           */
    m_driver->write(_24LC512_READ_ADDRESS);
    /*  leggo il dato                                                           */
    res = m_driver->read();
    /*  mando il nack                                                           */
    m_driver->nack();
    /*  mando la sequenza di stop                                               */
    m_driver->stop();
    /*  ritorno il risulato                                                     */
    return res;
}

bool AFramework::A24LC512::read(const uint16 address, AString & str){

    char res = 0x00;
    /*  controllo che il puntatore al driver sia valido                         */
    if(!m_driver){
        /*  se non è così ritorno false                                         */
        return false;
    }
    uint16 prova = address;
    
    while((res = read(prova++)) != '\0'){
        
        str += res;
    }
    return str.good();
    
    
    
    /*  Inizio la trasmissione                                                  */
//    m_driver->start();
//    /*  scrivo l'indirizzo in scrittura                                         */
//    m_driver->write(_24LC512_WRITE_ADDRESS);
//    /*  imposto gli MSB dell'indirizzo                                          */
//    m_driver->write(static_cast<uint8>((address & _24LC512_UPPER_ADDRESS_MASK) >> 0x08));
//    /*  imposto gli LSB dell'indirizzo                                          */
//    m_driver->write(static_cast<uint8>(address & _24LC512_LOWER_ADDRESS_MASK));
//    /*  mando la sequenza di restart                                            */
//    m_driver->restart();
//    /*  scrivo l'indirizzo in lettura                                           */
//    m_driver->write(_24LC512_READ_ADDRESS);
//    /*  fino a che non trovo la terminazione                                    */
//    while((res = m_driver->read()) != '\0'){
//        /*  accodo il carattere                                                 */
//        str += res;
//        /*  mando la sequenza di ack                                            */
//        m_driver->ack();
//    }
//    /*  mando la sequenza di nack                                               */
//    m_driver->nack();
//    /*  mando la sequenza di stop                                               */
//    m_driver->stop();
//    /*  ritorno lo stato della stringa                                          */    
//    return str.good();
}

bool AFramework::A24LC512::write(const uint16 address, const char data){
    /*  controllo che il puntatore al driver sia valido                         */
    if(!m_driver){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  Inizio la trasmissione                                                  */
    m_driver->start();
    /*  scrivo l'indirizzo in scrittura                                         */
    m_driver->write(_24LC512_WRITE_ADDRESS);
    /*  imposto gli MSB dell'indirizzo                                          */
    m_driver->write(static_cast<uint8>((address & _24LC512_UPPER_ADDRESS_MASK) >> 0x08));
    /*  imposto gli LSB dell'indirizzo                                          */
    m_driver->write(static_cast<uint8>(address & _24LC512_LOWER_ADDRESS_MASK));
    /*  scrivo il dato                                                          */
    m_driver->write(static_cast<uint8>(data));
    /*  mando la sequenza di stop                                               */
    m_driver->stop();
    /*  delay di 10 ms (altrimenti problemi :) )                                */
    System::delay(10);
    /*  ritorno true                                                            */
    return true;    
}

bool AFramework::A24LC512::write(uint16 address, const AString & str){
    /*  se la stringa è vuota o il puntatore al driver non è valido             */
    if(str.isEmpty() || !m_driver){
        /*  ritorno false                                                       */
        return false;
    }
    /*  per tutta la lunghezza della stringa                                    */
    for(uint32 i = 0; i < str.size(); i++){
        /*  scrivo i caratteri                                                  */
        write(address++, static_cast<uint8>(str[i]));
    }
    /*  scrivo la terminazione                                                  */
    write(address, '\0');
    /*  ritorno true                                                            */
    return true;
}
