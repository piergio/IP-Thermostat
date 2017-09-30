/* 
 * File:   AUARTDriver.h
 * Author: Giuseppe
 *
 * Created on 16 giugno 2016, 22.45
 */

#ifndef AUARTDRIVER_H
#define	AUARTDRIVER_H

#include "ACommons.h"
#include "AString.h"
#include "ARegisterDefs.h"
#include "AInterruptSource.h"

namespace AFramework{
    
    class AUARTDriver{
        public:
            enum Baud{
                Baud9600,
                Baud19200,
                Baud115200,
                NoBaud
            };
            
            enum Data{
                Data8bitNoParity,
                Data8bitEvenParity,
                Data9bitOddParity,
                Data9bitNoParity
            };
            
            enum StopSelection{
                Stop1bit,
                Stop2bit
            };
            
            AUARTDriver(volatile AUART_w * w, AInterruptSource * erInt, AInterruptSource * rxInt, AInterruptSource * txInt);
            bool open(const Baud baud, const Data dataLength, const StopSelection stop, const bool idleStop = false);
            bool isOpen() const;
            void close();
            AInterruptSource * getFaultEventController() volatile;
            AInterruptSource * getReceiverEventController() volatile;
            AInterruptSource * getTransmitEventController() volatile;
            bool write(const char * str);
            bool writeln(const char * str);
            bool write(const uint32 num);
            AString read() const;
            bool bufferContains(const AString & pattern, const bool & cs = false);
            void rxHandler();
            size_t bytesAvailable() const;
            void bufferClear();
            Baud baud() const;
            
            
        private:
            volatile AUART_w * m_reg;
            AInterruptSource * m_erInt;
            AInterruptSource * m_rxInt;
            AInterruptSource * m_txInt;
            char               m_buffer[__UART_BUFFER_SIZE__];
            uint16             m_index;
            bool               m_flg;
            Baud               m_baud;
    };
    
#if __HAS_UART1__    
    extern AUARTDriver UART1;
#endif

#if __HAS_UART2__
    extern AUARTDriver UART2;
#endif
}

#endif	/* AUARTDRIVER_H */

