; ---------------------------------------------------------------------------
; fxfromint.a65
; ---------------------------------------------------------------------------
;
; Convert from Integer to Fixed Point
;


.importzp	sreg
.export		_fxfromint

.segment "CODE"

.PC02		; Force 65C02 assembly mode

; ---------------------------------------------------------------------------
; fix16_t __fastcall__ _fxfromint(int16_t value);
; Reads value from SERIAL

; value [.x] A
; value [x.] X

.proc _fxfromint: near
	STA sreg
	STX sreg + 1
	LDA #0
	TAX
RTS
.endproc
