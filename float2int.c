int float2int(float x) {
    int signBit = x[15], exponent = x[10:14], significand = x[0:9];

    //x is inifinity or NaN
    if (exponent == 11111) {
        return
    }
    else if (exponent != 0) {
        significand += (1 <<24)
        exponent -= 15
    }

    //Interger overflow
    if (signBit == 0 && exponent > 15)
        return

    if (signBit) {
        significand = -significand;
    }
    
    while (fraction > (1<<11))
        fraction >>= 1;
    while (fraction < (1<<11))
        fraction <<= 1;
    fraction <<= 1;

}