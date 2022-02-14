//	
//	Fixed Point Math Library for cc65
//	
//	Implements Arithmetic and Trigometric Functions using the Q16.16 Format
//	

#ifndef FIXED_MATH
	#define FIXED_MATH
	
	#define FX_MAX		0x7FFFFFFF		// Maximum Value
	#define FX_MIN		0x80000000		// Minimum Value
	#define FX_OVFL		0x80000000		// Overflow Value
	#define FX_ONE		0x00010000		// 1.0
	#define FX_PIHALF	0x0001921F		// PI/2
	#define FX_PI		0x0003243F		// PI
	#define FX_PI2		0x0006487E		// PI*2
	#define FX_4DPI		0x000145F3		// 4/PI
	#define FX_PID4		0x0000C90F		// PI/4
	#define FX_3PID4	0x00025B2F		// PI*3/4
	#define FX_E		0x0002B7E1		// e (2.71828182846)
	#define FX_ET2		0x00369920		// e^4
	
	typedef int32_t	fix16_t;
	
	#define fxfromint(value) ((fix16_t)value << 16)		// Use this instead of the Assembly function, as it's probably faster
	//fix16_t __fastcall__ fxfromint(int16_t value);	// The Function is still included though, in case it's needed for something
	int16_t __fastcall__ fxtoint(fix16_t value);
	fix16_t __fastcall__ fxmul(fix16_t multiplier, fix16_t multiplicand);
	fix16_t __fastcall__ fxdiv(fix16_t Dividend, fix16_t Divisor);
	
	extern fix16_t __fastcall__ fxabs(fix16_t value);
	extern fix16_t __fastcall__ fxsqrt(fix16_t value);
	extern fix16_t __fastcall__ fxexp(fix16_t value);
	extern fix16_t __fastcall__ fxlog(fix16_t value);
	extern fix16_t __fastcall__ fxlog2(fix16_t value);
	
	extern fix16_t __fastcall__ fxsin(fix16_t inAngle);
	extern fix16_t __fastcall__ fxcos(fix16_t inAngle);
	extern fix16_t __fastcall__ fxtan(fix16_t inAngle);
	extern fix16_t __fastcall__ fxasin(fix16_t inAngle);
	extern fix16_t __fastcall__ fxacos(fix16_t inAngle);
	extern fix16_t __fastcall__ fxatan(fix16_t inAngle);
	extern fix16_t __fastcall__ fxatan2(fix16_t inY , fix16_t inX);
	
	
	#ifdef FT_SERIAL
		void __fastcall__ ftprintfx(fix16_t value);
	#endif
#endif