// ---------------------------------------------------------------------------
// xtan.c
// ---------------------------------------------------------------------------
//
// Fixed Point Tangent
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xtan(fix16_t inAngle){
	return xdiv(xsin(inAngle), xcos(inAngle));
}

