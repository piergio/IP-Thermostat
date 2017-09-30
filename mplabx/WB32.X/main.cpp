#include "ACore.h"
#include "ALcd.h"
#include "AESP8266.h"
#include "A24LC512.h"
#include "APCF8563.h"
#include "AXbee.h"
#include "MTemp.h"
#include "MTempDefs.h"
#include <sys/attribs.h>

using namespace AFramework;

extern "C"{
    
    void __ISR(_UART_1_VECTOR, IPL1AUTO) UART_1_HANDLER(){
        
        UART1.rxHandler();
    }
    void __ISR(_UART_2_VECTOR, IPL1AUTO) UART_2_HANDLER(){
        
        UART2.rxHandler();
    }
    
}

int main(int argc, char** argv) {
    
    System::init(16392, &PortB, bit15);
        
    UART1.getReceiverEventController()->enableInterrupt(Ip1, Isp0);
    UART2.getReceiverEventController()->enableInterrupt(Ip1, Isp0);
    System::outputMap(RPA0R, U1TXR);
    System::inputMap(RPA4R, U1RXR);
    
    System::outputMap(RPB10R, U2TXR);
    System::inputMap(RPA8R, U2RXR);   
    
    ALcd lcd(&PortC, bit0, &PortC, bit1, &PortC, bit2, &PortC, bit3, &PortC, bit4, &PortC, bit5, &PortC, bit6);
    AESP8266 wifi(&UART1);
    APCF8563 clock(&I2C2);
    A24LC512 memory(&I2C2, 0x00);
    AXbee    mario(&UART2);
    System::delay(2000);
    
    lcd.lightOn();
    lcd.clear();
    lcd << "Avvio\nModuli";
    MTempMaster app(&mario, &clock, &memory, &wifi, &lcd, &PortC);
    PortA.setOutput(bit7);
    PortC.setOutput(Quick::All);
    System::delay(1000);
    
    if(PortB.read(bit4) == Lo){
        
        app.networkConfig();
    }
    
    app.run();
    
}