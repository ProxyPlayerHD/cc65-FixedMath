// ---------------------------------------------------------------------------
// xatan.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arctangent
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xatan(fix16_t inAngle){
	return xatan2(inAngle, FX_ONE);
}

