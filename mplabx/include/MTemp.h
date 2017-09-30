#ifndef MTEMP_H
#define	MTEMP_H

#include "A24LC512.h"
#include "AESP8266.h"
#include "APCF8563.h"
#include "AString.h"
#include "AXbee.h"
#include "ALcd.h"
#include "MTempDefs.h"
#include "MTempCommons.h"

namespace AFramework{
    
    class MTempMaster{
        
        public:
                    MTempMaster(AXbee * xbee, APCF8563 *clk, A24LC512 *mem, AESP8266 *wifi, ALcd *lcd, volatile AHardwarePort *port);
            
            bool    networkConfig();            //configurazione rete
            bool    run();  
            
            
        private:
            
                        AESP8266 *      m_wifi;
                        A24LC512 *      m_memory;
                        AXbee    *      m_xbee;
                        APCF8563 *      m_clk;
                        ALcd     *      m_lcd;   
                        bool            m_flag;
                        AString         m_username;
                        AString         m_password;
                        Room            m_rooms[_MTEMP_ROOM_VEC_SIZE];
            volatile    AHardwarePort * m_port;
            
            bool    saveNetworkConfig(const AString &data) const;     //salva la configurazione della rete
            
            bool    prepareAp(const AString &ssid, const AString &pwd, const uint16 port) const;      //ap per il primo avvio
            
            void    checkPrograms();        //solo debug
            
            bool    defaultProgram();       //salva i programmi di default e le stanze di default
            
            bool    joinNetwork() const;          //si connette alla rete
            
            bool    programsManager(const bool read);
            
            bool    loadAll();             //loads rooms and programs 
            
            void    commandExec(const AString &cmd);
            
            void    msg(const QString & s, const uint32 ms = 1000) const;
            
            void    msg(const char * s, const uint32 ms = 1000) const;
            
            uint8   readTemp(AString &addr, const uint32 ms = 1000);
            
    };
}

#endif	/* MTEMP_H */

