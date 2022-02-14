; ---------------------------------------------------------------------------
; fxtoint.a65
; ---------------------------------------------------------------------------
;
; Convert from Fixed Point to Integer
;


.importzp	sreg
.export		_fxtoint

.segment "CODE"

.PC02		; Force 65C02 assembly mode

; ---------------------------------------------------------------------------
; int16_t __fastcall__ _fxtoint(fix16_t value);
; Reads value from SERIAL

; value [...x] A
; value [..x.] X
; value [.x..] sreg
; value [x...] sreg+1

.proc _fxtoint: near
	LDA sreg + 1	; Check if the Number is Negative
	BMI @L1			; If it is, do the Negative Rounding, otherwise do the Postive one
	TXA				; Get the High Byte of the Fractional part in A
	ASL				; Put the MSB of the Fractional part into the Carry
	LDA sreg		; Get the Low Byte of the Integer part
	ADC #0			; Add the Carry to it (basically if the fractional part was 0.5 or larger this adds 1 to the Integer part)
	TAY				; Temporarily Put it into Y
	LDA sreg + 1	; Get the High Byte of the Integer part
	ADC #0			; Add the Carry to it
	TAX				; And put it into X
	TYA				; Get the Low Byte back from Y
RTS
	@L1:
	TXA				; Get the High Byte of the Fractional part in A
	EOR #$80		; Invert the MSB
	ASL				; Put the inverse of the MSB of the Fractional part into the Carry
	LDA sreg		; Get the Low Byte of the Integer part
	SBC #0			; Subtract the Carry from it (basically if the fractional part was 0.5 or larger this subtracts 1 from the Integer part)
	TAY				; Temporarily Put it into Y
	LDA sreg + 1	; Get the High Byte of the Integer part
	SBC #0			; Add the Carry to it
	TAX				; And put it into X
	TYA				; Get the Low Byte back from Y
RTS
.endproc


