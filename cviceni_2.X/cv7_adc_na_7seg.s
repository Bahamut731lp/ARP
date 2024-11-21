;zobrazi hodnotu z ADC (potenciometr 1) na 7seg
PROCESSOR 16F1508 
 
#define	BTN_INC	PORTA,4	    ;tlacitko BT1 - sniz pocet
#define	BTN_DEC	PORTA,5	    ;tlacitko BT2 - zvys pocet
#define	LED1	PORTC,5
    
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
	
num7S	EQU 0x72	; cislo pro zobrazeni, dalsi 3B budou displeje!
dispL   EQU 0x73	; levy 7seg
dispM   EQU 0x74	; prostredni 7seg
dispR   EQU 0x75	; pravy 7seg

    
;**********************************************************************
PSECT PROGMEM0,delta=2, abs
RESETVEC:
    ORG		0x00 
    PAGESEL	Start
    GOTO	Start

    ORG		0x04
    movlb	7		; Banka7 s IOC
    btfss	IOCAF,4		; preruseni od BT1(RA4)?
    goto	Btn2Int		; je to tedy od BT2...
    btfss	IOCAF,5
    goto	Btn1Int
    retfie
    
Btn1Int:
    bcf		IOCAF,4		; vynulovat priznak od BT1(RA4)
    movlb	1		; Banka1 s ADC
    movlw	00101001B	; P2 = AN10
    ;movlw	00011000B	; P1 = AN6
    movwf	ADCON0
    movlw	01110000B	; leftAlig, FRC, VDD
    movwf	ADCON1
    clrf	ADCON2		; single conv.
    bsf		ADCON0,0	; ADON ;zapnout ADC
    movlb	0
    retfie
    
Btn2Int:
    bcf		IOCAF,5		; vynulovat priznak od BT1(RA4)
    movlb	1		; Banka1 s ADC
    ;movlw	00101000B	; P2 = AN10
    movlw	00011001B	; P1 = AN6
    movwf	ADCON0
    movlw	01110000B	; leftAlig, FRC, VDD
    movwf	ADCON1
    clrf	ADCON2		; single conv.
    bsf		ADCON0,0	; ADON ;zapnout ADC
    movlb	0
    retfie
    
Start:
    movlb	1		; Banka1
    movlw	01101000B	; 4MHz Medium
    movwf	OSCCON		; nastaveni hodin

    call	Config_IOs
    call	Config_SPI

    movlb	1		; Banka1 s ADC
    movlw	00101000B	; P2 = AN10
    ;movlw	00011000B	; P1 = AN6
    movwf	ADCON0
    movlw	01110000B	; leftAlig, FRC, VDD
    movwf	ADCON1
    clrf	ADCON2		; single conv.
    bsf		ADCON0,0	; ADON ;zapnout ADC
 
    ;config p?eru?ení
    movlb	7		; Banka7 s IOC
    bsf		IOCAN,4		; BT1(RA4) nastavena detekce pozitivni hrany
    bsf		IOCAP,5		; BT2(RA5) nastavena detekce negativni hrany
    clrf	IOCAF		; smazat priznak doted detekovanych hran

    bsf		INTCON, 3	; IOCIE	;povolit preruseni od IOC
    bsf		INTCON,7	; GIE	;povolit preruseni jako takove	

    movlb	0		; Banka0 s PORT

    
Loop:
    movlb	0
    btfss	BTN_INC,4
    goto	NUmber
    btfss	BTN_DEC,5
    goto	NUmber
    
    movlw	00001010B	
    call	SendByte7S

    movlw	00001010B	
    call	SendByte7S
    
    
    movlw	10011110B	
    call	SendByte7S

    call	Delay100
    goto    Loop    

NUmber:
    movlb	1		; Banka1 s ADC
    bsf		ADCON0,1	; GO ; start A/D prevodu
    btfsc	ADCON0,1	; GO ; A/D prevod skoncen?
    goto	$-1             ; pokud ne, navrat o radek vyse
    

    movf	ADRESH,W	; nacte nejvyssich 8 bit? vysledku
    movwf	num7S		; zapsani cisla pro zobrazeni
    call	Bin2Bcd		; z num7S udela BCD cisla v dispL-dispM-dispR

    movf	dispL,W
    call	Byte2Seg	; 4bit. cislo ve W zmeni na segment pro zobrazeni
    movwf	dispL

    movf	dispM,W
    call	Byte2Seg	; 4bit. cislo ve W zmeni na segment pro zobrazeni
    movwf	dispM

    movf	dispR,W
    call	Byte2Seg	; 4bit. cislo ve W zmeni na segment pro zobrazeni
    movwf	dispR	
    call	SendByte7S	; odesle W vzdy do leveho displeje (posun ostat.)
    movf	dispM,W
    call	SendByte7S	; odesle W vzdy do leveho displeje (posun ostat.)
    movf	dispL,W
    call	SendByte7S	; odesle W vzdy do leveho displeje (posun ostat.)
    call	Delay100	; jen aby u 7seg nesvitily i nepouzite segmenty
    
    
    ;bsf		LED1
    goto	Loop

Delay100:			 ; zpozdeni 100 ms
    movlw	100
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

	
#include	"Config_IOs.inc"
#include	"Display.inc"

END

