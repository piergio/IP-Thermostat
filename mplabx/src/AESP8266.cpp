
#include "AESP8266.h"

#define __ESP_AT_TEST       "AT"
#define __ESP_AT_RST        "AT+RST"
#define __ESP_AT_ECHO_ON    "ATE1"
#define __ESP_AT_ECHO_OFF   "ATE0"
#define __ESP_AT_FIRMWARE   "AT+GMR"
#define __ESP_AT_MODE       "AT+CWMODE="
#define __ESP_AT_CONF_AP    "AT+CWSAP="
#define __ESP_AT_JOIN_AP    "AT+CWJAP="
#define __ESP_AT_LEAVE_AP   "AT+CWQAP"
#define __ESP_AT_LIST_AP    "AT+CWLAP"
#define __ESP_AT_DHCP       "AT+CWDHCP="
#define __ESP_AT_IP_AP      "AT+CIPAP"
#define __ESP_AT_IP_ST      "AT+CIPSTA"
#define __ESP_AT_MUX        "AT+CIPMUX="
#define __ESP_AT_SERVER     "AT+CIPSERVER="
#define __ESP_AT_TIMEOUT    "AT+CIPSTO="
#define __ESP_AT_DATA       "+IPD,"
#define __ESP_AT_SEND       "AT+CIPSEND="

#define __ESP_AT_OK         "OK"
#define __ESP_AT_READY      "ready"
#define __ESP_AT_ERROR      "ERROR"
#define __ESP_AT_FAIL       "FAIL"


AFramework::AESP8266::AESP8266(AUARTDriver * driver, const AUARTDriver::Baud baud) : m_driver(NULL), m_flg(false){
    /*  se il puntatore al driver è valido                                      */
    if(driver){
        /*  assegno il puntatore                                                */
        m_driver = driver;
        /*  se la seriale è chiusa                                              */
        if(!m_driver->isOpen()){
            /*  la apro ed assegno il risulato della open al flag               */
            m_flg = m_driver->open(baud, AUARTDriver::Data8bitNoParity, AUARTDriver::Stop1bit);
        }else{
            /*  se invece è aperta salvo sul flag il risultato del confronto    */
            /*  tra il baud passato e quello corrente                           */
            m_flg = (m_driver->baud() == baud);
        }
    }
}

bool AFramework::AESP8266::isOk(const uint32 ms) const{
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(__ESP_AT_TEST);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP8266::reset(const uint32 ms) const{
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(__ESP_AT_RST);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_READY, ms);
}

bool AFramework::AESP8266::setEcho(const bool echo, const uint32 ms) const{
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln((echo ? __ESP_AT_ECHO_ON : __ESP_AT_ECHO_OFF));
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);    
}

bool AFramework::AESP8266::version(AString & str, const uint32 ms) const{
    bool res = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(__ESP_AT_FIRMWARE);
    /*  salvo il risultato del WDT                                              */
    res = wdttmr(__ESP_AT_OK, ms);
    /*  se il flag è ok                                                         */
    if(res){
        str = m_driver->read();
        while(str.remove(__ESP_AT_OK) || str.remove(" ") || str.remove("\r") || str.remove("\n"));
    }
    return res;
}

bool AFramework::AESP8266::setMode(const ESPMode mode, const bool rst, const uint32 ms) const{
    AString str = __ESP_AT_MODE;
    bool res = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    m_driver->bufferClear();
    switch(mode){
        case StationMode:
        case APMode:
        case BothMode:
            str += static_cast<char>(mode + 0x30);
            break;
        default:
            return false;
            break;
    }
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  salvo il risultato del WDT                                              */
    res = wdttmr(__ESP_AT_OK, ms);
    /*  se non deve essere resettato o l'operazione è fallita                   */
    if(!rst){
        /*  ritorno il risultato di del WDT                                     */
        return res;
    }
    /*  se l'operazione precedente è andata male                                */
    if(!res){
        /*  ritorno false                                                       */
        return res;
    }
    /*  ritorno il risultato di reset                                           */
    return reset();
}

bool AFramework::AESP8266::configureAP(const AString & ssid, const AString & pwd, const uint8 channel, const uint32 ms) const{
    AString str = __ESP_AT_CONF_AP;
    /*  controllo che il canale sia valido e che la seriale sia ok              */
    if(channel > 0x0B || !m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  accodo il nome                                                          */
    str += "\"";
    str += ssid;
    /*  accodo la password                                                      */
    str += "\",\"";
    str += pwd;
    /*  accodo il canale                                                        */
    str += "\",";
    str += static_cast<char>(channel + 0x30);
    /*  accodo il tipo di cifratura                                             */
    str += ",";
    str += (pwd.isEmpty() ? static_cast<char>(0 + 0x30) : static_cast<char>(4 + 0x30));
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms); 
}

bool AFramework::AESP8266::joinAP(const AString & ssid, const AString & pwd, const uint32 ms) const{
    AString str = __ESP_AT_JOIN_AP;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  accodo il nome                                                          */
    str += "\"";
    str += ssid;
    /*  accodo la password                                                      */
    str += "\",\"";
    str += pwd;
    /*  accodo il canale                                                        */
    str += "\"";
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);    
}

bool AFramework::AESP8266::leaveAP(const uint32 ms) const{
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(__ESP_AT_LEAVE_AP);
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);  
}

bool AFramework::AESP8266::availableAP(AString & res, const uint32 ms) const{
    bool flag = false;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(__ESP_AT_LIST_AP);
    /*  salvo il risultato del WDT                                              */
    flag = wdttmr(__ESP_AT_OK, ms);
    /*  salvo il buffer                                                         */
    res = m_driver->read();
    /*  ritorno il flag                                                         */
    return flag;
}

bool AFramework::AESP8266::setDhcp(const bool en, const ESPMode mode, const uint32 ms) const{
    
    AString str = __ESP_AT_DHCP;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  controllo la modalità                                                   */
    switch(mode){
        
        case StationMode:
            
            str += AString(static_cast<sint32>(1));
            break;
            
        case APMode:
            
            str += AString(static_cast<sint32>(0));
            break;
            
        case BothMode:
            
            str += AString(static_cast<sint32>(2));
            break;
        default:
            
            return false;
    }
    
    str += ",";
    
    if(en){
    
        str += "0";
    }else{
        
        str += "1";
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);  
}

bool AFramework::AESP8266::setIp(const AString &addr, const ESPMode mode , const uint32 ms) const{
    
    AString str; 
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  controllo la modalità                                                   */
    switch(mode){
        
        case StationMode:
            
            str += __ESP_AT_IP_ST;
            break;
            
        case APMode:
            
            str += __ESP_AT_IP_AP;
            break;
           
        default:
            
            return false;
    }
    str += "=\"";
    str += addr;
    str += "\"";
    
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);  
}

bool AFramework::AESP8266::ip(AString &addr, const ESPMode mode, const uint32 ms) const{
    bool flag = false;
    AString str; 
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    /*  controllo la modalità                                                   */
    switch(mode){
        
        case StationMode:
            
            str += __ESP_AT_IP_ST;
            break;
            
        case APMode:
            
            str += __ESP_AT_IP_AP;
            break;
           
        default:
            
            return false;
    }
    
    str += "?";
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    flag = wdttmr(__ESP_AT_OK, ms); 
    
    if(!flag){
        
        return false;
    }
    
    str.clear();
    str = m_driver->read();
        switch(mode){
        
        case StationMode:
            
            str.remove("+CIPSTA:");
            break;
            
        case APMode:
            
            str.remove("+CIPAP:");
            break;
           
        default:
            
            return false;
    }
    while(str.remove("\n") || str.remove("\r") || str.remove("OK") || str.remove("\""));
    
    addr = str;
    return true;
}

bool AFramework::AESP8266::setMultipleConnections(const bool en, const uint32 ms) const{
    
    AString str = __ESP_AT_MUX;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    if(en){
        
        str += "1";
    }else{
        
        str += "0";
    }
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP8266::openServer(const uint16 port, const uint32 timeout, const uint32 ms)const{
    
    bool flag = false;
    AString str = __ESP_AT_SERVER;
    /*  controllo che la seriale sia ok                                         */
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    
    str += "1,";
    str += AString(static_cast<sint32>(port));
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    flag = wdttmr(__ESP_AT_OK, ms);
    if(!flag){
        return false;
    }
    str.clear();
    str = __ESP_AT_TIMEOUT;
    str += AString(static_cast<sint32>(timeout));
    /*  pulisco il buffer                                                       */
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(str.c_str());
    /*  ritorno il risultato del WDT                                            */
    return wdttmr(__ESP_AT_OK, ms);
}

bool AFramework::AESP8266::prepareForReceive() const{
    
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
    m_driver->bufferClear();
    return true;
}

bool AFramework::AESP8266::waitForData(AString &str, const uint32 ms) const{
    
    AString tmp;
    if(!m_flg){
        /*  se non è così ritorno false                                         */
        return false;
    }
       
    if(wdttmr(__ESP_AT_DATA, ms / 2) && wdttmr("\r\n", ms / 2)){
        
        tmp = m_driver->read();
        m_driver->bufferClear();
        tmp.remove(__ESP_AT_DATA);
        while(tmp.remove("\n") || tmp.remove("\r"));
        tmp = tmp.right(tmp.indexOf(":") + 1);
        str = tmp.left(tmp.size() - 2);
        return true;
    }
    return false;

}

bool AFramework::AESP8266::send(const AString &str, const uint8 numConn) const{

    AString tmp = __ESP_AT_SEND;
    if(!m_flg || numConn > 4){
        /*  se non è così ritorno false                                         */
        return false;
    }
    //tmp += AString(static_cast<sint32>(numConn));
    tmp += "0";
    tmp += ",";
    tmp += AString(static_cast<sint32>(str.size()));
    m_driver->bufferClear();
    m_driver->writeln(tmp.c_str());
    if(wdttmr(">", 1000)){
        
        m_driver->bufferClear();
        m_driver->write(str.c_str());
        return wdttmr(__ESP_AT_OK, 1000); 
    }
    return false;
}

bool AFramework::AESP8266::wdttmr(const char * str, const uint32 ms) const{
    bool res1 = false;
    bool res2 = false;
    /*  prendo il tempo di sistema                                              */
    ATime deadline = System::aliveTime();
    /*  aggiungo il timeout                                                     */
    deadline += ms;
    /*  fino a che il tempo non è scaduto                                       */
    while(System::aliveTime() <= deadline){
        /*  controllo che nel buffer ci sia la stringa cercata                  */
        res1 = m_driver->bufferContains(str);
        /*  controllo che nel buffer ci sia FAIL oppure ERROR                   */
        res2 = (m_driver->bufferContains(__ESP_AT_FAIL) || 
                m_driver->bufferContains(__ESP_AT_ERROR));
        
        /*  se ho trovato il token                                              */
        if(res1){
            /*  esco dal loop                                                   */
            break;
        }
        /*  se il buffer contiene fail o error                                  */
        if(res2){
            /*  ritorno subito false                                            */
            return false;
        }
    }
    /*  ritorno il flag                                                         */
    return res1;
}
