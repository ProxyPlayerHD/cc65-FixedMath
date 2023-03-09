// ---------------------------------------------------------------------------
// xatan2.c
// ---------------------------------------------------------------------------
//
// Fixed Point Arctangent 2
//

#include <stdint.h>
#include "FixedMath.h"

fix16_t __fastcall__ xatan2(fix16_t inY , fix16_t inX){
	fix16_t abs_inY, angle, r, r_3;
	
	abs_inY = xabs(inY);	// Absolute inY

	if (inX >= 0){
		r = xdiv((inX - abs_inY), (inX + abs_inY));
		r_3 = xmul(xmul(r, r),r);
		angle = xmul(0x00003240 , r_3) - xmul(0x0000FB50,r) + FX_PID4;
	} else {
		r = xdiv( (inX + abs_inY), (abs_inY - inX));
		r_3 = xmul(xmul(r, r),r);
		angle = xmul(0x00003240 , r_3) - xmul(0x0000FB50,r) + FX_3PID4;
	}
	if (inY < 0){
		angle = -angle;
	}

	return angle;
}

