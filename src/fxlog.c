// ---------------------------------------------------------------------------
// fxlog.c
// ---------------------------------------------------------------------------
//
// Fixed Point Logarithmic
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxlog(fix16_t inValue){
	fix16_t guess = fxfromint(2);
	fix16_t delta;
	uint16_t scaling = 0;
	uint16_t count = 0;
	
	if (inValue <= 0){
		return FX_MIN;
	}
	
	// Bring the value to the most accurate range (1 < x < 100)
	while (inValue > fxfromint(100)){
		inValue = fxdiv(inValue, FX_ET2);
		scaling += 4;
	}
	
	while (inValue < FX_ONE){
		inValue = fxmul(inValue, FX_ET2);
		scaling -= 4;
	}
	do {
		// Solving e(x) = y using Newton's method
		// f(x) = e(x) - y
		// f'(x) = e(x)
		fix16_t e = fxexp(guess);
		delta = fxdiv(inValue - e, e);
		
		// It's unlikely that logarithm is very large, so avoid overshooting.
		if (delta > fxfromint(3))
			delta = fxfromint(3);
		
		guess += delta;
	} while ((count++ < 10) && ((delta > 1) || (delta < -1)));
	
	return guess + fxfromint(scaling);
}

