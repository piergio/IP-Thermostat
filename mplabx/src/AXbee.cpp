#include "AXbee.h"

/*      SETTINGS PAN COORDINATOR
 * ATCE = 1
 * ATDH = 0
 * ATDL = FFFF
 * ATJV = 0
 * ATJN = 1                                                                     */
#define __XBEE_COORDINATOR  "ATCE1"

/*      SETTINGS ROUTER
 * ATCE = 0
 * ATDH = 0
 * ATDL = 0
 * ATJV = 1
 * ATJN = 0                                                                     */
#define __XBEE_ROUTER       "ATCE0"

#define __XBEE_AT_TEST      "AT"    /*  Test modulo                             */
#define __XBEE_AT_COMMAND   "+++"   /*  Entra nella modalità di comando AT      */
#define __XBEE_AT_AP        "ATAP"  /*  Modalità di comando [ATAP0 Trasparent]  */
#define __XBEE_AT_PANID     "ATID"  /*  E' unico per tutta la famiglia          */
#define __XBEE_AT_DD        "ATDD"  /*  E' unico per tutta la famiglia          */
#define __XBEE_AT_NI        "ATNI"  /*  Stringa identificatrice del nodo        */
#define __XBEE_AT_CE        "ATCE"  /*  Abilita la modalità PAN Coordinator     */
#define __XBEE_AT_DH        "ATDH"  /*  Setta l'indirizzo alto di destinazione  */
#define __XBEE_AT_DL        "ATDL"  /*  Setta l'indirizzo basso di destinazione */
#define __XBEE_AT_JV        "ATJV"  /*  Abilita la ricerca di un Coordinator    */
#define __XBEE_AT_JN        "ATJN"  /*  Abilita l'invio di trame in broadcast   */
#define __XBEE_AT_DISCOVER  "ATND"  /*  Ricerca globale o di un nodo specifico  */
#define __XBEE_AT_SAVE      "ATWR"  /*  Scrive le modifiche                     */
#define __XBEE_AT_APPLY     "ATAC"  /*  Applica le modifiche                    */
#define __XBEE_AT_EXIT      "ATCN"  /*  Esce dalla modalità di comando AT       */
#define __XBEE_AT_TIMOUT    "ATCT"  /*  Setta il timeout prima di uscire 
                                        automaticamente dalla modalità comando  */

#define __XBEE_AT_OK        "OK"
#define __XBEE_AT_ERROR     "ERROR"

AFramework::AXbee::AXbee(AUARTDriver * driver, const AUARTDriver::Baud baud) : m_driver(NULL), m_flg(false){
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

bool AFramework::AXbee::initXbee(const uint32 ms) const{
    
    AString panID =         __XBEE_AT_PANID;
    AString deviceFamily =  __XBEE_AT_DD;
    AString apMode =        __XBEE_AT_AP;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    bool res4 = false;
    bool res5 = false;
    
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    if(enterATcommand()){
        
        m_driver->bufferClear();
        panID += "22";
        m_driver->writeln(panID.c_str());
        res1 = wdttmr(__XBEE_AT_OK, ms);
        deviceFamily += "A0000";
        m_driver->writeln(deviceFamily.c_str());
        res2 = wdttmr(__XBEE_AT_OK, ms);
        apMode += "0";
        m_driver->writeln(apMode.c_str());
        res3 = wdttmr(__XBEE_AT_OK, ms);
        
        /* scrivo la configurazione e applico le modifiche */
        m_driver->writeln(__XBEE_AT_SAVE);
        res4 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(__XBEE_AT_APPLY);
        res5 = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /*  se le operazioni non sono andate a buon fine                        */
        if(!res1 || !res2 || !res3){
            /*  ritorno false                                                   */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::isOk(const uint32 ms) const{
    
    bool res = false;
    
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    
    if(enterATcommand()){
        
        /*  pulisco il buffer                                                   */
        m_driver->bufferClear();
        /*  scrivo sulla seriale il comando                                     */
        m_driver->writeln(__XBEE_AT_TEST);
        /*  verifico il risultato del WDT                                       */
        res = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /* se l'operazione non è andata a buon fine                             */
        if(!res){
            /* ritorno false                                                    */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::enterATcommand(const uint32 ms) const{
    
    bool res = false;
    
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    m_driver->bufferClear();
    m_driver->write(__XBEE_AT_COMMAND);
    /*  salvo il risultato del WDT                                              */
    res = wdttmr(__XBEE_AT_OK, ms);
    /* se l'operazione non è andata bene                                        */
    if(!res){
        /* ritorno false                                                        */
        return false;
    }
    return true;
}

bool AFramework::AXbee::exitATcommand(const uint32 ms) const{
    
    bool res = false;
    
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    m_driver->bufferClear();
    m_driver->write(__XBEE_AT_EXIT);
    /*  salvo il risultato del WDT                                              */
    res = wdttmr(__XBEE_AT_OK, ms);
    /* se l'operazione non è andata a buon fine                                 */
    if(!res){
        /* ritorno false                                                        */
        return false;
    }
    return true;
}
bool AFramework::AXbee::setMode(const XbeeMode mode, AString name, const uint32 ms) const{
    
    AString job;
    AString identifier = __XBEE_AT_NI;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    bool res4 = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    
    if(enterATcommand()){
        m_driver->bufferClear();
        switch(mode){
            case CoordMode:
                
                job = __XBEE_COORDINATOR;
                break;
            case RouterMode:
                
                job = __XBEE_ROUTER;
                break;
            default:
                return false;
                break;
        }
        identifier += name;
        /*  scrivo sulla seriale il comando                                     */
        m_driver->writeln(job.c_str());
        res1 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(identifier.c_str());
        res2 = wdttmr(__XBEE_AT_OK, ms);
        
        /* scrivo la configurazione e applico le modifiche                      */
        m_driver->writeln(__XBEE_AT_SAVE);
        res3 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(__XBEE_AT_APPLY);
        res4 = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /*  se le operazioni non sono andate a buon fine                        */
        if(!res1 || !res2 || !res3 || !res4){
            /*  ritorno false                                                   */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::setDestHigh(const XbeeMode mode, const uint32 ms) const{
    
    AString str = __XBEE_AT_DH;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    
    if(enterATcommand()){
        m_driver->bufferClear();
        switch(mode){
            case CoordMode:
                str += "0";
                break;
            case RouterMode:
                str += "0";
                break;
            default:
                return false;
                break;
        }
        /*  scrivo sulla seriale il comando                                     */
        m_driver->writeln(str.c_str());
        res1 = wdttmr(__XBEE_AT_OK, ms);
        
        /* scrivo la configurazione e applico le modifiche                      */
        m_driver->writeln(__XBEE_AT_SAVE);
        res2 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(__XBEE_AT_APPLY);
        res3 = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /*  se le operazioni non sono andate a buon fine                        */
        if(!res1 || !res2 || !res3){
            /*  ritorno false                                                   */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::setDestLow(const XbeeMode mode, const uint32 ms) const{
    
    AString str = __XBEE_AT_DL;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    
    if(enterATcommand()){
        m_driver->bufferClear();
        switch(mode){
            case CoordMode:
                str += "FFFF";
                break;
            case RouterMode:
                str += "0";
                break;
            default:
                return false;
                break;
        }
        /*  scrivo sulla seriale il comando                                     */
        m_driver->writeln(str.c_str());
        res1 = wdttmr(__XBEE_AT_OK, ms);
        
        /* scrivo la configurazione e applico le modifiche                      */
        m_driver->writeln(__XBEE_AT_SAVE);
        res2 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(__XBEE_AT_APPLY);
        res3 = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /*  se le operazioni non sono andate a buon fine                        */
        if(!res1 || !res2 || !res3){
            /*  ritorno false                                                   */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::joinNotification(const XbeeMode mode, const uint32 ms) const{
    
    AString str = __XBEE_AT_JN;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    
    if(enterATcommand()){
        
        switch(mode){
            m_driver->bufferClear();
            case CoordMode:
                str += "1";
                break;
            case RouterMode:
                str += "0";
                break;
            default:
                return false;
                break;
        }
        /*  scrivo sulla seriale il comando                                     */
        m_driver->writeln(str.c_str());
        res1 = wdttmr(__XBEE_AT_OK, ms);
        
        /* scrivo la configurazione e applico le modifiche                      */
        m_driver->writeln(__XBEE_AT_SAVE);
        res2 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(__XBEE_AT_APPLY);
        res3 = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /*  se le operazioni non sono andate a buon fine                        */
        if(!res1 || !res2 || !res3){
            /*  ritorno false                                                   */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::joinVerification(const XbeeMode mode, const uint32 ms) const{
    
    AString str = __XBEE_AT_JV;
    bool res1 = false;
    bool res2 = false;
    bool res3 = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    
    if(enterATcommand()){
        
        switch(mode){
            m_driver->bufferClear();
            case CoordMode:
                str += "0";
                break;
            case RouterMode:
                str += "1";
                break;
            default:
                return false;
                break;
        }
        /*  scrivo sulla seriale il comando                                     */
        m_driver->writeln(str.c_str());
        res1 = wdttmr(__XBEE_AT_OK, ms);
        
        /* scrivo la configurazione e applico le modifiche                      */
        m_driver->writeln(__XBEE_AT_SAVE);
        res2 = wdttmr(__XBEE_AT_OK, ms);
        m_driver->writeln(__XBEE_AT_APPLY);
        res3 = wdttmr(__XBEE_AT_OK, ms);
        
        exitATcommand();
        /*  se le operazioni non sono andate a buon fine                        */
        if(!res1 || !res2 || !res3){
            /*  ritorno false                                                   */
            return false;
        }
    }
    return true;
}

bool AFramework::AXbee::nodeDiscover(const uint32 ms) const{
    
    AString str;
    bool res1 = false;
    bool res2 = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    enterATcommand();
    m_driver->bufferClear();
    /*  scrivo sulla seriale il comando                                         */
    m_driver->writeln(__XBEE_AT_DISCOVER);
    
    res1 = wdttmr("slave1", ms);
    res2 = wdttmr("slave2", ms);
    
    exitATcommand();
    /*  se le operazioni non sono andate a buon fine                            */ 
    if(!res1 || !res2){
        /* ritorno false                                                        */
        return false;
    }
    return true;
}

bool AFramework::AXbee::send(const AString &str){
    
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    m_driver->bufferClear();
    m_driver->writeln(str.c_str());    
    return true;
}

/*
 *  FORMATO STRINGA TEMPGET
 *  (CLIENT)        username*password*R*[TEMPGET]
 *  (SERVER)        R*TT*([OK] || [FAIL] || [ERROR])
 *  (SERVER-NODO)   SENSOR*[TEMPGET]
 *  (NODO)          (SENSOR*TT*[OK] || [FAIL] || [ERROR])
 */

bool AFramework::AXbee::receive(const AString &str, const uint32 ms){
    
    bool res = false;
    /*  se la seriale non è ok                                                  */
    if(!m_flg){
        /*  ritorno false                                                       */
        return false;
    }
    res = wdttmr(str.c_str(), ms);
    /* se l'operazione non è andata a buon fine                                 */
    if(!res){
        /* ritorno false                                                        */
        return false;
    }
    return true;
}

bool AFramework::AXbee::read(AString &str){
    
    str = m_driver->read();
    m_driver->bufferClear();
    if(str.good()){
        return true;
    }
    return false;
}

bool AFramework::AXbee::wdttmr(const char * str, const uint32 ms) const{
    
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
        /*  controllo che nel buffer ci sia oppure ERROR                   */
        res2 = (m_driver->bufferContains(__XBEE_AT_ERROR));
        
        /*  se ho trovato il token                                              */
        if(res1){
            /*  esco dal loop                                                   */
            break;
        }
        /*  se il buffer contiene error                                  */
        if(res2){
            /*  ritorno subito false                                            */
            return false;
        }
    }
    /*  ritorno il flag                                                         */
    return res1;
}
