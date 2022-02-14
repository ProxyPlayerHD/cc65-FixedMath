// ---------------------------------------------------------------------------
// fxcos.c
// ---------------------------------------------------------------------------
//
// Fixed Point Cosine
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxcos(fix16_t inAngle){
	return fxsin(inAngle + FX_PIHALF);
}

