// ---------------------------------------------------------------------------
// xtoa.c
// ---------------------------------------------------------------------------
//
// Fixed Point to String Conversion
//

#include <stdint.h>
#include "FixedMath.h"

	// 5 decimals is enough for full fix16_t precision
static const uint32_t scales[8] = {1, 10, 100, 1000, 10000, 100000, 100000, 100000};

static char *itoa_loop(char *buf, uint32_t scale, uint32_t value, uint8_t skip){
	while (scale){
		uint16_t digit = (value / scale);
		
		if ((skip > 0) || digit || (scale == 1)){
			skip = 0;
			*buf++ = '0' + digit;
			value %= scale;
		}
		scale /= 10;
	}
	return buf;
}

void __fastcall__ xtoa(fix16_t value, char *buf, uint8_t decimals){
	
	uint16_t intpart;
	uint32_t fracpart;
	uint32_t scale;
	uint32_t uvalue = (value >= 0) ? value : -value;
	
	if (value < 0){
		*buf++ = '-';
	}
	
	// Separate the integer and decimal parts of the value
	intpart = uvalue >> 16;
	fracpart = uvalue & 0xFFFF;
	scale = scales[decimals & 7];
	fracpart = xmul(fracpart, scale);
	
	if (fracpart >= scale){
		// Handle carry from decimal part
		++intpart;
		fracpart -= scale;    
	}
	
	// Format integer part
	buf = itoa_loop(buf, 10000, intpart, 1);
	
	// Format decimal part (if any)
	if (scale != 1){
		*buf++ = '.';
		buf = itoa_loop(buf, scale / 10, fracpart, 0);
	}
	
	*buf = '\0';
}

