//	
//	Fixed Point Math Library for cc65
//	
//	Implements Arithmetic and Trigometric Functions using the Q16.16 Format
//	

#ifndef FIXED_MATH
	#define FIXED_MATH
	
	#include <stdint.h>
	
	#define FX_MAX		0x7FFFFFFF		// Maximum Value
	#define FX_MIN		0x80000000		// Minimum Value
	#define FX_OVFL		0x80000000		// Overflow Value
	#define FX_ONE		0x00010000		// 1.0
	#define FX_ZERO5	0x00008000		// 0.5
	#define FX_PIHALF	0x0001921F		// PI/2
	#define FX_PI		0x0003243F		// PI
	#define FX_PI2		0x0006487E		// PI*2
	#define FX_4DPI		0x000145F3		// 4/PI
	#define FX_PID4		0x0000C90F		// PI/4
	#define FX_3PID4	0x00025B2F		// PI*3/4
	#define FX_E		0x0002B7E1		// e (2.71828182846)
	#define FX_ET2		0x00369920		// e^4
	
	typedef int32_t fix16_t;
	
	#define itox(value) ((fix16_t)value << 16)		// Use this instead of the Assembly function, as it's probably faster
	int16_t __fastcall__ xtoi(fix16_t value);
	extern fix16_t __fastcall__ atox(const char *buf);
	extern void __fastcall__ xtoa(fix16_t value, char *buf, uint8_t decimals);
	extern char* __fastcall__ xtoaf(fix16_t value, uint8_t decimals);
	
	fix16_t __fastcall__ xmul(fix16_t multiplier, fix16_t multiplicand);
	fix16_t __fastcall__ xdiv(fix16_t Dividend, fix16_t Divisor);
	extern fix16_t __fastcall__ xabs(fix16_t value);
	extern fix16_t __fastcall__ xsqrt(fix16_t value);
	extern fix16_t __fastcall__ xexp(fix16_t value);
	extern fix16_t __fastcall__ xlog(fix16_t value);
	extern fix16_t __fastcall__ xlog2(fix16_t value);
	
	extern fix16_t __fastcall__ xsin(fix16_t inAngle);
	extern fix16_t __fastcall__ xcos(fix16_t inAngle);
	extern fix16_t __fastcall__ xtan(fix16_t inAngle);
	extern fix16_t __fastcall__ xasin(fix16_t inAngle);
	extern fix16_t __fastcall__ xacos(fix16_t inAngle);
	extern fix16_t __fastcall__ xatan(fix16_t inAngle);
	extern fix16_t __fastcall__ xatan2(fix16_t inY , fix16_t inX);
	
#endif