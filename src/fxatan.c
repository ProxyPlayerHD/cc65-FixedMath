// ---------------------------------------------------------------------------
// fxatan.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arctangent
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxatan(fix16_t inAngle){
	return fxatan2(inAngle, FX_ONE);
}

