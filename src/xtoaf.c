// ---------------------------------------------------------------------------
// xtoaf.c
// ---------------------------------------------------------------------------
//
// Fixed Point to String Conversion (Fast)
//

#include <stdint.h>
#include <stdio.h>
#include "FixedMath.h"

char __FX_GLOBAL_STR[20];

char* __fastcall__ xtoaf(fix16_t value, uint8_t decimals){
	xtoa(value, __FX_GLOBAL_STR, decimals);
	return __FX_GLOBAL_STR;
}

