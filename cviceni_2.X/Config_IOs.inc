Config_IOs:	;config BT1 RA4, BT2 RA5, P1 RC2 (AN6), P2 RB4 (AN10) and LED1-3 RC5 RC3 RA2
	movlb	2		;Bank2
	clrf	LATA
	clrf	LATB
	clrf	LATC
	movlb	3		;Bank3
	movlw	00000000B
	movwf	ANSELA		;digital IO
	movlw	00010000B
	movwf	ANSELB		;digital IO, except RB4
	movlw	00000100B
	movwf	ANSELC		;digital IO, except RC2
	movlb	1		;Bank1
	movlw	11111011B
	movwf	TRISA
	movlw	00111111B
	movwf	TRISB
	movlw	00010101B
	movwf	TRISC
	return


	
	
	
	
	