// ---------------------------------------------------------------------------
// xlog2.c
// ---------------------------------------------------------------------------
//
// Fixed Point Logarithmic (Base-2)
//

#include <stdint.h>
#include "FixedMath.h"

static fix16_t xrs(fix16_t x){
	return (x >> 1) + (x & 1);
}

static fix16_t xlog2_inner(fix16_t x){
	uint8_t i;
	fix16_t result = 0;
	
	while(x >= itox(2)){
		++result;
		x = xrs(x);
	}
	
	if(x == 0) return (result << 16);
	
	for(i = 16; i > 0; i--)
	{
		x = xmul(x, x);
		result <<= 1;
		if(x >= itox(2))
		{
			result |= 1;
			x = xrs(x);
		}
	}
	
	x = xmul(x, x);
	if(x >= itox(2)) result++;
	
	return result;
}

fix16_t __fastcall__ xlog2(fix16_t inValue){
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
		if (inValue == 1) return itox(-16);
		
		return -xlog2_inner(xdiv(FX_ONE, inValue));
	}

	// If input >= 1, just proceed as normal.
	// Note that x == FX_ONE is a special case, where the answer is 0.
	return xlog2_inner(inValue);
}

