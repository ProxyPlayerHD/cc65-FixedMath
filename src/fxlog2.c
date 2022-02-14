// ---------------------------------------------------------------------------
// fxlog2.c
// ---------------------------------------------------------------------------
//
// Fixed Point Logarithmic (Base-2)
//

#include <stdint.h>
#include "FixedMath.h"

static fix16_t fxrs(fix16_t x){
	return (x >> 1) + (x & 1);
}

static fix16_t fxlog2_inner(fix16_t x){
	uint8_t i;
	fix16_t result = 0;
	
	while(x >= fxfromint(2)){
		++result;
		x = fxrs(x);
	}
	
	if(x == 0) return (result << 16);
	
	for(i = 16; i > 0; i--)
	{
		x = fxmul(x, x);
		result <<= 1;
		if(x >= fxfromint(2))
		{
			result |= 1;
			x = fxrs(x);
		}
	}
	
	x = fxmul(x, x);
	if(x >= fxfromint(2)) result++;
	
	return result;
}

fix16_t fxlog2(fix16_t inValue){
	// Note that a negative inValue gives a non-real result.
	// If inValue == 0, the limit of log2(inValue)  as inValue -> 0 = -infinity.
	// log2(-ve) gives a complex result.
	if (inValue <= 0){
		return FX_OVFL;
	}
	
	// If the input is less than one, the result is -log2(1.0 / in)
	if (inValue < FX_ONE){
		// Note that the inverse of this would overflow.
		// This is the exact answer for log2(1.0 / 65536)
		if (inValue == 1) return fxfromint(-16);
		
		return -fxlog2_inner(fxdiv(FX_ONE, inValue));
	}

	// If input >= 1, just proceed as normal.
	// Note that x == FX_ONE is a special case, where the answer is 0.
	return fxlog2_inner(inValue);
}

