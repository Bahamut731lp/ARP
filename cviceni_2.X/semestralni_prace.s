;zobrazi hodnotu z ADC (potenciometr 1) na 7seg
PROCESSOR 16F1508 

;Pou?ijeme LEDky jako jednobitovou pam??,
;Pá? nechci pou?ívate celou bu?ku v RAM a tohle bohat? sta?í...
;A navíc to je dobrej debug ngl...
#define TOGGLE_LED	PORTC,5
#define	BTN_TOGGLE	PORTA,4	    ;tlacitko BT1 - Toggle rotujiciho segmentu
#define	BTN_SPEED	PORTA,5	    ;tlacitko BT2 - Zmen rychlost rotace kolem segmentu

#define MAX_SPEED	3   ; Nejv?t?í mo?ný po?et re?im? rychlosti, indexováno od 0
#define MAX_FRAMES	10  ; Nejv?t?í mo?ný po?et snímk? rotace kolem displeje. Na obejetí celého displeje pot?ebujeme 10
    
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
#include	"Config_IOs.inc"
#include	"Display.inc"
  
;VARIABLE DEFINITIONS
;COMMON RAM 0x70 to 0x7F
cnt1	EQU 0x70
cnt2	EQU 0x71
	
speed_reg   EQU 0x72
frame_reg   EQU 0x73

num7S	EQU 0x74	; cislo pro zobrazeni, dalsi 3B budou displeje!
dispL   EQU 0x75	; levy 7seg
dispM   EQU 0x76	; prostredni 7seg
dispR   EQU 0x77	; pravy 7seg

    
;**********************************************************************
PSECT PROGMEM0,delta=2, abs
RESETVEC:
    ORG		0x00 
    PAGESEL	Start
    GOTO	Start

    ORG		0x04
    movlb	7		; Banka7 s IOC
    btfss	IOCAF,4		; preruseni od BT1(RA4)?
    goto	SPEED_INT     ; je to tedy od BT2...
    btfss	IOCAF,5		; hlavne nespadnout do if-else blunderu...
    goto	TOGGLE_INT
    retfie
    
TOGGLE_INT:
    bcf		IOCAF,4		; vynulovat priznak od BT1(RA4)
    
    movlb   0
    movlw	00100000B	;maska pro blikani TOGGLE_LED
    xorwf	PORTC

    retfie    
    
SPEED_INT:
    bcf		IOCAF,5		; vynulovat priznak od BT2(RA5)

    ; Zmen?íme rychlostní stupe?, a pokud je nula, tak resetujeme....
    decfsz  speed_reg, F
    retfie
    
    ; Reset kdy? nám to p?ete?e p?es maximální stupe?
    movlw   MAX_SPEED
    sublw   1
    movwf   speed_reg

    retfie
    
Start:
    movlb	1		; Banka1
    movlw	01101000B	; 4MHz Medium
    movwf	OSCCON		; nastaveni hodin

    call	Config_IOs
    call	Config_SPI

    ;=====================
    ;Nastavení p?eru?ení
    ;=====================
    movlb	7		; Banka7 s IOC
    bsf		IOCAN,4		; BT1(RA4) nastavena detekce pozitivni hrany
    bsf		IOCAP,5		; BT2(RA5) nastavena detekce negativni hrany
    clrf	IOCAF		; smazat priznak doted detekovanych hran

    bsf		INTCON, 3	; IOCIE	;povolit preruseni od IOC
    bsf		INTCON,7	; GIE	;povolit preruseni jako takove	

    movlb	0		; Banka0 s PORT
    
    ;=====================
    ;Nastaveni výchozích hodnot u registr?, které se pou?ívají pro LUT.
    ;=====================
    call RESET_SPEED
    call RESET_FRAMES
    goto Loop
    
RESET_SPEED:
    movlw   MAX_SPEED
    sublw   1
    movwf   speed_reg
    return

RESET_FRAMES:
    movlw   MAX_FRAMES
    sublw   1
    movwf   frame_reg
    return
    
Loop:
    movlb	0
   
    ; Zobrazení aktuálního snímku animace
    ; D?le?itý je si uv?domit, ?e tohle funguje jako fronta
    ; Tak?e kdy? zavolám SendByte7S, tak se to posune v?echno doprava
    ; A to co tam chci poslat se dá do prvního (resp. do toho nejvíc vlevo)
    movf    frame_reg, W
    addlw   0
    call    Frame_Table
    call    SendByte7S
    
    movf    frame_reg, W
    addlw   1
    call    Frame_Table
    call    SendByte7S
    
    movf    frame_reg, W
    addlw   2
    call    Frame_Table
    call    SendByte7S    
    
    ; Zm?na snímku animace pro dal?í frame
    decfsz  frame_reg, F
    call    RESET_FRAMES
    
    ; Delay mezi snímkama
    ; Hele, je mi jasný, ?e kdy? se v tom bude n?jaký trouba hrabat,
    ; a p?epí?e mi to na hodnotu, která je mimo tabulku, tak se budou dít divný
    ; v?ci. But you know what? Idc.
    movf    speed_reg, W;Index rychlostního re?imu
    call    Speed_Table	; Na?te aktuální rychlost do W
    call    Delay_ms
    
    
    goto    Loop

Delay_ms:
    movwf	cnt2		
OutLp:	
    movlw	249		
    movwf	cnt1		
    nop			
    decfsz	cnt1,F
    goto	$-2		
    decfsz	cnt2,F
    goto	OutLp
    return	

Frame_Table:
    brw
    ; První frame
    retlw   10000000B
    retlw   00000000B
    retlw   00000000B
    
    ; Druhý frame
    retlw   00000000B
    retlw   10000000B
    retlw   00000000B
    
    ; T?etí frame
    retlw   00000000B
    retlw   00000000B
    retlw   10000000B
    
    ; ?tvrtý frame
    retlw   00000000B
    retlw   00000000B
    retlw   01000000B
    
    ; Pátý frame
    retlw   00000000B
    retlw   00000000B
    retlw   00100000B

    ; ?estý frame
    retlw   00000000B
    retlw   00000000B
    retlw   00010000B
    
    ; Sedmý frame
    retlw   00000000B
    retlw   00010000B
    retlw   00000000B
    
    ; Osmý frame
    retlw   00010000B
    retlw   00000000B
    retlw   00000000B

    ; Devátý frame
    retlw   00001000B
    retlw   00000000B
    retlw   00000000B
    
    ; Desátý frame
    retlw   00000100B
    retlw   00000000B
    retlw   00000000B

Speed_Table:
    brw
    retlw   100
    retlw   200
    retlw   300
	

END

