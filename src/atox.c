// ---------------------------------------------------------------------------
// atox.c
// ---------------------------------------------------------------------------
//
// String to Fixed Point Conversion
//

#include <stdint.h>
#include "FixedMath.h"

static uint8_t isdigit(char c){
	return c >= '0' && c <= '9';
}

static uint8_t isspace(char c){
	return c == ' ' || c == '\r' || c == '\n' || c == '\t' || c == '\v' || c == '\f';
}

fix16_t __fastcall__ atox(const char *buf){
	uint8_t negative;
	uint32_t intpart = 0;
	uint16_t count = 0;
	fix16_t value;
	
	while (isspace(*buf)){
		++buf;
	}
	
	// Decode the sign
	negative = (*buf == '-');
	if (*buf == '+' || *buf == '-'){
		++buf;
	}
	
	// Decode the integer part
	while (isdigit(*buf)){
		intpart *= 10;
		intpart += *buf++ - '0';
		++count;
	}
	
	if (count == 0 || count > 5 || intpart > 32768U || (!negative && intpart > 32767U)){
		return FX_OVFL;
	}
	
	value = intpart << 16;
	
	// Decode the decimal part
	if (*buf == '.' || *buf == ','){
		uint32_t fracpart = 0;
		uint32_t scale = 1;
		
		++buf;
		
		while (isdigit(*buf) && scale < 100000){
			scale *= 10;
			fracpart *= 10;
			fracpart += *buf++ - '0';
		}
		
		value += xdiv(fracpart, scale);
	}
	
	// Verify that there is no garbage left over
	while (*buf != '\0'){
		if (!isdigit(*buf) && !isspace(*buf))
			return FX_OVFL;
		
		++buf;
	}
	
	return negative ? -value : value;
}

