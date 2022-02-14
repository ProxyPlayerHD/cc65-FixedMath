// ---------------------------------------------------------------------------
// fxasin.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arcsine
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxasin(fix16_t inAngle){
	fix16_t out;
	
	if((inAngle > FX_ONE) || (inAngle < -FX_ONE)){
		return 0;
	}
	
	out = (FX_ONE - fxmul(inAngle, inAngle));
	out = fxdiv(inAngle, fxsqrt(out));
	return fxatan(out);
}

