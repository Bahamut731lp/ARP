;prijme pismeno z PC, odesle zpatky male i velke
;9600, 8 b, 1 stop, bez parity a rizeni toku
;ls /dev/tty.* or ls /dev/cu.*
;screen /dev/cu.usbserial-D37LWKJO 9600,cs8,0,0,1

PROCESSOR 16F1508 

; window -> TMW -> conf. bits -> ctl c ctr v
; CONFIG1
CONFIG  FOSC = INTOSC         ; Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
CONFIG  WDTE = OFF            ; Watchdog Timer Enable (WDT disabled)
CONFIG  PWRTE = OFF           ; Power-up Timer Enable (PWRT disabled)
CONFIG  MCLRE = ON            ; MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
CONFIG  CP = OFF              ; Flash Program Memory Code Protection (Program memory code protection is disabled)
CONFIG  BOREN = ON            ; Brown-out Reset Enable (Brown-out Reset enabled)
CONFIG  CLKOUTEN = OFF        ; Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
CONFIG  IESO = ON             ; Internal/External Switchover Mode (Internal/External Switchover Mode is enabled)
CONFIG  FCMEN = ON            ; Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is enabled)

; CONFIG2
CONFIG  WRT = OFF             ; Flash Memory Self-Write Protection (Write protection off)
CONFIG  STVREN = ON           ; Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
CONFIG  BORV = LO             ; Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
CONFIG  LPBOR = OFF           ; Low-Power Brown Out Reset (Low-Power BOR is disabled)
CONFIG  LVP = ON              ; Low-Voltage Programming Enable (Low-voltage programming enabled)

#include <xc.inc> 
  
;VARIABLE DEFINITIONS
;COMMON RAM 0x70 to 0x7F
tmp	EQU 0x70

    
;**********************************************************************
PSECT PROGMEM0,delta=2, abs

RESETVEC:
    ORG		0x00 
    PAGESEL	Start
    GOTO	Start
	
    ORG		0x04
    retfie
	
	
Start:	
    movlb	1		;Banka1
    movlw	01101000B	;4MHz Medium
    movwf	OSCCON		;nastaveni hodin

    call	Config_IOs

    ;config UART
    movlb	3		;Banka3 s UART
    bsf		TXSTA,5		;TXEN	;povoleni odesilani dat
    bsf		TXSTA,2		;BRGH	;jiny zpusob vypoctu baudrate
    bsf		RCSTA, 4	;CREN	;povoleni prijimani dat
    clrf	SPBRGH
    movlw	25		;25 => 9615 bps s BRGH pri Fosc = 4MHz
    movwf	SPBRGL
    bsf		RCSTA,7		;SPEN	;po nastaveni vseho zapnout UART

    clrf	FSR1H
    movlw	0x11
    movwf	FSR1L		;PIR1 pomoci nepr. addr. (pro RCIF)


    movlb	3		;Banka3 s UART
Loop:	
    btfss	INDF1,5		;RCIF	;prisel byte?
    goto	$-1
    movf	RCREG,W		;nacist ho do W
    movwf	tmp		;ulozit protoze RCREG to po 1. precteni nehlida

    nop				;pro jistotu (pocka jeden takt)
    btfss	INDF1,4		; TXIF	;je TX buffer prazdny?
    goto	$-1
    movwf	TXREG		;zapsat do odesilaciho bufferu

    movlw	0x20
    subwf	tmp,W		;z maleho pismena velke


    nop				;pro jistotu
    btfss	INDF1,4		; TXIF	;je TX buffer prazdny?
    goto	$-1
    movwf	TXREG		;zapsat do odesilaciho bufferu

    nop				;pro jistotu
    btfss	TXSTA,1		; TRMT	;ceka zde dokud se vse neodesle
    goto	$-1

    goto    Loop


	
#include	"Config_IOs.inc"
END
