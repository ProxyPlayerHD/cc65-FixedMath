// ---------------------------------------------------------------------------
// fxabs.c
// ---------------------------------------------------------------------------
//
// Fixed Point Absolute
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t fxabs(fix16_t inValue){
	fix16_t mask = (inValue >> 31);
	return (inValue + mask) ^ mask;
}

