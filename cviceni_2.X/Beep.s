;Po N stiscich BT1 spusti BT2 N pipnuti
PROCESSOR 16F1508 


#define	INCR	PORTA,4	    ;tlacitko BT1 - zvys pocet pipnuti
#define	RUN	PORTA,5	    ;tlacitko BT2 - spust pipani
#define BUZZER  PORTC,1	    ;akusticky menic
    
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

;#include "p16f1508.inc"
#include <xc.inc> 

;VARIABLE DEFINITIONS
;COMMON RAM 0x70 to 0x7F
cnt1	EQU 0x70
cnt2	EQU 0x71
cnt3	EQU 0x72
num	EQU 0x73   
  
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
    movlb   0
	
Main:	
    clrf    num

; Test stisku tlacitka INCR
BLoop:	
    clrf    cnt1	; citac osetreni zakmitu tlacitek
BT2L:	
    btfsc   RUN
    goto    RBeep	; skok na pipani
    btfss   INCR	; preskok pri stisku tlacitka (H)
    goto    BLoop	; pri urovni L test od zacatku
    decfsz  cnt1,F
    goto    BT2L
    incf    num,F	; zvyseni poctu pipnuti

; Test uvolneni tlacitka INCR
    clrf    cnt1
BT2H:	
    btfsc   INCR
    goto    $-2
    decfsz  cnt1,F
    goto    BT2H
    goto    BLoop

; Pipani        
RBeep:	
    movf    num,W
    btfsc   STATUS, 2	; 2 = Z	;test citace pipnuti na nulu
    goto    Main	;cely cyklus od zacatku
BeepLp:	
    movlw   120
    movwf   cnt1	; citac poctu pulperiod zvukoveho kmito?tu
HalfPer:
    movlw   00000010
    xorwf   PORTC,F	; negace urovne pinu budiciho akust. m?nic
    clrf    cnt2
    nop			; zpozdeni pro p?lperiodu zvuku
    decfsz  cnt2,F
    goto    $-2
    decfsz  cnt1,F	; test konce pipnuti
    goto    HalfPer	; dalsi pulperioda

; Zpozdeni - pauza mezi pipnutimi - 3 vnorene smycky
    movlw   3
    movwf   cnt3
Pause1:	
    clrf    cnt2
Pause2:	
    clrf    cnt1
    decfsz  cnt1,F
    goto    $-1
    decfsz  cnt2,F
    goto    Pause2
    decfsz  cnt3,F
    goto    Pause1
    decf    num,F 	; dekrementace citace pÌpnuti               
    goto    RBeep
	
		
	
#include    "Config_IOs.inc"
		
END
