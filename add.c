#include "ieee754.h"

int main()
{
    float a = 3.14, b = 2.71, c;
    uint32_t bin_a_plus_b;

    printf("sign(a) = %s\n", (!ieee754_single_sign(a))?"+":"-");
    printf("fraction(a) = %u (0x%x)\n", ieee754_single_fraction(a), ieee754_single_fraction(a));
    printf("exp(a) = %u (0x%x)\n", ieee754_single_exponent(a), ieee754_single_exponent(a));

    /* Value of a, b */
    printf("a = %f\n", a);
    printf("a = 0x%4x (in binary)\n", *(uint32_t *)&a);
    printf("b = %f\n", b);
    printf("b = 0x%4x (in binary)\n", *(uint32_t *)&b);

    /* a+b */
    c = a+b;
    bin_a_plus_b = (*(uint32_t *)&a) + (*(uint32_t *)&b);

    printf("a + b = %f\n", c);
    printf("a + b = 0x%4x (in binary)\n", *(uint32_t *)(&c));
    printf("bin (a + b) = 0x%4x\n", bin_a_plus_b);

    return 0;
}
