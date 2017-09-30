/* 
 * File:   ARemappablePeripheral.h
 * Author: milaz
 *
 * Created on 18 maggio 2016, 9.33
 */

#ifndef AREMAPPABLEPERIPHERAL_H
#define	AREMAPPABLEPERIPHERAL_H

#include "ACore.h"

namespace AFramework{
    
    class ARemappablePeripheral{
        public:
            bool attach(const volatile uint32 gpio, const volatile uint32 function) volatile{
                return true;
            }
            bool detach(const volatile uint32 gpio) volatile{
                return true;
            }
    };
}

#endif	/* AREMAPPABLEPERIPHERAL_H */

