# cc65-FixedMath
A Simple Fixed Point Library for cc65, uses the Q16.16 Format

Using it is simple, just include the .h file in your c source file and tell ld65 to include the .lib file when linking.

# Implemented Functions:

* Conversion:
  * fxfromint(value);
  * fxtoint(value);
* Arithmetic:
  * fxmul(multiplier, multiplicand);
  * fxdiv(Dividend, Divisor);
  * fxabs(value);
  * fxsqrt(value);
  * fxexp(value);
  * fxlog(value);
  * fxlog2(value);
* Trigonometric
  * fxsin(fix16_t inAngle);
  * fxcos(fix16_t inAngle);
  * fxtan(fix16_t inAngle);
  * fxasin(fix16_t inAngle);
  * fxacos(fix16_t inAngle);
  * fxatan(fix16_t inAngle);
  * fxatan2(fix16_t inY , fix16_t inX);

# Defined Values:
```
FX_MAX		= 0x7FFFFFFF	// Maximum Value
FX_MIN		= 0x80000000	// Minimum Value
FX_OVFL		= 0x80000000	// Overflow Value
FX_ONE		= 0x00010000	// 1.0
FX_PIHALF	= 0x0001921F	// PI/2
FX_PI		= 0x0003243F	// PI
FX_PI2		= 0x0006487E	// PI*2
FX_4DPI		= 0x000145F3	// 4/PI
FX_PID4		= 0x0000C90F	// PI/4
FX_3PID4	= 0x00025B2F	// PI*3/4
FX_E		= 0x0002B7E1	// e (2.71828182846)
FX_ET2		= 0x00369920	// e^4
```
