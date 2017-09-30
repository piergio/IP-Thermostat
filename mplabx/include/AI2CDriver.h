/*******************************************************************************
*   @author:    Milazzo Giuseppe
*               Università KORE Enna
*   @e-mail:    milazzo.ga@gmail.com
*               info@antipode-dev.org
*******************************************************************************
*   Software Licence:
*******************************************************************************
*
*   This file is part of AFramework.
*
*   AFramework is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   AFramework is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with AFramework. If not, see <http://www.gnu.org/licenses/>.
*
*   Copyright 2015, 2016 Milazzo Giuseppe
*
*/

#ifndef AI2CDRIVER_H
#define	AI2CDRIVER_H

#include "ACore.h"

namespace AFramework{
    
    class AI2CDriver{
        public:
            
            enum I2CMode{
                Master,
                Slave
            };
            
            enum I2CFreq{
                Freq100KHz,
                Freq400KHz
            };
            
            AI2CDriver(volatile AI2C_w * w, volatile AHardwarePort * SDAPort, const uint32 SDA, volatile AHardwarePort * SCLPort, const uint32 SCL);
            bool open(const I2CFreq freq, const bool idleStop = false) volatile;
            bool isOpen() volatile;
            void close() volatile;
            bool start() volatile;
            bool stop() volatile;
            bool restart() volatile;
            bool write(const uint8 data) volatile;
            uint8 read() volatile;
            bool nack() volatile;
            bool ack() volatile;
        private:
            volatile AI2C_w        * m_reg;
            volatile AHardwarePort * m_SDAPort;
            volatile AHardwarePort * m_SCLPort;
                     uint32          m_SDA;
                     uint32          m_SCL;
                     bool            m_flg;
    };

#if __HAS_I2C_1__    
    extern volatile AI2CDriver I2C1;
#endif

#if __HAS_I2C_2__
    extern volatile AI2CDriver I2C2;
#endif
}



#endif	/* AI2CDRIVER_H */

