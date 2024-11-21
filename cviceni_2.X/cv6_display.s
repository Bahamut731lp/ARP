;Desitkovy citac (0 az 255)

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
cnt1	EQU 0x70
cnt2	EQU 0x71   
cnt3	EQU 0x72
sec	EQU 0x73    ; citac 1 sekundy
num7S   EQU 0x74    ; cislo pro zobrazeni, dalsi 3B budou displeje!
dispL	EQU 0x75    ; levy 7seg
dispM	EQU 0x76    ; prostredni 7seg
dispR	EQU 0x77    ; pravy 7seg
	

    
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
    movlb   1		    ; Bank1
    movlw   01101000B	    ; 4MHz Medium
    movwf   OSCCON	    ; nastaveni hodin

    call    Config_IOs
    call    Config_SPI	    ; konfiguruje periferie

    movlb   0
	
	
Main:	
    clrf    sec		    ; vynulovani registru sec
	
Loop:	
    movf    sec,W
    movwf   num7S	    ; zapsani cisla pro zobrazeni
    call    Bin2Bcd	    ; z num7S udela BCD cisla v dispL-dispM-dispR, zapisuje stovky, desitky a jednotky

    movf    dispL,W
    call    Byte2Seg	    ; 4bit. cislo ve W zmeni na segment pro zobrazeni
    movwf   dispL

    movf    dispM,W
    call    Byte2Seg	    ; 4bit. cislo ve W zmeni na segment pro zobrazeni
    movwf   dispM

    movf    dispR,W
    call    Byte2Seg	    ; 4bit. cislo ve W zmeni na segment pro zobrazeni
    movwf   dispR	
    call    SendByte7S	    ; odesle W vzdy do leveho displeje (posun ostat.)
    movf    dispM,W
    call    SendByte7S	    ; odesle W vzdy do leveho displeje (posun ostat.)
    movf    dispL,W
    call    SendByte7S	    ; odesle W vzdy do leveho displeje (posun ostat.)


    movlw   10		    ; zpozdeni 10*100=1000 ms
    movwf   cnt3
    call    Delay100
    decfsz  cnt3,F
    goto    $-2

    incf    sec,F
    goto    Loop

	
Delay100:		    ; zpozdeni 100 ms
    movlw   100
Delay_ms:
    movwf   cnt2		
OutLp:	
    movlw   249		
    movwf   cnt1		
    nop			
    decfsz  cnt1,F
    goto    $-2		
    decfsz  cnt2,F
    goto    OutLp
    return	

		
#include	"Config_IOs.inc"
#include	"Display.inc"
		
END
	
