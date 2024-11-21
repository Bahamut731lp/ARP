    LIST

;==========================================================================
; Build date : 6 dec 2023
;  pic-as PIC16F1508 processor include
; 
;  (c) Copyright 1999-2015 Microchip Technology, All rights reserved
;==========================================================================

    NOLIST

;==========================================================================
;  This header file defines configurations, registers, and other useful
;  bits of information for the PIC16F1508 microcontroller.  These names
;  are taken to match the data sheets as closely as possible.
;
;  Note that the processor must be selected before this file is included.
;  The processor may be selected the following ways:
;
;       1. Command line switch:
;               C:\MPASM MYFILE.ASM /PIC16F1508
;       2. LIST directive in the source file
;               LIST   P=PIC16F1508
;       3. Processor Type entry in the MPASM full-screen interface
;       4. Setting the processor in the MPLAB Project Dialog
;==========================================================================
;;;; Begin: Added in gputils

;==========================================================================
;
;       Gputils Specific Revision History
;
;==========================================================================

;       12 Jul 2014  Added the _DEBUG_ON and _DEBUG_OFF config options.
;;;; End: Added in gputils

;==========================================================================
;
;       Verify Processor
;
;==========================================================================
	;todo is it needed

;        IFNDEF __16F1508
;           MESSG "Processor-header file mismatch.  Verify selected processor."
;        ENDIF



;==========================================================================
;
;       Register Definitions
;
;==========================================================================

;W                EQU  0x0000
F                EQU  0x0001

;----- Register Files -----------------------------------------------------

;-----Bank0------------------
INDF0            EQU  0x0000
INDF1            EQU  0x0001
PCL              EQU  0x0002
STATUS           EQU  0x0003
FSR0             EQU  0x0004
FSR0L            EQU  0x0004
FSR0H            EQU  0x0005
FSR1             EQU  0x0006
FSR1L            EQU  0x0006
FSR1H            EQU  0x0007
BSR              EQU  0x0008
WREG             EQU  0x0009
PCLATH           EQU  0x000A
INTCON           EQU  0x000B
PORTA            EQU  0x000C
PORTB            EQU  0x000D
PORTC            EQU  0x000E
PIR1             EQU  0x0011
PIR2             EQU  0x0012
PIR3             EQU  0x0013
TMR0             EQU  0x0015
TMR1             EQU  0x0016
TMR1L            EQU  0x0016
TMR1H            EQU  0x0017
T1CON            EQU  0x0018
T1GCON           EQU  0x0019
TMR2             EQU  0x001A
PR2              EQU  0x001B
T2CON            EQU  0x001C

;-----Bank1------------------
TRISA            EQU  0x008C
TRISB            EQU  0x008D
TRISC            EQU  0x008E
PIE1             EQU  0x0091
PIE2             EQU  0x0092
PIE3             EQU  0x0093
OPTION_REG       EQU  0x0095
PCON             EQU  0x0096
WDTCON           EQU  0x0097
OSCCON           EQU  0x0099
OSCSTAT          EQU  0x009A
ADRES            EQU  0x009B
ADRESL           EQU  0x009B
ADRESH           EQU  0x009C
ADCON0           EQU  0x009D
ADCON1           EQU  0x009E
ADCON2           EQU  0x009F

;-----Bank2------------------
LATA             EQU  0x010C
LATB             EQU  0x010D
LATC             EQU  0x010E
CM1CON0          EQU  0x0111
CM1CON1          EQU  0x0112
CM2CON0          EQU  0x0113
CM2CON1          EQU  0x0114
CMOUT            EQU  0x0115
BORCON           EQU  0x0116
FVRCON           EQU  0x0117
DACCON0          EQU  0x0118
DACCON1          EQU  0x0119
APFCON           EQU  0x011D

;-----Bank3------------------
ANSELA           EQU  0x018C
ANSELB           EQU  0x018D
ANSELC           EQU  0x018E
PMADR            EQU  0x0191
PMADRL           EQU  0x0191
PMADRH           EQU  0x0192
PMDAT            EQU  0x0193
PMDATL           EQU  0x0193
PMDATH           EQU  0x0194
PMCON1           EQU  0x0195
PMCON2           EQU  0x0196
VREGCON          EQU  0x0197
RCREG            EQU  0x0199
TXREG            EQU  0x019A
SPBRG            EQU  0x019B
SPBRGL           EQU  0x019B
SPBRGH           EQU  0x019C
RCSTA            EQU  0x019D
TXSTA            EQU  0x019E
BAUDCON          EQU  0x019F

;-----Bank4------------------
WPUA             EQU  0x020C
WPUB             EQU  0x020D
SSP1BUF          EQU  0x0211
SSPBUF           EQU  0x0211
SSP1ADD          EQU  0x0212
SSPADD           EQU  0x0212
SSP1MSK          EQU  0x0213
SSPMSK           EQU  0x0213
SSP1STAT         EQU  0x0214
SSPSTAT          EQU  0x0214
SSP1CON1         EQU  0x0215
SSPCON           EQU  0x0215
SSPCON1          EQU  0x0215
SSP1CON2         EQU  0x0216
SSPCON2          EQU  0x0216
SSP1CON3         EQU  0x0217
SSPCON3          EQU  0x0217

;-----Bank7------------------
IOCAP            EQU  0x0391
IOCAN            EQU  0x0392
IOCAF            EQU  0x0393
IOCBP            EQU  0x0394
IOCBN            EQU  0x0395
IOCBF            EQU  0x0396

;-----Bank9------------------
NCO1ACC          EQU  0x0498
NCO1ACCL         EQU  0x0498
NCO1ACCH         EQU  0x0499
NCO1ACCU         EQU  0x049A
NCO1INC          EQU  0x049B
NCO1INCL         EQU  0x049B
NCO1INCH         EQU  0x049C
NCO1INCU         EQU  0x049D
NCO1CON          EQU  0x049E
NCO1CLK          EQU  0x049F

;-----Bank12------------------
PWM1DCL          EQU  0x0611
PWM1DCH          EQU  0x0612
PWM1CON          EQU  0x0613
PWM1CON0         EQU  0x0613
PWM2DCL          EQU  0x0614
PWM2DCH          EQU  0x0615
PWM2CON          EQU  0x0616
PWM2CON0         EQU  0x0616
PWM3DCL          EQU  0x0617
PWM3DCH          EQU  0x0618
PWM3CON          EQU  0x0619
PWM3CON0         EQU  0x0619
PWM4DCL          EQU  0x061A
PWM4DCH          EQU  0x061B
PWM4CON          EQU  0x061C
PWM4CON0         EQU  0x061C

;-----Bank13------------------
CWG1DBR          EQU  0x0691
CWG1DBF          EQU  0x0692
CWG1CON0         EQU  0x0693
CWG1CON1         EQU  0x0694
CWG1CON2         EQU  0x0695

;-----Bank30------------------
CLCDATA          EQU  0x0F0F
CLC1CON          EQU  0x0F10
CLC1POL          EQU  0x0F11
CLC1SEL0         EQU  0x0F12
CLC1SEL1         EQU  0x0F13
CLC1GLS0         EQU  0x0F14
CLC1GLS1         EQU  0x0F15
CLC1GLS2         EQU  0x0F16
CLC1GLS3         EQU  0x0F17
CLC2CON          EQU  0x0F18
CLC2POL          EQU  0x0F19
CLC2SEL0         EQU  0x0F1A
CLC2SEL1         EQU  0x0F1B
CLC2GLS0         EQU  0x0F1C
CLC2GLS1         EQU  0x0F1D
CLC2GLS2         EQU  0x0F1E
CLC2GLS3         EQU  0x0F1F
CLC3CON          EQU  0x0F20
CLC3POL          EQU  0x0F21
CLC3SEL0         EQU  0x0F22
CLC3SEL1         EQU  0x0F23
CLC3GLS0         EQU  0x0F24
CLC3GLS1         EQU  0x0F25
CLC3GLS2         EQU  0x0F26
CLC3GLS3         EQU  0x0F27
CLC4CON          EQU  0x0F28
CLC4POL          EQU  0x0F29
CLC4SEL0         EQU  0x0F2A
CLC4SEL1         EQU  0x0F2B
CLC4GLS0         EQU  0x0F2C
CLC4GLS1         EQU  0x0F2D
CLC4GLS2         EQU  0x0F2E
CLC4GLS3         EQU  0x0F2F

;-----Bank31------------------
ICDIO            EQU  0x0F8C
ICDCON0          EQU  0x0F8D
ICDSTAT          EQU  0x0F91
DEVSEL           EQU  0x0F95
ICDINSTL         EQU  0x0F96
ICDINSTH         EQU  0x0F97
ICDBK0CON        EQU  0x0F9C
ICDBK0L          EQU  0x0F9D
ICDBK0H          EQU  0x0F9E
BSRICDSHAD       EQU  0x0FE3
STATUS_SHAD      EQU  0x0FE4
WREG_SHAD        EQU  0x0FE5
BSR_SHAD         EQU  0x0FE6
PCLATH_SHAD      EQU  0x0FE7
FSR0L_SHAD       EQU  0x0FE8
FSR0H_SHAD       EQU  0x0FE9
FSR1L_SHAD       EQU  0x0FEA
FSR1H_SHAD       EQU  0x0FEB
STKPTR           EQU  0x0FED
TOSL             EQU  0x0FEE
TOSH             EQU  0x0FEF

;----- STATUS Bits -----------------------------------------------------
C                EQU  0x0000
DC               EQU  0x0001
Z                EQU  0x0002
NOT_PD           EQU  0x0003
NOT_TO           EQU  0x0004


;----- BSR Bits -----------------------------------------------------
BSR0             EQU  0x0000
BSR1             EQU  0x0001
BSR2             EQU  0x0002
BSR3             EQU  0x0003
BSR4             EQU  0x0004


;----- INTCON Bits -----------------------------------------------------
IOCIF            EQU  0x0000
INTF             EQU  0x0001
TMR0IF           EQU  0x0002
IOCIE            EQU  0x0003
INTE             EQU  0x0004
TMR0IE           EQU  0x0005
PEIE             EQU  0x0006
GIE              EQU  0x0007

T0IF             EQU  0x0002
T0IE             EQU  0x0005


;----- PORTA Bits -----------------------------------------------------
RA0              EQU  0x0000
RA1              EQU  0x0001
RA2              EQU  0x0002
RA3              EQU  0x0003
RA4              EQU  0x0004
RA5              EQU  0x0005


;----- PORTB Bits -----------------------------------------------------
RB4              EQU  0x0004
RB5              EQU  0x0005
RB6              EQU  0x0006
RB7              EQU  0x0007


;----- PORTC Bits -----------------------------------------------------
RC0              EQU  0x0000
RC1              EQU  0x0001
RC2              EQU  0x0002
RC3              EQU  0x0003
RC4              EQU  0x0004
RC5              EQU  0x0005
RC6              EQU  0x0006
RC7              EQU  0x0007


;----- PIR1 Bits -----------------------------------------------------
TMR1IF           EQU  0x0000
TMR2IF           EQU  0x0001
SSP1IF           EQU  0x0003
TXIF             EQU  0x0004
RCIF             EQU  0x0005
ADIF             EQU  0x0006
TMR1GIF          EQU  0x0007


;----- PIR2 Bits -----------------------------------------------------
NCO1IF           EQU  0x0002
BCL1IF           EQU  0x0003
C1IF             EQU  0x0005
C2IF             EQU  0x0006
OSFIF            EQU  0x0007


;----- PIR3 Bits -----------------------------------------------------
CLC1IF           EQU  0x0000
CLC2IF           EQU  0x0001
CLC3IF           EQU  0x0002
CLC4IF           EQU  0x0003


;----- T1CON Bits -----------------------------------------------------
TMR1ON           EQU  0x0000
NOT_T1SYNC       EQU  0x0002
T1OSCEN          EQU  0x0003

T1CKPS0          EQU  0x0004
T1CKPS1          EQU  0x0005
TMR1CS0          EQU  0x0006
TMR1CS1          EQU  0x0007


;----- T1GCON Bits -----------------------------------------------------
T1GVAL           EQU  0x0002
T1GGO_NOT_DONE   EQU  0x0003
T1GSPM           EQU  0x0004
T1GTM            EQU  0x0005
T1GPOL           EQU  0x0006
TMR1GE           EQU  0x0007

T1GSS0           EQU  0x0000
T1GSS1           EQU  0x0001


;----- T2CON Bits -----------------------------------------------------
TMR2ON           EQU  0x0002

T2CKPS0          EQU  0x0000
T2CKPS1          EQU  0x0001
T2OUTPS0         EQU  0x0003
T2OUTPS1         EQU  0x0004
T2OUTPS2         EQU  0x0005
T2OUTPS3         EQU  0x0006


;----- TRISA Bits -----------------------------------------------------
TRISA0           EQU  0x0000
TRISA1           EQU  0x0001
TRISA2           EQU  0x0002
TRISA3           EQU  0x0003
TRISA4           EQU  0x0004
TRISA5           EQU  0x0005


;----- TRISB Bits -----------------------------------------------------
TRISB4           EQU  0x0004
TRISB5           EQU  0x0005
TRISB6           EQU  0x0006
TRISB7           EQU  0x0007


;----- TRISC Bits -----------------------------------------------------
TRISC0           EQU  0x0000
TRISC1           EQU  0x0001
TRISC2           EQU  0x0002
TRISC3           EQU  0x0003
TRISC4           EQU  0x0004
TRISC5           EQU  0x0005
TRISC6           EQU  0x0006
TRISC7           EQU  0x0007


;----- PIE1 Bits -----------------------------------------------------
TMR1IE           EQU  0x0000
TMR2IE           EQU  0x0001
SSP1IE           EQU  0x0003
TXIE             EQU  0x0004
RCIE             EQU  0x0005
ADIE             EQU  0x0006
TMR1GIE          EQU  0x0007


;----- PIE2 Bits -----------------------------------------------------
NCO1IE           EQU  0x0002
BCL1IE           EQU  0x0003
C1IE             EQU  0x0005
C2IE             EQU  0x0006
OSFIE            EQU  0x0007


;----- PIE3 Bits -----------------------------------------------------
CLC1IE           EQU  0x0000
CLC2IE           EQU  0x0001
CLC3IE           EQU  0x0002
CLC4IE           EQU  0x0003


;----- OPTION_REG Bits -----------------------------------------------------
PSA              EQU  0x0003
TMR0SE           EQU  0x0004
TMR0CS           EQU  0x0005
INTEDG           EQU  0x0006
NOT_WPUEN        EQU  0x0007

PS0              EQU  0x0000
PS1              EQU  0x0001
PS2              EQU  0x0002
T0SE             EQU  0x0004
T0CS             EQU  0x0005


;----- PCON Bits -----------------------------------------------------
NOT_BOR          EQU  0x0000
NOT_POR          EQU  0x0001
NOT_RI           EQU  0x0002
NOT_RMCLR        EQU  0x0003
NOT_RWDT         EQU  0x0004
STKUNF           EQU  0x0006
STKOVF           EQU  0x0007


;----- WDTCON Bits -----------------------------------------------------
SWDTEN           EQU  0x0000

WDTPS0           EQU  0x0001
WDTPS1           EQU  0x0002
WDTPS2           EQU  0x0003
WDTPS3           EQU  0x0004
WDTPS4           EQU  0x0005


;----- OSCCON Bits -----------------------------------------------------
SCS0             EQU  0x0000
SCS1             EQU  0x0001
IRCF0            EQU  0x0003
IRCF1            EQU  0x0004
IRCF2            EQU  0x0005
IRCF3            EQU  0x0006


;----- OSCSTAT Bits -----------------------------------------------------
HFIOFS           EQU  0x0000
LFIOFR           EQU  0x0001
HFIOFR           EQU  0x0004
OSTS             EQU  0x0005
SOSCR            EQU  0x0007


;----- ADCON0 Bits -----------------------------------------------------
ADON             EQU  0x0000
GO_NOT_DONE      EQU  0x0001

ADGO             EQU  0x0001
CHS0             EQU  0x0002
CHS1             EQU  0x0003
CHS2             EQU  0x0004
CHS3             EQU  0x0005
CHS4             EQU  0x0006

GO               EQU  0x0001


;----- ADCON1 Bits -----------------------------------------------------
ADFM             EQU  0x0007

ADPREF0          EQU  0x0000
ADPREF1          EQU  0x0001


;----- ADCON2 Bits -----------------------------------------------------
TRIGSEL0         EQU  0x0004
TRIGSEL1         EQU  0x0005
TRIGSEL2         EQU  0x0006
TRIGSEL3         EQU  0x0007


;----- LATA Bits -----------------------------------------------------
LATA0            EQU  0x0000
LATA1            EQU  0x0001
LATA2            EQU  0x0002
LATA4            EQU  0x0004
LATA5            EQU  0x0005


;----- LATB Bits -----------------------------------------------------
LATB4            EQU  0x0004
LATB5            EQU  0x0005
LATB6            EQU  0x0006
LATB7            EQU  0x0007


;----- LATC Bits -----------------------------------------------------
LATC0            EQU  0x0000
LATC1            EQU  0x0001
LATC2            EQU  0x0002
LATC3            EQU  0x0003
LATC4            EQU  0x0004
LATC5            EQU  0x0005
LATC6            EQU  0x0006
LATC7            EQU  0x0007


;----- CM1CON0 Bits -----------------------------------------------------
C1SYNC           EQU  0x0000
C1HYS            EQU  0x0001
C1SP             EQU  0x0002
C1POL            EQU  0x0004
C1OE             EQU  0x0005
C1OUT            EQU  0x0006
C1ON             EQU  0x0007


;----- CM1CON1 Bits -----------------------------------------------------
C1NCH0           EQU  0x0000
C1NCH1           EQU  0x0001
C1NCH2           EQU  0x0002
C1PCH0           EQU  0x0004
C1PCH1           EQU  0x0005
C1INTN           EQU  0x0006
C1INTP           EQU  0x0007



;----- CM2CON0 Bits -----------------------------------------------------
C2SYNC           EQU  0x0000
C2HYS            EQU  0x0001
C2SP             EQU  0x0002
C2POL            EQU  0x0004
C2OE             EQU  0x0005
C2OUT            EQU  0x0006
C2ON             EQU  0x0007


;----- CM2CON1 Bits -----------------------------------------------------
C2NCH0           EQU  0x0000
C2NCH1           EQU  0x0001
C2NCH2           EQU  0x0002
C2PCH0           EQU  0x0004
C2PCH1           EQU  0x0005
C2INTN           EQU  0x0006
C2INTP           EQU  0x0007



;----- CMOUT Bits -----------------------------------------------------
MC1OUT           EQU  0x0000
MC2OUT           EQU  0x0001


;----- BORCON Bits -----------------------------------------------------
BORRDY           EQU  0x0000
BORFS            EQU  0x0006
SBOREN           EQU  0x0007


;----- FVRCON Bits -----------------------------------------------------
TSRNG            EQU  0x0004
TSEN             EQU  0x0005
FVRRDY           EQU  0x0006
FVREN            EQU  0x0007

ADFVR0           EQU  0x0000
ADFVR1           EQU  0x0001
CDAFVR0          EQU  0x0002
CDAFVR1          EQU  0x0003


;----- DACCON0 Bits -----------------------------------------------------
DACPSS           EQU  0x0002
DACOE2           EQU  0x0004
DACOE1           EQU  0x0005
DACEN            EQU  0x0007


;----- DACCON1 Bits -----------------------------------------------------
DACR0            EQU  0x0000
DACR1            EQU  0x0001
DACR2            EQU  0x0002
DACR3            EQU  0x0003
DACR4            EQU  0x0004


;----- APFCON Bits -----------------------------------------------------
NCO1SEL          EQU  0x0000
CLC1SEL          EQU  0x0001
T1GSEL           EQU  0x0003
SSSEL            EQU  0x0004

NCOSEL           EQU  0x0000


;----- ANSELA Bits -----------------------------------------------------
ANSA0            EQU  0x0000
ANSA1            EQU  0x0001
ANSA2            EQU  0x0002
ANSA4            EQU  0x0004



;----- ANSELB Bits -----------------------------------------------------
ANSB4            EQU  0x0004
ANSB5            EQU  0x0005



;----- ANSELC Bits -----------------------------------------------------
ANSC0            EQU  0x0000
ANSC1            EQU  0x0001
ANSC2            EQU  0x0002
ANSC3            EQU  0x0003
ANSC6            EQU  0x0006
ANSC7            EQU  0x0007



;----- PMCON1 Bits -----------------------------------------------------
RD               EQU  0x0000
WR               EQU  0x0001
WREN             EQU  0x0002
WRERR            EQU  0x0003
FREE             EQU  0x0004
LWLO             EQU  0x0005
CFGS             EQU  0x0006


;----- VREGCON Bits -----------------------------------------------------
Reserved         EQU  0x0000
VREGPM           EQU  0x0001


;----- RCSTA Bits -----------------------------------------------------
RX9D             EQU  0x0000
OERR             EQU  0x0001
FERR             EQU  0x0002
ADDEN            EQU  0x0003
CREN             EQU  0x0004
SREN             EQU  0x0005
RX9              EQU  0x0006
SPEN             EQU  0x0007


;----- TXSTA Bits -----------------------------------------------------
TX9D             EQU  0x0000
TRMT             EQU  0x0001
BRGH             EQU  0x0002
SENDB            EQU  0x0003
SYNC             EQU  0x0004
TXEN             EQU  0x0005
TX9              EQU  0x0006
CSRC             EQU  0x0007


;----- BAUDCON Bits -----------------------------------------------------
ABDEN            EQU  0x0000
WUE              EQU  0x0001
BRG16            EQU  0x0003
SCKP             EQU  0x0004
RCIDL            EQU  0x0006
ABDOVF           EQU  0x0007


;----- WPUA Bits -----------------------------------------------------
WPUA0            EQU  0x0000
WPUA1            EQU  0x0001
WPUA2            EQU  0x0002
WPUA3            EQU  0x0003
WPUA4            EQU  0x0004
WPUA5            EQU  0x0005



;----- WPUB Bits -----------------------------------------------------
WPUB4            EQU  0x0004
WPUB5            EQU  0x0005
WPUB6            EQU  0x0006
WPUB7            EQU  0x0007



;----- SSP1STAT Bits -----------------------------------------------------
BF               EQU  0x0000
UA               EQU  0x0001
R_NOT_W          EQU  0x0002
S                EQU  0x0003
P                EQU  0x0004
D_NOT_A          EQU  0x0005
CKE              EQU  0x0006
SMP              EQU  0x0007


;----- SSPSTAT Bits -----------------------------------------------------
BF               EQU  0x0000
UA               EQU  0x0001
R_NOT_W          EQU  0x0002
S                EQU  0x0003
P                EQU  0x0004
D_NOT_A          EQU  0x0005
CKE              EQU  0x0006
SMP              EQU  0x0007


;----- SSP1CON1 Bits -----------------------------------------------------
SSPM0            EQU  0x0000
SSPM1            EQU  0x0001
SSPM2            EQU  0x0002
SSPM3            EQU  0x0003
CKP              EQU  0x0004
SSPEN            EQU  0x0005
SSPOV            EQU  0x0006
WCOL             EQU  0x0007



;----- SSPCON Bits -----------------------------------------------------
SSPM0            EQU  0x0000
SSPM1            EQU  0x0001
SSPM2            EQU  0x0002
SSPM3            EQU  0x0003
CKP              EQU  0x0004
SSPEN            EQU  0x0005
SSPOV            EQU  0x0006
WCOL             EQU  0x0007



;----- SSPCON1 Bits -----------------------------------------------------
SSPM0            EQU  0x0000
SSPM1            EQU  0x0001
SSPM2            EQU  0x0002
SSPM3            EQU  0x0003
CKP              EQU  0x0004
SSPEN            EQU  0x0005
SSPOV            EQU  0x0006
WCOL             EQU  0x0007



;----- SSP1CON2 Bits -----------------------------------------------------
SEN              EQU  0x0000
RSEN             EQU  0x0001
PEN              EQU  0x0002
RCEN             EQU  0x0003
ACKEN            EQU  0x0004
ACKDT            EQU  0x0005
ACKSTAT          EQU  0x0006
GCEN             EQU  0x0007


;----- SSPCON2 Bits -----------------------------------------------------
SEN              EQU  0x0000
RSEN             EQU  0x0001
PEN              EQU  0x0002
RCEN             EQU  0x0003
ACKEN            EQU  0x0004
ACKDT            EQU  0x0005
ACKSTAT          EQU  0x0006
GCEN             EQU  0x0007


;----- SSP1CON3 Bits -----------------------------------------------------
DHEN             EQU  0x0000
AHEN             EQU  0x0001
SBCDE            EQU  0x0002
SDAHT            EQU  0x0003
BOEN             EQU  0x0004
SCIE             EQU  0x0005
PCIE             EQU  0x0006
ACKTIM           EQU  0x0007


;----- SSPCON3 Bits -----------------------------------------------------
DHEN             EQU  0x0000
AHEN             EQU  0x0001
SBCDE            EQU  0x0002
SDAHT            EQU  0x0003
BOEN             EQU  0x0004
SCIE             EQU  0x0005
PCIE             EQU  0x0006
ACKTIM           EQU  0x0007


;----- IOCAP Bits -----------------------------------------------------
IOCAP0           EQU  0x0000
IOCAP1           EQU  0x0001
IOCAP2           EQU  0x0002
IOCAP3           EQU  0x0003
IOCAP4           EQU  0x0004
IOCAP5           EQU  0x0005



;----- IOCAN Bits -----------------------------------------------------
IOCAN0           EQU  0x0000
IOCAN1           EQU  0x0001
IOCAN2           EQU  0x0002
IOCAN3           EQU  0x0003
IOCAN4           EQU  0x0004
IOCAN5           EQU  0x0005



;----- IOCAF Bits -----------------------------------------------------
IOCAF0           EQU  0x0000
IOCAF1           EQU  0x0001
IOCAF2           EQU  0x0002
IOCAF3           EQU  0x0003
IOCAF4           EQU  0x0004
IOCAF5           EQU  0x0005



;----- IOCBP Bits -----------------------------------------------------
IOCBP4           EQU  0x0004
IOCBP5           EQU  0x0005
IOCBP6           EQU  0x0006
IOCBP7           EQU  0x0007



;----- IOCBN Bits -----------------------------------------------------
IOCBN4           EQU  0x0004
IOCBN5           EQU  0x0005
IOCBN6           EQU  0x0006
IOCBN7           EQU  0x0007



;----- IOCBF Bits -----------------------------------------------------
IOCBF4           EQU  0x0004
IOCBF5           EQU  0x0005
IOCBF6           EQU  0x0006
IOCBF7           EQU  0x0007



;----- NCO1ACCL Bits -----------------------------------------------------
NCO1ACC0         EQU  0x0000
NCO1ACC1         EQU  0x0001
NCO1ACC2         EQU  0x0002
NCO1ACC3         EQU  0x0003
NCO1ACC4         EQU  0x0004
NCO1ACC5         EQU  0x0005
NCO1ACC6         EQU  0x0006
NCO1ACC7         EQU  0x0007


;----- NCO1ACCH Bits -----------------------------------------------------
NCO1ACC8         EQU  0x0000
NCO1ACC9         EQU  0x0001
NCO1ACC10        EQU  0x0002
NCO1ACC11        EQU  0x0003
NCO1ACC12        EQU  0x0004
NCO1ACC13        EQU  0x0005
NCO1ACC14        EQU  0x0006
NCO1ACC15        EQU  0x0007


;----- NCO1ACCU Bits -----------------------------------------------------
NCO1ACC16        EQU  0x0000
NCO1ACC17        EQU  0x0001
NCO1ACC18        EQU  0x0002
NCO1ACC19        EQU  0x0003


;----- NCO1INCL Bits -----------------------------------------------------
NCO1INC0         EQU  0x0000
NCO1INC1         EQU  0x0001
NCO1INC2         EQU  0x0002
NCO1INC3         EQU  0x0003
NCO1INC4         EQU  0x0004
NCO1INC5         EQU  0x0005
NCO1INC6         EQU  0x0006
NCO1INC7         EQU  0x0007


;----- NCO1INCH Bits -----------------------------------------------------
NCO1INC8         EQU  0x0000
NCO1INC9         EQU  0x0001
NCO1INC10        EQU  0x0002
NCO1INC11        EQU  0x0003
NCO1INC12        EQU  0x0004
NCO1INC13        EQU  0x0005
NCO1INC14        EQU  0x0006
NCO1INC15        EQU  0x0007


;----- NCO1CON Bits -----------------------------------------------------
N1PFM            EQU  0x0000
N1POL            EQU  0x0004
N1OUT            EQU  0x0005
N1OE             EQU  0x0006
N1EN             EQU  0x0007


;----- NCO1CLK Bits -----------------------------------------------------
N1CKS0           EQU  0x0000
N1CKS1           EQU  0x0001
N1PWS0           EQU  0x0005
N1PWS1           EQU  0x0006
N1PWS2           EQU  0x0007


;----- PWM1DCL Bits -----------------------------------------------------
PWM1DCL0         EQU  0x0006
PWM1DCL1         EQU  0x0007


;----- PWM1DCH Bits -----------------------------------------------------
PWM1DCH0         EQU  0x0000
PWM1DCH1         EQU  0x0001
PWM1DCH2         EQU  0x0002
PWM1DCH3         EQU  0x0003
PWM1DCH4         EQU  0x0004
PWM1DCH5         EQU  0x0005
PWM1DCH6         EQU  0x0006
PWM1DCH7         EQU  0x0007


;----- PWM1CON Bits -----------------------------------------------------
PWM1POL          EQU  0x0004
PWM1OUT          EQU  0x0005
PWM1OE           EQU  0x0006
PWM1EN           EQU  0x0007


;----- PWM1CON0 Bits -----------------------------------------------------
PWM1POL          EQU  0x0004
PWM1OUT          EQU  0x0005
PWM1OE           EQU  0x0006
PWM1EN           EQU  0x0007


;----- PWM2DCL Bits -----------------------------------------------------
PWM2DCL0         EQU  0x0006
PWM2DCL1         EQU  0x0007


;----- PWM2DCH Bits -----------------------------------------------------
PWM2DCH0         EQU  0x0000
PWM2DCH1         EQU  0x0001
PWM2DCH2         EQU  0x0002
PWM2DCH3         EQU  0x0003
PWM2DCH4         EQU  0x0004
PWM2DCH5         EQU  0x0005
PWM2DCH6         EQU  0x0006
PWM2DCH7         EQU  0x0007


;----- PWM2CON Bits -----------------------------------------------------
PWM2POL          EQU  0x0004
PWM2OUT          EQU  0x0005
PWM2OE           EQU  0x0006
PWM2EN           EQU  0x0007


;----- PWM2CON0 Bits -----------------------------------------------------
PWM2POL          EQU  0x0004
PWM2OUT          EQU  0x0005
PWM2OE           EQU  0x0006
PWM2EN           EQU  0x0007


;----- PWM3DCL Bits -----------------------------------------------------
PWM3DCL0         EQU  0x0006
PWM3DCL1         EQU  0x0007


;----- PWM3DCH Bits -----------------------------------------------------
PWM3DCH0         EQU  0x0000
PWM3DCH1         EQU  0x0001
PWM3DCH2         EQU  0x0002
PWM3DCH3         EQU  0x0003
PWM3DCH4         EQU  0x0004
PWM3DCH5         EQU  0x0005
PWM3DCH6         EQU  0x0006
PWM3DCH7         EQU  0x0007


;----- PWM3CON Bits -----------------------------------------------------
PWM3POL          EQU  0x0004
PWM3OUT          EQU  0x0005
PWM3OE           EQU  0x0006
PWM3EN           EQU  0x0007


;----- PWM3CON0 Bits -----------------------------------------------------
PWM3POL          EQU  0x0004
PWM3OUT          EQU  0x0005
PWM3OE           EQU  0x0006
PWM3EN           EQU  0x0007


;----- PWM4DCL Bits -----------------------------------------------------
PWM4DCL0         EQU  0x0006
PWM4DCL1         EQU  0x0007


;----- PWM4DCH Bits -----------------------------------------------------
PWM4DCH0         EQU  0x0000
PWM4DCH1         EQU  0x0001
PWM4DCH2         EQU  0x0002
PWM4DCH3         EQU  0x0003
PWM4DCH4         EQU  0x0004
PWM4DCH5         EQU  0x0005
PWM4DCH6         EQU  0x0006
PWM4DCH7         EQU  0x0007


;----- PWM4CON Bits -----------------------------------------------------
PWM4POL          EQU  0x0004
PWM4OUT          EQU  0x0005
PWM4OE           EQU  0x0006
PWM4EN           EQU  0x0007


;----- PWM4CON0 Bits -----------------------------------------------------
PWM4POL          EQU  0x0004
PWM4OUT          EQU  0x0005
PWM4OE           EQU  0x0006
PWM4EN           EQU  0x0007


;----- CWG1DBR Bits -----------------------------------------------------
CWG1DBR0         EQU  0x0000
CWG1DBR1         EQU  0x0001
CWG1DBR2         EQU  0x0002
CWG1DBR3         EQU  0x0003
CWG1DBR4         EQU  0x0004
CWG1DBR5         EQU  0x0005


;----- CWG1DBF Bits -----------------------------------------------------
CWG1DBF0         EQU  0x0000
CWG1DBF1         EQU  0x0001
CWG1DBF2         EQU  0x0002
CWG1DBF3         EQU  0x0003
CWG1DBF4         EQU  0x0004
CWG1DBF5         EQU  0x0005


;----- CWG1CON0 Bits -----------------------------------------------------
G1CS0            EQU  0x0000
G1POLA           EQU  0x0003
G1POLB           EQU  0x0004
G1OEA            EQU  0x0005
G1OEB            EQU  0x0006
G1EN             EQU  0x0007



;----- CWG1CON1 Bits -----------------------------------------------------
G1IS0            EQU  0x0000
G1IS1            EQU  0x0001
G1IS2            EQU  0x0002

G1ASDLA0         EQU  0x0004
G1ASDLA1         EQU  0x0005
G1ASDLB0         EQU  0x0006
G1ASDLB1         EQU  0x0007


;----- CWG1CON2 Bits -----------------------------------------------------
G1ASDSCLC2       EQU  0x0000
G1ASDSFLT        EQU  0x0001
G1ASDSC1         EQU  0x0002
G1ASDSC2         EQU  0x0003
G1ARSEN          EQU  0x0006
G1ASE            EQU  0x0007


;----- CLCDATA Bits -----------------------------------------------------
MCLC1OUT         EQU  0x0000
MCLC2OUT         EQU  0x0001
MCLC3OUT         EQU  0x0002
MCLC4OUT         EQU  0x0003


;----- CLC1CON Bits -----------------------------------------------------
LC1MODE0         EQU  0x0000
LC1MODE1         EQU  0x0001
LC1MODE2         EQU  0x0002
LC1INTN          EQU  0x0003
LC1INTP          EQU  0x0004
LC1OUT           EQU  0x0005
LC1OE            EQU  0x0006
LC1EN            EQU  0x0007

LCMODE0          EQU  0x0000
LCMODE1          EQU  0x0001
LCMODE2          EQU  0x0002
LCINTN           EQU  0x0003
LCINTP           EQU  0x0004
LCOUT            EQU  0x0005
LCOE             EQU  0x0006
LCEN             EQU  0x0007



;----- CLC1POL Bits -----------------------------------------------------
LC1G1POL         EQU  0x0000
LC1G2POL         EQU  0x0001
LC1G3POL         EQU  0x0002
LC1G4POL         EQU  0x0003
LC1POL           EQU  0x0007

G1POL            EQU  0x0000
G2POL            EQU  0x0001
G3POL            EQU  0x0002
G4POL            EQU  0x0003
POL              EQU  0x0007


;----- CLC1SEL0 Bits -----------------------------------------------------
LC1D1S0          EQU  0x0000
LC1D1S1          EQU  0x0001
LC1D1S2          EQU  0x0002
LC1D2S0          EQU  0x0004
LC1D2S1          EQU  0x0005
LC1D2S2          EQU  0x0006

D1S0             EQU  0x0000
D1S1             EQU  0x0001
D1S2             EQU  0x0002
D2S0             EQU  0x0004
D2S1             EQU  0x0005
D2S2             EQU  0x0006



;----- CLC1SEL1 Bits -----------------------------------------------------
LC1D3S0          EQU  0x0000
LC1D3S1          EQU  0x0001
LC1D3S2          EQU  0x0002
LC1D4S0          EQU  0x0004
LC1D4S1          EQU  0x0005
LC1D4S2          EQU  0x0006

D3S0             EQU  0x0000
D3S1             EQU  0x0001
D3S2             EQU  0x0002
D4S0             EQU  0x0004
D4S1             EQU  0x0005
D4S2             EQU  0x0006



;----- CLC1GLS0 Bits -----------------------------------------------------
LC1G1D1N         EQU  0x0000
LC1G1D1T         EQU  0x0001
LC1G1D2N         EQU  0x0002
LC1G1D2T         EQU  0x0003
LC1G1D3N         EQU  0x0004
LC1G1D3T         EQU  0x0005
LC1G1D4N         EQU  0x0006
LC1G1D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC1GLS1 Bits -----------------------------------------------------
LC1G2D1N         EQU  0x0000
LC1G2D1T         EQU  0x0001
LC1G2D2N         EQU  0x0002
LC1G2D2T         EQU  0x0003
LC1G2D3N         EQU  0x0004
LC1G2D3T         EQU  0x0005
LC1G2D4N         EQU  0x0006
LC1G2D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC1GLS2 Bits -----------------------------------------------------
LC1G3D1N         EQU  0x0000
LC1G3D1T         EQU  0x0001
LC1G3D2N         EQU  0x0002
LC1G3D2T         EQU  0x0003
LC1G3D3N         EQU  0x0004
LC1G3D3T         EQU  0x0005
LC1G3D4N         EQU  0x0006
LC1G3D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC1GLS3 Bits -----------------------------------------------------
LC1G4D1N         EQU  0x0000
LC1G4D1T         EQU  0x0001
LC1G4D2N         EQU  0x0002
LC1G4D2T         EQU  0x0003
LC1G4D3N         EQU  0x0004
LC1G4D3T         EQU  0x0005
LC1G4D4N         EQU  0x0006
LC1G4D4T         EQU  0x0007

G4D1N            EQU  0x0000
G4D1T            EQU  0x0001
G4D2N            EQU  0x0002
G4D2T            EQU  0x0003
G4D3N            EQU  0x0004
G4D3T            EQU  0x0005
G4D4N            EQU  0x0006
G4D4T            EQU  0x0007


;----- CLC2CON Bits -----------------------------------------------------
LC2MODE0         EQU  0x0000
LC2MODE1         EQU  0x0001
LC2MODE2         EQU  0x0002
LC2INTN          EQU  0x0003
LC2INTP          EQU  0x0004
LC2OUT           EQU  0x0005
LC2OE            EQU  0x0006
LC2EN            EQU  0x0007

LCMODE0          EQU  0x0000
LCMODE1          EQU  0x0001
LCMODE2          EQU  0x0002
LCINTN           EQU  0x0003
LCINTP           EQU  0x0004
LCOUT            EQU  0x0005
LCOE             EQU  0x0006
LCEN             EQU  0x0007



;----- CLC2POL Bits -----------------------------------------------------
LC2G1POL         EQU  0x0000
LC2G2POL         EQU  0x0001
LC2G3POL         EQU  0x0002
LC2G4POL         EQU  0x0003
LC2POL           EQU  0x0007

G1POL            EQU  0x0000
G2POL            EQU  0x0001
G3POL            EQU  0x0002
G4POL            EQU  0x0003
POL              EQU  0x0007


;----- CLC2SEL0 Bits -----------------------------------------------------
LC2D1S0          EQU  0x0000
LC2D1S1          EQU  0x0001
LC2D1S2          EQU  0x0002
LC2D2S0          EQU  0x0004
LC2D2S1          EQU  0x0005
LC2D2S2          EQU  0x0006

D1S0             EQU  0x0000
D1S1             EQU  0x0001
D1S2             EQU  0x0002
D2S0             EQU  0x0004
D2S1             EQU  0x0005
D2S2             EQU  0x0006



;----- CLC2SEL1 Bits -----------------------------------------------------
LC2D3S0          EQU  0x0000
LC2D3S1          EQU  0x0001
LC2D3S2          EQU  0x0002
LC2D4S0          EQU  0x0004
LC2D4S1          EQU  0x0005
LC2D4S2          EQU  0x0006

D3S0             EQU  0x0000
D3S1             EQU  0x0001
D3S2             EQU  0x0002
D4S0             EQU  0x0004
D4S1             EQU  0x0005
D4S2             EQU  0x0006



;----- CLC2GLS0 Bits -----------------------------------------------------
LC2G1D1N         EQU  0x0000
LC2G1D1T         EQU  0x0001
LC2G1D2N         EQU  0x0002
LC2G1D2T         EQU  0x0003
LC2G1D3N         EQU  0x0004
LC2G1D3T         EQU  0x0005
LC2G1D4N         EQU  0x0006
LC2G1D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC2GLS1 Bits -----------------------------------------------------
LC2G2D1N         EQU  0x0000
LC2G2D1T         EQU  0x0001
LC2G2D2N         EQU  0x0002
LC2G2D2T         EQU  0x0003
LC2G2D3N         EQU  0x0004
LC2G2D3T         EQU  0x0005
LC2G2D4N         EQU  0x0006
LC2G2D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC2GLS2 Bits -----------------------------------------------------
LC2G3D1N         EQU  0x0000
LC2G3D1T         EQU  0x0001
LC2G3D2N         EQU  0x0002
LC2G3D2T         EQU  0x0003
LC2G3D3N         EQU  0x0004
LC2G3D3T         EQU  0x0005
LC2G3D4N         EQU  0x0006
LC2G3D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC2GLS3 Bits -----------------------------------------------------
LC2G4D1N         EQU  0x0000
LC2G4D1T         EQU  0x0001
LC2G4D2N         EQU  0x0002
LC2G4D2T         EQU  0x0003
LC2G4D3N         EQU  0x0004
LC2G4D3T         EQU  0x0005
LC2G4D4N         EQU  0x0006
LC2G4D4T         EQU  0x0007

G4D1N            EQU  0x0000
G4D1T            EQU  0x0001
G4D2N            EQU  0x0002
G4D2T            EQU  0x0003
G4D3N            EQU  0x0004
G4D3T            EQU  0x0005
G4D4N            EQU  0x0006
G4D4T            EQU  0x0007


;----- CLC3CON Bits -----------------------------------------------------
LC3MODE0         EQU  0x0000
LC3MODE1         EQU  0x0001
LC3MODE2         EQU  0x0002
LC3INTN          EQU  0x0003
LC3INTP          EQU  0x0004
LC3OUT           EQU  0x0005
LC3OE            EQU  0x0006
LC3EN            EQU  0x0007

LCMODE0          EQU  0x0000
LCMODE1          EQU  0x0001
LCMODE2          EQU  0x0002
LCINTN           EQU  0x0003
LCINTP           EQU  0x0004
LCOUT            EQU  0x0005
LCOE             EQU  0x0006
LCEN             EQU  0x0007



;----- CLC3POL Bits -----------------------------------------------------
LC3G1POL         EQU  0x0000
LC3G2POL         EQU  0x0001
LC3G3POL         EQU  0x0002
LC3G4POL         EQU  0x0003
LC3POL           EQU  0x0007

G1POL            EQU  0x0000
G2POL            EQU  0x0001
G3POL            EQU  0x0002
G4POL            EQU  0x0003
POL              EQU  0x0007


;----- CLC3SEL0 Bits -----------------------------------------------------
LC3D1S0          EQU  0x0000
LC3D1S1          EQU  0x0001
LC3D1S2          EQU  0x0002
LC3D2S0          EQU  0x0004
LC3D2S1          EQU  0x0005
LC3D2S2          EQU  0x0006

D1S0             EQU  0x0000
D1S1             EQU  0x0001
D1S2             EQU  0x0002
D2S0             EQU  0x0004
D2S1             EQU  0x0005
D2S2             EQU  0x0006



;----- CLC3SEL1 Bits -----------------------------------------------------
LC3D3S0          EQU  0x0000
LC3D3S1          EQU  0x0001
LC3D3S2          EQU  0x0002
LC3D4S0          EQU  0x0004
LC3D4S1          EQU  0x0005
LC3D4S2          EQU  0x0006

D3S0             EQU  0x0000
D3S1             EQU  0x0001
D3S2             EQU  0x0002
D4S0             EQU  0x0004
D4S1             EQU  0x0005
D4S2             EQU  0x0006



;----- CLC3GLS0 Bits -----------------------------------------------------
LC3G1D1N         EQU  0x0000
LC3G1D1T         EQU  0x0001
LC3G1D2N         EQU  0x0002
LC3G1D2T         EQU  0x0003
LC3G1D3N         EQU  0x0004
LC3G1D3T         EQU  0x0005
LC3G1D4N         EQU  0x0006
LC3G1D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC3GLS1 Bits -----------------------------------------------------
LC3G2D1N         EQU  0x0000
LC3G2D1T         EQU  0x0001
LC3G2D2N         EQU  0x0002
LC3G2D2T         EQU  0x0003
LC3G2D3N         EQU  0x0004
LC3G2D3T         EQU  0x0005
LC3G2D4N         EQU  0x0006
LC3G2D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC3GLS2 Bits -----------------------------------------------------
LC3G3D1N         EQU  0x0000
LC3G3D1T         EQU  0x0001
LC3G3D2N         EQU  0x0002
LC3G3D2T         EQU  0x0003
LC3G3D3N         EQU  0x0004
LC3G3D3T         EQU  0x0005
LC3G3D4N         EQU  0x0006
LC3G3D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC3GLS3 Bits -----------------------------------------------------
LC3G4D1N         EQU  0x0000
LC3G4D1T         EQU  0x0001
LC3G4D2N         EQU  0x0002
LC3G4D2T         EQU  0x0003
LC3G4D3N         EQU  0x0004
LC3G4D3T         EQU  0x0005
LC3G4D4N         EQU  0x0006
LC3G4D4T         EQU  0x0007

G4D1N            EQU  0x0000
G4D1T            EQU  0x0001
G4D2N            EQU  0x0002
G4D2T            EQU  0x0003
G4D3N            EQU  0x0004
G4D3T            EQU  0x0005
G4D4N            EQU  0x0006
G4D4T            EQU  0x0007


;----- CLC4CON Bits -----------------------------------------------------
LC4MODE0         EQU  0x0000
LC4MODE1         EQU  0x0001
LC4MODE2         EQU  0x0002
LC4INTN          EQU  0x0003
LC4INTP          EQU  0x0004
LC4OUT           EQU  0x0005
LC4OE            EQU  0x0006
LC4EN            EQU  0x0007

LCMODE0          EQU  0x0000
LCMODE1          EQU  0x0001
LCMODE2          EQU  0x0002
LCINTN           EQU  0x0003
LCINTP           EQU  0x0004
LCOUT            EQU  0x0005
LCOE             EQU  0x0006
LCEN             EQU  0x0007



;----- CLC4POL Bits -----------------------------------------------------
LC4G1POL         EQU  0x0000
LC4G2POL         EQU  0x0001
LC4G3POL         EQU  0x0002
LC4G4POL         EQU  0x0003
LC4POL           EQU  0x0007

G1POL            EQU  0x0000
G2POL            EQU  0x0001
G3POL            EQU  0x0002
G4POL            EQU  0x0003
POL              EQU  0x0007


;----- CLC4SEL0 Bits -----------------------------------------------------
LC4D1S0          EQU  0x0000
LC4D1S1          EQU  0x0001
LC4D1S2          EQU  0x0002
LC4D2S0          EQU  0x0004
LC4D2S1          EQU  0x0005
LC4D2S2          EQU  0x0006

D1S0             EQU  0x0000
D1S1             EQU  0x0001
D1S2             EQU  0x0002
D2S0             EQU  0x0004
D2S1             EQU  0x0005
D2S2             EQU  0x0006



;----- CLC4SEL1 Bits -----------------------------------------------------
LC4D3S0          EQU  0x0000
LC4D3S1          EQU  0x0001
LC4D3S2          EQU  0x0002
LC4D4S0          EQU  0x0004
LC4D4S1          EQU  0x0005
LC4D4S2          EQU  0x0006

D3S0             EQU  0x0000
D3S1             EQU  0x0001
D3S2             EQU  0x0002
D4S0             EQU  0x0004
D4S1             EQU  0x0005
D4S2             EQU  0x0006



;----- CLC4GLS0 Bits -----------------------------------------------------
LC4G1D1N         EQU  0x0000
LC4G1D1T         EQU  0x0001
LC4G1D2N         EQU  0x0002
LC4G1D2T         EQU  0x0003
LC4G1D3N         EQU  0x0004
LC4G1D3T         EQU  0x0005
LC4G1D4N         EQU  0x0006
LC4G1D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC4GLS1 Bits -----------------------------------------------------
LC4G2D1N         EQU  0x0000
LC4G2D1T         EQU  0x0001
LC4G2D2N         EQU  0x0002
LC4G2D2T         EQU  0x0003
LC4G2D3N         EQU  0x0004
LC4G2D3T         EQU  0x0005
LC4G2D4N         EQU  0x0006
LC4G2D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC4GLS2 Bits -----------------------------------------------------
LC4G3D1N         EQU  0x0000
LC4G3D1T         EQU  0x0001
LC4G3D2N         EQU  0x0002
LC4G3D2T         EQU  0x0003
LC4G3D3N         EQU  0x0004
LC4G3D3T         EQU  0x0005
LC4G3D4N         EQU  0x0006
LC4G3D4T         EQU  0x0007

D1N              EQU  0x0000
D1T              EQU  0x0001
D2N              EQU  0x0002
D2T              EQU  0x0003
D3N              EQU  0x0004
D3T              EQU  0x0005
D4N              EQU  0x0006
D4T              EQU  0x0007


;----- CLC4GLS3 Bits -----------------------------------------------------
LC4G4D1N         EQU  0x0000
LC4G4D1T         EQU  0x0001
LC4G4D2N         EQU  0x0002
LC4G4D2T         EQU  0x0003
LC4G4D3N         EQU  0x0004
LC4G4D3T         EQU  0x0005
LC4G4D4N         EQU  0x0006
LC4G4D4T         EQU  0x0007

G4D1N            EQU  0x0000
G4D1T            EQU  0x0001
G4D2N            EQU  0x0002
G4D2T            EQU  0x0003
G4D3N            EQU  0x0004
G4D3T            EQU  0x0005
G4D4N            EQU  0x0006
G4D4T            EQU  0x0007


;----- ICDIO Bits -----------------------------------------------------
TRIS_ICDCLK      EQU  0x0002
TRIS_ICDDAT      EQU  0x0003
LAT_ICDCLK       EQU  0x0004
LAT_ICDDAT       EQU  0x0005
PORT_ICDCLK      EQU  0x0006
PORT_ICDDAT      EQU  0x0007


;----- ICDCON0 Bits -----------------------------------------------------
RSTVEC           EQU  0x0000
DBGINEX          EQU  0x0003
SSTEP            EQU  0x0005
FREEZ            EQU  0x0006
INBUG            EQU  0x0007


;----- ICDSTAT Bits -----------------------------------------------------
USRHLTF          EQU  0x0001
TRP0HLTF         EQU  0x0006
TRP1HLTF         EQU  0x0007


;----- DEVSEL Bits -----------------------------------------------------
DEVSEL0          EQU  0x0000
DEVSEL1          EQU  0x0001
DEVSEL2          EQU  0x0002


;----- ICDINSTL Bits -----------------------------------------------------
DBGIN0           EQU  0x0000
DBGIN1           EQU  0x0001
DBGIN2           EQU  0x0002
DBGIN3           EQU  0x0003
DBGIN4           EQU  0x0004
DBGIN5           EQU  0x0005
DBGIN6           EQU  0x0006
DBGIN7           EQU  0x0007


;----- ICDINSTH Bits -----------------------------------------------------
DBGIN8           EQU  0x0000
DBGIN9           EQU  0x0001
DBGIN10          EQU  0x0002
DBGIN11          EQU  0x0003
DBGIN12          EQU  0x0004
DBGIN13          EQU  0x0005


;----- ICDBK0CON Bits -----------------------------------------------------
BKHLT            EQU  0x0000
BKEN             EQU  0x0007


;----- ICDBK0L Bits -----------------------------------------------------
BKA0             EQU  0x0000
BKA1             EQU  0x0001
BKA2             EQU  0x0002
BKA3             EQU  0x0003
BKA4             EQU  0x0004
BKA5             EQU  0x0005
BKA6             EQU  0x0006
BKA7             EQU  0x0007


;----- ICDBK0H Bits -----------------------------------------------------
BKA8             EQU  0x0000
BKA9             EQU  0x0001
BKA10            EQU  0x0002
BKA11            EQU  0x0003
BKA12            EQU  0x0004
BKA13            EQU  0x0005
BKA14            EQU  0x0006


;----- STATUS_SHAD Bits -----------------------------------------------------
C_SHAD           EQU  0x0000
DC_SHAD          EQU  0x0001
Z_SHAD           EQU  0x0002



;==========================================================================
;
;       RAM Definitions
;
;==========================================================================
       __MAXRAM  0x0FFF
       __BADRAM  0x000F
       __BADRAM  0x0010
       __BADRAM  0x0014
       __BADRAM  0x001D-0x001E
       __BADRAM  0x001F
       __BADRAM  0x008F
       __BADRAM  0x0090
       __BADRAM  0x0094
       __BADRAM  0x0098
       __BADRAM  0x010F-0x0110
       __BADRAM  0x011A-0x011C
       __BADRAM  0x011E-0x011F
       __BADRAM  0x018F-0x0190
       __BADRAM  0x0198
       __BADRAM  0x01A0-0x01EF
       __BADRAM  0x020E-0x0210
       __BADRAM  0x0218-0x021F
       __BADRAM  0x0220-0x026F
       __BADRAM  0x028C-0x029F
       __BADRAM  0x02A0-0x02EF
       __BADRAM  0x030C-0x031F
       __BADRAM  0x0320-0x036F
       __BADRAM  0x038C-0x0390
       __BADRAM  0x0397-0x039F
       __BADRAM  0x03A0-0x03EF
       __BADRAM  0x040C-0x041F
       __BADRAM  0x0420-0x046F
       __BADRAM  0x048C-0x0497
       __BADRAM  0x04A0-0x04EF
       __BADRAM  0x050C-0x051F
       __BADRAM  0x0520-0x056F
       __BADRAM  0x058C-0x059F
       __BADRAM  0x05A0-0x05EF
       __BADRAM  0x060C-0x0610
       __BADRAM  0x061D-0x061F
       __BADRAM  0x0620-0x066F
       __BADRAM  0x068C-0x0690
       __BADRAM  0x0696-0x069F
       __BADRAM  0x06A0-0x06EF
       __BADRAM  0x070C-0x071F
       __BADRAM  0x0720-0x076F
       __BADRAM  0x078C-0x079F
       __BADRAM  0x07A0-0x07EF
       __BADRAM  0x080C-0x081F
       __BADRAM  0x0820-0x086F
       __BADRAM  0x088C-0x089F
       __BADRAM  0x08A0-0x08EF
       __BADRAM  0x090C-0x091F
       __BADRAM  0x0920-0x096F
       __BADRAM  0x098C-0x099F
       __BADRAM  0x09A0-0x09EF
       __BADRAM  0x0A0C-0x0A1F
       __BADRAM  0x0A20-0x0A6F
       __BADRAM  0x0A8C-0x0A9F
       __BADRAM  0x0AA0-0x0AEF
       __BADRAM  0x0B0C-0x0B1F
       __BADRAM  0x0B20-0x0B6F
       __BADRAM  0x0B8C-0x0B9F
       __BADRAM  0x0BA0-0x0BEF
       __BADRAM  0x0C0C-0x0C1F
       __BADRAM  0x0C20-0x0C6F
       __BADRAM  0x0C8C-0x0C9F
       __BADRAM  0x0CA0-0x0CEF
       __BADRAM  0x0D0C-0x0D1F
       __BADRAM  0x0D20-0x0D6F
       __BADRAM  0x0D8C-0x0D9F
       __BADRAM  0x0DA0-0x0DEF
       __BADRAM  0x0E0C-0x0E1F
       __BADRAM  0x0E20-0x0E6F
       __BADRAM  0x0E8C-0x0E9F
       __BADRAM  0x0EA0-0x0EEF
       __BADRAM  0x0F0C-0x0F0E
       __BADRAM  0x0F30-0x0F6F
       __BADRAM  0x0F8E-0x0F90
       __BADRAM  0x0F92-0x0F94
       __BADRAM  0x0F98-0x0F9B
       __BADRAM  0x0F9F
       __BADRAM  0x0FA0-0x0FBF
       __BADRAM  0x0FC0-0x0FCF
       __BADRAM  0x0FD0-0x0FE2
       __BADRAM  0x0FEC

;==========================================================================
;
;       Configuration Bits
;
;   NAME            Address
;   CONFIG1           8007h
;   CONFIG2           8008h
;
;==========================================================================

; The following is an assignment of address values for all of the
; configuration registers for the purpose of table reads
_CONFIG1         EQU  0x8007
_CONFIG2         EQU  0x8008

;----- CONFIG1 Options --------------------------------------------------
_FOSC_LP         EQU  0x3FF8    ; LP Oscillator, Low-power crystal connected between OSC1 and OSC2 pins
_FOSC_XT         EQU  0x3FF9    ; XT Oscillator, Crystal/resonator connected between OSC1 and OSC2 pins
_FOSC_HS         EQU  0x3FFA    ; HS Oscillator, High-speed crystal/resonator connected between OSC1 and OSC2 pins
_FOSC_EXTRC      EQU  0x3FFB    ; EXTRC oscillator: External RC circuit connected to CLKIN pin
_FOSC_INTOSC     EQU  0x3FFC    ; INTOSC oscillator: I/O function on CLKIN pin
_FOSC_ECL        EQU  0x3FFD    ; ECL, External Clock, Low Power Mode (0-0.5 MHz): device clock supplied to CLKIN pins
_FOSC_ECM        EQU  0x3FFE    ; ECM, External Clock, Medium Power Mode (0.5-4 MHz): device clock supplied to CLKIN pins
_FOSC_ECH        EQU  0x3FFF    ; ECH, External Clock, High Power Mode (4-20 MHz): device clock supplied to CLKIN pins

_WDTE_OFF        EQU  0x3FE7    ; WDT disabled
_WDTE_SWDTEN     EQU  0x3FEF    ; WDT controlled by the SWDTEN bit in the WDTCON register
_WDTE_NSLEEP     EQU  0x3FF7    ; WDT enabled while running and disabled in Sleep
_WDTE_ON         EQU  0x3FFF    ; WDT enabled

_PWRTE_ON        EQU  0x3FDF    ; PWRT enabled
_PWRTE_OFF       EQU  0x3FFF    ; PWRT disabled

_MCLRE_OFF       EQU  0x3FBF    ; MCLR/VPP pin function is digital input
_MCLRE_ON        EQU  0x3FFF    ; MCLR/VPP pin function is MCLR

_CP_ON           EQU  0x3F7F    ; Program memory code protection is enabled
_CP_OFF          EQU  0x3FFF    ; Program memory code protection is disabled

_BOREN_OFF       EQU  0x39FF    ; Brown-out Reset disabled
_BOREN_SBODEN    EQU  0x3BFF    ; Brown-out Reset controlled by the SBOREN bit in the BORCON register
_BOREN_NSLEEP    EQU  0x3DFF    ; Brown-out Reset enabled while running and disabled in Sleep
_BOREN_ON        EQU  0x3FFF    ; Brown-out Reset enabled

_CLKOUTEN_ON     EQU  0x37FF    ; CLKOUT function is enabled on the CLKOUT pin
_CLKOUTEN_OFF    EQU  0x3FFF    ; CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin

_IESO_OFF        EQU  0x2FFF    ; Internal/External Switchover Mode is disabled
_IESO_ON         EQU  0x3FFF    ; Internal/External Switchover Mode is enabled

_FCMEN_OFF       EQU  0x1FFF    ; Fail-Safe Clock Monitor is disabled
_FCMEN_ON        EQU  0x3FFF    ; Fail-Safe Clock Monitor is enabled

;----- CONFIG2 Options --------------------------------------------------
_WRT_ALL         EQU  0x3FFC    ; 000h to 1FFFh write protected, no addresses may be modified by EECON control
_WRT_HALF        EQU  0x3FFD    ; 000h to FFFh write protected, 1000h to 1FFFh may be modified by EECON control
_WRT_BOOT        EQU  0x3FFE    ; 000h to 1FFh write protected, 200h to 1FFFh may be modified by EECON control
_WRT_OFF         EQU  0x3FFF    ; Write protection off

_STVREN_OFF      EQU  0x3DFF    ; Stack Overflow or Underflow will not cause a Reset
_STVREN_ON       EQU  0x3FFF    ; Stack Overflow or Underflow will cause a Reset

_BORV_HI         EQU  0x3BFF    ; Brown-out Reset Voltage (Vbor), high trip point selected.
_BORV_LO         EQU  0x3FFF    ; Brown-out Reset Voltage (Vbor), low trip point selected.

_LPBOR_ON        EQU  0x37FF    ; Low-Power BOR is enabled
_LPBOR_OFF       EQU  0x3FFF    ; Low-Power BOR is disabled

;;;; Begin: Added in gputils
_DEBUG_ON        EQU  0x2FFF    ; In-Circuit Debugger enabled, ICSPCLK and ICSPDAT are dedicated to the debugger.
_DEBUG_OFF       EQU  0x3FFF    ; In-Circuit Debugger disabled, ICSPCLK and ICSPDAT are general purpose I/O pins.

;;;; End: Added in gputils
_LVP_OFF         EQU  0x1FFF    ; High-voltage on MCLR/VPP must be used for programming
_LVP_ON          EQU  0x3FFF    ; Low-voltage programming enabled

;----- DEVID Equates --------------------------------------------------
_DEVID1          EQU  0x8006

;----- IDLOC Equates --------------------------------------------------
_IDLOC0          EQU  0x8000
_IDLOC1          EQU  0x8001
_IDLOC2          EQU  0x8002
_IDLOC3          EQU  0x8003

	  ;todo is it needed

        LIST
