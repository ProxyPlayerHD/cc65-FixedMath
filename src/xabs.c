// ---------------------------------------------------------------------------
// xabs.c
// ---------------------------------------------------------------------------
//
// Fixed Point Absolute
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xabs(fix16_t inValue){
	fix16_t mask = (inValue >> 31);
	return (inValue + mask) ^ mask;
}

