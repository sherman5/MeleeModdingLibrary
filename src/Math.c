#include "Math.h"

float abs(float x) {

    return (x < 0 ? -x : x);

}

int8_t sign(float x) {

    return ((x >= 0) - (x < 0));

}

//error within 0.001
//x in degrees
float sin(float x) {

    x *= M_PI / 180.0;

    signed int neg = 1;

    if (x < 0) {
    
        x = -x;
        neg = -1;

    }

    while (x > 180) {
    
        x -= 360;

    }

    if (x < 0) {

        x = -x;
        neg *= -1;

    }

    float value = 1.27323954 * x - 0.405284735 * x * x;
    return neg * 0.225 * (value * value - value) + value;    

}

//error within 0.001
//x in degrees
float cos(float x) {

    return sin(x + 90);

}

