// ---------------------------------------------------------------------------
// xexp.c
// ---------------------------------------------------------------------------
//
// Fixed Point Exponent
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xexp(fix16_t inValue) {
	fix16_t result, term;
	uint8_t i, neg;
	
	if(inValue == 0){
		return FX_ONE;
	}
	if(inValue == FX_ONE){
		return FX_E;
	}
	if(inValue >= 681391){
		return FX_MAX;
	}
	if(inValue <= -772243){
		return 0;
	}
	
	// The algorithm is based on the power series for exp(x):
	// http://en.wikipedia.org/wiki/Exponential_function#Formal_definition
	// 
	// From term n, we get term n+1 by multiplying with x/n.
	// When the sum term drops to zero, we can stop summing.
	
	// The power-series converges much faster on positive values
	// and exp(-x) = 1/exp(x).
	neg = (inValue < 0);
	if (neg){
		inValue = -inValue;
	}
	
	result = inValue + FX_ONE;
	term = inValue;
	
	for (i = 2; i < 30; i++)
	{
		term = xmul(term, xdiv(inValue, itox(i)));
		result += term;
		
		if ((term < 500) && ((i > 15) || (term < 20)))
			break;
	}
	
	if (neg) result = xdiv(FX_ONE, result);
	
	return result;
}

