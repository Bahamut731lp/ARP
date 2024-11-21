;blikani pomoci WDT s uspavanim
PROCESSOR 16F1508 

   
;pozor zde je zmena - zapnut WDT!    
; window -> TMW -> conf. bits -> ctl c ctr v
; CONFIG1
CONFIG  FOSC = INTOSC         ; Oscillator Selection Bits (INTOSC oscillator: I/O function on CLKIN pin)
CONFIG  WDTE = ON            ; Watchdog Timer Enable (WDT disabled)
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

    movlw	00010010B	;cca 512 ms WDT
    movwf	WDTCON

    call	Config_IOs

    movlb	0
    bsf		PORTC,3		;rozsviceni LED2

    movlw	00101000B	;maska pro blikani LED1 a LED2
Loop:	
    sleep			;rezim spanku
    xorwf	PORTC		;dle masky zmeni polaritu LED
    goto	Loop
	
	
	
#include	"Config_IOs.inc"
		
END

