#ifndef ADHT22_H
#define	ADHT22_H

#include "APorts.h"
#include "ATimers.h"

namespace AFramework{

    class ADht22{
        public:
            typedef struct ATempHum{
                
                float   temp;
                float   hum;
            }ATempHum;
            
                        ADht22(volatile AHardwarePort *port, const uint32 pin);
            ATempHum    read(const uint32 ms = 1000);
            
        private:
            
            volatile AHardwarePort * m_port;
            uint32          m_pin;
    };  
}
#endif	