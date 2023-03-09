// ---------------------------------------------------------------------------
// xasin.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arcsine
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xasin(fix16_t inAngle){
	fix16_t out;
	
	if((inAngle > FX_ONE) || (inAngle < -FX_ONE)){
		return 0;
	}
	
	out = (FX_ONE - xmul(inAngle, inAngle));
	out = xdiv(inAngle, xsqrt(out));
	return xatan(out);
}

