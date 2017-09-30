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

#ifndef AP32MX270F256D_H
#define AP32MX270F256D_H
/**
 * Generics Def
 */
#define __32MX__
#define __DEVCLASS1__
#define __HAS_TIMER1__                              0x00000001
#define __HAS_TIMER2__                              0x00000001
#define __HAS_TIMER3__                              0x00000001
#define __HAS_TIMER4__                              0x00000001
#define __HAS_TIMER5__                              0x00000001
#define __HAS__PORTA__                              0x00000001
#define __HAS__PORTB__                              0x00000001
#define __HAS__PORTC__                              0x00000001
#define __HAS__PORTD__                              0x00000000
#define __HAS__PORTE__                              0x00000000
#define __HAS__PORTF__                              0x00000000
#define __HAS__PORTG__                              0x00000000
#define __HAS__PORTH__                              0x00000000
#define __HAS__PORTJ__                              0x00000000
#define __HAS__PORTK__                              0x00000000
#define __HAS_EXTOSC__                              0x00000000

#define __HAS_I2C_1__                               0x00000001
#define __SDA1_PORT__                               PortB
#define __SDA1_GPIO__                               bit9
#define __SCL1_PORT__                               PortB
#define __SCL1_GPIO__                               bit8

#define __HAS_I2C_2__                               0x00000001
#define __SDA2_PORT__                               PortB
#define __SDA2_GPIO__                               bit2
#define __SCL2_PORT__                               PortB
#define __SCL2_GPIO__                               bit3

#define __HAS_UART1__                               0x00000001
#define __HAS_UART2__                               0x00000001


/**
 * Timers
 */
#define _TxCON_ON_POSITION                          0x0000000F
#define _TxCON_ON_MASK                              0x00008000
#define _TxCON_ON_LENGTH                            0x00000001

#define _TxCON_SIDL_POSITION                        0x0000000D
#define _TxCON_SIDL_MASK                            0x00002000
#define _TxCON_SIDL_LENGTH                          0x00000001

#define _TxCON_TWDIS_POSITION                       0x0000000C
#define _TxCON_TWDIS_MASK                           0x00001000
#define _TxCON_TWDIS_LENGTH                         0x00000001

#define _TxCON_TWIP_POSITION                        0x0000000B
#define _TxCON_TWIP_MASK                            0x00000800
#define _TxCON_TWIP_LENGTH                          0x00000001

#define _TxCON_TGATE_POSITION                       0x00000007
#define _TxCON_TGATE_MASK                           0x00000080
#define _TxCON_TGATE_LENGTH                         0x00000001

#define _TxCON_16_TCKPS_POSITION                    0x00000004
#define _TxCON_16_TCKPS_MASK                        0x00000030
#define _TxCON_16_TCKPS_LENGTH                      0x00000002

#define _TxCON_32_TCKPS_POSITION                    0x00000004
#define _TxCON_32_TCKPS_MASK                        0x00000070
#define _TxCON_32_TCKPS_LENGTH                      0x00000003

#define _TxCON_T32_POSITION                         0x00000003
#define _TxCON_T32_MASK                             0x00000008
#define _TxCON_T32_LENGTH                           0x00000001

#define _TxCON_TSYNC_POSITION                       0x00000002
#define _TxCON_TSYNC_MASK                           0x00000004
#define _TxCON_TSYNC_LENGTH                         0x00000001

#define _TxCON_TCS_POSITION                         0x00000001
#define _TxCON_TCS_MASK                             0x00000002
#define _TxCON_TCS_LENGTH                           0x00000001
/**
 * Interrupt Controller
 */
#define _INTCON_INT0EP_POSITION                     0x00000000
#define _INTCON_INT0EP_MASK                         0x00000001
#define _INTCON_INT0EP_LENGTH                       0x00000001

#define _INTCON_INT1EP_POSITION                     0x00000001
#define _INTCON_INT1EP_MASK                         0x00000002
#define _INTCON_INT1EP_LENGTH                       0x00000001

#define _INTCON_INT2EP_POSITION                     0x00000002
#define _INTCON_INT2EP_MASK                         0x00000004
#define _INTCON_INT2EP_LENGTH                       0x00000001

#define _INTCON_INT3EP_POSITION                     0x00000003
#define _INTCON_INT3EP_MASK                         0x00000008
#define _INTCON_INT3EP_LENGTH                       0x00000001

#define _INTCON_INT4EP_POSITION                     0x00000004
#define _INTCON_INT4EP_MASK                         0x00000010
#define _INTCON_INT4EP_LENGTH                       0x00000001

#define _INTCON_TPC_POSITION                        0x00000008
#define _INTCON_TPC_MASK                            0x00000700
#define _INTCON_TPC_LENGTH                          0x00000003

#define _INTCON_MVEC_POSITION                       0x0000000C
#define _INTCON_MVEC_MASK                           0x00001000
#define _INTCON_MVEC_LENGTH                         0x00000001

#define _INTCON_SS0_POSITION                        0x00000010
#define _INTCON_SS0_MASK                            0x00010000
#define _INTCON_SS0_LENGTH                          0x00000001

#define _INTSTAT_VEC_POSITION                       0x00000000
#define _INTSTAT_VEC_MASK                           0x0000003F
#define _INTSTAT_VEC_LENGTH                         0x00000006

#define _INTSTAT_SRIPL_POSITION                     0x00000008
#define _INTSTAT_SRIPL_MASK                         0x00000700
#define _INTSTAT_SRIPL_LENGTH                       0x00000003

#define _IFSVEC_CTIF_POSITION                       0x00000000
#define _IFS_CTIF_POSITION                          0x00000000
#define _IFS_CTIF_MASK                              0x00000001
#define _IFS_CTIF_LENGTH                            0x00000001

#define _IFSVEC_CS0IF_POSITION                      0x00000000
#define _IFS_CS0IF_POSITION                         0x00000001
#define _IFS_CS0IF_MASK                             0x00000002
#define _IFS_CS0IF_LENGTH                           0x00000001

#define _IFSVEC_CS1IF_POSITION                      0x00000000
#define _IFS_CS1IF_POSITION                         0x00000002
#define _IFS_CS1IF_MASK                             0x00000004
#define _IFS_CS1IF_LENGTH                           0x00000001

#define _IFSVEC_INT0IF_POSITION                     0x00000000
#define _IFS_INT0IF_POSITION                        0x00000003
#define _IFS_INT0IF_MASK                            0x00000008
#define _IFS_INT0IF_LENGTH                          0x00000001

#define _IFSVEC_T1IF_POSITION                       0x00000000
#define _IFS_T1IF_POSITION                          0x00000004
#define _IFS_T1IF_MASK                              0x00000010
#define _IFS_T1IF_LENGTH                            0x00000001

#define _IFSVEC_IC1EIF_POSITION                     0x00000000
#define _IFS_IC1EIF_POSITION                        0x00000005
#define _IFS_IC1EIF_MASK                            0x00000020
#define _IFS_IC1EIF_LENGTH                          0x00000001

#define _IFSVEC_IC1IF_POSITION                      0x00000000
#define _IFS_IC1IF_POSITION                         0x00000006
#define _IFS_IC1IF_MASK                             0x00000040
#define _IFS_IC1IF_LENGTH                           0x00000001

#define _IFSVEC_OC1IF_POSITION                      0x00000000
#define _IFS_OC1IF_POSITION                         0x00000007
#define _IFS_OC1IF_MASK                             0x00000080
#define _IFS_OC1IF_LENGTH                           0x00000001

#define _IFSVEC_INT1IF_POSITION                     0x00000000
#define _IFS_INT1IF_POSITION                        0x00000008
#define _IFS_INT1IF_MASK                            0x00000100
#define _IFS_INT1IF_LENGTH                          0x00000001

#define _IFSVEC_T2IF_POSITION                       0x00000000
#define _IFS_T2IF_POSITION                          0x00000009
#define _IFS_T2IF_MASK                              0x00000200
#define _IFS_T2IF_LENGTH                            0x00000001

#define _IFSVEC_IC2EIF_POSITION                     0x00000000
#define _IFS_IC2EIF_POSITION                        0x0000000A
#define _IFS_IC2EIF_MASK                            0x00000400
#define _IFS_IC2EIF_LENGTH                          0x00000001

#define _IFSVEC_IC2IF_POSITION                      0x00000000
#define _IFS_IC2IF_POSITION                         0x0000000B
#define _IFS_IC2IF_MASK                             0x00000800
#define _IFS_IC2IF_LENGTH                           0x00000001

#define _IFSVEC_OC2IF_POSITION                      0x00000000
#define _IFS_OC2IF_POSITION                         0x0000000C
#define _IFS_OC2IF_MASK                             0x00001000
#define _IFS_OC2IF_LENGTH                           0x00000001

#define _IFSVEC_INT2IF_POSITION                     0x00000000
#define _IFS_INT2IF_POSITION                        0x0000000D
#define _IFS_INT2IF_MASK                            0x00002000
#define _IFS_INT2IF_LENGTH                          0x00000001

#define _IFSVEC_T3IF_POSITION                       0x00000000
#define _IFS_T3IF_POSITION                          0x0000000E
#define _IFS_T3IF_MASK                              0x00004000
#define _IFS_T3IF_LENGTH                            0x00000001

#define _IFSVEC_IC3EIF_POSITION                     0x00000000
#define _IFS_IC3EIF_POSITION                        0x0000000F
#define _IFS_IC3EIF_MASK                            0x00008000
#define _IFS_IC3EIF_LENGTH                          0x00000001

#define _IFSVEC_IC3IF_POSITION                      0x00000000
#define _IFS_IC3IF_POSITION                         0x00000010
#define _IFS_IC3IF_MASK                             0x00010000
#define _IFS_IC3IF_LENGTH                           0x00000001

#define _IFSVEC_OC3IF_POSITION                      0x00000000
#define _IFS_OC3IF_POSITION                         0x00000011
#define _IFS_OC3IF_MASK                             0x00020000
#define _IFS_OC3IF_LENGTH                           0x00000001

#define _IFSVEC_INT3IF_POSITION                     0x00000000
#define _IFS_INT3IF_POSITION                        0x00000012
#define _IFS_INT3IF_MASK                            0x00040000
#define _IFS_INT3IF_LENGTH                          0x00000001

#define _IFSVEC_T4IF_POSITION                       0x00000000
#define _IFS_T4IF_POSITION                          0x00000013
#define _IFS_T4IF_MASK                              0x00080000
#define _IFS_T4IF_LENGTH                            0x00000001

#define _IFSVEC_IC4EIF_POSITION                     0x00000000
#define _IFS_IC4EIF_POSITION                        0x00000014
#define _IFS_IC4EIF_MASK                            0x00100000
#define _IFS_IC4EIF_LENGTH                          0x00000001

#define _IFSVEC_IC4IF_POSITION                      0x00000000
#define _IFS_IC4IF_POSITION                         0x00000015
#define _IFS_IC4IF_MASK                             0x00200000
#define _IFS_IC4IF_LENGTH                           0x00000001

#define _IFSVEC_OC4IF_POSITION                      0x00000000
#define _IFS_OC4IF_POSITION                         0x00000016
#define _IFS_OC4IF_MASK                             0x00400000
#define _IFS_OC4IF_LENGTH                           0x00000001

#define _IFSVEC_INT4IF_POSITION                     0x00000000
#define _IFS_INT4IF_POSITION                        0x00000017
#define _IFS_INT4IF_MASK                            0x00800000
#define _IFS_INT4IF_LENGTH                          0x00000001

#define _IFSVEC_T5IF_POSITION                       0x00000000
#define _IFS_T5IF_POSITION                          0x00000018
#define _IFS_T5IF_MASK                              0x01000000
#define _IFS_T5IF_LENGTH                            0x00000001

#define _IFSVEC_IC5EIF_POSITION                     0x00000000
#define _IFS_IC5EIF_POSITION                        0x00000019
#define _IFS_IC5EIF_MASK                            0x02000000
#define _IFS_IC5EIF_LENGTH                          0x00000001

#define _IFSVEC_IC5IF_POSITION                      0x00000000
#define _IFS_IC5IF_POSITION                         0x0000001A
#define _IFS_IC5IF_MASK                             0x04000000
#define _IFS_IC5IF_LENGTH                           0x00000001

#define _IFSVEC_OC5IF_POSITION                      0x00000000
#define _IFS_OC5IF_POSITION                         0x0000001B
#define _IFS_OC5IF_MASK                             0x08000000
#define _IFS_OC5IF_LENGTH                           0x00000001

#define _IFSVEC_AD1IF_POSITION                      0x00000000
#define _IFS_AD1IF_POSITION                         0x0000001C
#define _IFS_AD1IF_MASK                             0x10000000
#define _IFS_AD1IF_LENGTH                           0x00000001

#define _IFSVEC_FSCMIF_POSITION                     0x00000000
#define _IFS_FSCMIF_POSITION                        0x0000001D
#define _IFS_FSCMIF_MASK                            0x20000000
#define _IFS_FSCMIF_LENGTH                          0x00000001

#define _IFSVEC_RTCCIF_POSITION                     0x00000000
#define _IFS_RTCCIF_POSITION                        0x0000001E
#define _IFS_RTCCIF_MASK                            0x40000000
#define _IFS_RTCCIF_LENGTH                          0x00000001

#define _IFSVEC_FCEIF_POSITION                      0x00000000
#define _IFS_FCEIF_POSITION                         0x0000001F
#define _IFS_FCEIF_MASK                             0x80000000
#define _IFS_FCEIF_LENGTH                           0x00000001

#define _IFSVEC_CMP1IF_POSITION                     0x00000001
#define _IFS_CMP1IF_POSITION                        0x00000000
#define _IFS_CMP1IF_MASK                            0x00000001
#define _IFS_CMP1IF_LENGTH                          0x00000001

#define _IFSVEC_CMP2IF_POSITION                     0x00000001
#define _IFS_CMP2IF_POSITION                        0x00000001
#define _IFS_CMP2IF_MASK                            0x00000002
#define _IFS_CMP2IF_LENGTH                          0x00000001

#define _IFSVEC_CMP3IF_POSITION                     0x00000001
#define _IFS_CMP3IF_POSITION                        0x00000002
#define _IFS_CMP3IF_MASK                            0x00000004
#define _IFS_CMP3IF_LENGTH                          0x00000001

#define _IFSVEC_USBIF_POSITION                      0x00000001
#define _IFS_USBIF_POSITION                         0x00000003
#define _IFS_USBIF_MASK                             0x00000008
#define _IFS_USBIF_LENGTH                           0x00000001

#define _IFSVEC_SPI1EIF_POSITION                    0x00000001
#define _IFS_SPI1EIF_POSITION                       0x00000004
#define _IFS_SPI1EIF_MASK                           0x00000010
#define _IFS_SPI1EIF_LENGTH                         0x00000001

#define _IFSVEC_SPI1RXIF_POSITION                   0x00000001
#define _IFS_SPI1RXIF_POSITION                      0x00000005
#define _IFS_SPI1RXIF_MASK                          0x00000020
#define _IFS_SPI1RXIF_LENGTH                        0x00000001

#define _IFSVEC_SPI1TXIF_POSITION                   0x00000001
#define _IFS_SPI1TXIF_POSITION                      0x00000006
#define _IFS_SPI1TXIF_MASK                          0x00000040
#define _IFS_SPI1TXIF_LENGTH                        0x00000001

#define _IFSVEC_U1EIF_POSITION                      0x00000001
#define _IFS_U1EIF_POSITION                         0x00000007
#define _IFS_U1EIF_MASK                             0x00000080
#define _IFS_U1EIF_LENGTH                           0x00000001

#define _IFSVEC_U1RXIF_POSITION                     0x00000001
#define _IFS_U1RXIF_POSITION                        0x00000008
#define _IFS_U1RXIF_MASK                            0x00000100
#define _IFS_U1RXIF_LENGTH                          0x00000001

#define _IFSVEC_U1TXIF_POSITION                     0x00000001
#define _IFS_U1TXIF_POSITION                        0x00000009
#define _IFS_U1TXIF_MASK                            0x00000200
#define _IFS_U1TXIF_LENGTH                          0x00000001

#define _IFSVEC_I2C1BIF_POSITION                    0x00000001
#define _IFS_I2C1BIF_POSITION                       0x0000000A
#define _IFS_I2C1BIF_MASK                           0x00000400
#define _IFS_I2C1BIF_LENGTH                         0x00000001

#define _IFSVEC_I2C1SIF_POSITION                    0x00000001
#define _IFS_I2C1SIF_POSITION                       0x0000000B
#define _IFS_I2C1SIF_MASK                           0x00000800
#define _IFS_I2C1SIF_LENGTH                         0x00000001

#define _IFSVEC_I2C1MIF_POSITION                    0x00000001
#define _IFS_I2C1MIF_POSITION                       0x0000000C
#define _IFS_I2C1MIF_MASK                           0x00001000
#define _IFS_I2C1MIF_LENGTH                         0x00000001

#define _IFSVEC_CNAIF_POSITION                      0x00000001
#define _IFS_CNAIF_POSITION                         0x0000000D
#define _IFS_CNAIF_MASK                             0x00002000
#define _IFS_CNAIF_LENGTH                           0x00000001

#define _IFSVEC_CNBIF_POSITION                      0x00000001
#define _IFS_CNBIF_POSITION                         0x0000000E
#define _IFS_CNBIF_MASK                             0x00004000
#define _IFS_CNBIF_LENGTH                           0x00000001

#define _IFSVEC_CNCIF_POSITION                      0x00000001
#define _IFS_CNCIF_POSITION                         0x0000000F
#define _IFS_CNCIF_MASK                             0x00008000
#define _IFS_CNCIF_LENGTH                           0x00000001

#define _IFSVEC_PMPIF_POSITION                      0x00000001
#define _IFS_PMPIF_POSITION                         0x00000010
#define _IFS_PMPIF_MASK                             0x00010000
#define _IFS_PMPIF_LENGTH                           0x00000001

#define _IFSVEC_PMPEIF_POSITION                     0x00000001
#define _IFS_PMPEIF_POSITION                        0x00000011
#define _IFS_PMPEIF_MASK                            0x00020000
#define _IFS_PMPEIF_LENGTH                          0x00000001

#define _IFSVEC_SPI2EIF_POSITION                    0x00000001
#define _IFS_SPI2EIF_POSITION                       0x00000012
#define _IFS_SPI2EIF_MASK                           0x00040000
#define _IFS_SPI2EIF_LENGTH                         0x00000001

#define _IFSVEC_SPI2RXIF_POSITION                   0x00000001
#define _IFS_SPI2RXIF_POSITION                      0x00000013
#define _IFS_SPI2RXIF_MASK                          0x00080000
#define _IFS_SPI2RXIF_LENGTH                        0x00000001

#define _IFSVEC_SPI2TXIF_POSITION                   0x00000001
#define _IFS_SPI2TXIF_POSITION                      0x00000014
#define _IFS_SPI2TXIF_MASK                          0x00100000
#define _IFS_SPI2TXIF_LENGTH                        0x00000001

#define _IFSVEC_U2EIF_POSITION                      0x00000001
#define _IFS_U2EIF_POSITION                         0x00000015
#define _IFS_U2EIF_MASK                             0x00200000
#define _IFS_U2EIF_LENGTH                           0x00000001

#define _IFSVEC_U2RXIF_POSITION                     0x00000001
#define _IFS_U2RXIF_POSITION                        0x00000016
#define _IFS_U2RXIF_MASK                            0x00400000
#define _IFS_U2RXIF_LENGTH                          0x00000001

#define _IFSVEC_U2TXIF_POSITION                     0x00000001
#define _IFS_U2TXIF_POSITION                        0x00000017
#define _IFS_U2TXIF_MASK                            0x00800000
#define _IFS_U2TXIF_LENGTH                          0x00000001

#define _IFSVEC_I2C2BIF_POSITION                    0x00000001
#define _IFS_I2C2BIF_POSITION                       0x00000018
#define _IFS_I2C2BIF_MASK                           0x01000000
#define _IFS_I2C2BIF_LENGTH                         0x00000001

#define _IFSVEC_I2C2SIF_POSITION                    0x00000001
#define _IFS_I2C2SIF_POSITION                       0x00000019
#define _IFS_I2C2SIF_MASK                           0x02000000
#define _IFS_I2C2SIF_LENGTH                         0x00000001

#define _IFSVEC_I2C2MIF_POSITION                    0x00000001
#define _IFS_I2C2MIF_POSITION                       0x0000001A
#define _IFS_I2C2MIF_MASK                           0x04000000
#define _IFS_I2C2MIF_LENGTH                         0x00000001

#define _IFSVEC_CTMUIF_POSITION                     0x00000001
#define _IFS_CTMUIF_POSITION                        0x0000001B
#define _IFS_CTMUIF_MASK                            0x08000000
#define _IFS_CTMUIF_LENGTH                          0x00000001

#define _IFSVEC_DMA0IF_POSITION                     0x00000001
#define _IFS_DMA0IF_POSITION                        0x0000001C
#define _IFS_DMA0IF_MASK                            0x10000000
#define _IFS_DMA0IF_LENGTH                          0x00000001

#define _IFSVEC_DMA1IF_POSITION                     0x00000001
#define _IFS_DMA1IF_POSITION                        0x0000001D
#define _IFS_DMA1IF_MASK                            0x20000000
#define _IFS_DMA1IF_LENGTH                          0x00000001

#define _IFSVEC_DMA2IF_POSITION                     0x00000001
#define _IFS_DMA2IF_POSITION                        0x0000001E
#define _IFS_DMA2IF_MASK                            0x40000000
#define _IFS_DMA2IF_LENGTH                          0x00000001

#define _IFSVEC_DMA3IF_POSITION                     0x00000001
#define _IFS_DMA3IF_POSITION                        0x0000001F
#define _IFS_DMA3IF_MASK                            0x80000000
#define _IFS_DMA3IF_LENGTH                          0x00000001

#define _IECVEC_CTIE_POSITION                       0x00000000
#define _IEC_CTIE_POSITION                          0x00000000
#define _IEC_CTIE_MASK                              0x00000001
#define _IEC_CTIE_LENGTH                            0x00000001

#define _IECVEC_CS0IE_POSITION                      0x00000000
#define _IEC_CS0IE_POSITION                         0x00000001
#define _IEC_CS0IE_MASK                             0x00000002
#define _IEC_CS0IE_LENGTH                           0x00000001

#define _IECVEC_CS1IE_POSITION                      0x00000000
#define _IEC_CS1IE_POSITION                         0x00000002
#define _IEC_CS1IE_MASK                             0x00000004
#define _IEC_CS1IE_LENGTH                           0x00000001

#define _IECVEC_INT0IE_POSITION                     0x00000000
#define _IEC_INT0IE_POSITION                        0x00000003
#define _IEC_INT0IE_MASK                            0x00000008
#define _IEC_INT0IE_LENGTH                          0x00000001

#define _IECVEC_T1IE_POSITION                       0x00000000
#define _IEC_T1IE_POSITION                          0x00000004
#define _IEC_T1IE_MASK                              0x00000010
#define _IEC_T1IE_LENGTH                            0x00000001

#define _IECVEC_IC1EIE_POSITION                     0x00000000
#define _IEC_IC1EIE_POSITION                        0x00000005
#define _IEC_IC1EIE_MASK                            0x00000020
#define _IEC_IC1EIE_LENGTH                          0x00000001

#define _IECVEC_IC1IE_POSITION                      0x00000000
#define _IEC_IC1IE_POSITION                         0x00000006
#define _IEC_IC1IE_MASK                             0x00000040
#define _IEC_IC1IE_LENGTH                           0x00000001

#define _IECVEC_OC1IE_POSITION                      0x00000000
#define _IEC_OC1IE_POSITION                         0x00000007
#define _IEC_OC1IE_MASK                             0x00000080
#define _IEC_OC1IE_LENGTH                           0x00000001

#define _IECVEC_INT1IE_POSITION                     0x00000000
#define _IEC_INT1IE_POSITION                        0x00000008
#define _IEC_INT1IE_MASK                            0x00000100
#define _IEC_INT1IE_LENGTH                          0x00000001

#define _IECVEC_T2IE_POSITION                       0x00000000
#define _IEC_T2IE_POSITION                          0x00000009
#define _IEC_T2IE_MASK                              0x00000200
#define _IEC_T2IE_LENGTH                            0x00000001

#define _IECVEC_IC2EIE_POSITION                     0x00000000
#define _IEC_IC2EIE_POSITION                        0x0000000A
#define _IEC_IC2EIE_MASK                            0x00000400
#define _IEC_IC2EIE_LENGTH                          0x00000001

#define _IECVEC_IC2IE_POSITION                      0x00000000
#define _IEC_IC2IE_POSITION                         0x0000000B
#define _IEC_IC2IE_MASK                             0x00000800
#define _IEC_IC2IE_LENGTH                           0x00000001

#define _IECVEC_OC2IE_POSITION                      0x00000000
#define _IEC_OC2IE_POSITION                         0x0000000C
#define _IEC_OC2IE_MASK                             0x00001000
#define _IEC_OC2IE_LENGTH                           0x00000001

#define _IECVEC_INT2IE_POSITION                     0x00000000
#define _IEC_INT2IE_POSITION                        0x0000000D
#define _IEC_INT2IE_MASK                            0x00002000
#define _IEC_INT2IE_LENGTH                          0x00000001

#define _IECVEC_T3IE_POSITION                       0x00000000
#define _IEC_T3IE_POSITION                          0x0000000E
#define _IEC_T3IE_MASK                              0x00004000
#define _IEC_T3IE_LENGTH                            0x00000001

#define _IECVEC_IC3EIE_POSITION                     0x00000000
#define _IEC_IC3EIE_POSITION                        0x0000000F
#define _IEC_IC3EIE_MASK                            0x00008000
#define _IEC_IC3EIE_LENGTH                          0x00000001

#define _IECVEC_IC3IE_POSITION                      0x00000000
#define _IEC_IC3IE_POSITION                         0x00000010
#define _IEC_IC3IE_MASK                             0x00010000
#define _IEC_IC3IE_LENGTH                           0x00000001

#define _IECVEC_OC3IE_POSITION                      0x00000000
#define _IEC_OC3IE_POSITION                         0x00000011
#define _IEC_OC3IE_MASK                             0x00020000
#define _IEC_OC3IE_LENGTH                           0x00000001

#define _IECVEC_INT3IE_POSITION                     0x00000000
#define _IEC_INT3IE_POSITION                        0x00000012
#define _IEC_INT3IE_MASK                            0x00040000
#define _IEC_INT3IE_LENGTH                          0x00000001

#define _IECVEC_T4IE_POSITION                       0x00000000
#define _IEC_T4IE_POSITION                          0x00000013
#define _IEC_T4IE_MASK                              0x00080000
#define _IEC_T4IE_LENGTH                            0x00000001

#define _IECVEC_IC4EIE_POSITION                     0x00000000
#define _IEC_IC4EIE_POSITION                        0x00000014
#define _IEC_IC4EIE_MASK                            0x00100000
#define _IEC_IC4EIE_LENGTH                          0x00000001

#define _IECVEC_IC4IE_POSITION                      0x00000000
#define _IEC_IC4IE_POSITION                         0x00000015
#define _IEC_IC4IE_MASK                             0x00200000
#define _IEC_IC4IE_LENGTH                           0x00000001

#define _IECVEC_OC4IE_POSITION                      0x00000000
#define _IEC_OC4IE_POSITION                         0x00000016
#define _IEC_OC4IE_MASK                             0x00400000
#define _IEC_OC4IE_LENGTH                           0x00000001

#define _IECVEC_INT4IE_POSITION                     0x00000000
#define _IEC_INT4IE_POSITION                        0x00000017
#define _IEC_INT4IE_MASK                            0x00800000
#define _IEC_INT4IE_LENGTH                          0x00000001

#define _IECVEC_T5IE_POSITION                       0x00000000
#define _IEC_T5IE_POSITION                          0x00000018
#define _IEC_T5IE_MASK                              0x01000000
#define _IEC_T5IE_LENGTH                            0x00000001

#define _IECVEC_IC5EIE_POSITION                     0x00000000
#define _IEC_IC5EIE_POSITION                        0x00000019
#define _IEC_IC5EIE_MASK                            0x02000000
#define _IEC_IC5EIE_LENGTH                          0x00000001

#define _IECVEC_IC5IE_POSITION                      0x00000000
#define _IEC_IC5IE_POSITION                         0x0000001A
#define _IEC_IC5IE_MASK                             0x04000000
#define _IEC_IC5IE_LENGTH                           0x00000001

#define _IECVEC_OC5IE_POSITION                      0x00000000
#define _IEC_OC5IE_POSITION                         0x0000001B
#define _IEC_OC5IE_MASK                             0x08000000
#define _IEC_OC5IE_LENGTH                           0x00000001

#define _IECVEC_AD1IE_POSITION                      0x00000000
#define _IEC_AD1IE_POSITION                         0x0000001C
#define _IEC_AD1IE_MASK                             0x10000000
#define _IEC_AD1IE_LENGTH                           0x00000001

#define _IECVEC_FSCMIE_POSITION                     0x00000000
#define _IEC_FSCMIE_POSITION                        0x0000001D
#define _IEC_FSCMIE_MASK                            0x20000000
#define _IEC_FSCMIE_LENGTH                          0x00000001

#define _IECVEC_RTCCIE_POSITION                     0x00000000
#define _IEC_RTCCIE_POSITION                        0x0000001E
#define _IEC_RTCCIE_MASK                            0x40000000
#define _IEC_RTCCIE_LENGTH                          0x00000001

#define _IECVEC_FCEIE_POSITION                      0x00000000
#define _IEC_FCEIE_POSITION                         0x0000001F
#define _IEC_FCEIE_MASK                             0x80000000
#define _IEC_FCEIE_LENGTH                           0x00000001

#define _IECVEC_CMP1IE_POSITION                     0x00000001
#define _IEC_CMP1IE_POSITION                        0x00000000
#define _IEC_CMP1IE_MASK                            0x00000001
#define _IEC_CMP1IE_LENGTH                          0x00000001

#define _IECVEC_CMP2IE_POSITION                     0x00000001
#define _IEC_CMP2IE_POSITION                        0x00000001
#define _IEC_CMP2IE_MASK                            0x00000002
#define _IEC_CMP2IE_LENGTH                          0x00000001

#define _IECVEC_CMP3IE_POSITION                     0x00000001
#define _IEC_CMP3IE_POSITION                        0x00000002
#define _IEC_CMP3IE_MASK                            0x00000004
#define _IEC_CMP3IE_LENGTH                          0x00000001

#define _IECVEC_USBIE_POSITION                      0x00000001
#define _IEC_USBIE_POSITION                         0x00000003
#define _IEC_USBIE_MASK                             0x00000008
#define _IEC_USBIE_LENGTH                           0x00000001

#define _IECVEC_SPI1EIE_POSITION                    0x00000001
#define _IEC_SPI1EIE_POSITION                       0x00000004
#define _IEC_SPI1EIE_MASK                           0x00000010
#define _IEC_SPI1EIE_LENGTH                         0x00000001

#define _IECVEC_SPI1RXIE_POSITION                   0x00000001
#define _IEC_SPI1RXIE_POSITION                      0x00000005
#define _IEC_SPI1RXIE_MASK                          0x00000020
#define _IEC_SPI1RXIE_LENGTH                        0x00000001

#define _IECVEC_SPI1TXIE_POSITION                   0x00000001
#define _IEC_SPI1TXIE_POSITION                      0x00000006
#define _IEC_SPI1TXIE_MASK                          0x00000040
#define _IEC_SPI1TXIE_LENGTH                        0x00000001

#define _IECVEC_U1EIE_POSITION                      0x00000001
#define _IEC_U1EIE_POSITION                         0x00000007
#define _IEC_U1EIE_MASK                             0x00000080
#define _IEC_U1EIE_LENGTH                           0x00000001

#define _IECVEC_U1RXIE_POSITION                     0x00000001
#define _IEC_U1RXIE_POSITION                        0x00000008
#define _IEC_U1RXIE_MASK                            0x00000100
#define _IEC_U1RXIE_LENGTH                          0x00000001

#define _IECVEC_U1TXIE_POSITION                     0x00000001
#define _IEC_U1TXIE_POSITION                        0x00000009
#define _IEC_U1TXIE_MASK                            0x00000200
#define _IEC_U1TXIE_LENGTH                          0x00000001

#define _IECVEC_I2C1BIE_POSITION                    0x00000001
#define _IEC_I2C1BIE_POSITION                       0x0000000A
#define _IEC_I2C1BIE_MASK                           0x00000400
#define _IEC_I2C1BIE_LENGTH                         0x00000001

#define _IECVEC_I2C1SIE_POSITION                    0x00000001
#define _IEC_I2C1SIE_POSITION                       0x0000000B
#define _IEC_I2C1SIE_MASK                           0x00000800
#define _IEC_I2C1SIE_LENGTH                         0x00000001

#define _IECVEC_I2C1MIE_POSITION                    0x00000001
#define _IEC_I2C1MIE_POSITION                       0x0000000C
#define _IEC_I2C1MIE_MASK                           0x00001000
#define _IEC_I2C1MIE_LENGTH                         0x00000001

#define _IECVEC_CNAIE_POSITION                      0x00000001
#define _IEC_CNAIE_POSITION                         0x0000000D
#define _IEC_CNAIE_MASK                             0x00002000
#define _IEC_CNAIE_LENGTH                           0x00000001

#define _IECVEC_CNBIE_POSITION                      0x00000001
#define _IEC_CNBIE_POSITION                         0x0000000E
#define _IEC_CNBIE_MASK                             0x00004000
#define _IEC_CNBIE_LENGTH                           0x00000001

#define _IECVEC_CNCIE_POSITION                      0x00000001
#define _IEC_CNCIE_POSITION                         0x0000000F
#define _IEC_CNCIE_MASK                             0x00008000
#define _IEC_CNCIE_LENGTH                           0x00000001

#define _IECVEC_PMPIE_POSITION                      0x00000001
#define _IEC_PMPIE_POSITION                         0x00000010
#define _IEC_PMPIE_MASK                             0x00010000
#define _IEC_PMPIE_LENGTH                           0x00000001

#define _IECVEC_PMPEIE_POSITION                     0x00000001
#define _IEC_PMPEIE_POSITION                        0x00000011
#define _IEC_PMPEIE_MASK                            0x00020000
#define _IEC_PMPEIE_LENGTH                          0x00000001

#define _IECVEC_SPI2EIE_POSITION                    0x00000001
#define _IEC_SPI2EIE_POSITION                       0x00000012
#define _IEC_SPI2EIE_MASK                           0x00040000
#define _IEC_SPI2EIE_LENGTH                         0x00000001

#define _IECVEC_SPI2RXIE_POSITION                   0x00000001
#define _IEC_SPI2RXIE_POSITION                      0x00000013
#define _IEC_SPI2RXIE_MASK                          0x00080000
#define _IEC_SPI2RXIE_LENGTH                        0x00000001

#define _IECVEC_SPI2TXIE_POSITION                   0x00000001
#define _IEC_SPI2TXIE_POSITION                      0x00000014
#define _IEC_SPI2TXIE_MASK                          0x00100000
#define _IEC_SPI2TXIE_LENGTH                        0x00000001

#define _IECVEC_U2EIE_POSITION                      0x00000001
#define _IEC_U2EIE_POSITION                         0x00000015
#define _IEC_U2EIE_MASK                             0x00200000
#define _IEC_U2EIE_LENGTH                           0x00000001

#define _IECVEC_U2RXIE_POSITION                     0x00000001
#define _IEC_U2RXIE_POSITION                        0x00000016
#define _IEC_U2RXIE_MASK                            0x00400000
#define _IEC_U2RXIE_LENGTH                          0x00000001

#define _IECVEC_U2TXIE_POSITION                     0x00000001
#define _IEC_U2TXIE_POSITION                        0x00000017
#define _IEC_U2TXIE_MASK                            0x00800000
#define _IEC_U2TXIE_LENGTH                          0x00000001

#define _IECVEC_I2C2BIE_POSITION                    0x00000001
#define _IEC_I2C2BIE_POSITION                       0x00000018
#define _IEC_I2C2BIE_MASK                           0x01000000
#define _IEC_I2C2BIE_LENGTH                         0x00000001

#define _IECVEC_I2C2SIE_POSITION                    0x00000001
#define _IEC_I2C2SIE_POSITION                       0x00000019
#define _IEC_I2C2SIE_MASK                           0x02000000
#define _IEC_I2C2SIE_LENGTH                         0x00000001

#define _IECVEC_I2C2MIE_POSITION                    0x00000001
#define _IEC_I2C2MIE_POSITION                       0x0000001A
#define _IEC_I2C2MIE_MASK                           0x04000000
#define _IEC_I2C2MIE_LENGTH                         0x00000001

#define _IECVEC_CTMUIE_POSITION                     0x00000001
#define _IEC_CTMUIE_POSITION                        0x0000001B
#define _IEC_CTMUIE_MASK                            0x08000000
#define _IEC_CTMUIE_LENGTH                          0x00000001

#define _IECVEC_DMA0IE_POSITION                     0x00000001
#define _IEC_DMA0IE_POSITION                        0x0000001C
#define _IEC_DMA0IE_MASK                            0x10000000
#define _IEC_DMA0IE_LENGTH                          0x00000001

#define _IECVEC_DMA1IE_POSITION                     0x00000001
#define _IEC_DMA1IE_POSITION                        0x0000001D
#define _IEC_DMA1IE_MASK                            0x20000000
#define _IEC_DMA1IE_LENGTH                          0x00000001

#define _IECVEC_DMA2IE_POSITION                     0x00000001
#define _IEC_DMA2IE_POSITION                        0x0000001E
#define _IEC_DMA2IE_MASK                            0x40000000
#define _IEC_DMA2IE_LENGTH                          0x00000001

#define _IECVEC_DMA3IE_POSITION                     0x00000001
#define _IEC_DMA3IE_POSITION                        0x0000001F
#define _IEC_DMA3IE_MASK                            0x80000000
#define _IEC_DMA3IE_LENGTH                          0x00000001

#define _IPCVEC_CTIP_POSITION                       0x00000000
#define _IPC_CTIS_POSITION                          0x00000000
#define _IPC_CTIS_MASK                              0x00000003
#define _IPC_CTIS_LENGTH                            0x00000002
#define _IPC_CTIP_POSITION                          0x00000002
#define _IPC_CTIP_MASK                              0x0000001C
#define _IPC_CTIP_LENGTH                            0x00000003

#define _IPCVEC_CS0IP_POSITION                      0x00000000
#define _IPC_CS0IS_POSITION                         0x00000008
#define _IPC_CS0IS_MASK                             0x00000300
#define _IPC_CS0IS_LENGTH                           0x00000002
#define _IPC_CS0IP_POSITION                         0x0000000A
#define _IPC_CS0IP_MASK                             0x00001C00
#define _IPC_CS0IP_LENGTH                           0x00000003

#define _IPCVEC_CS1IP_POSITION                      0x00000000
#define _IPC_CS1IS_POSITION                         0x00000010
#define _IPC_CS1IS_MASK                             0x00030000
#define _IPC_CS1IS_LENGTH                           0x00000002
#define _IPC_CS1IP_POSITION                         0x00000012
#define _IPC_CS1IP_MASK                             0x001C0000
#define _IPC_CS1IP_LENGTH                           0x00000003

#define _IPCVEC_INT0IP_POSITION                     0x00000000
#define _IPC_INT0IS_POSITION                        0x00000018
#define _IPC_INT0IS_MASK                            0x03000000
#define _IPC_INT0IS_LENGTH                          0x00000002
#define _IPC_INT0IP_POSITION                        0x0000001A
#define _IPC_INT0IP_MASK                            0x1C000000
#define _IPC_INT0IP_LENGTH                          0x00000003

#define _IPCVEC_T1IP_POSITION                       0x00000001
#define _IPC_T1IS_POSITION                          0x00000000
#define _IPC_T1IS_MASK                              0x00000003
#define _IPC_T1IS_LENGTH                            0x00000002
#define _IPC_T1IP_POSITION                          0x00000002
#define _IPC_T1IP_MASK                              0x0000001C
#define _IPC_T1IP_LENGTH                            0x00000003

#define _IPCVEC_IC1IP_POSITION                      0x00000001
#define _IPC_IC1IS_POSITION                         0x00000008
#define _IPC_IC1IS_MASK                             0x00000300
#define _IPC_IC1IS_LENGTH                           0x00000002
#define _IPC_IC1IP_POSITION                         0x0000000A
#define _IPC_IC1IP_MASK                             0x00001C00
#define _IPC_IC1IP_LENGTH                           0x00000003

#define _IPCVEC_OC1IP_POSITION                      0x00000001
#define _IPC_OC1IS_POSITION                         0x00000010
#define _IPC_OC1IS_MASK                             0x00030000
#define _IPC_OC1IS_LENGTH                           0x00000002
#define _IPC_OC1IP_POSITION                         0x00000012
#define _IPC_OC1IP_MASK                             0x001C0000
#define _IPC_OC1IP_LENGTH                           0x00000003

#define _IPCVEC_INT1IP_POSITION                     0x00000001
#define _IPC_INT1IS_POSITION                        0x00000018
#define _IPC_INT1IS_MASK                            0x03000000
#define _IPC_INT1IS_LENGTH                          0x00000002
#define _IPC_INT1IP_POSITION                        0x0000001A
#define _IPC_INT1IP_MASK                            0x1C000000
#define _IPC_INT1IP_LENGTH                          0x00000003

#define _IPCVEC_T2IP_POSITION                       0x00000002
#define _IPC_T2IS_POSITION                          0x00000000
#define _IPC_T2IS_MASK                              0x00000003
#define _IPC_T2IS_LENGTH                            0x00000002
#define _IPC_T2IP_POSITION                          0x00000002
#define _IPC_T2IP_MASK                              0x0000001C
#define _IPC_T2IP_LENGTH                            0x00000003

#define _IPCVEC_IC2IP_POSITION                      0x00000002
#define _IPC_IC2IS_POSITION                         0x00000008
#define _IPC_IC2IS_MASK                             0x00000300
#define _IPC_IC2IS_LENGTH                           0x00000002
#define _IPC_IC2IP_POSITION                         0x0000000A
#define _IPC_IC2IP_MASK                             0x00001C00
#define _IPC_IC2IP_LENGTH                           0x00000003

#define _IPCVEC_OC2IP_POSITION                      0x00000002
#define _IPC_OC2IS_POSITION                         0x00000010
#define _IPC_OC2IS_MASK                             0x00030000
#define _IPC_OC2IS_LENGTH                           0x00000002
#define _IPC_OC2IP_POSITION                         0x00000012
#define _IPC_OC2IP_MASK                             0x001C0000
#define _IPC_OC2IP_LENGTH                           0x00000003

#define _IPCVEC_INT2IP_POSITION                     0x00000002
#define _IPC_INT2IS_POSITION                        0x00000018
#define _IPC_INT2IS_MASK                            0x03000000
#define _IPC_INT2IS_LENGTH                          0x00000002
#define _IPC_INT2IP_POSITION                        0x0000001A
#define _IPC_INT2IP_MASK                            0x1C000000
#define _IPC_INT2IP_LENGTH                          0x00000003

#define _IPCVEC_T3IP_POSITION                       0x00000003
#define _IPC_T3IS_POSITION                          0x00000000
#define _IPC_T3IS_MASK                              0x00000003
#define _IPC_T3IS_LENGTH                            0x00000002
#define _IPC_T3IP_POSITION                          0x00000002
#define _IPC_T3IP_MASK                              0x0000001C
#define _IPC_T3IP_LENGTH                            0x00000003

#define _IPCVEC_IC3IP_POSITION                      0x00000003
#define _IPC_IC3IS_POSITION                         0x00000008
#define _IPC_IC3IS_MASK                             0x00000300
#define _IPC_IC3IS_LENGTH                           0x00000002
#define _IPC_IC3IP_POSITION                         0x0000000A
#define _IPC_IC3IP_MASK                             0x00001C00
#define _IPC_IC3IP_LENGTH                           0x00000003

#define _IPCVEC_OC3IP_POSITION                      0x00000003
#define _IPC_OC3IS_POSITION                         0x00000010
#define _IPC_OC3IS_MASK                             0x00030000
#define _IPC_OC3IS_LENGTH                           0x00000002
#define _IPC_OC3IP_POSITION                         0x00000012
#define _IPC_OC3IP_MASK                             0x001C0000
#define _IPC_OC3IP_LENGTH                           0x00000003

#define _IPCVEC_INT3IP_POSITION                     0x00000003
#define _IPC_INT3IS_POSITION                        0x00000018
#define _IPC_INT3IS_MASK                            0x03000000
#define _IPC_INT3IS_LENGTH                          0x00000002
#define _IPC_INT3IP_POSITION                        0x0000001A
#define _IPC_INT3IP_MASK                            0x1C000000
#define _IPC_INT3IP_LENGTH                          0x00000003

#define _IPCVEC_T4IP_POSITION                       0x00000004
#define _IPC_T4IS_POSITION                          0x00000000
#define _IPC_T4IS_MASK                              0x00000003
#define _IPC_T4IS_LENGTH                            0x00000002
#define _IPC_T4IP_POSITION                          0x00000002
#define _IPC_T4IP_MASK                              0x0000001C
#define _IPC_T4IP_LENGTH                            0x00000003

#define _IPCVEC_IC4IP_POSITION                      0x00000004
#define _IPC_IC4IS_POSITION                         0x00000008
#define _IPC_IC4IS_MASK                             0x00000300
#define _IPC_IC4IS_LENGTH                           0x00000002
#define _IPC_IC4IP_POSITION                         0x0000000A
#define _IPC_IC4IP_MASK                             0x00001C00
#define _IPC_IC4IP_LENGTH                           0x00000003

#define _IPCVEC_OC4IP_POSITION                      0x00000004
#define _IPC_OC4IS_POSITION                         0x00000010
#define _IPC_OC4IS_MASK                             0x00030000
#define _IPC_OC4IS_LENGTH                           0x00000002
#define _IPC_OC4IP_POSITION                         0x00000012
#define _IPC_OC4IP_MASK                             0x001C0000
#define _IPC_OC4IP_LENGTH                           0x00000003

#define _IPCVEC_INT4IP_POSITION                     0x00000004
#define _IPC_INT4IS_POSITION                        0x00000018
#define _IPC_INT4IS_MASK                            0x03000000
#define _IPC_INT4IS_LENGTH                          0x00000002
#define _IPC_INT4IP_POSITION                        0x0000001A
#define _IPC_INT4IP_MASK                            0x1C000000
#define _IPC_INT4IP_LENGTH                          0x00000003

#define _IPCVEC_T5IP_POSITION                       0x00000005
#define _IPC_T5IS_POSITION                          0x00000000
#define _IPC_T5IS_MASK                              0x00000003
#define _IPC_T5IS_LENGTH                            0x00000002
#define _IPC_T5IP_POSITION                          0x00000002
#define _IPC_T5IP_MASK                              0x0000001C
#define _IPC_T5IP_LENGTH                            0x00000003

#define _IPCVEC_IC5IP_POSITION                      0x00000005
#define _IPC_IC5IS_POSITION                         0x00000008
#define _IPC_IC5IS_MASK                             0x00000300
#define _IPC_IC5IS_LENGTH                           0x00000002
#define _IPC_IC5IP_POSITION                         0x0000000A
#define _IPC_IC5IP_MASK                             0x00001C00
#define _IPC_IC5IP_LENGTH                           0x00000003

#define _IPCVEC_OC5IP_POSITION                      0x00000005
#define _IPC_OC5IS_POSITION                         0x00000010
#define _IPC_OC5IS_MASK                             0x00030000
#define _IPC_OC5IS_LENGTH                           0x00000002
#define _IPC_OC5IP_POSITION                         0x00000012
#define _IPC_OC5IP_MASK                             0x001C0000
#define _IPC_OC5IP_LENGTH                           0x00000003

#define _IPCVEC_AD1IP_POSITION                      0x00000005
#define _IPC_AD1IS_POSITION                         0x00000018
#define _IPC_AD1IS_MASK                             0x03000000
#define _IPC_AD1IS_LENGTH                           0x00000002
#define _IPC_AD1IP_POSITION                         0x0000001A
#define _IPC_AD1IP_MASK                             0x1C000000
#define _IPC_AD1IP_LENGTH                           0x00000003

#define _IPCVEC_FSCMIP_POSITION                     0x00000006
#define _IPC_FSCMIS_POSITION                        0x00000000
#define _IPC_FSCMIS_MASK                            0x00000003
#define _IPC_FSCMIS_LENGTH                          0x00000002
#define _IPC_FSCMIP_POSITION                        0x00000002
#define _IPC_FSCMIP_MASK                            0x0000001C
#define _IPC_FSCMIP_LENGTH                          0x00000003

#define _IPCVEC_RTCCIP_POSITION                     0x00000006
#define _IPC_RTCCIS_POSITION                        0x00000008
#define _IPC_RTCCIS_MASK                            0x00000300
#define _IPC_RTCCIS_LENGTH                          0x00000002
#define _IPC_RTCCIP_POSITION                        0x0000000A
#define _IPC_RTCCIP_MASK                            0x00001C00
#define _IPC_RTCCIP_LENGTH                          0x00000003

#define _IPCVEC_FCEIP_POSITION                      0x00000006
#define _IPC_FCEIS_POSITION                         0x00000010
#define _IPC_FCEIS_MASK                             0x00030000
#define _IPC_FCEIS_LENGTH                           0x00000002
#define _IPC_FCEIP_POSITION                         0x00000012
#define _IPC_FCEIP_MASK                             0x001C0000
#define _IPC_FCEIP_LENGTH                           0x00000003

#define _IPCVEC_CMP1IP_POSITION                     0x00000006
#define _IPC_CMP1IS_POSITION                        0x00000018
#define _IPC_CMP1IS_MASK                            0x03000000
#define _IPC_CMP1IS_LENGTH                          0x00000002
#define _IPC_CMP1IP_POSITION                        0x0000001A
#define _IPC_CMP1IP_MASK                            0x1C000000
#define _IPC_CMP1IP_LENGTH                          0x00000003

#define _IPCVEC_CMP2IP_POSITION                     0x00000007
#define _IPC_CMP2IS_POSITION                        0x00000000
#define _IPC_CMP2IS_MASK                            0x00000003
#define _IPC_CMP2IS_LENGTH                          0x00000002
#define _IPC_CMP2IP_POSITION                        0x00000002
#define _IPC_CMP2IP_MASK                            0x0000001C
#define _IPC_CMP2IP_LENGTH                          0x00000003

#define _IPCVEC_CMP3IP_POSITION                     0x00000007
#define _IPC_CMP3IS_POSITION                        0x00000008
#define _IPC_CMP3IS_MASK                            0x00000300
#define _IPC_CMP3IS_LENGTH                          0x00000002
#define _IPC_CMP3IP_POSITION                        0x0000000A
#define _IPC_CMP3IP_MASK                            0x00001C00
#define _IPC_CMP3IP_LENGTH                          0x00000003

#define _IPCVEC_USBIP_POSITION                      0x00000007
#define _IPC_USBIS_POSITION                         0x00000010
#define _IPC_USBIS_MASK                             0x00030000
#define _IPC_USBIS_LENGTH                           0x00000002
#define _IPC_USBIP_POSITION                         0x00000012
#define _IPC_USBIP_MASK                             0x001C0000
#define _IPC_USBIP_LENGTH                           0x00000003

#define _IPCVEC_SPI1IP_POSITION                     0x00000007
#define _IPC_SPI1IS_POSITION                        0x00000018
#define _IPC_SPI1IS_MASK                            0x03000000
#define _IPC_SPI1IS_LENGTH                          0x00000002
#define _IPC_SPI1IP_POSITION                        0x0000001A
#define _IPC_SPI1IP_MASK                            0x1C000000
#define _IPC_SPI1IP_LENGTH                          0x00000003

#define _IPCVEC_U1IP_POSITION                       0x00000008
#define _IPC_U1IS_POSITION                          0x00000000
#define _IPC_U1IS_MASK                              0x00000003
#define _IPC_U1IS_LENGTH                            0x00000002
#define _IPC_U1IP_POSITION                          0x00000002
#define _IPC_U1IP_MASK                              0x0000001C
#define _IPC_U1IP_LENGTH                            0x00000003

#define _IPCVEC_I2C1IP_POSITION                     0x00000008
#define _IPC_I2C1IS_POSITION                        0x00000008
#define _IPC_I2C1IS_MASK                            0x00000300
#define _IPC_I2C1IS_LENGTH                          0x00000002
#define _IPC_I2C1IP_POSITION                        0x0000000A
#define _IPC_I2C1IP_MASK                            0x00001C00
#define _IPC_I2C1IP_LENGTH                          0x00000003

#define _IPCVEC_CNIP_POSITION                       0x00000008
#define _IPC_CNIS_POSITION                          0x00000010
#define _IPC_CNIS_MASK                              0x00030000
#define _IPC_CNIS_LENGTH                            0x00000002
#define _IPC_CNIP_POSITION                          0x00000012
#define _IPC_CNIP_MASK                              0x001C0000
#define _IPC_CNIP_LENGTH                            0x00000003

#define _IPCVEC_PMPIP_POSITION                      0x00000008
#define _IPC_PMPIS_POSITION                         0x00000018
#define _IPC_PMPIS_MASK                             0x03000000
#define _IPC_PMPIS_LENGTH                           0x00000002
#define _IPC_PMPIP_POSITION                         0x0000001A
#define _IPC_PMPIP_MASK                             0x1C000000
#define _IPC_PMPIP_LENGTH                           0x00000003

#define _IPCVEC_SPI2IP_POSITION                     0x00000009
#define _IPC_SPI2IS_POSITION                        0x00000000
#define _IPC_SPI2IS_MASK                            0x00000003
#define _IPC_SPI2IS_LENGTH                          0x00000002
#define _IPC_SPI2IP_POSITION                        0x00000002
#define _IPC_SPI2IP_MASK                            0x0000001C
#define _IPC_SPI2IP_LENGTH                          0x00000003

#define _IPCVEC_U2IP_POSITION                       0x00000009
#define _IPC_U2IS_POSITION                          0x00000008
#define _IPC_U2IS_MASK                              0x00000300
#define _IPC_U2IS_LENGTH                            0x00000002
#define _IPC_U2IP_POSITION                          0x0000000A
#define _IPC_U2IP_MASK                              0x00001C00
#define _IPC_U2IP_LENGTH                            0x00000003

#define _IPCVEC_I2C2IP_POSITION                     0x00000009
#define _IPC_I2C2IS_POSITION                        0x00000010
#define _IPC_I2C2IS_MASK                            0x00030000
#define _IPC_I2C2IS_LENGTH                          0x00000002
#define _IPC_I2C2IP_POSITION                        0x00000012
#define _IPC_I2C2IP_MASK                            0x001C0000
#define _IPC_I2C2IP_LENGTH                          0x00000003

#define _IPCVEC_CTMUIP_POSITION                     0x00000009
#define _IPC_CTMUIS_POSITION                        0x00000018
#define _IPC_CTMUIS_MASK                            0x03000000
#define _IPC_CTMUIS_LENGTH                          0x00000002
#define _IPC_CTMUIP_POSITION                        0x0000001A
#define _IPC_CTMUIP_MASK                            0x1C000000
#define _IPC_CTMUIP_LENGTH                          0x00000003

#define _IPCVEC_DMA0IP_POSITION                     0x0000000A
#define _IPC_DMA0IS_POSITION                        0x00000000
#define _IPC_DMA0IS_MASK                            0x00000003
#define _IPC_DMA0IS_LENGTH                          0x00000002
#define _IPC_DMA0IP_POSITION                        0x00000002
#define _IPC_DMA0IP_MASK                            0x0000001C
#define _IPC_DMA0IP_LENGTH                          0x00000003

#define _IPCVEC_DMA1IP_POSITION                     0x0000000A
#define _IPC_DMA1IS_POSITION                        0x00000008
#define _IPC_DMA1IS_MASK                            0x00000300
#define _IPC_DMA1IS_LENGTH                          0x00000002
#define _IPC_DMA1IP_POSITION                        0x0000000A
#define _IPC_DMA1IP_MASK                            0x00001C00
#define _IPC_DMA1IP_LENGTH                          0x00000003

#define _IPCVEC_DMA2IP_POSITION                     0x0000000A
#define _IPC_DMA2IS_POSITION                        0x00000010
#define _IPC_DMA2IS_MASK                            0x00030000
#define _IPC_DMA2IS_LENGTH                          0x00000002
#define _IPC_DMA2IP_POSITION                        0x00000012
#define _IPC_DMA2IP_MASK                            0x001C0000
#define _IPC_DMA2IP_LENGTH                          0x00000003

#define _IPCVEC_DMA3IP_POSITION                     0x0000000A
#define _IPC_DMA3IS_POSITION                        0x00000018
#define _IPC_DMA3IS_MASK                            0x03000000
#define _IPC_DMA3IS_LENGTH                          0x00000002
#define _IPC_DMA3IP_POSITION                        0x0000001A
#define _IPC_DMA3IP_MASK                            0x1C000000
#define _IPC_DMA3IP_LENGTH                          0x00000003

/**
 * Vector Numbers 
 */
#define _CORE_TIMER_VECTOR                          0
#define _CORE_SOFTWARE_0_VECTOR                     1
#define _CORE_SOFTWARE_1_VECTOR                     2
#define _EXTERNAL_0_VECTOR                          3
#define _TIMER_1_VECTOR                             4
#define _INPUT_CAPTURE_1_VECTOR                     5
#define _OUTPUT_COMPARE_1_VECTOR                    6
#define _EXTERNAL_1_VECTOR                          7
#define _TIMER_2_VECTOR                             8
#define _INPUT_CAPTURE_2_VECTOR                     9
#define _OUTPUT_COMPARE_2_VECTOR                    10
#define _EXTERNAL_2_VECTOR                          11
#define _TIMER_3_VECTOR                             12
#define _INPUT_CAPTURE_3_VECTOR                     13
#define _OUTPUT_COMPARE_3_VECTOR                    14
#define _EXTERNAL_3_VECTOR                          15
#define _TIMER_4_VECTOR                             16
#define _INPUT_CAPTURE_4_VECTOR                     17
#define _OUTPUT_COMPARE_4_VECTOR                    18
#define _EXTERNAL_4_VECTOR                          19
#define _TIMER_5_VECTOR                             20
#define _INPUT_CAPTURE_5_VECTOR                     21
#define _OUTPUT_COMPARE_5_VECTOR                    22
#define _ADC_VECTOR                                 23
#define _FAIL_SAFE_MONITOR_VECTOR                   24
#define _RTCC_VECTOR                                25
#define _FCE_VECTOR                                 26
#define _COMPARATOR_1_VECTOR                        27
#define _COMPARATOR_2_VECTOR                        28
#define _COMPARATOR_3_VECTOR                        29
#define _USB_1_VECTOR                               30
#define _SPI_1_VECTOR                               31
#define _UART_1_VECTOR                              32
#define _I2C_1_VECTOR                               33
#define _CHANGE_NOTICE_VECTOR                       34
#define _PMP_VECTOR                                 35
#define _SPI_2_VECTOR                               36
#define _UART_2_VECTOR                              37
#define _I2C_2_VECTOR                               38
#define _CTMU_VECTOR                                39
#define _DMA_0_VECTOR                               40
#define _DMA_1_VECTOR                               41
#define _DMA_2_VECTOR                               42
#define _DMA_3_VECTOR                               43

/**
 * IRQ Numbers
 */
#define _CORE_TIMER_IRQ                             0
#define _CORE_SOFTWARE_0_IRQ                        1
#define _CORE_SOFTWARE_1_IRQ                        2
#define _EXTERNAL_0_IRQ                             3
#define _TIMER_1_IRQ                                4
#define _INPUT_CAPTURE_ERROR_1_IRQ                  5
#define _INPUT_CAPTURE_1_IRQ                        6
#define _OUTPUT_COMPARE_1_IRQ                       7
#define _EXTERNAL_1_IRQ                             8
#define _TIMER_2_IRQ                                9
#define _INPUT_CAPTURE_ERROR_2_IRQ                  10
#define _INPUT_CAPTURE_2_IRQ                        11
#define _OUTPUT_COMPARE_2_IRQ                       12
#define _EXTERNAL_2_IRQ                             13
#define _TIMER_3_IRQ                                14
#define _INPUT_CAPTURE_ERROR_3_IRQ                  15
#define _INPUT_CAPTURE_3_IRQ                        16
#define _OUTPUT_COMPARE_3_IRQ                       17
#define _EXTERNAL_3_IRQ                             18
#define _TIMER_4_IRQ                                19
#define _INPUT_CAPTURE_ERROR_4_IRQ                  20
#define _INPUT_CAPTURE_4_IRQ                        21
#define _OUTPUT_COMPARE_4_IRQ                       22
#define _EXTERNAL_4_IRQ                             23
#define _TIMER_5_IRQ                                24
#define _INPUT_CAPTURE_ERROR_5_IRQ                  25
#define _INPUT_CAPTURE_5_IRQ                        26
#define _OUTPUT_COMPARE_5_IRQ                       27
#define _ADC_IRQ                                    28
#define _FAIL_SAFE_MONITOR_IRQ                      29
#define _RTCC_IRQ                                   30
#define _FLASH_CONTROL_IRQ                          31
#define _COMPARATOR_1_IRQ                           32
#define _COMPARATOR_2_IRQ                           33
#define _COMPARATOR_3_IRQ                           34
#define _USB_IRQ                                    35
#define _SPI1_ERR_IRQ                               36
#define _SPI1_RX_IRQ                                37
#define _SPI1_TX_IRQ                                38
#define _UART1_ERR_IRQ                              39
#define _UART1_RX_IRQ                               40
#define _UART1_TX_IRQ                               41
#define _I2C1_BUS_IRQ                               42
#define _I2C1_SLAVE_IRQ                             43
#define _I2C1_MASTER_IRQ                            44
#define _CHANGE_NOTICE_A_IRQ                        45
#define _CHANGE_NOTICE_B_IRQ                        46
#define _CHANGE_NOTICE_C_IRQ                        47
#define _PMP_IRQ                                    48
#define _PMP_ERROR_IRQ                              49
#define _SPI2_ERR_IRQ                               50
#define _SPI2_RX_IRQ                                51
#define _SPI2_TX_IRQ                                52
#define _UART2_ERR_IRQ                              53
#define _UART2_RX_IRQ                               54
#define _UART2_TX_IRQ                               55
#define _I2C2_BUS_IRQ                               56
#define _I2C2_SLAVE_IRQ                             57
#define _I2C2_MASTER_IRQ                            58
#define _CTMU_IRQ                                   59
#define _DMA0_IRQ                                   60
#define _DMA1_IRQ                                   61
#define _DMA2_IRQ                                   62
#define _DMA3_IRQ                                   63

/**
 * Peripheral Pin Select
 */



#define _PPS_V_POS_MASK                             0x000000FF

#define _PPS_GROUP_MASK                             0x00000F00

#define _PPS_VALUE_MASK                             0x0000F000
#define _PPS_VALUE_POSITION                         0x0000000C

#define _OUT                                        0x000F0000

#define _P00                                        0x00000000
#define _P01                                        0x00000001
#define _P02                                        0x00000002
#define _P03                                        0x00000003
#define _P04                                        0x00000004
#define _P05                                        0x00000005
#define _P06                                        0x00000006
#define _P07                                        0x00000007
#define _P08                                        0x00000008
#define _P09                                        0x00000009
#define _P0A                                        0x0000000A
#define _P0B                                        0x0000000B
#define _P0C                                        0x0000000C
#define _P0D                                        0x0000000D
#define _P0E                                        0x0000000E
#define _P0F                                        0x0000000F

#define _P10                                        0x00000010
#define _P11                                        0x00000011
#define _P12                                        0x00000012
#define _P13                                        0x00000013
#define _P14                                        0x00000014
#define _P15                                        0x00000015
#define _P16                                        0x00000016
#define _P17                                        0x00000017
#define _P18                                        0x00000018
#define _P19                                        0x00000019
#define _P1A                                        0x0000001A
#define _P1B                                        0x0000001B
#define _P1C                                        0x0000001C
#define _P1D                                        0x0000001D
#define _P1E                                        0x0000001E
#define _P1F                                        0x0000001F

#define _P20                                        0x00000020
#define _P21                                        0x00000021
#define _P22                                        0x00000022
#define _P23                                        0x00000023
#define _P24                                        0x00000024
#define _P25                                        0x00000025
#define _P26                                        0x00000026
#define _P27                                        0x00000027
#define _P28                                        0x00000028
#define _P29                                        0x00000029
#define _P2A                                        0x0000002A
#define _P2B                                        0x0000002B
#define _P2C                                        0x0000002C
#define _P2D                                        0x0000002D
#define _P2E                                        0x0000002E
#define _P2F                                        0x0000002F

#define _G01                                        0x00000100
#define _G02                                        0x00000200
#define _G03                                        0x00000400
#define _G04                                        0x00000800

#define _V00                                        0x00000000
#define _V01                                        0x00001000
#define _V02                                        0x00002000
#define _V03                                        0x00003000
#define _V04                                        0x00004000
#define _V05                                        0x00005000
#define _V06                                        0x00006000
#define _V07                                        0x00007000
#define _V08                                        0x00008000
#define _V09                                        0x00009000
#define _V0A                                        0x0000A000
#define _V0B                                        0x0000B000
#define _V0C                                        0x0000C000
#define _V0D                                        0x0000D000
#define _V0E                                        0x0000E000
#define _V0F                                        0x0000F000

/*  INPUT PPS                                                                   */

#define INT1R                                       (_P00 | _G04)
#define INT2R                                       (_P01 | _G03)
#define INT3R                                       (_P02 | _G02)
#define INT4R                                       (_P03 | _G01)
#define T2CKR                                       (_P05 | _G01)
#define T3CKR                                       (_P06 | _G02)
#define T4CKR                                       (_P07 | _G03)
#define T5CKR                                       (_P08 | _G04)
#define IC1R                                        (_P09 | _G03)
#define IC2R                                        (_P0A | _G04)
#define IC3R                                        (_P0B | _G02)
#define IC4R                                        (_P0C | _G01)
#define IC5R                                        (_P0D | _G03)
#define OCFAR                                       (_P11 | _G04)
#define OCFBR                                       (_P12 | _G03)
#define U1RXR                                       (_P13 | _G03)
#define U1CTSR                                      (_P14 | _G02)
#define U2RXR                                       (_P15 | _G02)
#define U2CTSR                                      (_P16 | _G03)
#define SDI1R                                       (_P20 | _G02)
#define SS1R                                        (_P21 | _G01)
#define SDI2R                                       (_P23 | _G03)
#define SS2R                                        (_P24 | _G04)
#define REFCLKIR                                    (_P24 | _G01)

/*  PPS                                                                         */

#define RPA0R                                       (_P00 | _G01 | _V00)
#define RPA1R                                       (_P01 | _G02 | _V00)
#define RPA2R                                       (_P02 | _G03 | _V00)
#define RPA3R                                       (_P03 | _G04 | _V00)
#define RPA4R                                       (_P04 | _G03 | _V02)
#define RPA8R                                       (_P08 | _G02 | _V05)
#define RPA9R                                       (_P09 | _G02 | _V07)

#define RPB0R                                       (_P0B | _G04 | _V02)
#define RPB1R                                       (_P0C | _G01 | _V03)
#define RPB2R                                       (_P0D | _G03 | _V04)
#define RPB3R                                       (_P0E | _G01 | _V01)
#define RPB4R                                       (_P0F | _G01 | _V02)
#define RPB5R                                       (_P10 | _G02 | _V01)
#define RPB7R                                       (_P12 | _G01 | _V04)
#define RPB8R                                       (_P13 | _G02 | _V04)
#define RPB9R                                       (_P14 | _G04 | _V04)
#define RPB10R                                      (_P15 | _G04 | _V03)
#define RPB11R                                      (_P16 | _G02 | _V03)
#define RPB13R                                      (_P18 | _G03 | _V03)
#define RPB14R                                      (_P19 | _G04 | _V01)
#define RPB15R                                      (_P1A | _G01 | _V03)

#define RPC0R                                       (_P1B | _G01 | _V06)
#define RPC1R                                       (_P1C | _G03 | _V06)
#define RPC2R                                       (_P1D | _G04 | _V06)
#define RPC3R                                       (_P1E | _G03 | _V07)
#define RPC4R                                       (_P1F | _G04 | _V07)
#define RPC5R                                       (_P20 | _G01 | _V07)
#define RPC6R                                       (_P21 | _G03 | _V05)
#define RPC7R                                       (_P22 | _G01 | _V05)
#define RPC8R                                       (_P23 | _G02 | _V06)
#define RPC9R                                       (_P24 | _G04 | _V05)

#define _PPS_NOCONNECT_                             (_G1 | _G2 | _G3 | _G4)

#define U1TXR                                       (_V01 | _G01 | _OUT)
#define U2RTSR                                      (_V02 | _G01 | _OUT)
#define SS1OUTR                                     (_V03 | _G01 | _OUT)
#define OC1R                                        (_V05 | _G01 | _OUT)
#define C2OUTR                                      (_V07 | _G01 | _OUT)

#define SDO1R                                       (_V03 | _G02 | _G03 | _OUT)
#define SDO2R                                       (_V04 | _G02 | _G03 | _OUT)
#define OC2R                                        (_V05 | _G02 | _OUT)
#define C3OUTR                                      (_V07 | _G02 | _OUT)

#define OC4R                                        (_V05 | _G03 | _OUT)
#define OC5R                                        (_V06 | _G03 | _OUT)
#define REFCLKOR                                    (_V07 | _G03 | _OUT)

#define U1RTSR                                      (_V01 | _G04 | _OUT)
#define U2TXR                                       (_V02 | _G04 | _OUT)
#define SS2OUTR                                     (_V04 | _G04 | _OUT)
#define OC3R                                        (_V05 | _G04 | _OUT)
#define C1OUTR                                      (_V07 | _G04 | _OUT)

/**
 * Inter Integrated Circuit
 */

#define _I2CxCON_SEN_POSITION                    0x00000000
#define _I2CxCON_SEN_MASK                        0x00000001
#define _I2CxCON_SEN_LENGTH                      0x00000001

#define _I2CxCON_RSEN_POSITION                   0x00000001
#define _I2CxCON_RSEN_MASK                       0x00000002
#define _I2CxCON_RSEN_LENGTH                     0x00000001

#define _I2CxCON_PEN_POSITION                    0x00000002
#define _I2CxCON_PEN_MASK                        0x00000004
#define _I2CxCON_PEN_LENGTH                      0x00000001

#define _I2CxCON_RCEN_POSITION                   0x00000003
#define _I2CxCON_RCEN_MASK                       0x00000008
#define _I2CxCON_RCEN_LENGTH                     0x00000001

#define _I2CxCON_ACKEN_POSITION                  0x00000004
#define _I2CxCON_ACKEN_MASK                      0x00000010
#define _I2CxCON_ACKEN_LENGTH                    0x00000001

#define _I2CxCON_ACKDT_POSITION                  0x00000005
#define _I2CxCON_ACKDT_MASK                      0x00000020
#define _I2CxCON_ACKDT_LENGTH                    0x00000001

#define _I2CxCON_STREN_POSITION                  0x00000006
#define _I2CxCON_STREN_MASK                      0x00000040
#define _I2CxCON_STREN_LENGTH                    0x00000001

#define _I2CxCON_GCEN_POSITION                   0x00000007
#define _I2CxCON_GCEN_MASK                       0x00000080
#define _I2CxCON_GCEN_LENGTH                     0x00000001

#define _I2CxCON_SMEN_POSITION                   0x00000008
#define _I2CxCON_SMEN_MASK                       0x00000100
#define _I2CxCON_SMEN_LENGTH                     0x00000001

#define _I2CxCON_DISSLW_POSITION                 0x00000009
#define _I2CxCON_DISSLW_MASK                     0x00000200
#define _I2CxCON_DISSLW_LENGTH                   0x00000001

#define _I2CxCON_A10M_POSITION                   0x0000000A
#define _I2CxCON_A10M_MASK                       0x00000400
#define _I2CxCON_A10M_LENGTH                     0x00000001

#define _I2CxCON_STRICT_POSITION                 0x0000000B
#define _I2CxCON_STRICT_MASK                     0x00000800
#define _I2CxCON_STRICT_LENGTH                   0x00000001

#define _I2CxCON_SCLREL_POSITION                 0x0000000C
#define _I2CxCON_SCLREL_MASK                     0x00001000
#define _I2CxCON_SCLREL_LENGTH                   0x00000001

#define _I2CxCON_SIDL_POSITION                   0x0000000D
#define _I2CxCON_SIDL_MASK                       0x00002000
#define _I2CxCON_SIDL_LENGTH                     0x00000001

#define _I2CxCON_ON_POSITION                     0x0000000F
#define _I2CxCON_ON_MASK                         0x00008000
#define _I2CxCON_ON_LENGTH                       0x00000001

#define _I2CxCON_IPMIEN_POSITION                 0x0000000B
#define _I2CxCON_IPMIEN_MASK                     0x00000800
#define _I2CxCON_IPMIEN_LENGTH                   0x00000001

#define _I2CxCON_I2CSIDL_POSITION                0x0000000D
#define _I2CxCON_I2CSIDL_MASK                    0x00002000
#define _I2CxCON_I2CSIDL_LENGTH                  0x00000001

#define _I2CxCON_I2CEN_POSITION                  0x0000000F
#define _I2CxCON_I2CEN_MASK                      0x00008000
#define _I2CxCON_I2CEN_LENGTH                    0x00000001

#define _I2CxCON_w_POSITION                      0x00000000
#define _I2CxCON_w_MASK                          0xFFFFFFFF
#define _I2CxCON_w_LENGTH                        0x00000020

#define _I2CxSTAT_TBF_POSITION                   0x00000000
#define _I2CxSTAT_TBF_MASK                       0x00000001
#define _I2CxSTAT_TBF_LENGTH                     0x00000001

#define _I2CxSTAT_RBF_POSITION                   0x00000001
#define _I2CxSTAT_RBF_MASK                       0x00000002
#define _I2CxSTAT_RBF_LENGTH                     0x00000001

#define _I2CxSTAT_R_W_POSITION                   0x00000002
#define _I2CxSTAT_R_W_MASK                       0x00000004
#define _I2CxSTAT_R_W_LENGTH                     0x00000001

#define _I2CxSTAT_S_POSITION                     0x00000003
#define _I2CxSTAT_S_MASK                         0x00000008
#define _I2CxSTAT_S_LENGTH                       0x00000001

#define _I2CxSTAT_P_POSITION                     0x00000004
#define _I2CxSTAT_P_MASK                         0x00000010
#define _I2CxSTAT_P_LENGTH                       0x00000001

#define _I2CxSTAT_D_A_POSITION                   0x00000005
#define _I2CxSTAT_D_A_MASK                       0x00000020
#define _I2CxSTAT_D_A_LENGTH                     0x00000001

#define _I2CxSTAT_I2COV_POSITION                 0x00000006
#define _I2CxSTAT_I2COV_MASK                     0x00000040
#define _I2CxSTAT_I2COV_LENGTH                   0x00000001

#define _I2CxSTAT_IWCOL_POSITION                 0x00000007
#define _I2CxSTAT_IWCOL_MASK                     0x00000080
#define _I2CxSTAT_IWCOL_LENGTH                   0x00000001

#define _I2CxSTAT_ADD10_POSITION                 0x00000008
#define _I2CxSTAT_ADD10_MASK                     0x00000100
#define _I2CxSTAT_ADD10_LENGTH                   0x00000001

#define _I2CxSTAT_GCSTAT_POSITION                0x00000009
#define _I2CxSTAT_GCSTAT_MASK                    0x00000200
#define _I2CxSTAT_GCSTAT_LENGTH                  0x00000001

#define _I2CxSTAT_BCL_POSITION                   0x0000000A
#define _I2CxSTAT_BCL_MASK                       0x00000400
#define _I2CxSTAT_BCL_LENGTH                     0x00000001

#define _I2CxSTAT_TRSTAT_POSITION                0x0000000E
#define _I2CxSTAT_TRSTAT_MASK                    0x00004000
#define _I2CxSTAT_TRSTAT_LENGTH                  0x00000001

#define _I2CxSTAT_ACKSTAT_POSITION               0x0000000F
#define _I2CxSTAT_ACKSTAT_MASK                   0x00008000
#define _I2CxSTAT_ACKSTAT_LENGTH                 0x00000001

#define _I2CxSTAT_I2CPOV_POSITION                0x00000006
#define _I2CxSTAT_I2CPOV_MASK                    0x00000040
#define _I2CxSTAT_I2CPOV_LENGTH                  0x00000001

#define _I2CxSTAT_w_POSITION                     0x00000000
#define _I2CxSTAT_w_MASK                         0xFFFFFFFF
#define _I2CxSTAT_w_LENGTH                       0x00000020
        
/**
 * UART
 */
        
#define _UxMODE_STSEL_POSITION                   0x00000000
#define _UxMODE_STSEL_MASK                       0x00000001
#define _UxMODE_STSEL_LENGTH                     0x00000001

#define _UxMODE_PDSEL_POSITION                   0x00000001
#define _UxMODE_PDSEL_MASK                       0x00000006
#define _UxMODE_PDSEL_LENGTH                     0x00000002

#define _UxMODE_BRGH_POSITION                    0x00000003
#define _UxMODE_BRGH_MASK                        0x00000008
#define _UxMODE_BRGH_LENGTH                      0x00000001

#define _UxMODE_RXINV_POSITION                   0x00000004
#define _UxMODE_RXINV_MASK                       0x00000010
#define _UxMODE_RXINV_LENGTH                     0x00000001

#define _UxMODE_ABAUD_POSITION                   0x00000005
#define _UxMODE_ABAUD_MASK                       0x00000020
#define _UxMODE_ABAUD_LENGTH                     0x00000001

#define _UxMODE_LPBACK_POSITION                  0x00000006
#define _UxMODE_LPBACK_MASK                      0x00000040
#define _UxMODE_LPBACK_LENGTH                    0x00000001

#define _UxMODE_WAKE_POSITION                    0x00000007
#define _UxMODE_WAKE_MASK                        0x00000080
#define _UxMODE_WAKE_LENGTH                      0x00000001

#define _UxMODE_UEN_POSITION                     0x00000008
#define _UxMODE_UEN_MASK                         0x00000300
#define _UxMODE_UEN_LENGTH                       0x00000002

#define _UxMODE_RTSMD_POSITION                   0x0000000B
#define _UxMODE_RTSMD_MASK                       0x00000800
#define _UxMODE_RTSMD_LENGTH                     0x00000001

#define _UxMODE_IREN_POSITION                    0x0000000C
#define _UxMODE_IREN_MASK                        0x00001000
#define _UxMODE_IREN_LENGTH                      0x00000001

#define _UxMODE_SIDL_POSITION                    0x0000000D
#define _UxMODE_SIDL_MASK                        0x00002000
#define _UxMODE_SIDL_LENGTH                      0x00000001

#define _UxMODE_ON_POSITION                      0x0000000F
#define _UxMODE_ON_MASK                          0x00008000
#define _UxMODE_ON_LENGTH                        0x00000001

#define _UxMODE_PDSEL0_POSITION                  0x00000001
#define _UxMODE_PDSEL0_MASK                      0x00000002
#define _UxMODE_PDSEL0_LENGTH                    0x00000001

#define _UxMODE_PDSEL1_POSITION                  0x00000002
#define _UxMODE_PDSEL1_MASK                      0x00000004
#define _UxMODE_PDSEL1_LENGTH                    0x00000001

#define _UxMODE_UEN0_POSITION                    0x00000008
#define _UxMODE_UEN0_MASK                        0x00000100
#define _UxMODE_UEN0_LENGTH                      0x00000001

#define _UxMODE_UEN1_POSITION                    0x00000009
#define _UxMODE_UEN1_MASK                        0x00000200
#define _UxMODE_UEN1_LENGTH                      0x00000001

#define _UxMODE_USIDL_POSITION                   0x0000000D
#define _UxMODE_USIDL_MASK                       0x00002000
#define _UxMODE_USIDL_LENGTH                     0x00000001

#define _UxMODE_UARTEN_POSITION                  0x0000000F
#define _UxMODE_UARTEN_MASK                      0x00008000
#define _UxMODE_UARTEN_LENGTH                    0x00000001

#define _UxMODE_w_POSITION                       0x00000000
#define _UxMODE_w_MASK                           0xFFFFFFFF
#define _UxMODE_w_LENGTH                         0x00000020
        
#define _UxSTA_URXDA_POSITION                    0x00000000
#define _UxSTA_URXDA_MASK                        0x00000001
#define _UxSTA_URXDA_LENGTH                      0x00000001

#define _UxSTA_OERR_POSITION                     0x00000001
#define _UxSTA_OERR_MASK                         0x00000002
#define _UxSTA_OERR_LENGTH                       0x00000001

#define _UxSTA_FERR_POSITION                     0x00000002
#define _UxSTA_FERR_MASK                         0x00000004
#define _UxSTA_FERR_LENGTH                       0x00000001

#define _UxSTA_PERR_POSITION                     0x00000003
#define _UxSTA_PERR_MASK                         0x00000008
#define _UxSTA_PERR_LENGTH                       0x00000001

#define _UxSTA_RIDLE_POSITION                    0x00000004
#define _UxSTA_RIDLE_MASK                        0x00000010
#define _UxSTA_RIDLE_LENGTH                      0x00000001

#define _UxSTA_ADDEN_POSITION                    0x00000005
#define _UxSTA_ADDEN_MASK                        0x00000020
#define _UxSTA_ADDEN_LENGTH                      0x00000001

#define _UxSTA_URXISEL_POSITION                  0x00000006
#define _UxSTA_URXISEL_MASK                      0x000000C0
#define _UxSTA_URXISEL_LENGTH                    0x00000002

#define _UxSTA_TRMT_POSITION                     0x00000008
#define _UxSTA_TRMT_MASK                         0x00000100
#define _UxSTA_TRMT_LENGTH                       0x00000001

#define _UxSTA_UTXBF_POSITION                    0x00000009
#define _UxSTA_UTXBF_MASK                        0x00000200
#define _UxSTA_UTXBF_LENGTH                      0x00000001

#define _UxSTA_UTXEN_POSITION                    0x0000000A
#define _UxSTA_UTXEN_MASK                        0x00000400
#define _UxSTA_UTXEN_LENGTH                      0x00000001

#define _UxSTA_UTXBRK_POSITION                   0x0000000B
#define _UxSTA_UTXBRK_MASK                       0x00000800
#define _UxSTA_UTXBRK_LENGTH                     0x00000001

#define _UxSTA_URXEN_POSITION                    0x0000000C
#define _UxSTA_URXEN_MASK                        0x00001000
#define _UxSTA_URXEN_LENGTH                      0x00000001

#define _UxSTA_UTXINV_POSITION                   0x0000000D
#define _UxSTA_UTXINV_MASK                       0x00002000
#define _UxSTA_UTXINV_LENGTH                     0x00000001

#define _UxSTA_UTXISEL_POSITION                  0x0000000E
#define _UxSTA_UTXISEL_MASK                      0x0000C000
#define _UxSTA_UTXISEL_LENGTH                    0x00000002

#define _UxSTA_ADDR_POSITION                     0x00000010
#define _UxSTA_ADDR_MASK                         0x00FF0000
#define _UxSTA_ADDR_LENGTH                       0x00000008

#define _UxSTA_ADM_EN_POSITION                   0x00000018
#define _UxSTA_ADM_EN_MASK                       0x01000000
#define _UxSTA_ADM_EN_LENGTH                     0x00000001

#define _UxSTA_URXISEL0_POSITION                 0x00000006
#define _UxSTA_URXISEL0_MASK                     0x00000040
#define _UxSTA_URXISEL0_LENGTH                   0x00000001

#define _UxSTA_URXISEL1_POSITION                 0x00000007
#define _UxSTA_URXISEL1_MASK                     0x00000080
#define _UxSTA_URXISEL1_LENGTH                   0x00000001

#define _UxSTA_UTXISEL0_POSITION                 0x0000000E
#define _UxSTA_UTXISEL0_MASK                     0x00004000
#define _UxSTA_UTXISEL0_LENGTH                   0x00000001

#define _UxSTA_UTXISEL1_POSITION                 0x0000000F
#define _UxSTA_UTXISEL1_MASK                     0x00008000
#define _UxSTA_UTXISEL1_LENGTH                   0x00000001

#define _UxSTA_UTXSEL_POSITION                   0x0000000E
#define _UxSTA_UTXSEL_MASK                       0x0000C000
#define _UxSTA_UTXSEL_LENGTH                     0x00000002

#define _UxSTA_w_POSITION                        0x00000000
#define _UxSTA_w_MASK                            0xFFFFFFFF
#define _UxSTA_w_LENGTH                          0x00000020

/**
 * Device ID, Revision, Config and Syskey
 */

#define _DEVID_VER_POSITION                      0x0000001C
#define _DEVID_VER_MASK                          0xF0000000
#define _DEVID_VER_LENGTH                        0x00000004

#define _CFGCON_TDOEN_POSITION                   0x00000000
#define _CFGCON_TDOEN_MASK                       0x00000001
#define _CFGCON_TDOEN_LENGTH                     0x00000001

#define _CFGCON_JTAGEN_POSITION                  0x00000003
#define _CFGCON_JTAGEN_MASK                      0x00000008
#define _CFGCON_JTAGEN_LENGTH                    0x00000001

#define _CFGCON_PMDLOCK_POSITION                 0x0000000C
#define _CFGCON_PMDLOCK_MASK                     0x00001000
#define _CFGCON_PMDLOCK_LENGTH                   0x00000001

#define _CFGCON_IOLOCK_POSITION                  0x0000000D
#define _CFGCON_IOLOCK_MASK                      0x00002000
#define _CFGCON_IOLOCK_LENGTH                    0x00000001

#define _DEVID_DEVID_POSITION                    0x00000000
#define _DEVID_DEVID_MASK                        0x0FFFFFFF
#define _DEVID_DEVID_LENGTH                      0x0000001C

#endif // AP32MX270F256D_H