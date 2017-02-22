#include <stdio.h>
#include <stdint.h>
#include "ieee754.h"

/*
 * IEEE 754 (IEEE Standard for Floating-Point Arithmetic)
 *
 * Single Precision
 *  - float: 4 Byte
 *  - 1 bit sign
 *  - 8 bit exponent
 *  - 23 bit mantissa
 *
 * Double Precision
 *  - double: 8 Byte
 *  - 1 bit sign
 *  - 11 bit exponent
 *  - 52 bit mantissa (or fraction)
 *
 * Extended Double Precision
 *  - long double: 10 Byte
 *  - 1 bit sign
 *  - 15 bit exponent
 *  - 1 bit integer part
 *  - 63 bit fraction
 */

inline uint8_t ieee754_single_sign(float num) {

    uint32_t binary;
    binary = (*(uint32_t *)&num);
    return binary / 0x80000000;
}

inline uint8_t ieee754_single_exponent(float num) {

    uint32_t binary;
    binary = (*(uint32_t *)&num);
    return (binary & 0x7f800000) / (0x800000);
}

inline uint32_t ieee754_single_fraction(float num) {

    uint32_t binary;
    binary = (*(uint32_t *)&num);
    return (binary & 0x07fffff) % (0x800000);
}
