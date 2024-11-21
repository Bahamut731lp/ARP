;RS-KO pomoci preruseni pozitivni hrana na BT1 a negativni hrana na BT2
PROCESSOR 16F1508 

;#define	LED1	PORTC,5
    
   
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
    movlb	7		; Banka7 s IOC
    btfss	IOCAF,4		; preruseni od BT1(RA4)?
    goto	BT2Int		; je to tedy od BT2...
    bcf		IOCAF,4		; vynulovat priznak od BT1(RA4)
    movlb	0		; Banka0 s PORT
    bsf		LED1
    retfie
	
BT2Int:	
    bcf		IOCAF,5		; vynulovat priznak od BT2(RA5)
    movlb	0		; Banka0 s PORT
    bcf		LED1
    retfie
	
	

Start:	
    movlb	1		; Banka1
    movlw	01101000B	; 4MHz Medium
    movwf	OSCCON		; nastaveni hodin

    call	Config_IOs

    ;nastaveni preruseni
    movlb	7		; Banka7 s IOC
    bsf		IOCAP,4		; BT1(RA4) nastavena detekce pozitivni hrany
    bsf		IOCAN,5		; BT2(RA5) nastavena detekce negativni hrany
    clrf	IOCAF		; smazat priznak doted detekovanych hran

    bsf		INTCON, 3	; IOCIE	;povolit preruseni od IOC
    bsf		INTCON,7	; GIE	;povolit preruseni jako takove	

    movlb	0		; Banka0 s PORT

	
Main:	
    goto	$		; stale opakovat smycku
	
	
    #include	"Config_IOs.inc"
    
		
END
		