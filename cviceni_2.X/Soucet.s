;Secte POCET 8-bitovych cisel od adresy ZAC, vysledek bude ve W

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

    
citac	EQU 0x70
aku	EQU 0x71

POCET   EQU 3 	        
ZAC     EQU 0x75
    
;**********************************************************************
PSECT PROGMEM0,delta=2, abs
RESETVEC:
    ORG	    0x00 
    PAGESEL Start
    GOTO    Start

    ORG	    0x04
    nop
    retfie

	
Start:	
    movlb   1		; Bank1
    movlw   01101000B	; 4MHz Medium
    movwf   OSCCON	; nastaveni hodin

    call    Config_IOs

    movlw   ZAC
    movwf   FSR0L       ; nastaveni indexregistru
    clrf    FSR0H
    movlw   POCET
    movwf   citac	; nastavenÌ citace
    clrf    aku         ; nulovani akumulatoru
Loop:	
    movf    INDF0,W     ; neprimo adresovane cislo -> W
    addwf   aku,F       ; pricteni do akumulatoru, F uklada kde vzalo operator
    incf    FSR0L,F     ; zvyseni adresy cisla
    decfsz  citac,F     ; dekrementace citace, preskok pri nule
    goto    Loop        ; opakovani cyklu
    movf    aku,W       ; vysledek -> W

    movf    WREG,W
    movwf   ZAC
    goto    $		; zacykleni

	
#include	"Config_IOs.inc"
		
END

