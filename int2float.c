unsigned int2float(int x) {
    int signBit, fraction, exponent=-1, copy=x, temp=x;
    //Determining signBit
    if (x>0) {
        signBit = 0;
    }else if (x==0)
        return 0;
    else {
        signBit = 1;
    //Determining exponent
    if (copy < 0) {
        temp=copy = copy*-1;
    }
    while (copy > 0) {
        copy = copy>>1;
        exponent++;
    }
    exponent += 15;
    //Determining fraction
    fraction = temp;
    while (fraction > (1<<9))
        fraction >>= 1;
    while (fraction < (1<<9))
        fraction <<= 1;
    fraction <<= 1;
    
    return (signBit<<15) | (exponent<<10) | fraction;