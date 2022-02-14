; ---------------------------------------------------------------------------
; fxdiv.a65
; ---------------------------------------------------------------------------
;
; Fixed Point Divide
;

.import		popeax, negeax
.importzp	sreg, tmp1, tmp2, tmp3, tmp4, ptr1, ptr2, ptr3, ptr4
.export		_fxdiv

.segment "CODE"

.PC02		; Force 65C02 assembly mode

; ---------------------------------------------------------------------------
; fix16_t __fastcall__ _fxdiv(fix16_t Dividend, fix16_t Divisor);
; Divides 2 Fixed Point values from eachother

; Software Stack+0 [...x] Input1 (Dividend)
; Software Stack+1 [..x.] Input1 (Dividend)
; Software Stack+2 [.x..] Input1 (Dividend)
; Software Stack+3 [x...] Input1 (Dividend)
; A				   [...x] Input2 (Divisor)
; X				   [..x.] Input2 (Divisor)
; sreg			   [.x..] Input2 (Divisor)
; sreg+1		   [x...] Input2 (Divisor)

.proc _fxdiv: near
	STZ ptr2		; Clear ptr2
	
	TAY				; Put the [...x] Byte into Y for now
	LDA sreg + 1
	BPL @IN2POS		; Check if the Divisor is Negative
	LDA ptr2		; If it is, Invert ptr2
	EOR #$FF
	STA ptr2
	
	TYA				; Get the [...x] Byte back from Y
	JSR negeax		; Get the 2's Complement of the Divisor (A/X/SREG)
	TAY				; And back it goes into Y
	LDA sreg + 1	; Load the [x...] Byte for the next part
	
	@IN2POS:
	PHA
	LDA sreg
	PHA
	PHX
	PHY				; Save the Divisor onto the Stack
	
	@IN1:
	JSR popeax		; Get the Dividend from the Software Stack
	TAY				; Put the [...x] Byte into Y for now
	LDA sreg + 1
	BPL @IN1POS		; Check if the Dividend is Negative
	LDA ptr2		; If it is, Invert ptr2
	EOR #$FF
	STA ptr2
	
	TYA				; Get the [...x] Byte back from Y
	JSR negeax		; Get the 2's Complement of the Dividend (A/X/SREG)
	TAY				; And back it goes into Y
	LDA sreg + 1	; Load the [x...] Byte for the next part
	
	@IN1POS:
	STA ptr3 + 1
	LDA sreg
	STA ptr3
	STX sreg + 1
	STY sreg		; Save the Dividend into the Memory (and effectively shift it by 16 bits to the left)
	
	STZ ptr4 + 1
	STZ ptr4
	STZ ptr1 + 1
	STZ ptr1		; Clear the Upper and Lower Byte of the Dividend
	

; 64bx32b=64b Division (32b Remainder)
;		ptr1   - Dividend [.......x] (set to 0)
;		ptr1+1 - Dividend [......x.] (set to 0)
;		sreg   - Dividend [.....x..]
;		sreg+1 - Dividend [....x...]
;		ptr3   - Dividend [...x....]
;		ptr3+1 - Dividend [..x.....]
;		ptr4   - Dividend [.x......] (set to 0)
;		ptr4+1 - Dividend [x.......] (set to 0)
;		tmp1   - Remainder    [...x]
;		tmp2   - Remainder    [..x.]
;		tmp3   - Remainder    [.x..]
;		tmp4   - Remainder    [x...]
; SP:		 1 - Divisor      [...x]
;			 2 - Divisor      [..x.]
;			 3 - Divisor      [.x..]
;			 4 - Divisor      [x...]

	@DIV32:
	STZ tmp1
	STZ tmp2
	STZ tmp3
	STZ tmp4			; Preset remainder to 0
	TSX					; Get the SP into X
	LDY #65				; Do the Loop 65 times
	CLC
	
	@LOOP:
	ROL ptr1
	ROL ptr1 + 1
	ROL sreg
	ROL sreg + 1
	ROL ptr3
	ROL ptr3 + 1
	ROL ptr4
	ROL ptr4 + 1		; Dividend * 2 + Carry, MSB -> Carry
	
	ROL tmp1
	ROL tmp2
	ROL tmp3
	ROL tmp4			; Remainder * 2 + Carry
	
	
	SEC
	LDA tmp1
	SBC $0101,X
	PHA
	LDA tmp2
	SBC $0102,X
	PHA
	LDA tmp3
	SBC $0103,X
	PHA
	LDA tmp4			; Substract the Divisor from the Remainder to see if it fits in
	SBC $0104,X
	BCC @SKIP			; If Carry=0 then divisor didn't fit in yet
	
	STA tmp4			; else save substraction result as new remainder
	PLA
	STA tmp3
	PLA
	STA tmp2
	PLA
	STA tmp1
	DEY
	BNE @LOOP
	BRA @EXIT
	@SKIP:
	PLA
	PLA
	PLA
	DEY
	BNE @LOOP
	@EXIT:
	
	; Result is now in:
	; P4+1 P4+0 P3+1 P3+0  S1   S0  P1+1 P1+0
	;  QQ   QQ   QQ   QQ   QQ   QQ   QQ   QQ
	;  --   --   --   --   S1   S0   X    A
	
	PLA
	PLA
	PLA
	PLA				; Adjust the Stack by 4 Bytes
	
	LDA ptr1
	LDX ptr1 + 1	; Put the lower 16-bits of the Result into A/X
	
	LDY ptr2		; Check if the Output is Negative
	BPL @ISPOS		; If it is:
	JSR negeax		; Get the 2's Complement of the Output (A/X/SREG)
	@ISPOS:			; Otherwise just skip this part
RTS
.endproc
