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
    exponent += 127;
    //Determining fraction
    fraction = temp;
    while (fraction > (1<<22))
        fraction >>= 1;
    while (fraction < (1<<22))
        fraction <<= 1;
    fraction <<= 1;
    return (signBit<<31) | (exponent<<23) | fraction;
// float convert_int(unsigned int num) {
//     float result;
//     unsigned int sign_bit = (num & 0x80000000);
//     unsigned int exponent = (num & 0x7F800000) >> 23;
//     unsigned int mantissa = (num & /* insert mask value here */);

//     /* you can take over from here */

//     return result;
// }