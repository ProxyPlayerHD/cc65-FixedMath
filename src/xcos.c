// ---------------------------------------------------------------------------
// xcos.c
// ---------------------------------------------------------------------------
//
// Fixed Point Cosine
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xcos(fix16_t inAngle){
	return xsin(inAngle + FX_PIHALF);
}

