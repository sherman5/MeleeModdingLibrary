#include "../math.h"

float atan2(float y, float x)
{
    float ax = fabs(x);
    float ay = fabs(y);
    float result;

    if (ay < ax) //first octant
    {
        result = (ax * ay) / (ax * ax + 0.28125f * ay * ay);
    }
    else //second octant
    {
        result = M_PI / 2 - (ax * ay) / (ay * ay + 0.28125f * ax * ax);
    }

    if (x < 0) { result = M_PI - result;} //reflect around y-axis
    if (y < 0) { result *= -1;} //reflect around x-axis
}
