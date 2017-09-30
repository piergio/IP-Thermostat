/* 
 * File:   A24LC512.h
 * Author: Giuseppe
 *
 * Created on 16 giugno 2016, 13.58
 */

#ifndef A24LC512_H
#define	A24LC512_H


#include "ACommons.h"
#include "AI2CDriver.h"
#include "AString.h"

namespace AFramework{
    
    class A24LC512{
      
        public:
            A24LC512(volatile AI2CDriver * driver, const uint8 lowAddress);
            char read(const uint16 address);
            bool read(const uint16 address, AString & str);
            bool write(const uint16 address, const char data);
            bool write(const uint16 address, const AString & str);
        private:
            volatile AI2CDriver * m_driver;
                     uint8        m_address;
    };
}


#endif	/* A24LC512_H */

