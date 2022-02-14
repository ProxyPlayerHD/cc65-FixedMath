// ---------------------------------------------------------------------------
// fxtan.c
// ---------------------------------------------------------------------------
//
// Fixed Point Tangent
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxtan(fix16_t inAngle){
	return fxdiv(fxsin(inAngle), fxcos(inAngle));
}

