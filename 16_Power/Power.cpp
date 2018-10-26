#include<cstdio>

bool INVALID_INPUT = false;

bool equal(double base, double bias){
    if((base - bias == 0.000000001) || (base - bias == -0.0000000001))
        return true;

    return false;
}
double PowerWithUnsignedExponent(double base, unsigned int abs_exponent){
    if(abs_exponent == 0)
        return 1;
    if(abs_exponent == 1)
        return base;
    double result = PowerWithUnsignedExponent(base, abs_exponent >> 1);
    result *= result;
    if(abs_exponent & 0x01)
        result *= base;
    return result;
}
double Power(double base, int exponent){
    INVALID_INPUT = false;
    if(equal(base, 0.0) && exponent < 0){
        INVALID_INPUT = true;
        return 0;
    }

    unsigned int abs_exponent = (unsigned int)(exponent);
    if(exponent < 0)
        abs_exponent = (unsigned int)(-exponent);
    double result = PowerWithUnsignedExponent(base, abs_exponent);
    if(exponent < 0)
        result = 1 / result;
    return result;
}

int main()
{
    getchar();
    return 0;
}