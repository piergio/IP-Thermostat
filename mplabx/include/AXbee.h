
#ifndef AXBEE_H
#define	AXBEE_H

#include "AUARTDriver.h"

namespace AFramework{

    class AXbee{
        public:
            enum XbeeMode{
                CoordMode,
                RouterMode,
                EndDeviceMode
            };
            AXbee(AUARTDriver * driver, const AUARTDriver::Baud baud = AUARTDriver::Baud9600);
            bool initXbee(const uint32 ms = 1000) const;
            bool isOk(const uint32 ms = 1000) const;
            bool enterATcommand(const uint32 ms = 1000) const;
            bool exitATcommand(const uint32 ms = 1000) const;
            bool setMode(const XbeeMode mode, AString name, const uint32 ms = 1000) const;
            bool setDestHigh(const XbeeMode mode, const uint32 ms = 1000) const;
            bool setDestLow(const XbeeMode mode, const uint32 ms = 1000) const;
            bool joinNotification(const XbeeMode mode, const uint32 ms = 1000) const;
            bool joinVerification(const XbeeMode mode, const uint32 ms = 1000) const;
            bool nodeDiscover(const uint32 ms) const;
            bool send(const AString &str);
            bool receive(const AString &str, const uint32 ms = 1000);
            bool read(AString &str);
        private:
            bool wdttmr(const char * str, const uint32 ms) const;
            AUARTDriver * m_driver;
            bool          m_flg;
    };
}
#endif	/* AXBEE_H */