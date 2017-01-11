#ifndef MATH_H
#define MATH_H

#include <stdint.h>

#define M_PI 3.14159265359f

/* Converts degrees to radians. used for trigonometric approxs */
inline float deg2Rad(float deg) { return deg * M_PI / 180.f; }

/* Returns degrees converted to the first quadrant. b > 0. used for trigonometric approxs*/
int pmod(int, int);

/* return sin(x), x is given in degress, error within 0.001 */
float sin(float deg);

#if 0

typedef struct point
{
    float x, y;

} Point;

float abs(float);



int8_t sign(float);



/* return cos(x), x is given in degress, error within 0.001 */
float cos(float deg);

/* Maximum error is 10.31 in degrees */
float acos(float deg);

float tan(float deg);

int ipow(int, uint32_t);

/* shitty sqrt, http://bits.stephan-brumme.com/squareRoot.html */
float sqrt(float);

int32_t imax(int32_t ra[]);

int32_t imin(int32_t ra[]);

/* returns point containing the b's position relative to a (a at origin) */
point relativeTo(point, point);

/* returns magnitude of a point */
float mag(point);

/* returns distance between two points */
float distance(point, point);
#endif

#endif
