// ---------------------------------------------------------------------------
// fxacos.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arccosine
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxacos(fix16_t inAngle){
	return (FX_PIHALF - fxasin(inAngle));
}

