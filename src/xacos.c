// ---------------------------------------------------------------------------
// xacos.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arccosine
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xacos(fix16_t inAngle){
	return (FX_PIHALF - xasin(inAngle));
}

