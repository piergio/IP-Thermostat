
#ifndef AESP8266_H
#define	AESP8266_H

#include "AUARTDriver.h"

namespace AFramework{

    class AESP8266{
        public:
            enum ESPMode{
                NoMode,
                StationMode,
                APMode,
                BothMode
            };
            AESP8266(AUARTDriver * driver, const AUARTDriver::Baud baud = AUARTDriver::Baud115200);
            bool isOk(const uint32 ms = 1000) const;
            bool reset(const uint32 ms = 2500) const;
            bool setEcho(const bool echo, const uint32 ms = 1000) const;
            bool version(AString & str, const uint32 ms = 1000) const;
            bool setMode(const ESPMode mode = ESPMode::StationMode, const bool rst = true, const uint32 ms = 2500) const;
            bool configureAP(const AString & ssid, const AString & pwd, const uint8 channel = 7, const uint32 ms = 2500) const;
            bool joinAP(const AString & ssid, const AString & pwd, const uint32 ms = 20000) const;
            bool leaveAP(const uint32 ms = 2000) const;
            bool availableAP(AString & res, const uint32 ms = 5000) const;
            bool setDhcp(const bool en, const ESPMode mode = ESPMode::StationMode, const uint32 ms = 1000) const;
            bool setIp(const AString &addr, const ESPMode mode = ESPMode::StationMode, const uint32 ms = 1000) const;
            bool ip(AString &addr, const ESPMode mode = ESPMode::StationMode, const uint32 ms = 1000) const;
            bool setMultipleConnections(const bool en, const uint32 ms = 1000) const;
            bool openServer(const uint16 port, const uint32 timeout = 60, const uint32 ms = 1000)const;
            bool prepareForReceive() const;
            bool waitForData(AString &str, const uint32 ms = 1000) const;
            bool send(const AString &str, const uint8 numConn = 0) const;
            
        private:
            bool wdttmr(const char * str, const uint32 ms) const;
            AUARTDriver * m_driver;
            bool          m_flg;
    };
}

#endif	/* AESP8266_H */

