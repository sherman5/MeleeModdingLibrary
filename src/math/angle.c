#include "../math.h"

float angle(Point a, Point b)
{
    return atan2(b.y - a.y, b.x - a.x);
}