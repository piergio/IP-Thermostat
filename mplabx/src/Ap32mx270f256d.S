//  Timer 1
TMR1_w = 0xBF800600
    .global TMR1_w
//  Timer 2
TMR2_w = 0xBF800800
    .global TMR2_w
//  Timer 3
TMR3_w = 0xBF800A00
    .global TMR3_w
//  Timer 4
TMR4_w = 0xBF800C00
    .global TMR4_w
//  Timer 5
TMR5_w = 0xBF800E00
    .global TMR5_w



//  Interrupt Controller
INT_w = 0xBF881000
    .global INT_w
    
    
    
//  Port A 
PORTA_w = 0xBF886000
    .global PORTA_w
//  Port B
PORTB_w = 0xBF886100
    .global PORTB_w
//  Port C
PORTC_w = 0xBF886200
    .global PORTC_w
    
//  Inter-Integrated Circuit 1
I2C1_w = 0xBF805000
    .global I2C1_w
//  Inter-Integrated Circuit 2
I2C2_w = 0xBF805100
    .global I2C2_w
    
//  UART1
UART1_w = 0xBF806000
    .global UART1_w
//  UART2
UART2_w = 0xBF806200
    .global UART2_w
    
//  DEVSPEC
DEVSPEC_w = 0xBF80F200
    .global DEVSPEC_w

//  RPI
RPI_w = 0xBF80FA04
    .global RPI_w
//  RPO
RPO_w = 0xBF80FB00
    .global RPO_w